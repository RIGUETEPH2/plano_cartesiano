#include <stdio.h>
#include <stdlib.h>

struct pontos
{
	int ponto_x;
	int ponto_y;
};
typedef struct pontos t_pontos;

void receber_pontos(t_pontos *pontos);

int main(int argc, char const *argv[])
{
t_pontos pontos;
receber_pontos(&pontos);
	return 0;
}
void receber_pontos(t_pontos *pontos){
	for (int i = 0; i < 3; ++i)
	{
		printf("digite o %i pontos x \n",i+1);
		scanf("%i",&pontos->ponto_x);
		printf("digite o %i pontos y \n",i+1);
		scanf("%i",&pontos->ponto_y);
	};
	
};