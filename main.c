#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <unistd.h>
#include <ctype.h>
#include <string.h>
#include <stdbool.h>

#define INFINITO 9999
#define MAX 16

//Prototipação
void dijkstra(int n, int Grafo[n][n], int partida, int chegada);
void menu();
void sobre();
int algoritmo();
void creditos();

int main()
{
    int n, partida, chegada;
    setlocale(LC_ALL, "Portuguese");
    menu();
    return 0;
}

void menu()
{
    while (1)
    {
        int digito;
        printf("\t\t  ----------------------------\n");
        printf("\t\t | ALGORITMO DO MENOR CAMINHO |\n");
        printf("\t\t  ----------------------------\n");
        printf("Pressione a tecla para executar a função correspondente:\n\n");
        printf("Digite (1) - INICIAR\n\n");
        printf("Digite (2) - SOBRE\n\n");
        printf("Digite (3) - CRÉDITOS\n\n");
        printf("Digite (0) - SAIR\n\n");
        scanf("%d", &digito);
        system("clear");

        if (digito == 1)
        {
            algoritmo();
        }
        else if (digito == 2)
        {
            sobre();
        }
        else if (digito == 3)
        {
            creditos();
        }
        else if (digito == 0)
        {
            system("clear");
            printf(" PROGRAMA ENCERRADO !\n");
            break;
        }
        else
        {
            printf("Valor incorreto, digite novamente!\n");
            sleep(1);
            system("clear");
        }
    }
}

void sobre()
{
    printf("O programa funciona com base no algoritmo de Dijkstra para\ndeterminar o menor caminho e a rota entre o usuario e o\nhospital determinado em um ponto fixo.\n\n\n");
    printf("Aperte a tecla ENTER para continuar...\n");
    getchar();
    getchar();
    system("clear");
}

void creditos()
{
    printf("Desenvolvedores :\n\n");
    printf("Gabriel Alves - gabriel.costa@uepb.aluno.edu.br\n\n");
    printf("José Carlos - jose.carlos@uepb.aluno.edu.br\n\n");
    printf("Klayton Marcos - klayton.junior@uepb.aluno.edu.br\n\n");
    printf("Lucas Henrique - lucas.pereira@uepb.aluno.edu.br\n\n\n");
    printf("Aperte a tecla ENTER para continuar...\n");
    getchar();
    getchar();
    system("clear");
}

int algoritmo(){
  int n, partida, chegada;

  n = 9;
  partida=-1;
    while (partida < 0 || partida > 8)
  {

    printf("Digite o ponto de partida entre 0 e 8:\n");
    scanf("%d", &partida);
    if (partida < 0 || partida > 8)
    {
      printf("Valor invalido, digite novamente !\n\n");
    }
  }

  system("clear");

  int G[n][n];

  G[0][0] = 0;
  G[0][1] = 135;
  G[0][2] = 0;
  G[0][3] = 0;
  G[0][4] = 0;
  G[0][5] = 0;
  G[0][6] = 0;
  G[0][7] = 145;
  G[0][8] = 0;

  G[1][0] = 135;
  G[1][1] = 0;
  G[1][2] = 135;
  G[1][3] = 0;
  G[1][4] = 0;
  G[1][5] = 0;
  G[1][6] = 0;
  G[1][7] = 0;
  G[1][8] = 145;

  G[2][0] = 0;
  G[2][1] = 135;
  G[2][2] = 0;
  G[2][3] = 145;
  G[2][4] = 0;
  G[2][5] = 0;
  G[2][6] = 0;
  G[2][7] = 0;
  G[2][8] = 0;

  G[3][0] = 0;
  G[3][1] = 0;
  G[3][2] = 145;
  G[3][3] = 0;
  G[3][4] = 145;
  G[3][5] = 0;
  G[3][6] = 0;
  G[3][7] = 0;
  G[3][8] = 135;

  G[4][0] = 0;
  G[4][1] = 0;
  G[4][2] = 0;
  G[4][3] = 145;
  G[4][4] = 0;
  G[4][5] = 135;
  G[4][6] = 0;
  G[4][7] = 0;
  G[4][8] = 0;
  
  G[5][0] = 0;
  G[5][1] = 0;
  G[5][2] = 0;
  G[5][3] = 0;
  G[5][4] = 135;
  G[5][5] = 0;
  G[5][6] = 135;
  G[5][7] = 0;
  G[5][8] = 145;

  G[6][0] = 0;
  G[6][1] = 0;
  G[6][2] = 0;
  G[6][3] = 0;
  G[6][4] = 0;
  G[6][5] = 135;
  G[6][6] = 0;
  G[6][7] = 145;
  G[6][8] = 0;

  G[7][0] = 145;
  G[7][1] = 0;
  G[7][2] = 0;
  G[7][3] = 0;
  G[7][4] = 0;
  G[7][5] = 0;
  G[7][6] = 145;
  G[7][7] = 0;
  G[7][8] = 135;

  G[8][0] = 0;
  G[8][1] = 145;
  G[8][2] = 0;
  G[8][3] = 135;
  G[8][4] = 0;
  G[8][5] = 145;
  G[8][6] = 0;
  G[8][7] = 135;
  G[8][8] = 0;

  chegada = 6;
  dijkstra(n, G, partida, chegada);
  return 0;
}

