// La simulazione si rompe quando un pianeta passa per 0, evidentemente ci sono problemi con la divisione
// i pianeti sembrano respinti più che attratti dalla stella

#include<stdio.h>
#include<stdlib.h>
#include<math.h>

typedef struct {
  double *t;        // puntatore per il vettore dei tempi
  double *r_a_x;    // Puntatore per il vettore di posizioni x
  double *r_a_y;    // Puntatore per il vettore di posizioni y
  double *r_b_x;    // Puntatore per il vettore di posizioni x
  double *r_b_y;    // Puntatore per il vettore di posizioni y
  double *v_a_x;        // Puntatore per il vettore di velocità x
  double *v_a_y;        // Puntatore per il vettore di velocità y
  double *v_b_x;        // Puntatore per il vettore di velocità x
  double *v_b_y;        // Puntatore per il vettore di velocità y
  double *phi_a_x;        // Puntatore per il vettore di accelerazione x
  double *phi_a_y;        // Puntatore per il vettore di acc y
  double *phi_b_x;        // Puntatore per il vettore di acc x
  double *phi_b_y;        // Puntatore per il vettore di acc y
  double *r_ab;        // Puntatore per il vettore di distanze
  // double *DE;       // Puntatore per il vettore dell'errore relativo
  int n;            // Numero di punti (lunghezza dei vettori) [scalare]
} spaziofasi;


//Dichiarazione funzione
void eulero_cromer(spaziofasi *dati, 
                        float r_a_x,
                        float r_a_y, 
                        float v_a_x, 
                        float v_a_y, 
                        float r_b_x, 
                        float r_b_y,
                        float v_b_x,
                        float v_b_y, 
                        float Tm,
                        float Dt, 
                        float GAMMA, 
                        float Ma,
                        float Mb);
// void eulero(spaziofasi *dati, float theta0, float v0, float Tm, float Dt, float O2, float verbose);
// void midpoint(spaziofasi *dati, float theta0, float v0, float Tm, float Dt, float O2);
// void verlet(spaziofasi *dati, float theta0, float v0, float Tm, float Dt, float O2);
// void analitica(spaziofasi *dati, float theta0, float v0, float Tm, float Dt, float O2);
void print_dati(spaziofasi *dati);



// Inizio del programma principale.

