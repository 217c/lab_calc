/*
Questo file include alcune modifiche alla terza parte, fatte appositamente per cercare di guardare tutte le matrici relative
a tutti gli angoli. Questo mi permetterà di generare tutti i grafici e confrontarli.
Questo programma è associato a coord_plot_improved.py, che crea un grafico animato usando coordinate_tuttigliangoli.dat
*/

# include <stdio.h>
# include <math.h>
# include <stdlib.h>
# include <time.h>

void product(double A[][3], double v[], double w[]); // dichiarazione della funzione product
void genvec(double v[]); // dichiarazione della funzione che genera il vettore
void printvec(double v[]);

// file pointer
FILE *outfpr;

int main() {

    // set randomizer
    srand(time(NULL));

    // dichiara le variabili
    double A[3][3];
    double v[3], w[3];
    double mod_squared;

    int ang_i, i, ii;
    double angolo;

    outfpr = fopen("coordinate_tuttigliangoli.dat", "w");

    for (ang_i = 0; ang_i <= 360; ang_i++) {

        // mettilo in radianti (non mi pare ci fosse scritto nelle istruzioni)
        angolo = ang_i * M_PI / 180;
        printf("phi = %6.4f \n", angolo);

        // setta la matrice
        A[0][0] = cos(angolo);
        A[0][1] = - sin(angolo);
        A[1][0] = sin(angolo);
        A[1][1] = cos(angolo);

        A[2][2] = 1.0;

        // stampa la matrice
        // printf("This is A: \n");
        // for (i=0; i<3; i++) {
        //     for (ii=0; ii<3; ii++) {
        //         printf("%.5f  ", A[i][ii]);
        //         }
        //     printf("\n");
        //     // print("")
        // }     

        for (i=0; i<=1000; i++) {

                // genera il vettore
                genvec(v);

                // calcola il prodotto
                product(A, v, w);

                // output to file
                fprintf(outfpr, "%f %f %f %f %f %f %f\n",
                    angolo,
                    v[0],
                    v[1],
                    v[2],
                    w[0],
                    w[1],
                    w[2]
                    );

        }
    }

   // close output file connection
   fclose(outfpr);

}



void product ( double A[ ] [ 3 ] , double v [] , double w[ ] ) {
    int r , c ;
    for	( r=0;r <3;r++)
    {
         w[ r ]=0.0;
         }
          for	( r=0;r <3;r++) {
             for	(c=0;c<3;c++) {
                 w[ r]+=A[ r ] [ c ]*v [ c ] ;
                 }
                 }
                 }

void genvec(double v[]) { // this is genvec_nuovo
    int i;
    double mod;

    // generate random vector
    for (i=0; i<3; i++) {
        v[i] = (double) rand() / (RAND_MAX / 2) - 1;
    }

    // get mod
    for (i=0; i<3; i++) {
        mod = mod + pow(v[i], 2);
    }
    mod = sqrt(mod);

    // rendilo un versore
    for (i=0; i<3; i++) {
        v[i] = v[i] / mod;
    }

}

void	printvec ( double v [ ] )
{
	int	i ;
	for	( i =0;i <3; i++)
{
	printf ("%6.4f	" ,v [ i ]) ;
}
printf ("\n") ;
}