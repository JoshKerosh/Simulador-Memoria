#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>


/*
Programa Inicializador: Este programa se encarga de crear el ambiente. Pide los recursos y los inicializa de manera
que los actores encuentren todo listo en el momento de empezar a funcionar. Este programa pide la cantidad de
páginas o espacios de memoria que va a haber y solicita la memoria compartida al sistema operativo. Este proceso
debe morir después de realizar la inicialización. 
*/
struct espacioMemoria{
	bool libre;
	int PID;
};

int SolicitarMemoria();
int CrearMemoria();
int CrearSemaforo();
int CrearListasProcesos();

int main() {

	//Inicializa los recursos
	printf("\n------\n");
	printf("Cuantas paginas o espacios en memoria?\n");
	printf(">> ");
	int cantPagsSegs;
	scanf("%d", &cantPagsSegs);
	printf("%i \n", cantPagsSegs);
	SolicitarMemoria(cantPagsSegs);
	printf("\nINICIALIZADOR TERMINADO!\n\n");

}

int SolicitarMemoria(int cant){
	CrearMemoria(cant);
	CrearSemaforo();
	CrearListasProcesos();
	return 0;
}

int CrearSemaforo(){
	//inicia en verde
	printf("Semáforo creado\n");
	return 0;
}

int CrearMemoria(int cant){
	// lista de espaciosMemoria, [cant]
	printf("Memoria creada, %i espacios\n", cant);
	return cant;
}

int CrearListasProcesos(){
	//lista Ready
	//lista Terminados
	//lista Muertos
	printf("Listas creadas\n");
	return 0;
}