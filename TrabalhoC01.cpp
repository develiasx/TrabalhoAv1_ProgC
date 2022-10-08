#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <locale.h>
#include <cstring>

//Struct Produto
struct Produto{
	char nome[50];
	int codProd;
	int quantidade;
};

Produto produto;

int fazerpedido();
int altpedido();
int conspedido();
int telaPrincipal();

//Tela Principal Aplicativo
int main(void){
	setlocale(LC_ALL, "Portuguese");
	telaPrincipal();
}
//Função Cardapio 
int fpedido(){
	int option;
	int ref;
	printf("------------ CARDAPIO --------------\n");
	printf("| 1 - Refeições | 2 - Tiragosto    |\n");
	printf("| 3 - Bebidas   | 4 - Voltar       |\n");
	printf("------------------------------------\n\n");
	printf("Escolha a opção que você deseja fazer o pedido: ");
	scanf("%d", &option);
	system("cls");
	switch (option){
		case 1: {
			printf("---------- CARDAPIO ----------\n");
			printf("| 1 - Frango ao molho          |\n");
			printf("-------------------------------\n");
			printf("| 2 - Feijoada                 |\n");
			printf("-------------------------------\n");
			printf("| 3 - Panqueca                 |\n");
			printf("-------------------------------\n");
			printf("| 4 - Feijão Tropeiro          |\n");
			printf("-------------------------------\n");
			printf("Escolha uma Refeição: ");
			scanf("%d", &ref);
			printf("Informe a quantidade: ");
			scanf("%d", &produto.quantidade);
			if(ref == 1){
				strcpy(produto.nome, "Frango ao molho");
			}else if(ref == 2){
				strcpy(produto.nome, "Feijoada");
			}else if(ref == 3){
				strcpy(produto.nome, "Panqueca");
			}else if(ref == 4){
				strcpy(produto.nome, "Feijão Tropeiro");
			}else{
				printf("Escolha uma opção válida!");
				return fpedido();
			}
			printf("\nVocê escolheu o item: %s/quantidade: %d\n", produto.nome, produto.quantidade);
			return fpedido();
			break;
		}
