#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int pregunta (int a, int b) {
  int r;
  
  printf ("Cuanto es %d*%d?\n", a, b);
  scanf ("%d" ,&r);
  
  return r;
}

int respuesta (int r, int v) {
 if (v == r) {
   printf ("Su respuesta es correcta\n");
   return 1;
  }
   else {
     printf ("Su respuesta es incorrecta, la respues correcta es %d\n" ,v);
     return 0;
 }
}  


int main (void)
{
  int a, b;
  int r;
  
  srand( time ( NULL ) );
  
  int suma = 0;
  
  for (int i = 0; i<10; i++) {
  
   a = 1 + rand() % 10;
   b = 1 + rand() % 10; 
   r = pregunta(a, b);
   suma += respuesta (r, a*b);
 }
 
 if (suma <= 7) 
  printf ("Felicitaciones, esta listo para pasar al siguiente nivel!");

 else 
  printf ("Pidale ayuda adicional a su maestro");
  
  return 0;
  
  }
   
 
  
  
  
  
