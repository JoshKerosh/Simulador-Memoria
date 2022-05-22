
#include <stdio.h>

/*
Programa Finalizador: Se encarga de matar todos los procesos que estén en escena. Devolver los recursos que había
solicitado. Y cerrar el archivo de la Bitácora.
*/

int MatarProcesos();
int DevolverMemoria();
int CerrarBitacora();

int main() {
	//Inicializa los recursos
	printf("\nEspia INICIADO!\n\n");
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