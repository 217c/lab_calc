# include <stdio.h>

# define nrows 10

// file pointer
FILE *fpr;

// multidimensional array
int dati[nrows][2];

// unidimensional array
double media[nrows];

// additional variables
int i, my_index;

int main() {
  // open file in read mode
  fpr=fopen("trimestre1.dat", "r");

  // import data from file
  for (i=0; i<=nrows; i++) {
    fscanf(fpr, "%i %i %i", &my_index, &dati[i][0], &dati[i][1]);

  }

  // close input file after reading data
  fclose(fpr);

  //print data
  for (i=0; i<nrows; i++) {
    printf("%i %i %i\n", i+1, dati[i][0], dati[i][1]);

  }

  printf("\n");
  
  // compute hourly mean
  for (i=0; i<nrows; i++) {
    //printf("res %f\n", (double)dati[i][0]/dati[i][1] );
    media[i] = (double)dati[i][0]/dati[i][1];
  }

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





}
