#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "prueba.h"

/*
------------------------------
----------DISCLAIMER----------
------------------------------
ESTA ES *UNA* FORMA EN QUE SE PUEDE UTILIZAR LO MOSTRADO
PROBABLEMENTE NO ES LA MÁS EFICIENTE
NO LO HICE ESPECÍFICO A LA TAREA
SU FUNCIÓN ES HACERLES ENTENDER COMO FUNCIONAN CIERTAS FUNCIONES
*/


int puntero(){

    //Distintos tipos de datos para probar los punteros
    int num = 25;
    char c = 'h';
    float f = 4.5;

    //Un puntero (definido de manera distinta pero equivalente) para cada tipo de dato definido
    int *ptr1; 
    char * ptr2;
    float* ptr3;

    //Asociamos el puntero con la dirección de memoria de cada variable definida
    ptr1 = &num;
    ptr2 = &c;
    ptr3 = &f; 

    //Imprimimos en el terminal el valor *(&var) y la memoria &var
    printf("Número: %d, dirección %p \n", *ptr1, ptr1);
    printf("Caracter: %c, dirección %p \n", *ptr2, ptr2);
    printf("Flotante: %f, dirección %p \n", *ptr3, ptr3);

    int *ptr4 = NULL;
    ptr4 = ptr1;
    printf("La copia de la dirección de %d es: %p \n", *ptr4, ptr4);

    ptr4 = ptr4 + 50; // equivalente a ptr4 + 50 * sizeof(int)
    printf("ptr1: %p, ptr4: %p \n", ptr1, ptr4);

    ptr1 = ptr1 - 1000; //equivalente a ptr1 - 1000 * sizeof(int)
    printf("ptr1: %p, ptr4: %p \n", ptr1, ptr4);

    return 0;
}

void memory(){

    //Memoria estática, no podemos cambiar su largo
    char nombre[20];
    strcpy(nombre, "Ale Zamora Villa");

    //Memoria dinámica, le asignamos 100 lugares tipo char (por ahora)
    char *about1, *about2;
    about1 = malloc(sizeof(char)*100);
    about2 = calloc(100, sizeof(char));

    strcpy(about1, "Aquí utilizamos malloc(sizeof(char)*100) para decirles que soy la ayudante de lp. ");
    strcpy(about2, "Aquí utilizamos calloc(100,sizeof(char)) para hacer lo mismo. \n");

    printf("Nombre: %s \n", nombre);
    printf("Descripción 1: %s %s", about1, about2);

    //Le damos más espacio a about1, teniendo ahora 200 espacios para tipo char
    about1 = realloc(about1, sizeof(char)*500);
    strcat(about1, "Ahora le agregué más espacio a la primera descripción utilizando realloc(about1, sizeof(char)*200) para decirles que espero que les vaya muy bien uwu. ");

    printf("----------------------- \n");

    printf("Nombre: %s \n", nombre);
    printf("Descripción 2: %s %s", about1, about2);

    //Liberamos la memoria después de haber terminado de usarlos.
    free(about1);
    free(about2);
}

void estructura(){

    //Asignar memoria al struct
    Test *test;
    test = (Test*) malloc(sizeof(Test));

    //Asignar memoria a la cantidad de elementos del struct
    int largo = 5;
    test->var = (int*) malloc(sizeof(int)*largo);
    //Guardamos la posición inicial del struct
    int *v = test->var;

    //Ingresar valores a struct
    for(int i = 0; i < largo; i++){
        *test->var = i+1;
        test->var++;
    }

    //Volver a la posición inicial de var
    test->var = v;

    //Imprimir en pantalla el valor y la dirección de cada uno de los elementos del struct
    printf("El struct tiene dirección de memoria: %p \n", test);
    for(int i = 0; i < largo; i++){
        printf("Elemento %d del struct: %d, con posición de memoria: %p \n", i, *test->var, test->var);
        test->var++;
    }


    /*Corrección!!!!!!
    Se me olvidó devolver el puntero a su posición inicial
    Ahora está testeado con valgrind y no hay leaks de memoria :) */
   test->var = v;
   free(test->var);

    //Y por último liberamos la memoria del struct
    free(test);
}

int efescanf(){

    FILE* text = fopen("hola.txt", "r");
    char buff[100];
    while (fscanf(text, "%*s %s", buff) == 1){
        printf("%s\n", buff);
    }
    
    fclose(text);
    return 0;
}



