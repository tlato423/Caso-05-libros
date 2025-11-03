#include <stdio.h>
#include <string.h>

#define MAX_LIBROS 40
#define MAX_LONGITUD_TITULO 100
#define MAX_CATEGORIAS 6
#define MAX_LONGITUD_CATEGORIA 50

void inicializarPunteros(char *ptrs_titulos[], char *ptrs_cats[], char almacen_tit[][MAX_LONGITUD_TITULO],char almacen_cats[][MAX_LONGITUD_CATEGORIA]);
void mostrarMenu();
void agregarLibro(char *ptrs_titulos[], char *ptrs_cats[], int *pNumLibros);
void buscarLibro(char *ptrs_titulos[], char *ptrs_cats[], int numLibros);
void modificarLibro(char *ptrs_titulos[], char *ptrs_cats[], int numLibros);
void imprimirTodos(char *ptrs_titulos[], char *ptrs_cats[], int numLibros);
void imprimirPorCategoria(char *ptrs_titulos[], char *ptrs_cats[], int numLibros);
int obtenerOpcionCategoria();


void inicializarPunteros(char *ptrs_titulos[], char *ptrs_cats[],char almacen_tit[][MAX_LONGITUD_TITULO], char almacen_cats[][MAX_LONGITUD_CATEGORIA]) {
    int i;
    for (i = 0; i < MAX_LIBROS; i++) {
        ptrs_titulos[i] = almacen_tit[i];
        ptrs_cats[i] = almacen_cats[i];
    }
}

void mostrarMenu() {
    printf("\n--- Menú de la Biblioteca (Sin Globales) ---\n");
    printf("1. Agregar un nuevo libro\n");
    printf("2. Buscar un libro\n");
    printf("3. Modificar un libro\n");
    printf("4. Imprimir todos los libros\n");
    printf("5. Imprimir por categoría\n");
    printf("0. Salir\n");
    printf("Seleccione una opción: ");
}

void agregarLibro(char *ptrs_titulos[], char *ptrs_cats[], int *pNumLibros) {
    if (*pNumLibros >= MAX_LIBROS) {
        printf("Error: La biblioteca está llena.\n");
        return;
    }

    printf("Ingrese el título del nuevo libro: ");
    fgets(ptrs_titulos[*pNumLibros], MAX_LONGITUD_TITULO, stdin);
    ptrs_titulos[*pNumLibros][strcspn(ptrs_titulos[*pNumLibros], "\n")] = 0;

    int opcionCat = obtenerOpcionCategoria();
    
    char nombresCategorias[MAX_CATEGORIAS][MAX_LONGITUD_CATEGORIA] = {
        "Ficcion", "No Ficcion", "Ciencia Ficcion", "Misterio", "Fantasia", "Clasico"
    };

    strcpy(ptrs_cats[*pNumLibros], nombresCategorias[opcionCat]);

    printf("¡Libro '%s' agregado a la categoría '%s'!\n",
            ptrs_titulos[*pNumLibros], ptrs_cats[*pNumLibros]);

    (*pNumLibros)++;
}

void buscarLibro(char *ptrs_titulos[], char *ptrs_cats[], int numLibros) {
    if (numLibros == 0) {
        printf("La biblioteca está vacía.\n");
        return;
    }

    char busqueda[MAX_LONGITUD_TITULO];
    printf("Ingrese el título (o parte) a buscar: ");
    fgets(busqueda, MAX_LONGITUD_TITULO, stdin);
    busqueda[strcspn(busqueda, "\n")] = 0;

    int encontrados = 0;
    printf("\n--- Resultados de la Búsqueda ---\n");
    int i;
    for (i = 0; i < numLibros; i++) { 
        if (strstr(ptrs_titulos[i], busqueda) != NULL) {
            printf("ID: %d | Título: %s | Categoría: %s\n",
                    i, ptrs_titulos[i], ptrs_cats[i]);
            encontrados++;
        }
    }

    if (encontrados == 0) {
        printf("No se encontraron libros que coincidan.\n");
    }
}

void modificarLibro(char *ptrs_titulos[], char *ptrs_cats[], int numLibros) {
    if (numLibros == 0) {
        printf("La biblioteca está vacía.\n");
        return;
    }

    int indice;
    printf("Ingrese el ID del libro a modificar (0 a %d): ", numLibros - 1);
    
    if (scanf("%d", &indice) != 1 || indice < 0 || indice >= numLibros) {
        while (getchar() != '\n');
        printf("ID no válido.\n");
        return;
    }
    while (getchar() != '\n'); // Limpiar buffer

    printf("Modificando: [ID: %d, Título: %s, Cat: %s]\n",
            indice, ptrs_titulos[indice], ptrs_cats[indice]);

    // Modificar Título
    printf("Ingrese el nuevo título (Enter para no cambiar): ");
    char nuevoTitulo[MAX_LONGITUD_TITULO];
    fgets(nuevoTitulo, MAX_LONGITUD_TITULO, stdin);
    nuevoTitulo[strcspn(nuevoTitulo, "\n")] = 0;

    if (strlen(nuevoTitulo) > 0) {
        strcpy(ptrs_titulos[indice], nuevoTitulo);
        printf("Título actualizado.\n");
    }

    // Modificar Categoría
    printf("¿Desea cambiar la categoría? (s/n): ");
    char cambiarCat = getchar();
    while (getchar() != '\n');

    if (cambiarCat == 's' || cambiarCat == 'S') {
        int opcionCat = obtenerOpcionCategoria();
        
        // Definimos los nombres localmente para poder copiar
        char nombresCategorias[MAX_CATEGORIAS][MAX_LONGITUD_CATEGORIA] = {
            "Ficcion", "No Ficcion", "Ciencia Ficcion", "Misterio", "Fantasia", "Clasico"
        };
        
        strcpy(ptrs_cats[indice], nombresCategorias[opcionCat]);
        printf("Categoría actualizada.\n");
    }

    printf("Resultado: [ID: %d, Título: %s, Cat: %s]\n",
            indice, ptrs_titulos[indice], ptrs_cats[indice]);
}

