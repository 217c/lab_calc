/* Questo riguarda le parti 1 e 2 */

# include <stdio.h>
# include <math.h>
# include <stdlib.h>
# include <time.h>

double * product(double [3][3], double [3]); // dichiarazione della funzione product
double * genvec(); // dichiarazione della funzione che genera il vettore

int main() {

    // set randomizer
    srand(time(NULL));

    // printf("Sanity check\n");

    // dichiara le variabili
    double A[3][3];
    double vec[3];
    double *w; /* a pointer to a double */
    int i, ii;

    // setta la matrice
    for (i=0; i<3; i++) {
        for (ii=0; ii<3; ii++) {
            A[i][ii] = (i+1) * (ii+1);
        }
    }

    // stampa la matrice
    printf("This is A: \n");
    for (i=0; i<3; i++) {
        for (ii=0; ii<3; ii++) {
            printf("%.1f  ", A[i][ii]);
            }
        printf("\n");
    }

    // setta il vettore
    for (i=0; i<3; i++) {
        printf("Inserisci il valore %d nel vettore: ", i);
        scanf("%lf", &vec[i]);
    }

    // stampa il vettore
    printf("This is v: \n");
    for (i=0; i<3; i++) {
        printf("%.1f ", vec[i]);
    }
    printf("\n");

    // calcola il prodotto e salva w
    w = product(A, vec);

    // stampa il vettore
    printf("This is w: \n");
    for (i=0; i<3; i++) {
        printf("%.1f ", w[i]);
    }
    printf("\n");

    printf("\n\n");
    printf("Genera il versore...\n");

    genvec();


}

double * genvec() {
    static double versore[3];
    int i;

    // generate random vector
    for (i=0; i<3; i++) {
        versore[i] = (double) rand() / (RAND_MAX / 2) - 1;
    }

    // stampalo
    printf("This is versore casuale: \n");
    for (i=0; i<3; i++) {
        printf("%.10f ", versore[i]);
    }
    printf("\n\n");

    // rendilo un versore
    for (i=0; i<3; i++) {
        versore[i] = versore[i] / (sqrt(pow(versore[i], 2)));
    }

    // stampalo
    printf("This is versore: \n");
    for (i=0; i<3; i++) {
        printf("%.10f ", versore[i]);
    }
    printf("\n");



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
    // printf("%lf ", sum);
    // printf("\n");

    return w;
}
