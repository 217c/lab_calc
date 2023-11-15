/*
Questo foglio soddisfa la prima parte di questa esercitazione
*/

# include <stdio.h>
# include <math.h>
# include <stdlib.h>

/*
La distribuzione binomiale, o distribuzione di Bernoulli, è una distribuzione di probabilità discreta che 
descrive la probabilità che in n esperimenti si verifichi k volte un evento con probabilità individuale p
*/

long long int factorial(int ); // dichiarazione della funzione fattoriale

int main() {


    // printf("sanity check\n");

    int i, k;
    long long int n;
    double p, bern_p;
    FILE *fp;

    // set n and p
    n = 12;
    p = 1.0/6;

    // printf("n = %llu; p = %.2f\n", n, p);

    // apri il file di output
    fp = fopen("bernoulli.dat", "w");

    // compute bernoulli
    for (i=0; i<=n; i++) {
        // useless variable assignment, fatto solo per non confondersi tra l'indicatore e il k
        k = i;

        // printf("k = %3i, n! = %llu, k! = %llu, n-k! = %llu, p^k = %8.6f, (1-p)^k = %8.6f\n",
        // k,
        // factorial(n),
        // factorial(k),
        // factorial(n-k),
        // pow(p, k),
        // pow(1-p, n-k)
        // );

        bern_p = ( factorial(n) / ( factorial(k) * factorial(n-k) ) ) * (pow(p, k) * pow(1-p, n-k));
        // printf("bern_p is %.5f\n", bern_p);

        // print on output file
        fprintf(fp, "%d %f\n", k, bern_p);
    }
    


}

/*
Qui viene implementata la funzione fattoriale
*/

long long int factorial(int n){

    if (n==0) {
        return 1;
    } 
    else if (n > 0) {
        return n * factorial(n-1);
    }

}