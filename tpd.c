#include <stdio.h>
#include <stdlib.h>
#include <time.h>

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


int main (void)
{
  int a, b;
  int r;
  
  printf ("Insutruccion asistida por computadora\n");
  srand( time ( NULL ) );
  
  a = 1 + rand() % 10;
  b = 1 + rand() % 10;  

  
  do {
  r = pregunta(a, b);
  respuesta (r, a*b);
  }
  while ( r != a*b);
  
  
  
  return 0;
  
  }
   
 
  
