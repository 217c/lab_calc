/*
Carlo Fabrizio 1653849

Questo foglio implementa il programma richiesto per la prova valutata.


Dalla parte che richiede di modificare il programma in poi le istruzioni
sono davvero molto poco chiare e soggette all'interpretazione soggettiva.
In generale il grafico credo vada bene, ma penso che la prof
volesse un file .dat con meno dati, contenente direttamente le frequenze.
*/

// import delle librerie
# include <stdio.h>
# include <math.h>
# include <stdlib.h>
# include <time.h>

// direttive define
# define L 13
# define H 40
# define n_times 100000

// puntatore a file
FILE *outfpr;

// dichiarazione delle funzioni custom
void move(int pos[2]);
void print_pos(int pos[2]);
void print_field(char field[H][L]);
void aggiorna(int pos[2], char field[H][L]);

// main
int main() {

    // dichiarazione delle variabili
    // // array bidimensionali
    char field[H][L];
    // // array unidimensionali
    int pos[2] = {0,6};
    int H_arr[3] = {10,20,40};
    // // indicatori
    int i, ii, j, n_count = 0;

    // impostazione del seme di randomizzazione
    srand(time(NULL));

    // open file in append mode
    outfpr = fopen("histo_H.txt", "a");

    // ##################################### programma...

    // assegna i trattini a field
    for (i = 0; i < H; i++) {
        for (ii = 0; ii < L; ii++) {
            field[i][ii] = '-';
        }
    }

    // segna la posizione iniziale della formica
    aggiorna(pos, field);
    
    // stampa field
    // print_field(field);

    // stampa la posizione della formica
    // printf("\nQuesto è il vettore pos: \n");
    // print_pos(pos);
    

    for (j = 0; j < n_times; j++) {

        while ( pos[1] < L && pos[1] >= 0 && pos[0] < H ) {


            n_count += 1;

            // STEP 1: la posizione della formica cambia!
            move(pos);

            // stampa la posizione della formica
            // printf("Nuova posizione: \n");
            // print_pos(pos);

            // STEP 2: aggiorna il campo di gioco inserendo l'asterisco!
            aggiorna(pos, field);

            // stampa field
            // print_field(field);

            // printf(
            //     "alla mossa n. %d la formica si trova sulla riga %d e sulla colonna %d\n",
            //     n_count,
            //     pos[0],
            //     pos[1]
            //     );
        
        }

        // stampa field
        // print_field(field);
        if ( pos[0] >= H ) { // condizione di fondo raggiunto (vero)
            fprintf(outfpr,
            "%d %d\n",
            n_count, H);
        }

        // reinizializza pos
        pos[0] = 0;
        pos[1] = 6;
        
        // reinizializza n_count
        n_count = 0;
        
    }

}

// programmazione delle funzioni custom
void move(int pos[2]) {
    int mossa;
    int max_num = 4, min_num = 0;

    // genera un numero casuale che corrisponde alla mossa della formica
    mossa = rand() % (max_num - min_num) + min_num;

    // printf("mossa: %d\n", mossa);

    /*
    Per associare gli esiti possibili alle mosse che voglio,
    posso fare in modo che i valori 0 e 1 indichino la mossa verso il basso,
    mentre 2 indica la mossa verso sx
    e 3 indica la mossa verso dx.

    Come faccio per fare questo?
    Siccome sto parlando di condizioni da cui derivano degli esiti,
    ho bisogno di utilizzare un if statement.
    */

   // se esce 0 o 1, vado in basso
   if ( mossa == 0 || mossa == 1) {
       pos[0] = pos[0] + 1; 
   }

    // se esce 2 vado verso sx
    if (mossa == 2) {
        pos[1] = pos[1] - 1;
    }

    // se esce 3 vado verso dx
    if (mossa == 3) {
        pos[1] = pos[1] + 1;
    }

}

void aggiorna(int pos[2], char field[H][L]) {
    /*
    Questa funzione aggiorna il campo di gioco,
    inserendo un asterisco nella nuova posizione occupata dalla formica.
    */

   // controllo che la mossa non porti la formica fuori dai bordi del campo
   if (pos[1] < L && pos[1] >= 0 && pos[0] < H) { // è vero che siamo dentro al bordo destro, sinistro e inferiore
    field[ pos[0] ][ pos[1] ] = '*';
   }

   
}

void print_pos(int pos[2]) {
    printf("%d %d\n", pos[0], pos[1]);
}

void print_field(char field[H][L]) {
    int i, ii;
    
    for (i = 0; i < H; i++) {
        for (ii = 0; ii < L; ii++) {
            printf("%c ", field[i][ii]);
        }
        printf("\n");
    }
}