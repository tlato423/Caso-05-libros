#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#define NOM_LIBRO 60
#define MAX_LIBROS 40

struct categorias{
    char terror[NOM_LIBRO][MAX_LIBROS];
    char cFiccion[NOM_LIBRO][MAX_LIBROS];
    char cocina[NOM_LIBRO][MAX_LIBROS];
    char romance[NOM_LIBRO][MAX_LIBROS];
    char historia[NOM_LIBRO][MAX_LIBROS];
    char miscelaneo[NOM_LIBRO][MAX_LIBROS];
};

//void ejecutarPrograma();

void agregarLibro(int *numLibros, struct categorias biblioteca[],char libro[NOM_LIBRO]){
    int i;

    if(*numLibros>=MAX_LIBROS){
        printf("Ya no se pueden agregar más libros");
        return;
    }


    printf("Digite el nombre del libro: ");
    fgets(libro,NOM_LIBRO,stdin);
    libro[strcspn(libro, "\n")] = '\0';


    printf("En que categoria lo quieres guardar? ");
    menuCategoria(*numLibros,biblioteca,libro);

    printf("Tu libro %s se guardo exitosamente",libro);

}


void menuCategoria(int *numLibros, struct categorias biblioteca[NOM_LIBRO][MAX_LIBROS],char libro[NOM_LIBRO]){
    int opc;

    printf("1- Terror\n");
    printf("2- Ciencia ficcion\n");
    printf("3- cocina\n");
    printf("4- Romance\n");
    printf("5- Historia\n");
    printf("6- Otros\n");
    printf("Opcion: ");
    scanf("%i",&opc);
    while(getchar() != 'n');

    if(opc>=1 && opc <= 6){
        switch (opc)
        {
        case 1: 
            biblioteca[NOM_LIBRO][*numLibros].terror = libro;
        break;
        case 2: libro = biblioteca[NOM_LIBRO][*numLibros].cFiccion = libro;
        break;
        case 3:biblioteca[NOM_LIBRO][*numLibros].cocina = libro;
        break;
        case 4:biblioteca[NOM_LIBRO][*numLibros].romance = libro;
        break;
        case 5:biblioteca[NOM_LIBRO][*numLibros].historia = libro;
        break;
        case 6:biblioteca[NOM_LIBRO][*numLibros].miscelaneo = libro;
        break;
        default:
            printf("opcion no valida");
        break;
        }
        (*numLibros)++;
    }
}

/*void menu(char nombreLibro[NOM_LIBRO], char libros[MAX_LIBROS]){
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
}*/

int main(){
    int a,b, c;
   // ejecutarPrograma();
    agregarLibro(a,b,c);
    return 0;
}