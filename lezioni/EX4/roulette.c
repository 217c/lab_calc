/* Questo programma simula una partita di roulette */

# include <stdio.h>
# include <math.h>
# include <stdlib.h>
# include <time.h>
# include <string.h>



int main()
{
    int i = 1, seed, num, money = 100, how_much_punta = 0;
    char eo[10], mp[10];
    char what_punta[10];

    // set seed
    seed = time(NULL);
    srand(seed);
    printf("Seed is: %d\n", seed);

    while (i <= 10 && money > 0)
    {      
        printf("Giro %d\n", i);

        // inizializza le variabili per le puntate
        strcpy(eo, "x");
        strcpy(mp, "x");

        // Il giocatore punta
        printf("Decidi su cosa vuoi puntare, se even/odd o manque/passe. Scrivi uno dei comandi seguenti: E, O, M, P --> ");
        scanf("%s", what_punta);

        do {
            printf("Decidi quanto vuoi puntare. Hai a disposizione %d dindi --> ", money);
            scanf("%d", &how_much_punta);
            if (how_much_punta > money) printf("Non hai tutti quei soldi!\n");
        } while (how_much_punta > money);

        printf("La tua giocata è: %s %d\n", what_punta, how_much_punta);
        
        money = money - how_much_punta;

        printf("Dindi rimasti: %d\n", money);

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

        // controlla se hai vinto
        if (strcmp(what_punta, eo) == 0) // qui hai vinto per EO
        {   
            //printf("Hai vinto! %s %s\n", what_punta, eo);
            money = money + (how_much_punta * 2);
        } else if (strcmp(what_punta, mp) == 0) // qui hai vinto per MP
        {
            money = money + (how_much_punta * 2);
        } // quindi o ne vinci uno o nessuno.

        // OUTPUT: stampa il risultato
        printf("Estratto: %d, %s %s\n", num, eo, mp);
        printf("Nuovo ammontare: %d\n", money);

        i++;
    }

    printf("\n\n Game over! Hai giocato %d partite e ora hai %d dindi\n", i-1, money);
}