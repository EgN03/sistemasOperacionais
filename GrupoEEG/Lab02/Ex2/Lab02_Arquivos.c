//Ex2 - Grupo EEG
#include <stdio.h>


int main() {
	FILE *fptr;
	char arquivo[100];
	char arquivoSaida[100];
	printf("Nome do arquivo que deseja abrir\n"); //Chamada 1
	scanf("%s", arquivo); //C 2
	printf("Nome do arquivo que deseja escrever\n");//C 3
	scanf("%s", arquivoSaida);//C 4

	fptr = fopen(arquivo, "r");//C 5
	if(fptr == NULL){
		printf("Nao foi possivel encontrar o arquivo %s",arquivo); //C 6
		return -1;
	}
	long tamanho;
	char *conteudo;
	fseek(fptr, 0L, SEEK_END); //C 7 
    tamanho = ftell(fptr); //C 8
    fseek(fptr, 0L, SEEK_SET);  //C 9
    conteudo = (char*)calloc(tamanho, sizeof(char));   
    
    
	fread(conteudo, sizeof(char), tamanho, fptr); //C 10
    fclose(fptr);//C 11
 
 	FILE *file;
 	file = fopen(arquivoSaida, "w");//C 12
    fprintf(file,"%s" ,conteudo); //C 13
    fclose(file);//C 14
    printf("Modificado com sucesso!");//C 15
	return 0;
	//Faz 15 chamadas no sistema.
}
