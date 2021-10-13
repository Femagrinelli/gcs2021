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
	printf("Insira a identificação da nova solitação de mudança: ");
	gets(mudanca->identificacao);
}

void produto(SM *mudanca){
	printf("Insira o produto da nova solitação de mudança: ");
	gets(mudanca->produto);
}

void relato(SM *mudanca){
	printf("Insira o relato referente à solitação de mudança: ");
	gets(mudanca->relato);
}

void responsaveis(SM *mudanca){
	printf("Insira o responsável por receber a solitação de mudança: ");
	gets(mudanca->responsavelReceber);
	printf("Insira o responsável pela solicitação(cliente): ");
	gets(mudanca->responsavelRequisitante);
}

void decisao(SM *mudanca){
	bool quebrar = false;
	do{
		printf("Insira a decisão tomada em relação à solitação de mudança[aprovada/reprovada]: ");
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
	printf("\nIdentificação: %s\n", mudanca->identificacao);
	printf("Produto: %s\n", mudanca->produto);
	printf("Relato: %s\n", mudanca->relato);
	printf("Responsável a receber: %s\n", mudanca->responsavelReceber);
	printf("Requisitante: %s\n", mudanca->responsavelRequisitante);
	if(mudanca->decisao){
		printf("Decisão: Aprovada");
	}
	else if(!mudanca->decisao){
		printf("Decisão: Reprovada");
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
