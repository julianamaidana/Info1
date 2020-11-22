#include <stdio.h>
#include <stdlib.h>
#include <time.h>


struct fecha {
    int dia;
    int mes;
    int a;
};

struct rango{
    float min;
    float max;
};


struct perfil{
    char nombre[80];
    char apellido[80];
    char sexo[80];
    struct fecha nacimiento;
    float altura;
    float peso;
};

void carga(struct perfil *p){
    printf("Ingrese su nombre: ");
    scanf(" %s", p->nombre);
    printf("Ingrese su apellido: ");
    scanf(" %s", p->apellido);
    printf("Ingrese su genero: ");
    scanf(" %s", p->sexo);
    printf("Ingrese su dia nacimiento ");
    scanf("%d", &(p -> nacimiento.dia)); 
    printf("Ingrese su mes de nacimiento en ");
    scanf ("%d", &(p -> nacimiento.mes)); 
    printf("Ingrese su año de nacimiento ");
    scanf ("%d", &(p -> nacimiento.a));
    printf("Ingrese su altura en metros: ");
    scanf("%f", &(p->altura));
    printf("Ingrese su peso en kilogramos: ");
    scanf("%f", &(p->peso));
}
int edad(struct fecha nacimiento){
    time_t t = time(NULL);
    struct tm tm = *localtime(&t);
    struct fecha actual = {tm.tm_mday, tm.tm_mon + 1, tm.tm_year + 1900};

    if(actual.mes < nacimiento.mes || (actual.mes == nacimiento.mes && actual.dia < nacimiento.dia))
        actual.a--;
    return actual.a - nacimiento.a;
}

float BMI(struct perfil paciente){
    return paciente.peso / (paciente.altura * paciente.altura);
}   
int freqMax(struct perfil paciente){
    return 220 - edad(paciente.nacimiento);
}
struct rango freqideal(struct perfil paciente){
    return (struct rango){freqMax(paciente)*0.5, freqMax(paciente)*0.85};
}
    
void imprimir(struct perfil *p){
    printf("Nombre: %s\n", p -> nombre);
    printf ("Apellido: %s\n", p-> apellido);
    printf("Genero: %s\n", p -> sexo);
    printf("Nacimiento: %d/%d/%d\n", p -> nacimiento.dia, p -> nacimiento.mes, p -> nacimiento.a);
    printf("Altura: %.2f m\n", p -> altura);
    printf("Peso: %.2f kg\n", p -> peso);
}


int main(void){
    struct perfil paciente;
    struct perfil *p = &paciente;
    carga(p);
    printf("Bienvenido a su Ficha Medica, HealthProfile\n");
    imprimir(p);
    printf("\nBMI: %.2f\n", BMI(paciente));
    printf("Edad: %d años\n", edad(paciente.nacimiento));
    printf("Tu frecuencia Cardiaca Maxima: %d bpm\n", freqMax(paciente));
    printf("Tu frecuencia Cardiaca Ideal: %.2f bpm - %.2f bpm\n", freqideal(paciente).min, freqideal(paciente).max);
    return 0;
}
