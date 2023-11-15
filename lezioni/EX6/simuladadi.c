/*
Questo foglio soddisfa la seconda parte di questa esercitazione
*/

# include <stdio.h>
# include <math.h>
# include <stdlib.h>

/*
simuladadi.c che simuli il lancio di n dadi a sei facce, per verificare che l’evento di uscita di una
determinata faccia segua effettivamente la distribuzione binomiale.
Per poter fare ciò, è necessario ripetere molte volte l’esperimento (cioè ripetere Nlanci volte il lancio
di n dadi), e tener traccia della frequenza con cui in ogni lancio di n dadi si verifica l’uscita di k 3.
*/

long long int factorial(int); // dichiarazione della funzione fattoriale

int dado();

int main() {

    int i, k;
    long long int n;
    int n_lanci;
    double p, bern_p;
    FILE *fp;

    // set n and p
    // n = 12;
    scanf("set n: %llu\n", n);
    scanf("set n_lanci: %i\n", n_lanci);
    p = 1.0/6; // questa è la probabilità standard per un dado a 6 facce

    // printf("n = %llu; p = %.2f\n", n, p);

    // apri il file di output
    // nonostante l'istogramma sia solo il grafico effettivo, chiamiamo questo file "istogramma.dat", come richiesto dall'esercizio
    fp = fopen("istogramma.dat", "w");

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
Questa funzione simula il lancio di un dado
*/

int dado() {
    int seed;
    seed = time(NULL);
    srand(seed);
    return rand()%6;
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