# include <stdio.h>
# include <math.h>
# include <stdlib.h>

float eps = 0.0000000000001;

// la funzione sarà cos(x)
// la sua derivatà è -sin(x)

// questi sono i due estremi in cui viene applicato l'algoritmo
// Non credo che servano qui
//float a = 0.0, b = 3.0;

float x0 = 1, x_new, x_old;
int i, counter;

/*
L'algoritmo va a convergenza molto presto, ma ci sono dei valori per cui la tangente esplode.
Se ad esempio come valore di partenza inserisco 1+sqrt(2)-0.19 non riesco a trovare la radice, ma vado verso -infinito.
Credo che questo abbia a che fare con l'incontro delle altre funzioni x0 = 1+sqrt(2)
*/

int main()
{
    //printf("fabs(1.50000 - 0.56250) = %.5f\n", fabs(1.50000 - 0.56250));
    x0 = 1+sqrt(2)-0.1825;
    do {
        counter++;
        /*
        printf("x0 - (cos(x0) / -sin(x0)) =\n %.5f - (cos(%.5f) / -sin(%.5f)) =\n %.5f - (%.5f / %.5f) =\n %.5f - %.5f =\n ",
         x0, x0, x0, x0, cos(x0), -sin(x0), x0, cos(x0) / -sin(x0));
        x_new = x0 - (cos(x0) / -sin(x0));

        printf("x0 - (pow(x0, 2) - 1) / 2*x0) =\n %.5f - (pow(%.5f, 2) - 1) / 2*%.5f) =\n %.5f - (%.5f / %.5f) =\n %.5f - %.5f =\n",
         x0, x0, x0,
         x0, pow(x0, 2) - 1, 2*x0,
         x0, (pow(x0, 2) - 1) / (2*x0));
        */

        // compute value
        x_new = x0 - ((pow(x0, 2) - 1) / 2*x0);
        printf("%.5f\n", x_new);
        
        // update variables
        x_old = x0;
        x0 = x_new;

        // qui si controlla se è stata raggiunta la soglia di errore
        // printf("error is abs(%.5f - %.5f) = %.5f\n", x_old, x0, fabs(x_old - x0));
    } while (fabs(x_old - x0) > eps);

    printf("L'algoritmo è andato a convergenza in %i iterazioni\n", counter);
    printf("La radice trovata è %.7f\n", x0);
}