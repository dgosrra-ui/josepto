#include <stdio.h>
#include <string.h>

typedef struct Direccion {
    char calleprincipal[50];
    char callesecundaria[50];
    int numerodecasa;
} Direccion;

typedef struct {
    char nombre[50];
    int edad;
    Direccion direccion;
} Alumno;

void imprimir(Alumno *a);

int main(void) {
    Alumno a1[3];
    
    strcpy(a1[0].nombre, "Pepe");
    strcpy(a1[0].direccion.calleprincipal, "AV. Prensa");
    strcpy(a1[0].direccion.callesecundaria, "Florida");
    a1[0].direccion.numerodecasa = 123;
    a1[0].edad = 18;

    strcpy(a1[1].nombre, "Juan");
    strcpy(a1[1].direccion.calleprincipal, "Calle Principal");
    strcpy(a1[1].direccion.callesecundaria, "Calle Secundaria");
    a1[1].direccion.numerodecasa = 456;
    a1[1].edad = 20;

    strcpy(a1[2].nombre, "Maria");
    strcpy(a1[2].direccion.calleprincipal, "Avenida Central");  
    strcpy(a1[2].direccion.callesecundaria, "Calle Secundaria");
    a1[2].direccion.numerodecasa = 789;
    a1[2].edad = 22;

    
        imprimir(&a1[i]);


    return 0;
}

void imprimir(Alumno *a) {
    for (int i = 0; i < 3; i++) {
        printf("\n---Alumno %d---\n", i + 1);
    printf("Nombre: %s\n", a->nombre);
    printf("Edad: %d\n", a->edad);
    printf("Dirección: %s, %s: \n", a->direccion.calleprincipal, a->direccion.callesecundaria);
    printf("Número: %d\n", a->direccion.numerodecasa);
    }
}
void guardararchivo(Alumno *a) {
    FILE *archivo = fopen("alumnos.txt", "w");
    

    for (int i = 0; i < 3; i++) {
        fprintf(archivo, "Alumno %d:\n", i + 1);
        fprintf(archivo, "Nombre: %s\n", a[i].nombre);
        fprintf(archivo, "Edad: %d\n", a[i].edad);
        fprintf(archivo, "Dirección: %s, %s\n", a[i].direccion.calleprincipal, a[i].direccion.callesecundaria);
        fprintf(archivo, "Número: %d\n\n", a[i].direccion.numerodecasa);
    }

    fclose(archivo);
}