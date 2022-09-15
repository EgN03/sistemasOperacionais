/* Grupo EEG - 4N
Enrique Granado 32107803
Enzo Damato 32125992
Gustavo Saad 32173091 */

#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#define F 5 													//numero de threads/filosofos que serão criadas

pthread_mutex_t garfos[F]; 										//alocando a area de memoria compartilhada
pthread_t filosofos[F]; 										// lista de threads/filosofos
int ids[F]; 

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


void* filosofo(void* i){										//"construtor" do filosofo, controla suas acoes
	int *id = (int*) i;
	sleep(1);
	while(1){
		pensa(*id);
		pega_garfos(id);
		come(*id);
		solta_garfos(id);
	}
	
}

int main (void) {
	int i;
	for(i=0;i<F;i++){
		pthread_mutex_init(&garfos[i],NULL);					//inicializa o espaco de memoria compartilhado
	}
	for(i=0;i<F;i++){
		ids[i]=i;												//cria as threads e informa seus ids
		pthread_create(&filosofos[i], NULL, &filosofo ,(void *) &ids[i]);
		printf("sou o #%d a chegar para jantar\n",i);
	}
	for(i=0;i<F;i++){											//espera o encerramento das threads
		pthread_join(filosofos[i],NULL);
	}
	
	return 0;
}
