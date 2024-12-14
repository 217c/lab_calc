
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>

// Funzione per generare un numero casuale compreso tra 0 e L-1 senza bias 

int rand_range(int L) {

    int res = rand()/((RAND_MAX + 1u) / L);
    /* int res = rand() % L; */
    /* printf("res: %d\n", res); */
    return res;
    // Nota: rand()%L e' biased se RAND MAX non e' multiplo di L

};


// Struttura per rappresentare una particella
typedef struct {
    int x;
    int y;
    int id;
    int passi_dx_sx;
    int passi_su_giu;
} Particella;

// Funzione per verificare se la posizione è occupata
bool posizione_occupata(char *reticolo, int lato_reticolo, int x, int y) { 
    return reticolo [y * lato_reticolo + x] == '0';
}


// Funzione per inizializzare le particelle in posizioni casuali

void inizializza_particelle(char *reticolo, Particella *particelle, int lato_reticolo, int numero_particelle) {
    
    for (int i = 0; i < numero_particelle; i++) {
        
        int x, y; 
    
        do {
            x = rand_range(lato_reticolo);
            y = rand_range(lato_reticolo);
        } while (posizione_occupata(reticolo, lato_reticolo, x, y));

            particelle[i].x = x;
            particelle[i].y = y;
            particelle[i].id = i;
            particelle[i].passi_dx_sx = 0;
            particelle[i].passi_su_giu = 0;
            reticolo[y * lato_reticolo + x] = '0';
    };
};


// Funzione per aggiornare la posizione di una particella con condizioni periodiche al 

void aggiorna_posizione(Particella *p, int lato_reticolo, char *reticolo) {
    int nuova_x = p->x;
    int nuova_y= p->y;
    int direzione = rand_range(4);


    switch (direzione) {
        case 0: // Su
            nuova_y= (p->y + 1) % lato_reticolo;
            break;
        case 1: // Giù
            nuova_y= (p->y - 1+ lato_reticolo) % lato_reticolo;
            break;
        case 2: // Destra
            nuova_x = (p->x + 1) % lato_reticolo;
            break;
        case 3: // Sinistra
            nuova_x = (p->x - 1 + lato_reticolo) % lato_reticolo;
            break;
    };

    
    // Controlla se la nuova posizione è occupata
    if (!posizione_occupata (reticolo, lato_reticolo, nuova_x, nuova_y)) { // Aggiorna la posizione nel reticolo
        reticolo[p->y * lato_reticolo + p->x] = '_';
        p->x = nuova_x;
        p->y = nuova_y;
        reticolo[p->y * lato_reticolo + p->x] = '0';

        
        // Aggiorna i contatori 
        if (direzione == 0) {
            p->passi_su_giu++;
        } else if (direzione == 1) {
            p->passi_su_giu--;
        } else if (direzione == 2) {
            p->passi_dx_sx++;
        } else if (direzione == 3) {
            p->passi_dx_sx--;
        }
    }
}


// Funzione per stampare lo stato del reticolo 
void stampa_reticolo (char *reticolo, int lato_reticolo) {
    // Stampa il reticolo
    for (int i = 0; i < lato_reticolo; i++) {
        for (int j = 0; j< lato_reticolo; j++) {
            printf("%c", reticolo [i* lato_reticolo + j]);
        } 
        printf("\n");
    }
    printf("\n");
}

// Funzione per calcolare il coefficiente di diffusione
double calcola_coefficiente_diffusione(Particella *particelle, int numero_particelle, int STEPS){

    double somma_spostamenti_quadrati = 0.0;
    for (int i = 0; i < numero_particelle; i++) { 
        int dx = particelle [i].passi_dx_sx;
        int dy = particelle[i].passi_su_giu;
        somma_spostamenti_quadrati += (dx * dx) + (dy * dy);
    }
    
    double media_spostamenti_quadrati = somma_spostamenti_quadrati / numero_particelle;
    return media_spostamenti_quadrati / (2.0 * STEPS);
}

int main(int argc, char *argv[]) {

    // Parametri della simulazione
    int lato_reticolo;           // Dimensione del reticolo
    int numero_particelle;       // Numero di particelle
    int STEPS;                 // Numero di passi della simulazione
    int seed;                 // Seed per il generatore di numeri casuali

    double coefficiente_diffusione;

    lato_reticolo = atoi(argv[1]);
    numero_particelle = atoi(argv[2]);
    STEPS = atoi(argv[3]);
    seed = atoi(argv[4]);

    // Imposta il seed del generatore di numeri casuali
    srand(seed);

    // Allocazione del reticolo
    char *reticolo = (char *)malloc(lato_reticolo * lato_reticolo * sizeof(char));
    if (reticolo == NULL) {
        fprintf(stderr, "Errore nell'allocazione del reticolo.\n");
        return 1;
    }
    // Inizializza il reticolo con '_'
    for (int i = 0; i < lato_reticolo * lato_reticolo; i++) {
        reticolo[i] = '_';
    }

    // stampa il reticolo vuoto
    //printf("Reticolo inizialmente vuoto:\n");
    //stampa_reticolo(reticolo, lato_reticolo);

    // Allocazione delle particelle
    Particella *particelle = (Particella *)malloc(numero_particelle * sizeof(Particella));
    if (particelle == NULL) {
        fprintf(stderr, "Errore nell'allocazione delle particelle.\n");
        free(reticolo);
        return 1;
    }

    // Inizializza le particelle
    inizializza_particelle(reticolo, particelle, lato_reticolo, numero_particelle);

    // Simulazione
    for (int t = 0; t < STEPS; t++) {
        //printf("Passo %d:\n", t);
        
        //stampa_reticolo(reticolo, lato_reticolo);

        // Aggiorna la posizione delle particelle
        for (int i = 0; i < numero_particelle; i++) {
            aggiorna_posizione(&particelle[i], lato_reticolo, reticolo);
        }

        // t D
        printf("%i %f\n", t, calcola_coefficiente_diffusione(particelle, numero_particelle, t));
    }

    // Calcolo del coefficiente di diffusione
    
    //printf("Coefficiente di diffusione finale: %f\n", calcola_coefficiente_diffusione(particelle, numero_particelle, STEPS));

    // Libera la memoria
    free(reticolo);
    free(particelle);

    return 0;
}
