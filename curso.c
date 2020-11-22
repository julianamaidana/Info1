#include <stdio.h>
#include <string.h>

struct estudiante {
  int legajo;
  char nombre[40];
  char apellido[40];
  int nota;
};
int main (void)
{
  struct estudiante estudiantes[3] = {0};
  FILE *fp;

  fp = fopen("curso.txt", "w");
  
  for (int i = 0; i<2; i++){
   printf ("Legajo");
   scanf ("%d", &estudiantes[i].legajo);
   printf ("Ingrese el nombre");
   scanf ("%s", estudiantes[i].nombre);
   printf ("Ingrese el apellido");
   scanf ("%s", estudiantes[i].apellido);
   printf ("nota");
   scanf ("%d", &estudiantes[i].nota);
  fprintf(fp, "%d %s %s %d", estudiantes[i].legajo, estudiantes[i].nombre, estudiantes[i].apellido, estudiantes[i].nota);
  }
  
  fclose(fp);
 
return 0;
}
  
  
  
   
   
   
