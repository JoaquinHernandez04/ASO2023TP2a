#include <pthread.h> 
#include <stdio.h> 
#include <stdlib.h> 
#define NUMBER_OF_THREADS 2
#define CANTIDAD_INICIAL_HAMBURGUESAS 20
int cantidad_restante_hamburguesas = CANTIDAD_INICIAL_HAMBURGUESAS; 

int turno = 0;
int siguienteTurno(){
	if(turno == NUMBER_OF_THREADS-1){
		turno = 0;
	} else {
		turno++;
	}
}

void *comer_hamburguesa(void *tid) {
	 
while(1 == 1){ //repetir infinitamente hasta que fuerce la terminacion del hilo con pthread_exit
	if (cantidad_restante_hamburguesas > 0) {

		while(turno == tid){
			printf("Hola! soy el hilo(comensal) %d , me voy a comer una hamburguesa ! ya que todavia queda/n %d \n",tid, cantidad_restante_hamburguesas);
			cantidad_restante_hamburguesas--; //me como una hamburguesa
			siguienteTurno();
		}


	//}
	} else
	{
	printf("SE TERMINARON LAS HAMBURGUESAS :( \n"); 
	pthread_exit(NULL); //forzar terminacion del hilo
	}

}

}

int main(int argc, char *argv[]) { 
	pthread_t threads[NUMBER_OF_THREADS]; 
	int status,i,ret ; 
	for(int i=0; i < NUMBER_OF_THREADS; i++) { 
		printf("Hola!, soy el hilo principal. Estoy creando el hilo %d \n", i); 
		status = pthread_create(&threads[i], NULL, comer_hamburguesa, (void *)i); 
		if (status != 0) { 
		printf("Algo salio mal, al crear el hilo recibi el codigo de error %d \n", status);
		exit(-1); 
		} 
	} 

	for (i= 0; i < NUMBER_OF_THREADS; i++) {
        void *retval;
        ret = pthread_join(threads[i], &retval); //espero por la terminacion de los hilos que cree
        }
        pthread_exit(NULL); //como los hilos que cree ya terminaron de ejecutarse, termino yo tambien.

} 
