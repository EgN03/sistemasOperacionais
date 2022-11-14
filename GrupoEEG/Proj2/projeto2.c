/*Projeto 2 - Transferência Bancária 
Integrantes: 
Enrique Granado Novaes 32107803 
Enzo Rocha Damato 32125992
Gustavo Saad Andrade Maluhy 32173091*/

#include <stdio.h>  
#include <stdlib.h>
#include <pthread.h>
#define THREADS 100    //define numero maximo de threads como 100

int c1=100, c2=100, numero_thread[THREADS];	//inicia as duas contas com 100 reais, e cria o array do numero de marcacao das threads
pthread_mutex_t transf;	//define o mutex que sera usado como condicao de corrida
pthread_t transferencias[THREADS];//define o array de threads

void *transferencia(void *i)//codigo que sera execultado por cada thread
{
	pthread_mutex_lock(&transf);//bloqueia o mutex, impedindo outras threads de acessarem as contas
	int *num = (int*) i;
	printf("tranferencia de numero #%d:\n",*num);
	int conta = rand()%2 +1;//decide qual conta ira transferir
	int valor = rand()%100 +1;//decide o valor da transferencia
	int *from,*to;
	if(conta == 1){//conta a trnsferir é c1
		from = &c1;
		to = &c2;
		printf("  conta c1 transfere %d para conta c2\n", valor);
	}else{//conta a trnsferir é c2
		from = &c2;
		to = &c1;
		printf("  conta c2 transfere %d para conta c1\n", valor);
	}
	if (*from >= valor){ // verifica se há saldo e faz a tranferencia
		*from -= valor;
		*to += valor;
	}else{
		printf("Transferência negada!\n");
	}
	printf("  Saldo de c1: %d\n", c1);
	printf("  Saldo de c2: %d\n", c2);
	pthread_mutex_unlock(&transf);//libera o acesso as contas
	return 0;
}

int main(int argc, void* args[])
{
	int i ,t=THREADS;//numero de threads a serem criadas
	if(argc>1){//verifica se foi especificado um numero de threads
		t = atoi(args[1]);
		if(t>THREADS){//verifica se é um numero valido
			t=THREADS;
		}
	}
	pthread_mutex_init(&transf,NULL);//inicializa o espaco de memoria compartilhado
	
	for(i=0;i<t;i++){ //ira inicializar o numero de threads especificado
		numero_thread[i] = i; // informa o numero referente a thread
		pthread_create(&transferencias[i], NULL, &transferencia , (void *) &numero_thread[i]);//inicializa a thread
	}
	for(i=0;i<t;i++){//encerra as threads
		pthread_join(transferencias[i],NULL);
		printf("Processo %d finalizado!\n",i);
	}
	
	
	printf("Saldo final de c1: %d\n", c1);
	printf("Saldo final de c2: %d\n", c2);
	return 0;
}
