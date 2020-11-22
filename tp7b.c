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

  int messages = rand () % 3;

 if (v == r) {
    switch (messages) {
   case 0 : 
             printf ("Muy bien!\n");
             break;
   case 1 : 
             printf ("Excelente!\n");
             break;
   case 2 : 
             printf ("Buen trabajo!\n");
             break;
   case 3 : 
             printf ("Sigue con el buen trabajo!\n");
             break;
   }
  } 
  else      
 switch (messages) {
   case 0 : 
             printf ("No. Por favor intentelo de nuevo.\n");
             break;
   case 1 : 
             printf ("Incorrecto, intentelo una vez mas.\n");
             break;
   case 2 : 
             printf ("No te rindas!\n");
             break;
   case 3 : 
             printf ("Sigue intentandolo!\n");
             break;
    } 
  }

int main (void)
{
  int a, b;
  int r;
  
  srand( time ( NULL ) );
  
  a = 1 + rand() % 10;
  b = 1 + rand() % 10;  
  v = a*b;
  
  do {
  r = pregunta(a, b);
  respuesta (r, a*b);
  }
  while ( r != (a*b));
  
  return 0;
}
  
