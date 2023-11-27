/*
Le risposte alle domande sono in fondo al foglio.
Questa esercitazione per funzionare doveva includere alcune cose che non erano esplicitate nelle istruzioni.
la terza_parte_IMPROVED è successiva e alternativa a questo. Serve per guardare tutti gli angoli e non era richiesta,
l'ho creata per capire meglio il problema e rispondere alle domande.
*/


# include <stdio.h>
# include <math.h>
# include <stdlib.h>
# include <time.h>

void product(double A[][3], double v[], double w[]); // dichiarazione della funzione product
void genvec(double v[]); // dichiarazione della funzione che genera il vettore
void printvec(double v[]);

// file pointer
FILE *outfpr;

int main() {

    // set randomizer
    srand(time(NULL));

    // dichiara le variabili
    double A[3][3];
    double v[3], w[3];
    double mod_squared;

    int i, ii;
    double angolo;

    // // leggi l'angolo
    printf("Inserisci un angolo phi: \n");
    scanf("%lf", &angolo);

    // mettilo in radianti (non mi pare ci fosse scritto nelle istruzioni)
    angolo = angolo * M_PI / 180;
    printf("phi = %6.4f \n", angolo);

    // setta la matrice
    /* 
    Considera che quando inizializzi un array bidimensionale, tutti i valori sono 0.
    Quindi sostituisco solo quelli che mi servono seguendo le istruzioni
    */
    A[0][0] = cos(angolo);
    A[0][1] = - sin(angolo);
    A[1][0] = sin(angolo);
    A[1][1] = cos(angolo);

    A[2][2] = 1.0;

    // stampa la matrice
    printf("This is A: \n");
    for (i=0; i<3; i++) {
        for (ii=0; ii<3; ii++) {
            printf("%.5f  ", A[i][ii]);
            }
        printf("\n");
        // print("")
    }

    /*
    b) usando la funzione genvec() generi una sequenza casuale di vettori v (almeno 100) tramite
    un ciclo for nel quale, ad ogni passo,
        i. si calcola il prodotto w = Av (dove A è la matrice unitaria di cui sopra);
        ii. si scrivono i vettori v e w sul file coordinate.dat nel formato a sei colonne: v[0] v[1] v[2] w[0] w[1] w[2];
        iii. si calcola il modulo quadro del vettore w e si stampa su schermo solo se esso non è uguale a 1 (entro una tolleranza di una parte su 10^7).
    */

   outfpr = fopen("coordinate.dat", "w");

   for (i=0; i<=200; i++) {

        // genera il vettore
        /*
        non sono d'accordo con questa modalità di assegnazione di una variabile.
        È surreale che una funzione non ritorni nulla e magicamente una variabile venga assegnata.
        Credo che sia molto meglio la modalità in cui la funzione ritorna un puntatore attraverso cui si assegna il valore,
         com'era nella versione precedente del file.
        */
        genvec(v);

        // printf("This is v: \n");
        // printvec(v);

        // calcola il prodotto
        product(A, v, w);

        // output to file
        
        fprintf(outfpr, "%f %f %f %f %f %f\n",
            v[0],
            v[1],
            v[2],
            w[0],
            w[1],
            w[2]
            );
        
        // modulo quadro
        // devo dire che questa richiesta non l'ho capita. In generale a che serve?
        // for (ii=0; ii<3; ii++) {
        //     mod_squared = pow(sqrt(pow(w[ii], 2)), 2);

        //     if ((mod_squared-1.0) >= 0.0000001) {
        //         printf("This is mod_squared: %.10f\n", mod_squared);
        //     }
        // }

   }

   // close output file connection
   fclose(outfpr);

}



// void genvec(double v[]) {
//     int i;

//     // generate random vector
//     for (i=0; i<3; i++) {
//         v[i] = (double) rand() / (RAND_MAX / 2) - 1;
//     }

//     // rendilo un versore
//     // for (i=0; i<3; i++) {
//     //     v[i] = v[i] / (sqrt(pow(v[i], 2)));
//     // }

// }

/*

Tolgo le mie e metto le funzioni scritte dalla prof.
void product(double A[][3], double v[], double w[]) {
    int j, ii;

    // reset elements to 0.0
    for (j=0; j<3; j++) {
        w[j] = 0.0;
    }

    for (j=0; j<3; j++) {
        for (ii=0; ii<3; ii++) {
            w[j] += A[j][ii] * v[ii];
        }
    }

    // return w;
}

void printvec(double v[]) {
    // stampa il vettore
    int i;

    // printf("This is v: \n");
    for (i=0; i<3; i++) {
        printf("%.1f ", v[i]);
    }
    printf("\n");
}

*/

void product ( double A[ ] [ 3 ] , double v [] , double w[ ] ) {
    int r , c ;
    for	( r=0;r <3;r++)
    {
         w[ r ]=0.0;
         }
          for	( r=0;r <3;r++) {
             for	(c=0;c<3;c++) {
                 w[ r]+=A[ r ] [ c ]*v [ c ] ;
                 }
                 }
                 }

// void genvec (double v[]) {
//     int i;
//     double mod=0.0;
    
//     for ( i =0;i <3; i++){
//         v [ i ]= -1.0+2.0*( double ) (rand () )/RAND_MAX;
//         mod=mod+v [ i ]*v [ i ] ;
//         }
//     mod=sqrt (mod);
//     for ( i =0;i <3; i++) {
//         v [ i ]=v [ i ]/mod;
//         }
// }

void genvec(double v[]) { // this is genvec_nuovo
    int i;
    double mod;

    // generate random vector
    for (i=0; i<3; i++) {
        v[i] = (double) rand() / (RAND_MAX / 2) - 1;
    }
    // printf("Generated nuovo's: \n");
    // printvec(v);

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

void	printvec ( double v [ ] )
{
	int	i ;
	for	( i =0;i <3; i++)
{
	printf ("%6.4f	" ,v [ i ]) ;
}
printf ("\n") ;
}

// double modulus( double v [ ] )
// {
// 	int	i ;
// 	double	l =0;
// 	for	( i =0;i <3; i++)
// { l=l+v [ i ]*v [ i ] ;
// }	
// l= sqrt(l) ; 
// return	l ;
// }

/*
Come cambia il grafico di correlazione fra la quarta e la prima colonna del file coordinate.dat in funzione dell’angolo ϕ?
    - La correlazione dipende dall'angolo di rotazione. 
    Ad esempio per 0, 180, 360, sono correlati perfettamente (che sia positivamente o negativamente).

Come mai per alcuni valori notevoli il grafico è un cerchio e per altri una retta?
    - Con la versione IMPROVED sono riuscito a guardare tutti gli angoli.
    Si nota che:
        a 0 e 360 c'è una correlazione positiva perfetta (+1.0)
        a 90 non c'è correlazione (0.0), infatti i punti sono disposti a cerchio (come quelli dello scatter plot fra v1 e v3)
        poi si scorre verso la correlazione negativa che arriva perfetta a 180 (-1.0)
        di nuovo a 270 non c'è correlazione (0.0)
        e si aumenta fino a una correlazione positiva perfetta (+1.0) a 360°, che equivale effettivamente a 0°

    I punti si dispongono a cerchio quando non c'è correlazione per via dell'effetto del modulo. 
    Infatti se togli il modulo si dispongono a quadrato, ma il comportamento della correlazione è comunque lo stesso (testato). 
    Si tratterebbe di ruotare un quadrato.
*/