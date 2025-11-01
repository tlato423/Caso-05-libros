#include <stdio.h>

int main(int argc, char *argv[]) {
	char *titulos[] = {
		"Un cuento de dos ciudades",
		"Cumbres borrascosas",
		"Don Quijote",
		"Odisea",
		"Moby Dick",
		"Hamlet",
		"Las travesias de Gulliver"
	};
	char **mejoresLibros[3];
	char **librosDeIngles[4];
	int n;
	mejoresLibros[0]= &titulos[0];
	mejoresLibros[1]= &titulos[3];
	mejoresLibros[2]= &titulos[5];
	librosDeIngles[0]= &titulos[0];
	librosDeIngles[1]= &titulos[1];
	librosDeIngles[2]= &titulos[5];
	librosDeIngles[3]= &titulos[6];
	printf("%s\n", *librosDeIngles[1]); // Cumbres borrascosas
	printf("Direcciones de los titulos.\n");
	for(n=0; n<7; n++) {
		printf("%p\n", (titulos+n));
		}
	printf("Direcciones de los mejores libros.\n");
	for(n=0; n<3; n++) {
		printf("%p\n", *(mejoresLibros+n));
		}
	printf("Direcciones de los libros en ingles.\n");
	for(n=0; n<4; n++) {
		printf("%p\n", *(librosDeIngles+n));
		}
	printf("Los mejores libros.\n");
	for(n=0; n<3; n++) {
		printf("%s\n", *(mejoresLibros[n]));
		}
	printf("Libros en ingles.\n");
	for(n=0; n<4; n++) {
		printf("%s\n", *(librosDeIngles[n]));
		}
	
	return 0;
}