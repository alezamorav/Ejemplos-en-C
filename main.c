#include<stdio.h>
#include "prueba.h"

/*
INSTRUCCIONES
-------------
En la carpeta donde tengan guardados todos los archivos deben poner en el terminal make uwu
Para ejecutarlo deben escribir ./uwu
Para limpiar los archivos de ejecución deben escribir make clean

Por favor no usen nada de este ejemplo literal en sus tareas, se considerará como copia
*/



int main(){

    printf("-Menu- \n");
    printf("1. Prueba punteros. \n");
    printf("2. Prueba memoria. \n");
    printf("3. Prueba estructura. \n");
    printf("4. Prueba fscanf. \n");
    printf("0. Salir. \n");

    char x = 'a';
    printf("Elige: ");
    scanf("%c", &x);

    switch(x){
        case '1':
            puntero();
            break;

        case '2':
            memory();
            break;

        case '3':
            estructura();
            break;

        case '4':
            efescanf();
            break;

        case '0':
            return 0;
    }

}
