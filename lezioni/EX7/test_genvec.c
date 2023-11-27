/*
Questo foglio serve per testare le funzioni genvec, perché la mia inizialmente non produceva il comportamento sperato.
genvec_nuovo credo che alla fine sia quello che ho usato in algebra_terza_parte.c
*/

# include <stdio.h>
# include <math.h>
# include <stdlib.h>
# include <time.h>

void genvec_prof(double v[]); 
void genvec_mio(double v[]);
void genvec_nuovo(double v[]);
void printvec(double v[]);

int main() {

    srand(time(NULL));

    double v[3] = {0.0};

    genvec_prof(v);
    printf("This is prof's: \n");
    printvec(v);

    genvec_mio(v);
    printf("This is mio: \n");
    printvec(v);
    
    genvec_nuovo(v);
    printf("This is nuovo: \n");
    printvec(v);

}

void genvec_prof(double v[]) {
    int i;
    double mod=0.0;
    
    for (i=0; i<3; i++) {
        v[i] = -1.0 + 2.0 * (double)(rand()) / RAND_MAX;
        mod = mod + v[i] * v[i];
        }
    mod = sqrt(mod);
    printf("This is mod: %.5f \n", mod);

    printf("Generated prof's: \n");
    printvec(v);

    for (i=0; i<3; i++) {
        v[i] = v[i] / mod;
    }
}

void genvec_nuovo(double v[]) {
    int i;
    double mod;

    // generate random vector
    for (i=0; i<3; i++) {
        v[i] = (double) rand() / (RAND_MAX / 2) - 1;
    }
    printf("Generated nuovo's: \n");
    printvec(v);

    // get mod
    for (i=0; i<3; i++) {
        mod = mod + pow(v[i], 2);
    }
    mod = sqrt(mod);

    // rendilo un versore
    for (i=0; i<3; i++) {
        v[i] = v[i] / mod;
    }

}

void genvec_mio(double v[]) {
    int i;

    // generate random vector
    for (i=0; i<3; i++) {
        v[i] = (double) rand() / (RAND_MAX / 2) - 1;
    }
    printf("Generated mio's: \n");
    printvec(v);

    // rendilo un versore
    for (i=0; i<3; i++) {
        v[i] = v[i] / (sqrt(pow(v[i], 2)));
    }

}



void printvec(double v[]) {
    // stampa il vettore
    int i;

    // printf("This is v: \n");
    for (i=0; i<3; i++) {
        printf("%6.4f ", v[i]);
    }
    printf("\n");
}