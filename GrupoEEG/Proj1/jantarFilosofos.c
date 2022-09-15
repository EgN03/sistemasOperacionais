#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>
#define F 5 													//numero de threads/filosofos que serão criadas

void pensa(int id){ 											//chamado quando o filosofo nao esta com fome
	int tempo = (rand()%3 +3);									//faz a thread dormir por um tempo aleatorio de 3 a 6 sec
	printf("\nFilosofo %d pensa por %d segundos\n",id,tempo);
	sleep(tempo);
}

void come(int id){												//chamado quando o filosofo esta com fome
	int tempo = (rand()%5 +3);									//faz a thread dormir por um tempo aleatorio de 3 a 8 sec
	printf("\nFilosofo %d come por %d segundos\n",id,tempo);
	sleep(tempo);
}

void pega_garfos(int* id){										//verifica se os garfos proximos estao livres, se nao espera ate ficarem
	pthread_mutex_lock(&garfos[(*id+1)%5]);						//entra na fila para acesso a memoria compartilhada
	pthread_mutex_lock(&garfos[(*id+4)%5]);

}
void solta_garfos(int* id){										//libera os garfos para o proximo filosofo
	pthread_mutex_unlock(&garfos[(*id+1)%5]);					//sai da fila da memoria compartilhada e deixa o proximo entrar
	pthread_mutex_unlock(&garfos[(*id+4)%5]);

}


int main (void) {
	
	return 0;
}
