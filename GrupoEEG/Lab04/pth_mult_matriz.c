/*Grupo EEG
Lab 03 - Pthread

Compilar o programa:
	gcc -g -Wall -o pth_mult_matriz  pth_mult_matriz.c -lpthread 
Executando o programa: 
	./pth_mult_matriz <num de threads>
*/

#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

#define M 3  //numero de linha de A e Y
#define N 2  // numero de colunas de B e Y
#define K 4  // numero de colunas de A e linhas de B
#define thread_count 3 //numero de threads

int A[M][K] ={{4,6,2,8}, {7,4,2,7}, {9,0,2,6}};
int B[K][N] ={{8,2}, {6,6}, {1,0}, {9,3}};
int C[M][N];
int y[M];

void imprimeMatriz(int linhas, int colunas, int matriz[linhas][colunas]){ //funcao para imprimir as matrizes
	int lin,col;
	for(lin=0;lin<linhas;lin++){
		for(col=0;col<colunas;col++){
			printf("%d ", matriz[lin][col]);
		}
		printf("\n");
	}
}

void *Pht_mat_vect(void* rank){ // funcao para calcular cada linha da matriz C
	long my_rank = (long) rank; // liga uma linha da matriz C a thread atual
	int i, j;

	for(i = 0; i < N; i++){ // roda para todas as colunas de B
		for(j = 0; j<K; j++) // roda para todas as linhas de B
			C[my_rank][i] += A[my_rank][j]*B[j][i]; // calcula cada valor de sua linha
	}
	return NULL;
} /*Pth_mat_vect */


int main(void){
	long thread;
	pthread_t threads[thread_count]; // separa a memoria para as threads

	printf("vetor A:\n");
	imprimeMatriz(M,K,A);
	
	printf("\nvetor B:\n");
	imprimeMatriz(K,N,B);
	
	for(thread =0; thread<thread_count; thread++){
		pthread_create(&threads[thread], NULL, Pht_mat_vect, (void*) thread); // inicializa cada thread e passa a linha ligada a ela
	}
	
	for(thread =0; thread<thread_count; thread++){
		pthread_join(threads[thread], NULL); // encerra as threads
	}
	
	printf("\nvetor C:\n");
	imprimeMatriz(M,N,C);
	
}