void dijkstra(int n, int Grafo[n][n], int partida, int chegada){
  int i, j;
  int custo[MAX][MAX];
  int distancia[MAX], anterior[MAX], proximo, menorDistancia; 
  bool visitado[MAX];
  
  //Imprimir MATRIZ
  printf("MATRIZ DO MAPA\n\n");

  for(i = 0; i < n; i++){
    printf("           ");
    for(j = 0; j < n; j++){
        printf("%d ", Grafo[i][j]);
    }
    printf("\n");
  }

  printf("\n\nAperte a tecla ENTER para continuar...\n");
  getchar();
  getchar();
  system("clear");

  //Setar matriz com zero no infinito.
  for(i = 0; i < n; i++){
    for(j = 0; j < n; j++){
      if(Grafo[i][j] == 0){
        custo[i][j] = INFINITO;
      } else {
        custo[i][j] = Grafo[i][j];
      }
    }
  }

  //Setar distância, anterior, visitado 
  for(i = 0; i < n; i++){
    distancia[i] = custo[partida][i];
    anterior[i] = partida; 
    visitado[i] = false;
    if(i == partida){
    distancia[partida] = 0;
    visitado[partida] = true;
    }
  }
          
  int cont = 0;
  while (cont < n-1){
    menorDistancia = INFINITO;
    //proximo nó e menor distancia
    for(i = 0; i < n; i++){
      if(visitado[i] == false && distancia[i] < menorDistancia){
        menorDistancia = distancia[i];
        proximo = i;
      }
    }

    visitado[proximo] = true;
    //Verificar Menor Caminho
    for(i = 0; i < n; i++){
      if(visitado[i] == false){
        if(menorDistancia + custo[proximo][i] < distancia[i]){
        distancia[i] = menorDistancia + custo[proximo][i];
        anterior[i] = proximo;
        }
      }
    }
    cont++;
  }

  int save[n];

  //Imprimir
  printf("\nA Menor Distancia de %d a %d = %d metros", partida, chegada, distancia[chegada]);
  save[0] = chegada;

  cont = 1;
  j=chegada;
  do
  {
  j=anterior[j];
  save[cont++] = j;
  }while(j!=partida);

  printf("\nCaminho = ");
  for(j = --cont; j >= 0; j--){
    if(j != 0){
      printf("%d->",save[j]);
    } else {
      printf("%d",save[j]);
    }
  }
  printf("\n");

  printf("\n\nAperte a tecla ENTER para voltar ao Menu ...\n");
  getchar();
  //getchar();
  system("clear");
}