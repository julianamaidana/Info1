#include <stdio.h>

 void suma (int n1, int n2){
 
 printf ("El resultado de la operacion es: %d\n" ,n1+n2);
}


 void resta (int n1, int n2){
 
 printf ("El resultado de la operacion es: %d\n" ,n1-n2);
}


 void multi (int n1, int n2){
 
 printf ("El resultado de la operacion es: %d\n" ,n1*n2);
}


 void div (int n1,  int n2){
 
 printf ("El resultado de la operacion es: %d\n" ,n1/n2);
}

int main (void) {

 int n1, n2, cod;
 
 do {
 printf ("Ingrese 1 para sumar 2 numeros\n");
 printf ("Ingrese 2 para restar 2 numeros\n");
 printf ("Ingrese 3 para multiplicar 2 numeros\n");
 printf ("Ingrese 4 para dividir 2 numeros\n");
 printf ("Ingrese 5 para salir del programa 2 numeros\n");
 scanf ("%d", &cod);
 if (cod!=5) {
 printf ("Ingrese 2 numeros\n");
 scanf ("%d%d", &n1, &n2);  
}
 
 switch (cod){
   case 1:
     suma(n1, n2);
     break;
   case 2:
     resta(n1, n2);
     break;
   case 3:
     multi(n1, n2);
     break; 
   case 4:
     div(n1, n2);
 }
}
 while (cod != 5);
 return 0;
 
} 










