#include <stdio.h>

/* 
Programa Espía: Para efectos de control este programa debe responder a las siguientes solicitudes del usuario
• Estado de la memoria en determinado momento. Debe mostrar cómo están acomodados los procesos en la
memoria.
• Estado de los Procesos
• Al pedir el estado debe decirme
• El PID de los proceso que estén en la memoria en ese momento (sleep) (punto 5 del proceso)
• El PID del único proceso que esté buscando espacio en la memoria. (punto 2 del proceso)
• El PID de los procesos que estén bloqueados (esperando por la región critica) (punto 1 o 6 del proceso)
• El PID de los procesos que han muerto por no haber espacio suficiente.
• El PID de los procesos que ya terminaron su ejecución
*/

int MostrarReporte();
int MostrarMemoria();
int EstadoProcesos();

int main() {
	//Inicializa los recursos
	printf("\nEspia INICIADO!\n\n");
	MostrarReporte();
	printf("\nEspia TERMINADO!\n\n");
}

int MostrarReporte(){
	MostrarMemoria();
	EstadoProcesos();
}

int MostrarMemoria(){
	printf("Estado de la Memoria:\n");

	printf("\n");


}

int EstadoProcesos(){
	printf("Estado de los Procesos:\n");
	//	Procesos Activos, en memoria
	printf("Procesos Activos:\n");
	printf("PIDs\n");

	//	Unico Proceso Buscando memoria, con el semaforo y buscando.
	printf("Proceso Buscando Ubicacion:\n");
	printf("PIDs\n");

	//	Procesos esperando Semaforo para pedir memoria (esperando region critica)
	printf("Proceso Esperando Region Critica:\n");
	printf("PIDs\n");

	//	Procesos Muertos
	printf("Proceso Muertos:\n");
	printf("PIDs\n");

	//	Procesos Terminados
	printf("Proceso Terminados:\n");
	printf("PIDs\n");
}