#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <unistd.h>
#include <pthread.h>

/*
Programa Productor de Procesos: Este es un programa que genera procesos que llegan al “Ready” (Threads). Lo
primero que debe hacer es solicitar el tipo de algoritmo con el que se desea correr la simulación (Paginación o
Segmentación). Para cada uno de los hilos se define de manera Random los siguientes valores:

Paginación 
- Cantidad de páginas (1-10)
- Tiempo (20s-60s).

Segmentación 
- Cantidad de Segmentos (1-5)
- Cantidad de espacios de memoria por segmento (1-3)
- Tiempo (20s-60s).

Dependiendo del esquema que se esté usando todos los procesos se crean dentro de ese mismo esquema. La
Distribución con la que se generaran los procesos estará determinada por un tiempo aleatorio (30s-60s). Cada
proceso debe buscar dentro de la memoria las páginas o espacio para sus segmentos. Si no hay espacio suficiente
el proceso muere. Solo un proceso a la vez puede estar corriendo el algoritmo de búsqueda de espacio, para que no
haya choques que 2 procesos seleccionen el mismo hueco/página. Una vez que haya encontrado lugar transcurrirá
un sleep con la cantidad de tiempo definida para él y después de forma exclusiva (Región Critica) devuelve los
espacios de memoria que tenía asignados.
*/

typedef struct proceeso PROC;

struct proceso{
	int PID;
	int llegada;
	int cantPaginas;
	int cantSegmentos;
	int memSegmentos;
	int tiempo;
	struct proceso *sig;

};

//variables
int semaforo = 0;
int procActivo;

int running = 0;
int ejecutando = 0;

int momento = 0;
int IDassign = 0;

//tipo de Manejo de Memoria ejegido
int tipoSimu; // 1.Paginacion / 2.Segmentacion

//lista de procesos Ready
struct proceso *raizReady=NULL;
struct proceso *fondoReady=NULL;

//funciones
int Vacia();
int CorrerSimulacion();
int CorrerProceso();
int CrearProceso();
int PedirMemoria();

int main() {
	running = 1;
	momento = 0;
	srand(time(NULL)); 
	//while(running){ //para probar
		printf("------\n");
		printf("Elija tipo de Manejo de Memoria:\n");
		printf("1. Paginación\n");
		printf("2. Segmentacion\n");
		printf(">> ");
		scanf("%d", &tipoSimu);
	//while(running){ //original
		if(tipoSimu == 1){
			printf("\nHas ejegido Paginación \n");
			CorrerSimulacion();
		}
		else if(tipoSimu == 2){
			printf("\nHas elegido Segmentación \n");
			CorrerSimulacion();
		}
		else{
			printf("XX opcion invalida XX\n\n");
		}
	//}

	return 0;
}

//devuelve 1 si esta la Fila Ready vacia y 0 si tiene elmentos
int Vacia(){
    if (raizReady == NULL)
        return 1;
    else
        return 0;
}

//SIMULACION
int CorrerSimulacion(){
	ejecutando = 1;
	while (ejecutando)
	{
		//Se crean procesos cada 30s - 60s
		//int tasaCreacion = (rand() % 30) + 31; 
		int tasaCreacion = (rand() % 3) + 7;  //for testing
		sleep(tasaCreacion);
		CorrerProceso(); // hacer thread aqui
		printf("proceso corriendo\n\n");

	}
	return 0;
	
}

int CorrerProceso(){
	int id = CrearProceso();
	//PedirSemaforo();
	if(PedirMemoria(id)){
		//log(); //Escribir bitacora
		//DevolvervSemaforo();
		//Ejecutar(id); //Esperar
		//PedirSemaforo();
		//LiberarMemoria();
		//log(); //Escribir bitacora
	}
	else {
		//lista de procesos que murieron por no encontrar espacio
		//log(); //Escribir bitacora
	}
	//DevolverSemaforo()
	return tipoSimu;
}

//CREAR PROCESOS
//Crea un proceso y lo inserta en la cola
int CrearProceso(){
	struct proceso *nuevo;
	nuevo= malloc(sizeof(struct proceso));
	nuevo->PID=IDassign;
	IDassign = IDassign+1;
	//Depende el tipo de Manejo, se dan los valores
	if(tipoSimu == 1){
		int cantPaginas = (rand() % 10) + 1;
		nuevo->cantPaginas=cantPaginas;
	}
	if(tipoSimu  == 2){
		int cantSegmentos = (rand() % 5) + 1;
		int memSegmentos = (rand() % 3) + 1;
		nuevo->cantSegmentos=cantSegmentos;
		nuevo->memSegmentos=memSegmentos;
	}
	int tiempo = (rand() % 40) + 21;
	nuevo->tiempo=tiempo;
	nuevo->sig=NULL;
	//la agrega a la lista de Ready
	if (Vacia())
	{
		raizReady = nuevo;
		fondoReady = nuevo;
	}
	else
	{
		fondoReady->sig = nuevo;
		fondoReady = nuevo;
	}
	return nuevo->PID;
}

int PedirMemoria(){

	return 0;
}



