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
	         case 2:{
			int deg;
			printf("---------- CARDAPIO ----------\n");
			printf("| 1 - Enrolado de Presunto  |\n");
			printf("-----------------------------\n");
			printf("| 2 - Coxinha de Camarão    |\n");
			printf("-----------------------------\n");
			printf("| 3 - Baurú                 |\n");
			printf("-----------------------------\n");
			printf("| 4 - Bomba de calabresa    |\n");
			printf("-----------------------------\n");
			printf("Escolha uma Refeição: ");
			scanf("%d", &deg);
			printf("Digite a quantidade: ");
			scanf("%d", &produto.quantidade);
			if(deg == 1){
				strcpy(produto.nome, "Enrolado de Presunto");
			}else if(deg == 2){
				strcpy(produto.nome, "Coxinha de Camarão");
			}else if(deg == 3){
				strcpy(produto.nome, "Baurú");
			}else if(deg == 4){
				strcpy(produto.nome, "Bomba de calabresa");
			}else{
				printf("Escolha uma opção válida!");
				return fpedido();
			}
			printf("\nVocê Escolheu o item: %s/quantidade: %d\n", produto.nome, produto.quantidade);
			return fpedido();
			break;
		}
		 case 3:{
			int optionDrink;
			printf("---------- CARDAPIO ----------\n");
			printf("| 1 - Guaraná Jesus      |\n");
			printf("-----------------------------\n");
			printf("| 2 - Suco de Tamarindo  |\n");
			printf("-----------------------------\n");
			printf("| 3 - Guaraná da Amazônia|\n");
			printf("-----------------------------\n");
			printf("| 4 - Água Saborizada    |\n");
			printf("-----------------------------\n");
			printf("| 5 - Voltar             |\n");
			printf("-----------------------------\n");
			printf("Escolha uma opção válida: ");
			scanf("%d", &optionDrink);
			system("cls");
			printf("Informe a quantidade: ");
			scanf("%d", &produto.qtd);
			if(optionDrink == 1){
				strcpy(produto.nome, "Guaraná Jesus");
			}
			else if(optionDrink == 2){
				strcpy(produto.nome, "Suco de Tamarindo");
			}
			else if(optionDrink == 3){
				strcpy(produto.nome, "Guaraná da Amazônia");
			}
			else if(optionDrink == 4){
				strcpy(produto.nome, "Água Saboriza");
			}
			else if(optionDrink == 5){
				return fpedido();
			}else{
				printf("Escolha uma opção válida!");
				return fpedido();
			}

			printf("\nVocê adicionou o item: %s com a quantidade de %d\n", produto.nome, produto.qtd);
			return fpedido();
			break;
   }
		case 4: {
			telaPrincipal();
			break;
		}	
	}
	
	return 0;
}

//Função de criação de alteração do pedido
int alterpedido(){
	printf("Alterar pedido");

}
