
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/shm.h>

/*
Programa Finalizador: Se encarga de matar todos los procesos que estén en escena. Devolver los recursos que había
solicitado. Y cerrar el archivo de la Bitácora.
*/

int MatarProcesos();
int DevolverMemoria();
int CerrarBitacora();


#define BLOCK_SIZE 4096
#define FILENAME "block.mem"

#define IPC_RESULT_ERROR (-1)

char * attach_memory_block(char *filename, int size);
bool detach_memory_block(char *block);
bool destroy_memory_block(char *filename);

int main() {
	MatarProcesos();
	DevolverMemoria();
	CerrarBitacora();
	printf("\nSistema de FINALIZADO!\n\n");
}

int MatarProcesos(){

}

int DevolverMemoria(){

}

int CerrarBitacora(){

}

//
static int get_share_block(char *filename, int size){
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

bool destroy_memory_block(char *filename){
	int shared_block_id = get_share_block(filename, 0);

	if(shared_block_id == IPC_RESULT_ERROR){
		return NULL;
	}

	return (shmctl(shared_block_id, IPC_RMID, NULL) != IPC_RESULT_ERROR);

}