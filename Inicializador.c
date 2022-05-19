#include <stdio.h>
#include <stdlib.h>


/*
Programa Inicializador: Este programa se encarga de crear el ambiente. Pide los recursos y los inicializa de manera
que los actores encuentren todo listo en el momento de empezar a funcionar. Este programa pide la cantidad de
páginas o espacios de memoria que va a haber y solicita la memoria compartida al sistema operativo. Este proceso
debe morir después de realizar la inicialización. 
*/

int main() {

	//Inicializa los recursos
	printf("\n------\n");
	printf("Cuantas paginas o espacios en memoria?\n");
	printf(">> ");
	int cantPagsSegs;
	scanf("%d", &cantPagsSegs);
	printf("%i \n", cantPagsSegs);
	//SolicitarMemoriaCompartida()
}