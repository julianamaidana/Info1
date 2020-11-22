#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>


int pregunta (int a, int b) {
  int r;
  printf ("Cuanto es %d*%d?\n", a, b);
  scanf ("%d" ,&r);
  
  return r;
}

void respuesta (int r, int v) {
 if (v == r)
   printf ("Su respuesta es correcta\n");
 else 
   printf ("Su respuesta es incorrecta, intentelo de nuevo\n");
  
}

int pregunta1 (void) {
 int n;
printf ("En que nivel desea ingresar\n");
scanf ("%d", &n);
 return n;
}       
   
int main (void)
{
  int a, b;
  int r, n, f;
  
  
  printf ("Bienvenido\n");
  srand( time ( NULL ) );
  
  n = pregunta1();
  f = pow (10, n);
 
  a = 1 + rand() % (f);  
  b = 1 + rand() % (f);  

  
  do {
  r = pregunta(a, b);
  respuesta (r, a*b);
  }
  while ( r != a*b);
  
  
  
  return 0;
  
  }
   
 
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  

