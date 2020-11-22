#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int generar(int,int);
int suma(int,int);
int resta(int,int);
int multiplicacion(int,int);
int aleatorio(int,int,int,int);
void respcorrectas(void);
void respincorrectas(void);

//(Variando los tipos de problemas)

int main(void){
	int resultado,respuesta,porcentaje,dificultad,operacion;
	int correctas=0,incorrectas=0;
	srand(time(NULL));
	printf("Ingrese el nivel de dificultad: ");
	do{
	    scanf("%d",&dificultad);
	    if(dificultad<1)
		    printf("Ingrese un valor de dificultad válido: ");
	}while(dificultad<1);
	printf("MENÚ DE OPERACIONES\n");
	printf("1 - Suma\n");
	printf("2 - Resta\n");
	printf("3 - Multiplicación\n");
	printf("4 - Aleatorio\n");
	printf("Ingrese el tipo de problema que desea estudiar: ");
	do{
	    scanf("%d",&operacion);
	    if(operacion<1||operacion>4)
		    printf("Ingrese un valor de operacion válido: ");
	}while(operacion<1||operacion>4);
	do{	
        resultado=generar(dificultad,operacion);
		do{
			scanf("%d",&respuesta);
			if(respuesta!=resultado){
			    respincorrectas();
                incorrectas++;
			}
		}while(correctas+incorrectas<10&&respuesta!=resultado);
		
		if(respuesta==resultado){
		    respcorrectas();
            correctas++;
		}
	}while(correctas+incorrectas<10);
   
    porcentaje=correctas*10;
    if(porcentaje<75)
        printf("\nPídale ayuda adicional a su maestro\n");
    else
        printf("\n¡Felicitaciones, está listo para pasar al siguiente nivel!\n");

	return 0;
}

int generar(int dif,int op){
    int n1,n2,r,ceros=1;
    for(int i=0;i<dif;i++)
        ceros*=10;
	n1=rand()%ceros;
	n2=rand()%ceros;

	switch(op){
	    case 1: r=suma(n1,n2);break;
	    case 2: r=resta(n1,n2);break;
	    case 3: r=multiplicacion(n1,n2);break;
	    case 4: r=aleatorio(n1,n2,rand()%ceros,rand()%ceros);break;
	    default: break;
	}
	return r;
}

int suma(int a,int b){
    int res;
    printf("¿Cuánto es %d + %d?\n",a,b);
    res=a+b;
    return res;
}

int resta(int a,int b){
    int res;
    printf("¿Cuánto es %d - %d?\n",a,b);
    res=a-b;
    return res;
}

int multiplicacion(int a,int b){
    int res;
    printf("¿Cuánto es %d x %d?\n",a,b);
    res=a*b;
    return res;
}

int aleatorio(int a,int b,int c,int d){
    int res=a, n[4]={a,b,c,d};
    printf("¿Cuánto es (((%d",n[0]);
    for(int i=0;i<3;i++){
        switch(rand()%3+1){
            case 1: 
                printf(" + %d)",n[i]);
                res+=n[i];
                break;
            case 2: 
                printf(" - %d)",n[i]);
                res-=n[i];
                break;
            case 3: 
                printf(" * %d)",n[i]);
                res*=n[i];
                break;
            default: break;
        }
    }
    printf("?  ");
    return res;
}

void respcorrectas(void){
    switch(rand()%4+1){
        case 1: printf("¡Muy bien!\n");break;
        case 2: printf("¡Excelente!\n");break;
        case 3: printf("¡Buen trabajo!\n");break;
        case 4: printf("Siga con el buen trabajo!\n");break;
        default: break;
    }
}

void respincorrectas(void){
    switch(rand()%4+1){
        case 1: printf("No. Por favor intente de nuevo.\n");break;
        case 2: printf("Incorrecto. Intentar una vez más.\n");break;
        case 3: printf("No te rindas!\n");break;
        case 4: printf("No. Sigue intentándolo.\n");break;
        default: break;
    }  
}
