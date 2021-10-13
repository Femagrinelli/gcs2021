#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <string.h>
#include <ctype.h>

typedef struct solitacaoMudanca{
	char identificacao[50];
	char produto[50];
	char relato[100];
	char responsavelRequisitante[50];
	char responsavelReceber[50];
	bool decisao;
}SM;

void identificacao(SM *mudanca){
	printf("Insira a identifica��o da nova solita��o de mudan�a: ");
	gets(mudanca->identificacao);
}

void produto(SM *mudanca){
	printf("Insira o produto da nova solita��o de mudan�a: ");
	gets(mudanca->produto);
}

void relato(SM *mudanca){
	printf("Insira o relato referente � solita��o de mudan�a: ");
	gets(mudanca->relato);
}

void responsaveis(SM *mudanca){
	printf("Insira o respons�vel por receber a solita��o de mudan�a: ");
	gets(mudanca->responsavelReceber);
	printf("Insira o respons�vel pela solicita��o(cliente): ");
	gets(mudanca->responsavelRequisitante);
}

void decisao(SM *mudanca){
	bool quebrar = false;
	do{
		printf("Insira a decis�o tomada em rela��o � solita��o de mudan�a[aprovada/reprovada]: ");
		char decisao[15];
		fflush(stdin);
		scanf("%s", &decisao);
		printf("%s", decisao);
		if(strcmp(decisao, "aprovada") == 0){
			mudanca->decisao = true;
			quebrar = true;
		}else if(strcmp(decisao, "reprovada") == 0){
			mudanca->decisao = false;
			quebrar = true;
		}
	}while(quebrar != true);
}

void mostrar(SM *mudanca)
{
	printf("\nIdentifica��o: %s\n", mudanca->identificacao);
	printf("Produto: %s\n", mudanca->produto);
	printf("Relato: %s\n", mudanca->relato);
	printf("Respons�vel a receber: %s\n", mudanca->responsavelReceber);
	printf("Requisitante: %s\n", mudanca->responsavelRequisitante);
	if(mudanca->decisao){
		printf("Decis�o: Aprovada");
	}
	else if(!mudanca->decisao){
		printf("Decis�o: Reprovada");
	}
}

int main(){
	setlocale(LC_ALL, "Portuguese");
	SM mudanca;
	identificacao(&mudanca);
	produto(&mudanca);
	relato(&mudanca);
	responsaveis(&mudanca);
	decisao(&mudanca);
	mostrar(&mudanca);
	return 0;
}
