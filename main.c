#include<stdio.h>
#include<string.h>
#include<stdlib.h>

typedef struct libro{
    char titulo[64];
    int anioDePublicacion;
    struct libro *siguiente;
}Libro, *LibroPtr;

void lanzarMenu();
LibroPtr crearNodo(char titulo[], int anioDePublicacion);
LibroPtr buscarLibro(LibroPtr actual, char titulo[]);
void imprimirLista(LibroPtr actual);

int main(int argc, char *argv[]){
    LibroPtr raiz, actual, ultimo;
    int opcion, anioDePublicacion;
    char titulo[64];
    raiz = NULL;
    ultimo = NULL;

    lanzarMenu();
    scanf("%i", &opcion);

    while(opcion >= 1 && opcion <= 3){
        switch(opcion){
        case 1:
        printf("Introduce el titulo del libro: \n");
        scanf("%s", titulo);
        printf("Introduce la fecha de publicacion: \n");
        scanf("%i", &anioDePublicacion);

        actual = crearNodo(titulo, anioDePublicacion);
        if(raiz == NULL){
            raiz = actual;
        }else{
            ultimo->siguiente = actual;
        }
        ultimo = actual;
        break;
        case 2:
        printf("Introduce el titulo del libro a buscar: \n");
        scanf("%s", &titulo);
        actual = buscarLibro(raiz, titulo);
        if(actual == NULL){
            printf("Elemento no encontrado.\n");
        }else{
            printf("\t\t\tElemento encontrado: \n");
            printf("Titulo del libro: %s\n", actual->titulo);
            printf("Fecha de publicacion: %i\n", actual->anioDePublicacion);
        }
        break;
        case 3:
        if(raiz == NULL){
            printf("La lista esta vacia\n");
        }else{
            imprimirLista(raiz);
        }
        break;
        }

        lanzarMenu();
        scanf("%i", &opcion);
    }

    return 0;
}

void lanzarMenu(){
    printf("\t\t\tLista enlazada.\n");
    printf("1.-Crear nodo.\n");
    printf("2.-Buscar nodo.\n");
    printf("3.-Imprimir lista.\n");
    printf("4.-Salir.\n");
    printf("Introduce una opcion: \n");
}

LibroPtr crearNodo(char titulo[], int anioDePublicacion){
    LibroPtr actual = (LibroPtr)malloc(sizeof(Libro));
    strcpy(actual->titulo, titulo);
    actual->anioDePublicacion = anioDePublicacion;
    actual->siguiente = NULL;

    return actual;
}

LibroPtr buscarLibro(LibroPtr actual, char titulo[]){
    LibroPtr temp = NULL; 

    while(actual != NULL){
        if(strcmp(actual->titulo, titulo) == 0){
            temp = actual;
            break;
        }else{
            actual = actual->siguiente;
        }
    }
    return temp;
}

void imprimirLista(LibroPtr actual){
    printf("\t\t\tImpresion de la lista: \n");
    while(actual != NULL){
        printf("Titulo del libro: %s\n", actual->titulo);
        printf("Fecha de publicacion: %i\n", actual->anioDePublicacion);
        actual = actual->siguiente;
    }
}