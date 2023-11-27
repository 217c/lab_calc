# include <stdio.h>
# include <stdlib.h>
# include <time.h>
#include <math.h>
void product(double A[ ][ 3 ], double v[], double w[]);
void genvec(double v[]);
void printvec(double v[]);
double modulus(double v[]);

int main() {
    // dichiarazione degli array 
    double v[3]={0.0}, w[3]={0.0};
    double A[3][3]={0.0}, phi = 0.0, angle = 0.0, lw = 0.0;
    int r, c;
    int i, Ngrande=1000;
    FILE *fpw;

    srand(time(NULL));

    printf(" inserisci phi\n"); 
    scanf ("%lf", &angle);
    
    phi = angle * M_PI;

    printf("phi = %6.4f \n", phi);

    //	definisce	la	matrice A
    A[0][0]= cos ( phi ) ;
    A[0][1]= - sin ( phi ) ;
    A[0][2]=0.0;
    A[1][0]= sin ( phi ) ;
    A[1][1]= cos ( phi ) ;
    A[1][2]=0.0;
    A[2][0]=0.0;
    A[2][1]=0.0;
    A[2][2]=1.0;

    printf ("Matrice A:\n");
    
    for	( r=0;r <3;r++) {
         printvec (A[ r ]) ;
    }
    
    
    // apre i l f i l e " coordinate . dat" in modalita ’ lettura 
    fpw=fopen ("coordinate_prof.dat", "w");

    // genera casualmente	le	componenti di v tramite	la	funzione genvec
    for	(i = 0; i<Ngrande; i++) { 
    genvec (v) ;
    // chiamata	alla	funzione product 
    product (A,v ,w);
    // scrive su f i l e le componenti di v e w 
    fprintf (fpw , "%6.4f %6.4f %6.4f %6.4f %6.4f %6.4f \n" ,v [0] , v [1] , v [2] ,w[0] ,w[1] ,w[2]) ;
    // calcola	i l	modulo del	vettore w 
    lw=modulus(w) ;
        //	printf ("w= (%6.4f , %6.4f , %6.4 f ) , lw=%6.4f \n" ,w[0] ,w[1] ,w[2] , lw) ;
    // e lo stampa su schermo se non e ’ uguale a 1.0
    if((lw -1.0) >=0.0000001) printf ("lw = %6.4f \n" ,lw) ;
    }
    // dopo aver stampato tutte le righe chiude i l f i l e coordinate . dat 
    fclose(fpw) ;
    }

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

void genvec (double v[]) {
    int i;
    double mod=0.0;
    
    for ( i =0;i <3; i++){
        v [ i ]= -1.0+2.0*( double ) (rand () )/RAND_MAX;
        mod=mod+v [ i ]*v [ i ] ;
        }
    mod=sqrt (mod);
    for ( i =0;i <3; i++) {
        v [ i ]=v [ i ]/mod;
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

double modulus( double v [ ] )
{
	int	i ;
	double	l =0;
	for	( i =0;i <3; i++)
{ l=l+v [ i ]*v [ i ] ;
}	
l= sqrt(l) ; 
return	l ;
}