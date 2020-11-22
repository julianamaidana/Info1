//TP8: Sondeo
#include <stdio.h>

void cuestionario(int respuesta[][10], char *tema, int i, int j){
  printf ("Responda las siguientes 5 preguntas el participante N°%d\n", j+1);
  	do{
		printf("\nCual es la importancia para Ud. acerca de: %s\n", tema);
		printf("Su respuesta:\n ");
		scanf("%d", &respuesta[i][j]);
		if(respuesta[i][j] < 1 || respuesta[i][j] > 10)
		 printf ("El puntaje debe estar entre 1 y 10");
	} while(respuesta[i][j] < 1 || respuesta[i][j] > 10);
 
 }
void informe(int respuesta[][10], char *causas[5], int n){

	int mayor = -1, menor = -1;
	int PMayor = 0, PMenor = 0;

	printf("\n%-30s\t", "Puntaje");
	for (int i = 1; i <= 10; i++)
		printf("%5d ", i);
	printf("%10s\n\n", "Promedio");

	for (int i = 0; i < 5; i++){
	  int total = 0;
		printf("%-30s\t", causas[i]);
		for (int j = 0; j < n; j++){
			printf("%5d ", respuesta[i][j]);

			total += respuesta[i][j];	
		}
		printf("%7.2f", total != 0 ? (float) total/n : 0);

		if (total > PMayor || mayor == -1){
			mayor = i;
			PMayor = total;
		}

		if (total < PMenor || menor == -1){
			menor = i;
			PMenor = total;
		}
		printf("\n");
	}
	printf("\nMayor puntaje: %s con %d puntos\n", causas[mayor], PMayor);
	printf("Menor puntaje: %s con %d puntos\n\n", causas[menor], PMenor);
}

int main(void){
 int n;
 char *temas[5] = {"Ley de cupo Femenino", "racismo", "Calentamiento Global", "Legalizacion del aborto", "Educacion"};
	
int respuestas[5][10] = {{0}};


 printf("Este cuestionario trata sobre problematicas globales\n");
 printf("Responda en una escala del 1 al 10\n");
 printf("que tan importantes les parecen estas problematicas\n");
 printf ("Esta encuesta es para un maximo de 10 participantes\n");
 printf ("\nIngrese la cantidad de partipantes:\n");
 scanf ("%d", &n);



for (int j = 0; j < n; j++) {
 for (int i = 0; i<5; i++){
 cuestionario(respuestas, temas[i], i, j);
 }
}
informe(respuestas, temas, n);


return 0;
}  
   
   
   
   
   
   
   
   
   
   
