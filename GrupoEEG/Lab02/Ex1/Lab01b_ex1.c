/*Lab01b_Exercício 1 - Grupo EEG
Links utilizados de apoio:
	https://www.ime.usp.br/~pf/algoritmos/aulas/io.html
	https://guialinux.uniriotec.br/chamadas-de-sistema/
*/

#include<stdio.h>
#include<string.h>
#include<stdlib.h>

int main(void){
	FILE* ex1; //Ponteiro com tipo FILE. 
	ex1=fopen("exercicio1.txt","r"); //Guarda numa variável o txt lido("r" é para leitura e "w" para escrita). CHAMADA 1 
	if (ex1 == NULL) { //Verifica se existe arquivo.
      printf ("\nArquivo? Não há nenhum!\n"); //CHAMADA 2
      exit (EXIT_FAILURE);}
    char arquivo1;
    while((arquivo1=fgetc(ex1)) != EOF){ //Se o arquivo não tiver mais bytes, getc devolve a constante  EOF.
    	printf("%c", arquivo1); //CHAMADA 3 
	}
	fclose(ex1);
	//Ocorrem 3 chamadas de sistemas ao SO. Linhas 8,10 e 14.
}