int main(int argc, char* argv[]) {

  //Contrllo sul numero degli imput inseriti da riga di comando.
  if(argc!=15){fprintf(stderr, "il numero di argomenti fornito non è valido. Sono necessari 14 argomenti, che vanno forniti nel seguente ordine:\n GAMMA, \n Ma, \n Mb, \n r_a_x_0, \n r_a_y_0, \n r_b_x_0, \n r_b_y_0, \n v_a_x_0, \n v_a_y_0, \n v_b_x_0, \n v_b_y_0, \n passo d'integrazione, \n tempo totale,\n algoritmo scelto [e=1, ec=2, mp=3, v=4, a=5]. \n");
    exit(1);}

  // Conversione delle variabili di interesse.
  float GAMMA     = atof(argv[1]);
  float Ma    = atof(argv[2]);
  float Mb    = atof(argv[3]);
  float r_a_x_0    = atof(argv[4]);
  float r_a_y_0    = atof(argv[5]);
  float r_b_x_0    = atof(argv[6]);
  float r_b_y_0    = atof(argv[7]);
  float v_a_x_0    = atof(argv[8]);
  float v_a_y_0    = atof(argv[9]);
  float v_b_x_0    = atof(argv[10]);
  float v_b_y_0    = atof(argv[11]);
  // float v0        = atof(argv[3]);
  float Dt        = atof(argv[12]);
  float Tm        = atof(argv[13]);
  float algoritmo = atof(argv[14]);

  // numero di punti nello spazio delle fasi
  int n;
  n = (int) Tm/Dt;

  // Dichiarazione della variabile 'dati' di tipo 'spaziofasi'
  spaziofasi dati;
  dati.n = n;
  
  // Allocazione dinamica dei vettori usando malloc
  dati.t = (double *)malloc(dati.n * sizeof(double));
  dati.r_a_x = (double *)malloc(dati.n * sizeof(double));
  dati.r_a_y = (double *)malloc(dati.n * sizeof(double));
  dati.r_b_x = (double *)malloc(dati.n * sizeof(double));
  dati.r_b_y = (double *)malloc(dati.n * sizeof(double));
  dati.v_a_x = (double *)malloc(dati.n * sizeof(double));
  dati.v_a_y = (double *)malloc(dati.n * sizeof(double));
  dati.v_b_x = (double *)malloc(dati.n * sizeof(double));
  dati.v_b_y = (double *)malloc(dati.n * sizeof(double));
  dati.phi_a_x = (double *)malloc(dati.n * sizeof(double));
  dati.phi_a_y = (double *)malloc(dati.n * sizeof(double));
  dati.phi_b_x = (double *)malloc(dati.n * sizeof(double));
  dati.phi_b_y = (double *)malloc(dati.n * sizeof(double));
  dati.r_ab = (double *)malloc(dati.n * sizeof(double));
  // dati.DE = (double *)malloc(dati.n * sizeof(double));

  // Verifica se l'allocazione è riuscita
  // if (dati.t == NULL || dati.theta == NULL || dati.v == NULL) {
  //   printf("Errore nell'allocazione della memoria.\n");
  //   return 1;  // Termina il programma in caso di errore di allocazione
  // } else {
  //   printf("Allocazione di memoria ben riuscita:\nCi saranno %i punti nello spazio delle fasi\n", dati.n);
  // }
  
  if (algoritmo == 1)  {
    // eulero(&dati, theta0, v0, Tm, Dt, O2, 0);
  } else if (algoritmo == 2) {
    eulero_cromer(&dati, r_a_x_0,
                         r_a_y_0, 
                         v_a_x_0, 
                         v_a_y_0, 
                         r_b_x_0, 
                         r_b_y_0,
                         v_b_x_0,
                         v_b_y_0, 
                         Tm,
                         Dt, 
                         GAMMA, 
                         Ma,
                         Mb);
  } else if (algoritmo == 3) {
    // midpoint(&dati, theta0, v0, Tm, Dt, O2);
  } else if (algoritmo == 4)  {
    // verlet(&dati, theta0, v0, Tm, Dt, O2);
  } else if (algoritmo == 5)  {
    // analitica(&dati, theta0, v0, Tm, Dt, O2);
  } else {
    printf("Hai selezionato la funzione sbagliata.");
  }

  print_dati(&dati);
  
  // Liberazione della memoria allocata dinamicamente
  free(dati.t);
  free(dati.r_a_x);
  free(dati.r_a_y);
  free(dati.r_b_x);
  free(dati.r_b_y);
  free(dati.v_a_x);
  free(dati.v_a_y);
  free(dati.v_b_x);
  free(dati.v_b_y);
  free(dati.phi_a_x);
  free(dati.phi_a_y);
  free(dati.phi_b_x);
  free(dati.phi_b_y);
  free(dati.r_ab);
  
}