void imprimirTodos(char *ptrs_titulos[], char *ptrs_cats[], int numLibros) {
    if (numLibros == 0) {
        printf("La biblioteca está vacía.\n");
        return;
    }

    printf("\n--- Todos los Libros (%d/%d) ---\n", numLibros, MAX_LIBROS);
    int i;
    for (i = 0; i < numLibros; i++) {
        printf("ID: %d\n", i);
        // Usamos la notación de aritmética de punteros
        printf("  Título: %s\n", *(ptrs_titulos + i));
        printf("  Categoría: %s\n", *(ptrs_cats + i));
        printf("----------------------------\n");
    }
}

void imprimirPorCategoria(char *ptrs_titulos[], char *ptrs_cats[], int numLibros) {
    if (numLibros == 0) {
        printf("La biblioteca está vacía.\n");
        return;
    }

    char nombresCategorias[MAX_CATEGORIAS][MAX_LONGITUD_CATEGORIA] = {
        "Ficcion", "No Ficcion", "Ciencia Ficcion", "Misterio", "Fantasia", "Clasico"
    };

    printf("Seleccione la categoría que desea imprimir:\n");
    int opcionCat = obtenerOpcionCategoria();
    
    char *catSeleccionada = nombresCategorias[opcionCat];

    printf("\n--- Libros en la categoría: %s ---\n", catSeleccionada);
    int encontrados = 0;
    int i;
    for (i = 0; i < numLibros; i++) {
        if (strcmp(ptrs_cats[i], catSeleccionada) == 0) {
            printf("ID: %d | Título: %s\n", i, ptrs_titulos[i]);
            encontrados++;
        }
    }

    if (encontrados == 0) {
        printf("No se encontraron libros en esta categoría.\n");
    }
}

int obtenerOpcionCategoria() {
    // Definimos los nombres localmente solo para mostrarlos
    char nombresCategorias[MAX_CATEGORIAS][MAX_LONGITUD_CATEGORIA] = {
        "Ficcion",
        "No Ficcion",
        "Ciencia Ficcion",
        "Misterio",
        "Fantasia",
        "Clasico"
    };

    int opcion;
    printf("Seleccione una categoría:\n");
    int i;
    for (i = 0; i < MAX_CATEGORIAS; i++) {
        printf("%d. %s\n", i + 1, nombresCategorias[i]);
    }
    printf("Opción (1-%d): ", MAX_CATEGORIAS);

    while (scanf("%d", &opcion) != 1 || opcion < 1 || opcion > MAX_CATEGORIAS) {
        while (getchar() != '\n');
        printf("Opción no válida. Ingrese un número entre 1 y %d: ", MAX_CATEGORIAS);
    }
    while (getchar() != '\n');

    return opcion - 1;
}

void ejecutarPrograma(){
    
    char almacen_titulos[MAX_LIBROS][MAX_LONGITUD_TITULO];
    char almacen_categorias[MAX_LIBROS][MAX_LONGITUD_CATEGORIA];
    char *punteros_titulos[MAX_LIBROS];
    char *punteros_categorias[MAX_LIBROS];

    int numLibros = 0;
    

    inicializarPunteros(punteros_titulos, punteros_categorias, almacen_titulos, almacen_categorias);

    int opcion;
    do {
        mostrarMenu();
        if (scanf("%d", &opcion) != 1) {
            opcion = -1; 
        }
        while (getchar() != '\n');

        switch (opcion) {
            case 1:
                agregarLibro(punteros_titulos, punteros_categorias, &numLibros);
                break;
            case 2:
                buscarLibro(punteros_titulos, punteros_categorias, numLibros);
                break;
            case 3:
                modificarLibro(punteros_titulos, punteros_categorias, numLibros);
                break;
            case 4:
                imprimirTodos(punteros_titulos, punteros_categorias, numLibros);
                break;
            case 5:
                imprimirPorCategoria(punteros_titulos, punteros_categorias, numLibros);
                break;
            case 0:
                printf("Saliendo del programa...\n");
                break;
            default:
                printf("Opción no válida. Por favor, intente de nuevo.\n");
        }
    } while (opcion != 0);

}

int main(int argc, char const *argv[]) {
    ejecutarPrograma();    
    return 0;
}
