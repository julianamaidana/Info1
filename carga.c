#include <stdio.h>
#define N 100
#define M 100
int main (void)
{
  int j, i, k, m, n, cont = 0;
  float b, d, e = 0.009;
  float A [N][M];
  
  do {
  printf ("Ingrese la cantidad de ecucaciones de su sistema\n");
  scanf ("%d", &n);
  if (n<=0 || n>100)
    printf ("Cantidad que excede los limites del programa, pruebe de      		     nuevo\n");
  else 
    cont = 1;
  }while (cont==0);
  cont = 0;
  
  do {
  printf ("Ingrese la cantidad de variables que tiene su sistema\n");
   scanf ("%d", &m);
  if (m<=0 || m>100)
    printf ("Cantidad que excede los limites del programa, pruebe de      		     nuevo\n");
  else 
    cont = 1;
  }while (cont==0);
  cont = 0;
  
   for (i = 0; i<n; i++) {
    for (j = 0; j<m; j++){
     printf("Ingrese el elemento(%d;%d): ",i,j);
     scanf("%f",&A[i][j]);
     }
     printf("Ingrese el termino independiente: ");
     scanf ("%f", &A[i][j]);
   }
   
  printf("Su sistema de ecuaciones ordenado es:\n");
      for(i=0;i<n;i++){
      	for(j=0;j<m;j++){
        	printf("%.2f  ",A[i][j]);
        }
        printf("| %.2f",A[i][j]);
        printf("\n");
      } 
    printf("\n");  
 //gauss jordan 
 for (k=0; k<n; k++) {
  for (i=0; i<m; i++){
   if (k!=i) {
    b = -(A[i][k]/A[k][k]);
    for (j=0; j<m; j++) {
      A[i][j] += b*(A[k][j]);
   }
  }   
 } 
} 
   
 for (i=0; i<n; i++) {
  d = A[i][i];
  for (j=0; j<m; j++){
    A[i][j] /= d;
  }
 } 
  
  
   for (i = 0; i<n; i++) {
    for (j = 0; j<m; j++){
    if (A[i][j]>-e && A[i][j]<e)
     printf ("%.2f\t", 0.00);
    else 
     printf("%.2f\t", A[i][j]);
  }
  printf ("\n");
 }
 return 0;
 }
        
   

   
   
