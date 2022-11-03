/*Projeto 2 - Transferência Bancária 
Integrantes: 
Enrique Granado Novaes 32107803 
Enzo Rocha Damato 32125992
Gustavo Saad Andrade Maluhy*/

/*#define _GNU_SOURCE
#include <stdlib.h>
#include <malloc.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <signal.h>
#include <sched.h>
#include <stdio.h>*/
// 64kB stack

#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#define THREADS 100

int c1=100, c2=100;
pthread_mutex_t transf;
pthread_t transferencias[THREADS];
int valor;
// The child thread will execute this function

void *transferencia(void *i)
{
	pthread_mutex_lock(&transf);
	int *num = (int*) i;
	printf("tranferencia de numero #%d:\n",*num);
	int conta = rand()%2 +1;
	int valor = rand()%100 +1;
	int *from,*to;
	if(conta == 1){
		from = &c1;
		to = &c2;
		printf("  conta c1 transfere %d para conta c2\n", valor);
	}else{
		from = &c2;
		to = &c1;
		printf("  conta c2 transfere %d para conta c1\n", valor);
	}
	if (*from >= valor){ // 2
		*from -= valor;
		*to += valor;
		printf("  Transferência concluida com sucesso!\n");
	}else{
		printf("Transferência negada!\n");
	}
	printf("  Saldo de c1: %d\n", c1);
	printf("  Saldo de c2: %d\n", c2);
	printf("Processo finalizado!\n");
	pthread_mutex_unlock(&transf);
	return 0;
}

int main()
{
	int i;
	pthread_mutex_init(&transf,NULL);					//inicializa o espaco de memoria compartilhado
	
	for(i=0;i<THREADS;i++){
		pthread_create(&transferencias[i], NULL, &transferencia , (void *) &i);
	}
	for(i=0;i<THREADS;i++){											//espera o encerramento das threads
		pthread_join(transferencias[i],NULL);
	}
	
	
	printf("Saldo final de c1: %d\n", c1);
	printf("Saldo final de c2: %d\n", c2);
	return 0;
}
