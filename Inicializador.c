#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/shm.h>

/*
Programa Inicializador: Este programa se encarga de crear el ambiente. Pide los recursos y los inicializa de manera
que los actores encuentren todo listo en el momento de empezar a funcionar. Este programa pide la cantidad de
páginas o espacios de memoria que va a haber y solicita la memoria compartida al sistema operativo. Este proceso
debe morir después de realizar la inicialización. 
*/

#define BLOCK_SIZE 4096
#define FILENAME "block.mem"

#define IPC_RESULT_ERROR (-1)

char * attach_memory_block(char *filename, int size);
bool detach_memory_block(char *block);




struct espacioMemoria{
	bool libre;
	struct espacioMemoria *sig;
};


struct memoriaCompartida{
	struct espacioMemoria *Memoria;
	struct proceso *lProcesos;
	int Semaforo;
};

static int SolicitarMemoria(char *filename, int size);
int CrearMemoria();
int CrearSemaforo();
int CrearListasProcesos();
int AbrirBitacora();

int main() {
	//Inicializa los recursos
	printf("\n------\n");
	printf("Cuantas paginas o espacios en memoria?\n");
	printf(">> ");
	int cantPagsSegs;
	scanf("%d", &cantPagsSegs);
	printf("%i \n", cantPagsSegs);

	SolicitarMemoria(FILENAME, BLOCK_SIZE);

	CrearMemoria(cantPagsSegs);
	CrearSemaforo();
	CrearListasProcesos();
	AbrirBitacora();
	printf("\nINICIALIZADOR TERMINADO!\n\n");

}

//
static int SolicitarMemoria(char *filename, int size){
	key_t key;

	//Request a key
	//the key is linked to a file, so that other programs can access it.
	key = ftok(filename, 0);
	if (key == IPC_RESULT_ERROR){
		return IPC_RESULT_ERROR;
	}

	//get shared block --- create it if it doesn't exist
	return shmget(key, size, 0644 | IPC_CREAT);
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

int AbrirBitacora(){
	return 0;
}