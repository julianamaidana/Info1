#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define TAMANIO 13
int main (void) 
{

  int cara, cara1, suma; 
  int tiro; // contador de tiros 1 a 6000 
  int frecuencia[ TAMANIO ] = { 0 }; 
  float por;

  srand( time ( NULL ) ); // generador de la semilla de números aleatorios
  // tira el dado 3600 veces
  for ( tiro = 1; tiro <= 3600; tiro++ ) {
    cara = 1 + rand() % 6;
    cara1 = 1 + rand() % 6;
    suma = cara+cara1;
    ++frecuencia[ suma ];


  } //fin de for
   // muestra los elementos
   for ( cara = 2; cara < TAMANIO; cara++ ) {
     printf( "La suma de los 2 dado dio %d, salio %d veces,", cara,  frecuencia[ cara ] );
     por = (float) (frecuencia[ cara ]*100)/3600;
     printf (" con un porcentaje de %3.f%% \n" ,por);
     printf ("\n");
  } 



  return 0;
 }
