/*
Questo foglio soddisfa la seconda parte di questa esercitazione
*/

# include <stdio.h>
# include <math.h>
# include <stdlib.h>
# include <time.h>

/*
simuladadi.c che simuli il lancio di n dadi a sei facce, per verificare che l’evento di uscita di una
determinata faccia segua effettivamente la distribuzione binomiale.
Per poter fare ciò, è necessario ripetere molte volte l’esperimento (cioè ripetere Nlanci volte il lancio
di n dadi), e tener traccia della frequenza con cui in ogni lancio di n dadi si verifica l’uscita di k 3.
*/

int dado();

/*
Per evitare che il generatore di numeri casuali generi sempre lo stesso risultato
per dado, il seme della sequenza va inizializzato una sola volta all’inizio del programma, e non
all’interno della funzione.
*/

/*
Devo contare quante volte si è verificato un certo k. k può andare da 0 a n, perché puoi avere 0 successi o il massimo di successi.
A ogni giro ho un nuovo k. Posso creare un array con il verificarsi di n successi, dove la posizione indica quel certo numero di successi,
e il valore viene aggiornato con una somma a ogni giro.
*/

int main() {

    int seed;
    int i, ii, k, res_lancio, count_succ = 0;
    int k_successi[50];
    double k_succ_freq[50];
    long long int n;
    int n_lanci;
    double p, bern_p;
    FILE *fp;

    // set seed
    seed = time(NULL);
    srand(seed);

    // set n and p
    printf("Set n: ");
    scanf("%llu", &n);
    printf("Set n_lanci: ");
    scanf("%i", &n_lanci);
    p = 1.0/6; // questa è la probabilità standard per un dado a 6 facce

    // inizializza l'array con i successi
    for (i=0; i<=n; i++) {
        k_successi[i] = 0;
    }

    // apri il file di output
    // nonostante l'istogramma sia solo il grafico effettivo, chiamiamo questo file "istogramma.dat", come richiesto dall'esercizio
    fp = fopen("istogramma.dat", "w");

    
    for (i=0; i<=n_lanci; i++) { // per n_lanci...
        for (ii=0; ii<=n; ii++) {// ...lancia n dadi
            res_lancio = dado();
            // printf("%i ", res_lancio);
            
            if (res_lancio == 3) count_succ++;

        } 
        // printf("| k: %i\n", count_succ);

        // aggiorna la quantità di successi
        k_successi[count_succ] = k_successi[count_succ] + 1;

        count_succ = 0; // il contatore viene azzerato a ogni nuovo giro
    }

    // calcola la frequenza dei k successi
    for (i=0; i<n; i++) {
        // printf("k_successi: %i / %i = %f\n", k_successi[i], n_lanci, (double)k_successi[i] / n_lanci);
        k_succ_freq[i] = (double)k_successi[i] / n_lanci;
    }

    //print data
    printf("k_successi: \n");
    for (i=0; i<n; i++) {
        printf("%i ", k_successi[i]);
    }
    printf("\n");

    //print data
    printf("k_successi frequenze: \n");
    for (i=0; i<n; i++) {
        printf("%f ", k_succ_freq[i]);
    }
    printf("\n");

    // final print to output file
    for (i=0; i<n; i++) {
        fprintf(fp, "%i %i %f\n", i, k_successi[i], k_succ_freq[i]);
    }
}

/*
Confrontare (graficamente) i dati generati dai due programmi per gli stessi valori di n e k. 
Qual è il numero minimo di lanci da usare nel secondo programma per ottenere un campionamento ragionevole della distribuzione di Bernoulli?
    -- direi dal migliaio in su.
Se si esegue il secondo programma più volte per uno stesso numero di lanci Nlanci, come cambia la distribuzione? 
    -- è difficile vedere cambiamenti nella distribuzione per n_lanci > 1000, ma l'idea è che più è basso n_lanci, 
    più il risultato rischia di non rappresentare la distribuzione di Bernoulli.
Che cosa si può fare per diminuire le fluttuazioni nel risultato?
    -- per n_lanci che tende a infinito, la distribuzione che si ottiene è sempre più simile a quella di Bernoulli.
    Ovviamente, per avere basse fluttuazioni, bisogna avere n_lanci molto grande.
    L'idea è che se in un esperimento si campionano troppi pochi dati, si rischia di osservare un comportamento che è distante da quello reale/atteso.
    Quando si fanno delle misure è bene farne tante per poter catturare con maggior precisione la misura reale.
*/


int dado() {
    /*
    Questa funzione simula il lancio di un dado
    */

    return rand()%6+1;
}