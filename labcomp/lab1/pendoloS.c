#include<stdio.h>
#include<stdlib.h>


//Dichiarazione funzione
void eulero_cromer(float x0, float v0, float Tm, float Dt, float O2);
void eulero(float x0, float v0, float Tm, float Dt, float O2);



// Inizio del programma principale.

int main(int argc, char* argv[]) {

  //Contrllo sul numero degli imput inseriti da riga di comando.
  if(argc!=6){fprintf(stderr, "il numero di argomenti fornito non è valido. Sono necessari 5 argomenti, che vanno forniti nel seguente ordine:\n omega quadro, \n posizione iniziale, \n velocità iniziale,\n  passo d'integrazione, \n tempo totale. \n");
    exit(1);}

  // Conversione delle variabili di interesse.
  float O2=atof(argv[1]);
  float x0=atof(argv[2]);
  float v0=atof(argv[3]);
  float Dt=atof(argv[4]);
  float Tm=atof(argv[5]);

  eulero_cromer(x0,v0,Tm,Dt,O2);
  
}


//Definizione funzione:
void eulero_cromer(float x0, float v0, float Tm, float Dt, float O2){

  int N,i;
  float phi, xn, vn, t, Em, E0, DE;
  
  N= (int) Tm/Dt;
  
  xn=x0;
  vn=v0;
  t=0;
  E0=0.5*vn*vn+0.5*O2*xn*xn;
  printf("# t[s], x[m], v[m/s], DE \n");
  for(i=1;i<=N;i++){
    phi=-O2*xn;
    vn=vn+phi*Dt;
    xn=xn+vn*Dt;
    t=t+Dt;
    Em=0.5*vn*vn+0.5*O2*xn*xn;
    DE=(Em-E0)/E0;
    printf("%f %f %f %f %f \n", t, xn, vn, DE, Em);
  } 
}


void eulero(float x0, float v0, float Tm, float Dt, float O2){

  int N,i;
  float phi, xn, vn, t, Em, E0, DE;
  
  N= (int) Tm/Dt;
  
  xn=x0;
  vn=v0;
  t=0;
  E0=0.5*vn*vn+0.5*O2*xn*xn;
  printf("# t[s], x[m], v[m/s], DE \n");
  for(i=1;i<=N;i++){
    phi=-O2*xn;
    xn=xn+vn*Dt;
    vn=vn+phi*Dt;
    t=t+Dt;
    Em=0.5*vn*vn+0.5*O2*xn*xn;
    DE=(Em-E0)/E0;
    printf("%f %f %f %f %f \n", t, xn, vn, DE, Em);
  }
}


