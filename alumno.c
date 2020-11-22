#include <stdio.h>
#include <stdlib.h>

#define N 100

struct estudiante {
 unsigned int legajo;
 char nombre[80];
};

 void carga (struct estudiante est[], int n) {
   for (int i = 0; i<n; i++) {
     printf("estudiante %d\n", i+1);
     printf ("Ingrese el legajo: ");
     scanf (" %u", &est[i].legajo);
     printf ("Ingrese el nombre: ");
     scanf (" %s", est[i].nombre);
 }
}
  
 void imprimir (struct estudiante *p, int n){
 
  for (int i = 0; i<n; i++) {
   printf ("estudiante %d\n", i+1);
   printf ("Legajo %u\n", p[i].legajo);
   printf ("Nombre %s\n", p[i].nombre);
  }
 } 

void ordenar (struct estudiante est[], int n){
 struct estudiante temp[n];
  for(int j=0;j<n-1;j++){
   for(int i=0;j<n-1-i;i++){
     if(est[i+1].legajo<est[i].legajo){
	temp[i]=est[i];
	est[i]=est[i+1];
        est[i+1]=temp[i];				
   }
  }
 }
}
int main(void)
{
 struct estudiante *p;
 int n;
 
 do{
  printf("Cuantos estudiantes se cargarán: ");
  scanf("%d", &n);
    if (n<0||n>N)
      printf("Cantidad de alumnos no válida\n");
	} while(n<0||n>N);

p = malloc (n*sizeof (*p));
	
 carga (p, n);
 ordenar (p, n);
 imprimir (p, n);
 
 return 0;
}


 
 
 
 
 
 
 
 
 
 