// %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
//Definizione funzione:
void eulero_cromer(spaziofasi *dati, 
                        float r_a_x_0,
                        float r_a_y_0, 
                        float v_a_x_0, 
                        float v_a_y_0, 
                        float r_b_x_0, 
                        float r_b_y_0,
                        float v_b_x_0,
                        float v_b_y_0, 
                        float Tm,
                        float Dt, 
                        float GAMMA, 
                        float Ma,
                        float Mb){

  int N,i;
  float phi_a_x, phi_a_y, phi_b_x, phi_b_y, r_a_x_n, r_a_y_n, r_b_x_n, r_b_y_n, v_a_x_n, v_a_y_n, v_b_x_n, v_b_y_n, r_ab, t, Em, E0, DE;
  
  N = (int) Tm/Dt;
  printf("# viene usato l'algoritmo di Eulero-Cromer\n");

  // posizione iniziale
  r_a_x_n = r_a_x_0;
  r_a_y_n = r_a_y_0;
  r_b_x_n = r_b_x_0;
  r_b_y_n = r_b_y_0;
  v_a_x_n = v_a_x_0;
  v_a_y_n = v_a_y_0;
  v_b_x_n = v_b_x_0;
  v_b_y_n = v_b_y_0;
  t=0;
  // E0=0.5*vn*vn+0.5*O2*thetan*thetan;
  //printf("# t[s], theta[rad], v[rad/s], a[rad/s^2],  DE \n");
  
  for(i=0;i<N;i++){
    r_ab = sqrt(pow((r_a_x_n - r_b_x_n),2) + pow((r_a_y_n - r_b_y_n),2)); // distanza fra due punti sul piano

    // accelerazioni
    phi_a_x = GAMMA*( r_a_x_n/pow(r_a_x_n,3) + Mb*(r_ab/pow(r_ab,3)) );
    phi_a_y = GAMMA*( r_a_y_n/pow(r_a_y_n,3) + Mb*(r_ab/pow(r_ab,3)) );
    phi_b_x = GAMMA*( r_b_x_n/pow(r_b_x_n,3) + Ma*(r_ab/pow(r_ab,3)) );
    phi_b_y = GAMMA*( r_b_y_n/pow(r_b_y_n,3) + Ma*(r_ab/pow(r_ab,3)) );

    // velocità
    v_a_x_n = v_a_x_n + phi_a_x*Dt;
    v_a_y_n = v_a_y_n + phi_a_y*Dt;
    v_b_x_n = v_b_x_n + phi_b_x*Dt;
    v_b_y_n = v_b_y_n + phi_b_y*Dt;

    // posizione
    r_a_x_n = r_a_x_n + v_a_x_n*Dt;
    r_a_y_n = r_a_y_n + v_a_y_n*Dt;
    r_b_x_n = r_b_x_n + v_b_x_n*Dt;
    r_b_y_n = r_b_y_n + v_b_y_n*Dt;

    // next step
    t = t+Dt;
    // Em     = 0.5*vn*vn+0.5*O2*thetan*thetan;
    // DE     = (Em-E0)/E0;

    //printf("%f %f %f %f %f \n", t, thetan, vn, phi, DE);
    //printf("inserisco in struttura t\n");
    dati->t[i] = t;

    dati->r_a_x[i] = r_a_x_n;
    dati->r_a_y[i] = r_a_y_n;
    dati->r_b_x[i] = r_b_x_n;
    dati->r_b_y[i] = r_b_y_n;
    dati->v_a_x[i] = v_a_x_n;
    dati->v_a_y[i] = v_a_y_n;
    dati->v_b_x[i] = v_b_x_n;
    dati->v_b_y[i] = v_b_y_n;
    dati->phi_a_x[i] = phi_a_x;
    dati->phi_a_y[i] = phi_a_y;
    dati->phi_b_x[i] = phi_b_x;
    dati->phi_b_y[i] = phi_b_y;
    dati->r_ab[i] = r_ab;


    // dati->DE[i] = DE;
  } 
}

