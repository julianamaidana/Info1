#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int pregunta (int a, int b, char x) {
  int r;
  printf ("Cuanto es %d%c%d?\n", a, x, b);
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
  int a, b, r, v, i;
  int x;
  int sig;
  
  printf ("Insutruccion asistida por computadora\n");
  printf ("Ingrese 1 para realizar operaciones aleatorias\n");
  printf ("Ingrese 2 para realizar operaciones de suma\n");
  printf ("Ingrese 3 para realizar operaciones de resta\n");
  printf ("Ingrese 4 para realizar operaciones de multiplicacion\n");
  scanf ("%d", &x);
  
  srand( time ( NULL ) );

  a = 1 + rand() % 10;
  b = 1 + rand() % 10; 

 if (x != 1){  
  switch (x){
   case 2: v = a+b;
         break;
   case 3: v = a-b;
          break;
   case 4: v = a*b;  
     
 }
   r = pregunta (a, b, x);
   respuesta (r, v);
}

 else {
 
 printf ("Cuanto es: ");
 printf("%d", a);
 v = a;
 
 for (i = 0; i<4; i++) {
  sig = rand() % 3;
  a = 1 + rand() % 10;
  
 switch (sig){ 
  case 0:
    printf ("+%d)", a);
    v += a;
    break;
 case 1:
    printf ("-%d)", a);
    v -= a;
    break;
 case 2:
    printf ("*%d)", a);
    v *= a;
    break;
 case 4:
    printf ("/%d)", a);
    v /= a;
    break;   
 }
}       
 printf (" ? ");    
 scanf ("%d", &r);  
 respuesta (r, v);
}

return 0;
}
 
