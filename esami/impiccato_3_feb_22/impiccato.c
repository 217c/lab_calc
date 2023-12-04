/*
Questo programma implementa una versione semplificata del gioco dell'impiccato.
Si gioca con la parola: "estemporaneo".
*/

// import delle librerie
# include <stdio.h>
# include <math.h>
# include <stdlib.h>
# include <time.h>
# include <string.h>

// direttive define
# define n_lettere 12+1 // 12 lettere della parola "estemporaneo" + 1 per il carattere di fine stringa
# define min_minuscole 97
# define max_minuscole 122

// dichiarazione funzioni custom
char lettera();
void print_lett_hist(int lett_hist_da_stampare[]);
int check(char, char[], char[]);
void print_riepilogo(char lettera_estratta, char guess_now[], int lett_hist_da_stampare[], int index);
int conta_caratteri_indovinati(char parola[], char guess[]);

// puntatore a file
FILE *outfpr;

// implementazione del main
int main() {

    // dichiarazione delle variabili

    // // array unidimensionali
    char parola[n_lettere] = "estemporaneo";
    char guess[n_lettere] = "------------";
    int lett_hist[max_minuscole - min_minuscole + 1] = {0};
    // // indici di iterazioni
    int i, tentativi = 0;
    // // check se ho indovinato tutto
    int tutto_indovinato = 0; // questo è un booleano
    int n_caratteri_indovinati;
    // // caratteri vari
    char lettera_estratta;
    // quante volte c'è quella lettera
    int letter_counter;

    // inizializzazione del generatore di numeri casuali
    srand(time(NULL));

    // open file in write mode
    outfpr = fopen("tentativi.txt", "w");

    // inizia il gioco, stampa il messaggio di benvenuto
    printf("Questo è il gioco dell'impiccato. Il programma dovrà indovinare la parola: %s\n", parola);

    // for (i=0; i<n_lettere; i++) { // è solo < e non <= perché l'ultimo carattere è quello di fine stringa.
    //     printf("%c", parola[i]);
    // }
    // printf("\n");

    printf("Guess è: %s\n", guess);

    // loop per l'implementazione del gioco
    while (tutto_indovinato == 0) {
        
        // aumenta il contatore dei tentativi
        tentativi += 1;


        // chiamata alla funzione lettera
        /*
        Questa chiamata va fatta finché non viene incontrata una condizione.
        Prima si esegue l'istruzione una volta e poi si controlla se va ripetuta, perciò è un do-while
        */
        do {
            lettera_estratta = lettera();
        } while(lett_hist[lettera_estratta - min_minuscole] == 1); // // controlla se la lettera è già uscita

        // segna che adesso è uscita e procedi oltre
        lett_hist[lettera_estratta - min_minuscole] = 1;

        // printf("La lettera estratta è %c\n", lettera_estratta);

        // stampa lett_hist per controllarlo:
        // print_lett_hist(lett_hist);

        // chiamata alla funzione check
        letter_counter = check(lettera_estratta, parola, guess);
        // printf("Questa lettera compare %d volte\n", letter_counter);

        // printf("%s\n", guess);

        // stampa del messaggio di riepilogo
        printf("\n");
        print_riepilogo(lettera_estratta, guess, lett_hist, tentativi);

        n_caratteri_indovinati = conta_caratteri_indovinati(parola, guess);
        // stampa su file
        /*
        salvate su un file tentativi.txt tre colonne contenenti
        (1) il numero del tentativo, 
        (2) il numero di volte che la lettera estratta compare nella parola da indovinare, e 
        (3) il numero di caratteri indovinati fino a quel momento.
        */
        fprintf(outfpr, "%d %d %d\n", tentativi, letter_counter, n_caratteri_indovinati);


        // STOP condition
        if (strcmp(parola, guess) == 0) { // se sono uguali, allora tutto è stato indovinato (altrimenti continua il while)
            // printf("Sono uguali! %s == %s\n", parola, guess);
            tutto_indovinato = 1;
        }
        
    }

    // gioco terminato, stampa il messaggio finale:
    printf("\n\nParola indovinata: %s\n", guess);
    printf("Numero di tentativi necessari per indovinarla: %d\n", tentativi);

    fclose(outfpr);

}

// implementazione funzioni custom

/*
Questa funzione restituisce una lettera minuscola casuale.
*/
char lettera() {
    char c;

    c = rand()%(max_minuscole-min_minuscole)+min_minuscole;
    return c;
}

int check(char questa_lettera, char parola[], char guess[]) {
    /*
     riceve in input la lettera estratta e controlla se si trovi all’interno della parola da indovinare. 
     In caso positivo aggiorna l’array guess[], sostituendo ai trattini il carattere indovinato. 
     La funzione restituisce anche alla funzione chiamante il numero di volte in cui il carattere compare nella parola da indovinare.
    */
   int i, counter = 0;

   for (i=0; i<n_lettere; i++) {
    // printf("La lettera che controllo è %c, in posizione %d, ", parola[i], i);
    if (questa_lettera == parola[i]) { // se la lettera c'è

        guess[i] = questa_lettera;
        counter += 1; // se la lettera è stata trovata e sostituita, aumenta la conta
        // printf("C'è!\n");
    }
    // else printf("Non c'è\n");
   }

   return counter;
}

void print_lett_hist(int lett_hist_da_stampare[]) {
    
    int i;

    // stampa lett_hist per vedere com'è
    for (i=0; i< max_minuscole - min_minuscole + 1; i++) {
        printf("Per il valore %d (lettera %c): %d\n", i, i+min_minuscole, lett_hist_da_stampare[i]);
    }
}

void print_riepilogo(char lettera_estratta, char guess_now[], int lett_hist_da_stampare[], int index) {
    
    int i;
    printf("Tentativo n. %d, lettera: %c\n", index, lettera_estratta);
    printf("Contenuto dell'array guess:\n");
    printf("%s\n", guess_now);
    printf("Lettere utilizzate finora:\n");

    for (i=0; i< max_minuscole - min_minuscole + 1; i++) {
        if (lett_hist_da_stampare[i] == 1) {
            printf("%c ", i + min_minuscole);

        }
    }
    printf("\n---------------------------------------------------------------------------------------\n");

}

int conta_caratteri_indovinati(char parola[], char guess[]) {
    int i, conta=0;

    for (i=0; i<n_lettere; i++) {
        if (parola[i] == guess[i]) {
            conta += 1;
        }
    }
    return conta;
}
