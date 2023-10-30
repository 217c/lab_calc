/* Questo programma simula una lancio di roulette */

# include <stdio.h>
# include <math.h>
# include <stdlib.h>
# include <time.h>
# include <string.h>

int main()
{
    int seed, num;
    char eo[10], mp[10];

    seed = time(NULL);
    srand(seed);

    printf("Seed is: %d\n", seed);

    // LANCIO: genera un numero casuale per la roulette [intero N compreso tra 1 e 36 (incluso)]
    num = rand()%37;

    // ANALISI: vedi se è pari o dispari
    if (num % 2 == 0) {
        strcpy(eo, "E");
    } else if (num % 2 != 0) {
        strcpy(eo, "O");
    }

    // vedi se è oltre 18
    if (num <= 18) {
        strcpy(mp, "M");
    } else if (num > 18) {
        strcpy(mp, "P");
    }

    // OUTPUT: stampa il risultato
    printf("Estratto: %d, %s %s\n", num, eo, mp);

}