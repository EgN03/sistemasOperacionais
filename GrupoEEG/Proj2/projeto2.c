/*Projeto 2 - Transferência Bancária 
Integrantes: 
Enrique Granado Novaes 32107803 
Enzo Rocha Damato 32125992
Gustavo Saad Andrade Maluhy*/

#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#define THREADS 100

int c1=100, c2=100, numero_thread[THREADS];
pthread_mutex_t transf;
pthread_t transferencias[THREADS];

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
	}else{
		printf("Transferência negada!\n");
	}
	printf("  Saldo de c1: %d\n", c1);
	printf("  Saldo de c2: %d\n", c2);
	pthread_mutex_unlock(&transf);
	return 0;
}

int main(int argc, void* args[])
{
	int i ,t=100;
	if(argc>1){
		t = atoi(args[1]);
		if(t>100){
			t=100;
		}
	}
	pthread_mutex_init(&transf,NULL);					//inicializa o espaco de memoria compartilhado
	
	for(i=0;i<t;i++){
		numero_thread[i] = i;
		pthread_create(&transferencias[i], NULL, &transferencia , (void *) &numero_thread[i]);
	}
	for(i=0;i<t;i++){											//espera o encerramento das threads
		pthread_join(transferencias[i],NULL);
		printf("Processo %d finalizado!\n",i);
	}
	
	
	printf("Saldo final de c1: %d\n", c1);
	printf("Saldo final de c2: %d\n", c2);
	return 0;
}
