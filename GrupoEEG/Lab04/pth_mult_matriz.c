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

void *Pht_mat_vect(void* rank){
	long my_rank = (long) rank;
	int i, j;
	int local_m =  m/thread_count;
	int my_first_row = my_rank*local_m
	int my_last_row = (my_rank+1)*local_m -1;
	
	for(i = my_first_row; i <= my_last_row; i++){
		y[i] = 0.0;
		for(j = 0; j<n; j++)
			y[i] += A[i][j]*x[j];
	}
	return NULL
} /*Pth_mat_vect */
