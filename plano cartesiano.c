#include <stdio.h>
#include <stdlib.h>
#include <math.h>

struct pontos{
	int ponto_x;
	int ponto_y;
};

typedef struct pontos t_pontos;

void receber_pontos(t_pontos **pontos,int* );
void selecao_opcao(int opcao, t_pontos **pontos, int *quant_pontos);
void opcao_select(int *opcao);

int main(int argc, char const *argv[])
{
	int quant_pontos = 1;
	t_pontos *pontos = NULL;
	//receber_pontos(&pontos, &quant_pontos);
	int opcao;
	do{
	opcao_select(&opcao);
	selecao_opcao(opcao, &pontos, &quant_pontos);
	}while(opcao != 5);

	free(pontos);
	return 0;
}

void receber_pontos(t_pontos **pontos,int *quant_pontos){
	(*quant_pontos)++;//inclementa
	*pontos = (t_pontos*)realloc(*pontos,(*quant_pontos) * sizeof(t_pontos));
	
		if(*pontos == NULL){
			printf("erro de alocação");
			exit(1);
	}
		int i = *quant_pontos - 1;
		printf("digite o %i pontos x \n",i);
		scanf("%i",&(*pontos)[i].ponto_x);
		printf("digite o %i pontos y \n",i);
		scanf("%i",&(*pontos)[i].ponto_y);

	
};

void selecao_opcao(int opcao, t_pontos **pontos, int *quant_pontos){
	switch(opcao){
		case 1 :{
			receber_pontos(pontos, quant_pontos);
			break;
		   }
		case 2 :{
		   	remover_ponto();
		 	break;
		};
		case 5 :{
			printf("obrigado por usar o programa");
			break;
		}	
		default :{
			printf("opcao invalida");
			break;
		}
	}
};
void opcao_select(int *opcao){
	printf("bom dia!! bem vindo ao plano cartesiano digite a opcao\n");
	printf("1 - adicionar ponto\n");
	printf("2 - remover ponto\n");
	printf("3 - lista ponto\n");
	printf("4 - calcular distancia dos ponto\n");
	printf("5 - sair\n");
	scanf("%d",opcao);
};

void remover_ponto(){

};