// %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
/* 
void eulero(spaziofasi *dati, float theta0, float v0, float Tm, float Dt, float O2, float verbose){

  int N,i;
  float phi, thetan, vn, t, Em, E0, DE;
  
  N= (int) Tm/Dt;

  printf("# viene usato l'algoritmo di Eulero\n");
  
  thetan=theta0;
  vn=v0;
  t=0;
  E0=0.5*vn*vn+0.5*O2*thetan*thetan;
  printf("# t[s], x[m], v[m/s], DE \n");
  for(i=0;i<N;i++){
    phi    = -O2*sin(thetan);
    thetan = thetan+vn*Dt;
    vn     = vn+phi*Dt;
    t      = t+Dt;
    Em     = 0.5*vn*vn+0.5*O2*thetan*thetan;
    DE     = (Em-E0)/E0;
    
    if (verbose==1) {
      printf("%f %f %f %f %f \n", t, thetan, vn, DE, Em);
    }
    
    dati->t[i] = t;
    dati->theta[i] = thetan;
    dati->v[i] = vn;
    dati->DE[i] = DE;
  }
}

// %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
void midpoint(spaziofasi *dati, float theta0, float v0, float Tm, float Dt, float O2){

  int N,i;
  float phi, thetan, vn, v12, t, Em, E0, DE;
  
  N = (int) Tm/Dt;

  printf("# viene usato l'algoritmo Midpoint\n");
  
  thetan=theta0;
  t=0;
  

  phi=-O2*sin(thetan);
  
  // il primo passo viene specificato impiegando Eulero
  v12 = v0 + 0.5*phi*Dt;

  E0=0.5*v12*v12+0.5*O2*thetan*thetan;
  printf("# t[s], x[m], v[m/s], DE \n");
  
  for(i=0;i<N;i++){
    v12    = v12+phi*Dt;
    thetan = thetan+v12*Dt;
    phi    = -O2*sin(thetan); 
    t      = t+Dt;
    Em     = 0.5*v12*v12+0.5*O2*thetan*thetan;
    DE     = (Em-E0)/E0;
    
    //printf("%f %f %f %f %f \n", t, thetan, v12, DE, Em);
    dati->t[i]     = t;
    dati->theta[i] = thetan;
    dati->v[i]     = vn;
    dati->DE[i]    = DE;
  }
}

//%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%

void verlet(spaziofasi *dati, float theta0, float v0, float Tm, float Dt, float O2){

  int N,i;
  float phi, thetan, vn, t, Em, E0, DE, phi_next;
  
  N = (int) Tm/Dt;
  printf("# viene usato l'algoritmo di Verlet\n");
  thetan=theta0;
  vn=v0;
  t=0;
  E0=0.5*vn*vn+0.5*O2*thetan*thetan;
  printf("# t[s], theta[rad], v[rad/s], a[rad/s^2],  DE \n");
  for(i=0;i<N;i++){
    phi      = -O2*sin(thetan);
    thetan   = thetan+vn*Dt+0.5*phi*Dt*Dt;
    phi_next = -O2*sin(thetan);
    vn       = vn+0.5*(phi_next+phi)*Dt;
    t        = t+Dt;
    Em       = 0.5*vn*vn+0.5*O2*thetan*thetan;
    DE       = (Em-E0)/E0;
    //printf("%f %f %f %f %f \n", t, thetan, vn, phi, DE);
    
    dati->t[i]     = t;
    dati->theta[i] = thetan;
    dati->v[i]     = vn;
    dati->DE[i]    = DE;
  } 
}

//%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%

void analitica(spaziofasi *dati, float theta0, float v0, float Tm, float Dt, float O2){

  int N,i;
  float phi, fase, A, thetan, vn, t, Em, E0, DE, phi_next, O;

  fase=atan(-v0/theta0);
  A=theta0/cos(fase);
  O=pow(O2,0.5); //Radice di omega quadro
  
  N = (int) Tm/Dt;
  printf("# viene usata la soluzione analitica\n");
  
  thetan=theta0;
  vn=v0;
  t=0;
  E0=0.5*vn*vn+0.5*O2*thetan*thetan;
  printf("# t[s], theta[rad], v[rad/s], a[rad/s^2],  DE \n");
  
  for(i=0;i<N;i++){
    
    thetan = A*cos(O*t+fase);
    vn     = -A*O*sin(O*t+fase);
    phi    = -A*O2*cos(O*t+fase);
    t      = t+Dt;
    Em     = 0.5*vn*vn+0.5*O2*thetan*thetan;
    DE     = (Em-E0)/E0;

    //printf("%f %f %f %f %f \n", t, thetan, vn, phi, DE);
  } 
}
*/

//%%%%%%%%%%%%%%%
void print_dati(spaziofasi *dati) {
  for (int i = 0; i < dati->n; i++) {
    printf("%f %f %f %f %f %f %f %f %f %f %f %f %f %f \n", dati->t[i],
                                                        dati->r_a_x[i], 
                                                        dati->r_a_y[i],
                                                        dati->r_b_x[i],
                                                        dati->r_b_y[i],
                                                        dati->v_a_x[i], 
                                                        dati->v_a_y[i],
                                                        dati->v_b_x[i],
                                                        dati->v_b_y[i],
                                                        dati->phi_a_x[i], 
                                                        dati->phi_a_y[i],
                                                        dati->phi_b_x[i],
                                                        dati->phi_b_y[i],
                                                        dati->r_ab[i]);
  }
}
