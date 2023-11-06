# include <stdio.h>

# define nrows 10

// file pointers
FILE *fpr;
FILE *outfpr;

// multidimensional arrays
int dati[nrows][2];
double sortmedia[nrows][2];

// unidimensional arrays
double media[nrows];
int rank[nrows];

// additional variables
int i, ii, my_index;
double bubtemp[2];

int main() {
  // open file in read mode
  fpr=fopen("trimestre1.dat", "r");

  // import data from file
  for (i=0; i<=nrows; i++) {
    fscanf(fpr, "%i %i %i", &my_index, &dati[i][0], &dati[i][1]);
  }

  // close input file after reading data
  fclose(fpr);

  /*
  //print data
  for (i=0; i<nrows; i++) {
    printf("%i %i %i\n", i+1, dati[i][0], dati[i][1]);

  }

  printf("\n");
  */
  
  // compute hourly mean
  for (i=0; i<nrows; i++) {
    //printf("res %f\n", (double)dati[i][0]/dati[i][1] );
    media[i] = (double)dati[i][0]/dati[i][1];
  }

  /*
  //print data
  for (i=0; i<nrows; i++) {
    printf("Guy %i made %.3f $/h\n", i+1, media[i]);

  }

  //final print
  printf("\n");
  printf("Guy   # h  # (€) # Media\n");
  for (i=0; i<nrows; i++) {
    printf("Guy %i # %i # %i # %.3f €/h\n",
	   i, dati[i][1], dati[i][0], media[i]);

  }
  */

  // qui viene creata la matrice da ordinare
  for (i=0; i<nrows; i++) {
    sortmedia[i][0] = i;
    sortmedia[i][1] = media[i];
  }

  //print data
  printf("This is sortmedia:\n");
  for (i=0; i<nrows; i++) {
    printf("%.0f %.3f\n", sortmedia[i][0], sortmedia[i][1]);
  }
  printf("\n");
  printf("Started sorting...\n");
  
  // sort data using bubblesort algorithm
  for (i=0; i<nrows; i++)
    {
      for (ii=nrows-1; ii>i; ii--)
	{
	  if (sortmedia[ii-1][1]<sortmedia[ii][1])
	    {
	      // salva l'indice
	      bubtemp[0]=sortmedia[ii-1][0];
	      // salva il valore
	      bubtemp[1]=sortmedia[ii-1][1];

	      //scambia il valore
	      sortmedia[ii-1][0] = sortmedia[ii][0];
	      sortmedia[ii-1][1] = sortmedia[ii][1];

	      sortmedia[ii][0] = bubtemp[0];
	      sortmedia[ii][1] = bubtemp[1];
	    }
	}
    }

  // print data
  printf("\n");
  printf("Sorted data:\n");
  for (i=0; i<nrows; i++) {
    printf("%.0f %.4f\n", sortmedia[i][0], sortmedia[i][1]);
  }
  printf("\n");
  
  // #### data analysis ####
  // 1. ranking
  for (i=0; i<nrows; i++) {
    rank[i] = i+1;
  }
  
  //final print
  printf("\n");
  printf("Rank pos   # Guy    # h   # (€)       # Media\n");
  for (i=0; i<nrows; i++) {
    printf("Position %i # Guy %i # %i # %.3f €/h # %.3f\n",
	   rank[i],
	   sortmedia[i][0],
	   dati[(int)sortmedia[i][0]][1],
	   dati[(int)sortmedia[i][0]][0],
	   sortmedia[i][1]);

  }

  // output data
  // open file in write mode
  outfpr=fopen("rank.dat", "w");

  // import data from file
  for (i=0; i<nrows; i++) {
    fprintf(fpr, "%i %i %i %f %f\n",
	   rank[i],
	   sortmedia[i][0],
	   dati[(int)sortmedia[i][0]][1],
	   dati[(int)sortmedia[i][0]][0],
	   sortmedia[i][1]);
  }
}
