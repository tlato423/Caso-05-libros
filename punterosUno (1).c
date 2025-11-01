#include <stdio.h>

int main(int argc, char *argv[]) {
	void * ptrVacio;
	int a = 40;
	int *ptrInt;
	ptrVacio = &a;
	printf("direccion de a        : %p\n", &a);
	ptrInt = (int *)ptrVacio;
	printf("contenido de ptrVacio : %d\n", *ptrInt);
	return 0;
}