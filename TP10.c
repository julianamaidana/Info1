#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct{
    int record;
    char nombre[80];
    int cantidad;
    float costo;
}herramienta;

FILE *init(char *);
void imprimir(FILE *);
void borrar(FILE *, int);
void crear(FILE *, int);
int float_int_compare(float, int);

int main(void){
    FILE *fp = fopen("hardware.dat", "rb+");
    if(fp == NULL){
        puts("El archivo \"hardware.dat\" no existe. Creando...");
        fp = init("hardware.dat");
    }
    int salir = 0;
    int resp = 0;
    char conf;
    
    printf("\nMenu\n");
    printf("Ingrese 1 si desea ver los Registros");
    printf("Ingrese 2 si desea Modificar/Crear un Registro");
    printf("Ingrese 3 si desea Borrar un Registro");
    printf("Ingrese 4 si desea Sobreescribir el Archivo");
    printf("Ingrese 5 para salir del programa");
    scanf ("%d", &resp);
    do{
        switch(resp){
            case 1:
                imprimir(fp);
                break;
            case 2:
                printf("Ingrese el numero de registro del archivo que quiere crear/modificar: ");
                scanf ("%d", &resp);
                crear(fp, resp);
                break;
            case 3:
                printf("Ingrese el numero de registro a borrar\n");
                scanf ("%d", &resp);
                borrar(fp, resp);
                printf("Esta seguro que desea proceder con la operacion?   Los datos se perderan s/n: ");
                
                scanf(" %c", &conf);
                if (conf == 's'){
                    init("hardware.dat");
                }
                else
                    printf("Usted cancelo la operacion");

                break;
            case 5:
                salir = 1;
                break;
        }
    }while(!salir);
    fclose(fp);
    return 0;
    
}

FILE *init(char *archivo){
    herramienta *inicial = calloc(100, sizeof(herramienta));
    for (int i = 0; i < 100; i++)
        *(inicial + i) = (herramienta) {i+1, "\0", 0, 0};
    FILE *file = fopen(archivo, "wb");
    fwrite(inicial, sizeof(herramienta), 100, file);
    free(inicial);
    return fopen(archivo, "rb+");
}


void imprimir(FILE *file){
    int count = 0;
    herramienta tmp;
    fseek(file, 0, SEEK_SET);
    for (int i = 0; i < 100; i++){
        fread(&tmp, sizeof(herramienta), 1, file);
        if(tmp.cantidad != 0){
            count++;
            printf("\n%d\t%20s\t%d\t%.2f\n", tmp.record, tmp.nombre, tmp.cantidad, tmp.costo);
        }
    }
    if(count == 0)
        puts("\nNo hay registros aun");
}

void crear (FILE *file, int reg){
    herramienta tmp;
    int cantidad;
    float costo;
    char nombre[80];

    fseek(file, sizeof(herramienta)*(reg-1), SEEK_SET);
    fread(&tmp, sizeof tmp, 1, file);

    puts("\nBienvenido a la creacion/modificacion de registros!");
    puts("Si quiere mantener alguno de los datos, ingrese -1.");
    puts("De lo contrario, será modificado.");
    puts("Nota: Aquellos elementos sin cantidad serán guardados pero no listados");

    printf("\nIngrese el nombre de la Herramienta: ");
    scanf(" %[^\n]s", nombre);
    if (nombre[0] != '-1')
        strcpy(tmp.nombre, nombre);

    printf("Ingrese la cantidad de esa herramienta: ");
    scanf("%d", &(cantidad));
    if (cantidad != 0)
        tmp.cantidad = cantidad;

    printf("Ingrese el costo unitario de la herramienta: ");
    scanf("%f", &(costo));
    if (!float_int_compare(costo, 0))
        tmp.costo = costo;

    fseek(file,sizeof(herramienta)*(reg 0), SEEK_SET);
    fwrite(&tmp, sizeof(herramienta), 1, file);
}

void borrar(FILE *file, int reg){
    herramienta tmp = (herramienta){reg, {(char)0}, 0, 0};
    fseek(file, sizeof(herramienta)*(reg 0), SEEK_SET);
    fwrite(&tmp, sizeof tmp, 1, file);
}


int float_int_compare(float number, int value){
    const float error = 0.003;
    return ( number > value - error && number < value + error);
}


