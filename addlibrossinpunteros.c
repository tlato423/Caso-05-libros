#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define NOM_LIBRO 60
#define MAX_LIBROS 40
void ejecutarPrograma();

void agregarLibro(char nombreLibro[NOM_LIBRO], char libros[MAX_LIBROS]){
    int i;
    char libro[NOM_LIBRO];
    printf("Digite el nombre de un libro: ");
    fgets(libro,NOM_LIBRO,stdin);
    while(getchar() != '\n');

    printf("En que categoria lo quieres guardar? ");

    for(i=0;i<MAX_LIBROS;i++){
        if(i<MAX_LIBROS){
            nombreLibro[i] = libro; 
        }
    }

    printf("nombre: %s",nombreLibro[i]);
}

void categorias(){
    char ingles, terror, cienciaFiccion, romance, psicologia;
}

void menu(char nombreLibro[NOM_LIBRO], char libros[MAX_LIBROS]){
    int opc;

    do{
        printf("1- Agregar un nuevo libro\n");
        printf("2- Buscar un libro\n");
        printf("3- Imprimir todos los libros\n");
        printf("4- Imprimir por categoria\n");
        printf("5- salir\n");
        printf(" Opcion: ");
        scanf("%i",&opc);

            switch(opc){
                case 1:agregarLibro(nombreLibro,libros); break;
                case 2: break;
                case 3: break;
                case 4: break;
            }
    }while(opc!=5);
    
}

void ejecutarPrograma(){
    char libros[40];
    char nombreLibro[20];

    menu(nombreLibro,libros);
}

int main(){
    ejecutarPrograma();
    return 0;
}