# include <stdio.h>
# include <math.h>

double * product(double [3][3], double [3]); // dichiarazione della funzione product

int main() {

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
    for (i=0; i<3; i++) {
        printf("%.1f ", vec[i]);
    }
    printf("\n");

    // calcola il prodotto e salva w
    w = product(A, vec);

    printf("This is w: \n");

    // stampa il vettore
    for (i=0; i<3; i++) {
        printf("%.1f ", w[i]);
    }
    printf("\n");


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