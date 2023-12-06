/*
Questo programma implementa il sandpile
*/

// librerie
# include <stdio.h>
# include <math.h>
# include <time.h>
# include <stdlib.h>

// define
# define SIZE 21
# define MIN 100
# define MAX 500

// puntatore a file
FILE *outfpr;

// funzioni
void print_grid(int grid[SIZE][SIZE]);
int count_grains(int grid[SIZE][SIZE]);
int check_grid(int grid[SIZE][SIZE]);
void topple(int grid[SIZE][SIZE]);
int check_end(int grid[SIZE][SIZE]);


// main
int main ()  {
    int grid[SIZE][SIZE] = {0}; // viene inizializzata con tutti 0
    int turn_iter;
    int granelli_tot_now, initial_sand_grains, init_rand_row, init_rand_col;


    // set seed
    srand(time(NULL));

    // open file in write mode
    outfpr = fopen("history.dat", "w");

    // stampa la griglia vuota
    // print_grid(grid);

    // deposita un numero casuale di granelli in una casella casuale
    initial_sand_grains = rand()%(MAX)+MIN;
    init_rand_row = rand()%SIZE;
    init_rand_col = rand()%SIZE;
    grid[init_rand_row][init_rand_col] = initial_sand_grains;

    // stampa la griglia iniziale
    printf("\n");
    print_grid(grid);

    // controlla check_end
    // printf("Check end dice: %i\n", check_end(grid));

    // iniziano i turni
    while (!check_end(grid)) {
        turn_iter += 1;
        

        // stampa la griglia ogni 50 turni
        if (turn_iter%50 == 0) {
            printf("\nTurno %d, griglia: \n", turn_iter);
            print_grid(grid);
        }

        // conta i granelli
        granelli_tot_now = count_grains(grid);

        // controlla se all’interno dell’array ci siano caselle con 4 o pi`u granelli di sabbia
        // printf("Ci sono caselle con più di 4 elementi?: %d", check_grid(grid));

        // se c'è una casella che contiene più di 4 granelli, avvia topple
        if (check_grid(grid)) {
            // topple fa cadere la sabbia nelle caselle intorno
            topple(grid);
        }

        // printf("Check end dice: %i\n", check_end(grid));

        // stampa su file
        fprintf(
          outfpr,
          "%d %d %d %d\n",
          turn_iter, 
          granelli_tot_now, 
          grid[init_rand_row][init_rand_col], // granelli nella casella iniziale
          grid[11][11]  // granelli nella casella centrale
          );

    }

    printf("\nGriglia finale al turno %d:\n", turn_iter);
    print_grid(grid);

    // close input file after reading data
    fclose(outfpr);

}

// programmazione funzioni
void print_grid(int grid[SIZE][SIZE]) {
    int i, ii;

    for (i=0; i<SIZE; i++) {
        for (ii=0; ii<SIZE; ii++) {
            printf("%d ", grid[i][ii]);
        }
        printf("\n");
    }
}

int count_grains(int grid[SIZE][SIZE]) {
    int i, ii, conta = 0;

    for (i=0; i<SIZE; i++) {
        for (ii=0; ii<SIZE; ii++) {
            conta = conta + grid[i][ii];
        }
    }

    return conta;
}

int check_grid(int grid[SIZE][SIZE]) {
    int i, ii, conta = 0;

    for (i=0; i<SIZE; i++) {
        for (ii=0; ii<SIZE; ii++) {
            if ( grid[i][ii] >= 4 ) {
                return 1;
            }
        }
    }

    return 0;
}

void topple(int grid[SIZE][SIZE]) {
    int i, ii;

    for (i=0; i<SIZE; i++) {
        for (ii=0; ii<SIZE; ii++) {
            if ( grid[i][ii] >= 4 ) {
                // la pila più alta si abbassa
                grid[i][ii] = grid[i][ii] - 4;

                // le pile intorno si alzano, ma solo se non si esce dai bordi
                if (i-1 >= 0) {
                    grid[i-1][ii] = grid[i-1][ii] + 1;
                }
                if (i+1 < SIZE) {
                    grid[i+1][ii] = grid[i+1][ii] + 1;
                }
                if (ii-1 >= 0) {
                    grid[i][ii-1] = grid[i][ii-1] + 1;
                }
                if (ii+1 < SIZE) {
                    grid[i][ii+1] = grid[i][ii+1] + 1;
                }
                
            }
        }
    }
}

int check_end(int grid[SIZE][SIZE]) {
    /*
    Questa funzione controlla se si è verificata la condizione di fine della simulazione:
    "fino a quando tutte le caselle non contengano 3 granelli di sabbia o meno"
    */

   int i, ii, count;

   for (i=0; i<SIZE; i++) {
        for (ii=0; ii<SIZE; ii++) {
            if ( grid[i][ii] <= 3 ) {
                count += 1;
            }
        }
   }

   if ( count == SIZE * SIZE ) { // se tutte le caselle contengono 3 granelli o meno
    return 1;
   }

   return 0;
   
}