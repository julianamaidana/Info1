#include <stdio.h>
#include <stdlib.h>
#include <string.h>


typedef struct{
    int registro;
    char nombre[80];
    int cantidad;
    float costo;
}herramienta;

FILE *crearArchivo(char *);
void mostrar(FILE *);
void borrar(FILE *, int);
void crearRegistro(FILE *, int);

int main(void){
    FILE *fp = fopen("hardware.dat", "rb+");
    if(fp == NULL){
        printf("El archivo \"hardware.dat\" no existe por lo que sera creado\n");
        fp = crearArchivo("hardware.dat");
    }

	int opcion, salir = 0, registro;
	do{
		do{   printf("\nMenu\n");
    printf("Ingrese 1 si desea ver los Registros\n");
    printf("Ingrese 2 si desea Modificar/Crear un Registro\n");
    printf("Ingrese 3 si desea Borrar un Registro\n");
    printf("Ingrese 4 si desea Sobreescribir el Archivo\n");
    printf("Ingrese 5 para salir del programa\n");
    printf("Opcion: ");
    scanf("%d", &opcion);
   }while(opcion > 5 || opcion < 1);
	
     switch(opcion){
            case 1:
                mostrar(fp);
                break;
            case 2:
		    do{
		      printf("Ingrese el numero de registro del archivo que desea crear/modificar: ");
		    scanf("%d", &registro);
		    }while(registro > 100 || registro < 1);
                crearRegistro(fp, registro);
                break;
            case 3:
				do{
					printf("Ingrese el numero de registro del archivo que desea borrar: ");
					scanf("%d", &registro);
				}while(registro > 100 || registro < 1);
                borrar(fp, registro);
                break;
            case 4:
                printf("Estas seguro que desea proceder con la operacion? perdera los datos. S/n: ");
                char confirm;
                scanf(" %c", &confirm);
                if (confirm == 'S'){
                    puts("Sobreescribiendo archivo\n");
					crearArchivo("hardware.dat");
                }
                else
                    printf("Usted cancelo la operacion\n");
                break;
            case 5:
                salir = 1;
                break;
        }
    }while(!salir);
    fclose(fp);
    return 0;
}

FILE *crearArchivo(char *archivo){
    herramienta tabla[100];
    for (int i = 0; i < 100; i++)
        tabla[i] = (herramienta) {i+1, "\0", 0, 0};
    FILE *fp = fopen(archivo, "wb");
    fwrite(tabla, sizeof(herramienta), 100, fp);
    return fopen(archivo, "rb+");
}

void mostrar(FILE *fp){
	
    int count = 0;
    herramienta temp;
    fseek(fp, 0, SEEK_SET);
    for (int i = 0; i < 100; i++){
        fread(&temp, sizeof(herramienta), 1, fp);
        if(temp.cantidad != 0){
            count++;
            printf("\n%d\t%20s\t%d\t%.2f\n", temp.registro, temp.nombre, temp.cantidad, temp.costo);
        }
    }
    if(count == 0)
        printf("\nNo hay registros ingresados\n");
}

void borrar(FILE *fp, int registro){
    herramienta tempvar = (herramienta){registro, {(char)0}, 0, 0};
    fseek(fp, sizeof(herramienta)*(registro-1), SEEK_SET);
    fwrite(&tempvar, sizeof tempvar, 1, fp);
}

	
	
void crearRegistro(FILE *file, int reg){
    herramienta tmp;
    int cantidad;
    float costo;
    char nombre[80];

    fseek(file, sizeof(herramienta)*(reg-1), SEEK_SET);
    fread(&tmp, sizeof tmp, 1, file);

    printf("\nUsted a seleccionado la opcion de creacion/modificacion de registros\n");
    printf("Si desea mantener alguno de los datos, ingrese 0.\n");
    printf("De lo contrario, será modificado.\n");

    printf("\nIngrese el nombre de la Herramienta: ");
    scanf(" %[^\n]s", nombre);
    if (nombre[0] != '0')
        strcpy(tmp.nombre, nombre);

    printf("Ingrese la cantidad de esa herramienta: ");
    scanf("%d", &(cantidad));
    if (cantidad != 0)
        tmp.cantidad = cantidad;

    printf("Ingrese el costo unitario de la herramienta: ");
    scanf("%f", &(costo));
    if (!(costo > - 0.0005 && costo < 0.0005))
        tmp.costo = costo;

    fseek(file,sizeof(herramienta)*(reg-1), SEEK_SET);
    fwrite(&tmp, sizeof(herramienta), 1, file);
}
