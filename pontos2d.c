#include <stdio.h>
#include <stdlib.h>
#include <math.h>

struct pontos_2D{
    int x;
    int y;
};

typedef struct pontos_2D t_pontos_2D;//dando nome curto para a struct

struct controle_pontos2D
{
  t_pontos_2D* pontos_2D; //ponteiro na qual aponta para a primeira struct
  int quantidade; //controle de quantidade de pontos
};

typedef struct controle_pontos2D t_controle_pontos;

void imprimir_menu();//imprimir menu
void seletor_de_opcao(int*);//opçao do menu
void processar_e_direcionar_funcionalidade_opcao(t_controle_pontos*,int);//declarar struct como um ponteiro
void inicializar(t_controle_pontos*);//inicializo a struct pontos_2d e int quantidade
void cadastrar(t_controle_pontos*);
void listar_opcao(t_controle_pontos*);
void alterar_opcao(t_controle_pontos*);
void calcular_distancia(t_controle_pontos*);

int main(int argc, char **argv)
{
  t_controle_pontos controle_pontos2D;
  //inicializar
   inicializar(&controle_pontos2D);
  int opcao;

  do{
    imprimir_menu();
    seletor_de_opcao(&opcao);
    processar_e_direcionar_funcionalidade_opcao(&controle_pontos2D ,opcao);//passando parametros
     
  }while(opcao != 0);


  return (0);
};

void imprimir_menu(){
  printf("0 - sair do programa \n");
  printf("1 - cadastrar ponto 2D \n");
  printf("2 - listar pontos 2D \n");
  printf("3 - excluir ponto 2D \n");
  printf("4 - alterar ponto 2D \n");
  printf("5 - calcular distancia de um ponto ao outro\n");
  printf("digite sua opcao: \n");
}

void seletor_de_opcao(int *opcao){
  scanf("%i", opcao);
};

void processar_e_direcionar_funcionalidade_opcao(t_controle_pontos *controle_pontos2D, int opcao){
   switch(opcao){
    case 0 :
      printf("saindo do programa");
      break;
    case 1 : 
     cadastrar(controle_pontos2D);
      break;
    case 2 :
      listar_opcao(controle_pontos2D);
      break;
    /*case 3 :
      excluir_opcao(controle_pontos2D);
      break;*/
    case 4 :
     alterar_opcao(controle_pontos2D);
      break;
    case 5 :
      calcular_distancia(controle_pontos2D);
      break;
    default:
      printf("voce digitou uma opcao invalida\n");
  };
}

void cadastrar(t_controle_pontos *controle_pontos2D){
 t_pontos_2D pontos_2D;
 printf("DIGITE OS PARES CARDEAIS\n");
 printf(" INFORME O PONTO X \n");
 scanf("%i",&pontos_2D.x);
 printf(" INFORME O PONTO Y\n");
 scanf("%i",&pontos_2D.y);

controle_pontos2D->pontos_2D[controle_pontos2D->quantidade++] = pontos_2D;
controle_pontos2D->pontos_2D = (t_pontos_2D*) realloc(controle_pontos2D->pontos_2D,(controle_pontos2D->quantidade + 1 ) * sizeof(t_pontos_2D));
};

void listar_opcao(t_controle_pontos *controle_pontos2D){
for (int i = 0; i < controle_pontos2D->quantidade; ++i)
{
  printf("\n%i\n(%i,%i)\n\n",i+1,controle_pontos2D->pontos_2D[i].x,controle_pontos2D->pontos_2D[i].y);
}
   
};
/*
void excluir_opcao(){
   
};
*/
void alterar_opcao(t_controle_pontos *controle_pontos2D){
int contador;
printf("digite qual numero vc quer alterar em posicao ordinal\n");
scanf("%i", &contador);
for (int i = 0; i < controle_pontos2D->quantidade; ++i)

if(i == contador -1){
  printf("voce vai alterar o par ordenado (%i,%i)\n",controle_pontos2D->pontos_2D[(contador-1)].x,controle_pontos2D->pontos_2D[(contador-1)].y);
  printf("digite o novo valor de x\n");
  scanf("%i", &controle_pontos2D->pontos_2D[(contador-1)].x);
  printf("digite o novo valor para y\n");
  scanf("%i", &controle_pontos2D->pontos_2D[(contador-1)].y);
}
   
};

void calcular_distancia(t_controle_pontos *controle_de_pontos2D){
  float posicao_x1;
  float posicao_y1;
  float posicao_x2;
  float posicao_y2;
  int ponto1,ponto2;
  float x;
  printf("vamos calcular a distancia de dois pontos 2D\n");
  printf("digite a posicao ordenal do primeiro ponto\n");
  scanf("%i",&ponto1);
  printf("digite a posicao ordenal do segundo ponto\n");
  scanf("%i",&ponto2);
  
  posicao_x1 = controle_de_pontos2D->pontos_2D[ponto1-1].x;
  posicao_y1 = controle_de_pontos2D->pontos_2D[ponto1-1].y;

  posicao_x2 = controle_de_pontos2D->pontos_2D[ponto2-1].x;
  posicao_y2 = controle_de_pontos2D->pontos_2D[ponto2-1].y;

float poteciar_x = pow(posicao_x2 - posicao_x1, 2); // (x2 - x1)^2
float poteciar_y = pow(posicao_y2 - posicao_y1, 2); // (y2 - y1)^2
 x = (poteciar_x + poteciar_y);
float calculo_2d = sqrt(x); 

printf("a distancia de dois pontos e %f\n",calculo_2d);
}
void inicializar(t_controle_pontos *controle_de_pontos2D){
   controle_de_pontos2D->quantidade = 0;// inicializei com 0;
   controle_de_pontos2D->pontos_2D =(t_pontos_2D*) malloc(sizeof(t_pontos_2D)); //
}