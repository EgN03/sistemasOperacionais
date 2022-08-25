#include <stdio.h>



int main() {
	FILE *fptr;
	char arquivo[100];
	char arquivoSaida[100];
	printf("Nome do arquivo que deseja abrir\n");
	scanf("%s", arquivo);
	printf("Nome do arquivo que deseja escrever\n");
	scanf("%s", arquivoSaida);

	fptr = fopen(arquivo, "r");
	if(fptr == NULL){
		printf("Nao foi possivel encontrar o arquivo %s",arquivo);
		return -1;
	}
	long tamanho;
	char *conteudo;
	fseek(fptr, 0L, SEEK_END);
    tamanho = ftell(fptr);
    fseek(fptr, 0L, SEEK_SET);  
    conteudo = (char*)calloc(tamanho, sizeof(char));   
    
    
	fread(conteudo, sizeof(char), tamanho, fptr);
    fclose(fptr);
 
 	FILE *file;
 	file = fopen(arquivoSaida, "w");
    fprintf(file,"%s" ,conteudo); 
	return 0;
}
