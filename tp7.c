#include <stdio.h>
#include <stdlib.h>
#include <time.h>


void test (int n1, int n2)
{
   int result;
   
  do {
  printf ("Cuanto es %d*%d?\n" ,n1, n2);
  scanf ("%d" ,&result);
  
  if (result == (n1*n2))
   printf ("Muy bien!\n");
   else {
   printf ("No, intentelo una vez mas\n");
   }
  } 
 while (result != (n1*n2));

} 

void test2 (int n1, int n2)
{

 int result, messages, messages2;
 
  printf ("Programa para reducir la fatiga del estudiante\n");
  
  do{                
  printf ("Cuanto es %d*%d?\n" ,n1, n2);
  scanf ("%d" ,&result);
  
  if (result == (n1*n2))
    messages = 1 + rand() % 4;
   else 
    messages2 = 1 + rand() % 4;

  switch (messages) {
   case 1 : 
             printf ("Muy bien!\n");
             break;
   case 2 : 
             printf ("Excelente!\n");
             break;
   case 3 : 
             printf ("Buen trabajo!\n");
             break;
   case 4 : 
             printf ("Sigue con el buen trabajo!\n");
             break;
   }
            
 switch (messages2) {
   case 1 : 
             printf ("No. Por favor intentelo de nuevo.\n");
             break;
   case 2 : 
             printf ("Incorrecto, intentelo una vez mas.\n");
             break;
   case 3 : 
             printf ("No te rindas!\n");
             break;
   case 4 : 
             printf ("Sigue intentandolo!\n");
             break;
    } 
  }
  while (result != (n1*n2));
}  
void test3 (int n1, int n2) 
{
  int good, result;
  
  printf ("Programa de monitoreo de desempeño estudiantil\n");
  for (int i=0; i<10; i++) {
  
  srand( time ( NULL ) );
  n1 = 1 + rand() % 10;
  n2 = 1 + rand() % 10;  
  
    printf ("Cuanto es %d*%d?\n" ,n1, n2);
    scanf ("%d" ,&result);
  
      if (result == (n1*n2)) {
        printf ("Respuesta correcta\n");
        ++good;
      }  
      else 
        printf ("Respuesta incorrecta\n");
  } 
  
  if (good >= 7)
    printf ("Felicitaciones! esta listo para pasar al siguente nivel\n");
  else 
    printf ("Pidale ayuda edicional a un maestro\n");
}

void test4 (int n1, int n2)
{
   int result;
  printf ("Nivel 2\n");
  do {
  printf ("Cuanto es %d*%d?\n" ,n1, n2);
  scanf ("%d" ,&result);
  
  if (result == (n1*n2))
   printf ("Muy bien!\n");
   else {
   printf ("No, intentelo una vez mas\n");
   }
  } 
 while (result != (n1*n2));

} 

void test4 (int n1, int n2)
{
 int result, cod;
 
   printf ("Programa que varia los tipos de problema\n");
   printf ("Ingrese 1 para problemas de resta\n");
   printf ("Ingrese 2 para problemas de resta\n");
   printf ("Ingrese 3 para problemas de resta\n");
   printf ("Ingrese 4 para problemas de resta\n");    
   scanf ("%d" ,&cod);
   
     
     switch (cod) {
   case 1 : 
             printf ("Cuanto es %d+%d?\n" ,n1, n2);
             scanf ("%d" ,&result);
             break;
   case 2 : 
             printf ("Cuanto es %d-%d?\n" ,n1, n2);
             scanf ("%d" ,&result);
             break;
   case 3 : 
             printf ("Cuanto es %d*%d?\n" ,n1, n2);
             scanf ("%d" ,&result);
    } 
  }
 
 
 
int main (void)
{
  int n1, n2;
  
  srand( time ( NULL ) );
  n1 = 1 + rand() % 10;
  n2 = 1 + rand() % 10;
  
   test (n1, n2);
   
  srand( time ( NULL ) );
  n1 = 1 + rand() % 10;
  n2 = 1 + rand() % 10; 
  
   test2 (n1, n2); 
   test3 (n1, n2);
   
    srand( time ( NULL ) );
  n1 = 1 + rand() % 100;
  n2 = 1 + rand() % 100;
  
  test4 (n1, n2); 
  
   return 0;
}




















