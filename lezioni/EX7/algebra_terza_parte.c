# include <stdio.h>
# include <math.h>
# include <stdlib.h>
# include <time.h>

double * product(double [3][3], double [3]); // dichiarazione della funzione product
double * genvec(); // dichiarazione della funzione che genera il vettore

// file pointer
FILE *outfpr;

int main() {

    // set randomizer
    srand(time(NULL));

    // dichiara le variabili
    double A[3][3];
    double vec[3];
    double *w, *v; /* pointers to a double */
    double mod_squared;

    int i, ii;
    int angolo;

    // setta la matrice

    // // leggi l'angolo
    printf("Inserisci un angolo phi: \n");
    scanf("%d", &angolo);

    /* 
    Considera che quando inizializzi un array bidimensionale, tutti i valori sono 0.
    Quindi sostituisco solo quelli che mi servono seguendo le istruzioni
    */
    A[0][0] = cos(angolo);
    A[0][1] = -1.0 * sin(angolo);
    A[1][0] = sin(angolo);
    A[1][1] = cos(angolo);

    A[2][2] = 1.0;

    // stampa la matrice
    printf("This is A: \n");
    for (i=0; i<3; i++) {
        for (ii=0; ii<3; ii++) {
            printf("%.5f  ", A[i][ii]);
            }
        printf("\n");
    }

    /*
    b) usando la funzione genvec() generi una sequenza casuale di vettori v (almeno 100) tramite
    un ciclo for nel quale, ad ogni passo,
        i. si calcola il prodotto w = Av (dove A è la matrice unitaria di cui sopra);
        ii. si scrivono i vettori v e w sul file coordinate.dat nel formato a sei colonne: v[0] v[1] v[2] w[0] w[1] w[2];
        iii. si calcola il modulo quadro del vettore w e si stampa su schermo solo se esso non è uguale a 1 (entro una tolleranza di una parte su 10^7).
    */

   for (i=0; i<=100; i++) {
        // genera il vettore
        v = genvec();

        // calcola il prodotto
        w = product(A, v);

        // output to file
        outfpr = fopen("coordinate.dat", "a");
        fprintf(outfpr, "%f %f %f %f %f %f\n",
            v[0],
            v[1],
            v[2],
            w[0],
            w[1],
            w[2]
            );
        
        // modulo quadro
        // devo dire che questa richiesta non l'ho capita. Non ho implementato la tolleranza come richiesto, ma in generale a che serve?
        for (ii=0; ii<3; ii++) {
            mod_squared = pow(sqrt(pow(w[ii], 2)), 2);

            if (mod_squared != 1.0) {
                printf("This is mod_squared: %.10f\n", mod_squared);
            }
        }

   }

   // close output file connection
   fclose(outfpr);

}

double * genvec() {
    static double versore[3];
    int i;

    // generate random vector
    for (i=0; i<3; i++) {
        versore[i] = (double) rand() / (RAND_MAX / 2) - 1;
    }

    // rendilo un versore
    for (i=0; i<3; i++) {
        versore[i] = versore[i] / (sqrt(pow(versore[i], 2)));
    }

    return versore;
}

double * product(double mat[3][3], double vec[3]) {
    int j, ii;
    double sum = 0;
    static double w[3];

    for (j=0; j<3; j++) {
        for (ii=0; ii<3; ii++) {
            sum = sum + mat[j][ii] * vec[ii];
        }
        w[j] = sum;
    }

    return w;
}