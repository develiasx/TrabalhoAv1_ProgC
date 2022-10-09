#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <locale.h>
#include <string.h>

//Struct Produto
typedef struct
{
	char nome[50];
	int codProd;
	int quantidade;
	float valor;
} Produto[10];

typedef struct entrada{
	char index[50];
} ;

typedef struct
{
	char nome[50];
	int codProd;
	int quantidade;
	float valor;
} Produto2[10];

typedef struct
{
	char nome[50];
	int codProd;
	int quantidade;
	float valor;
} Produto3[10];

struct tm *timeinfo;

Produto produto;
Produto2 produto2;
Produto3 produto3;

int realizarpedido();
int bebidas();
int sobremesas();
int alterarpedido();
int consultarpedido();
int telaPrincipal();

//Tela Principal Lanchonete
int telaPrincipal(){
	int choice;
	printf("\n\n------------------ 70LANCHES --------------\n");
	printf("| 1 - Realizar Pedido  | 2 - Alterar Pedido   |\n");
	printf("| 3 - Consultar Pedido | 4 -Finalizar Processo|\n");
	printf("-----------------------------------------------\n");
	printf("Escolha uma opcao: ");
	scanf("%d", &choice);
	if(choice < 1 || choice > 4){
		system("cls");
		printf("\n>>Informe uma opcao valida\n\n");
		telaPrincipal();
	}
	switch(choice){
		case 1: {
			system("cls");
			rpedido();
			break;
		}
		case 2: {
			system("cls");
			alterpedido();
			break;
		}
		case 3: {
			system("cls");
			consulpedido();
			break;
		}
		case 4: {
			float totalC = 0;
			float totalC2 = 0;
			float totalC3 = 0;
			int i;
			for (i = 0; i < 10; i++)
			{
				totalC += produto[i].valor;
				totalC2 += produto2[i].valor;
				totalC3 += produto3[i].valor;

			}
	
			system("cls");
			printf("Finalizando pedido...\n");
			printf("Horario de inicio da comanda: %02d:%02d:%02d\n", timeinfo->tm_hour, timeinfo->tm_min, timeinfo->tm_sec);

			struct tm *timeinfo2;
			time_t time2;
			time2 = time(NULL);
			
			timeinfo2 = localtime(&time2);
			printf("Horario de fim da comanda: %02d:%02d:%02d\n\n", timeinfo2->tm_hour, timeinfo2->tm_min, timeinfo2->tm_sec);
			printf("Valor total do pedido: %.2f\n\n", totalC + totalC2 + totalC3);
			system("PAUSE");
			return 0;
			break;
		}
	}
}

int main(void){

	time_t time2;
	time2 = time(NULL);
	//printf("%d", &time);
	
	timeinfo = localtime(&time2);
	
	printf("%02d:%02d:%02d", timeinfo->tm_hour, timeinfo->tm_min, timeinfo->tm_sec);

	/* time_t tempo;
	time (&tempo);
	struct tm *tempo = gmtime(&tempo);
	printf("%d", tempo -> tm_hour ); */


	setlocale(LC_ALL, "Portuguese");
	telaPrincipal();
}


//Função Realizar Pedido
int rpedido(){
	int option;
	int k;
	int lan;
	int i = 0;
	printf("------------ CARDAPIO 70LANCHES --------------\n");
	printf("| 1 - Sanduiches| 2 - Sobremesas  |\n");
	printf("| 3 - Bebidas   | 4 - Voltar       |\n");
	printf("------------------------------------\n\n");
	printf("Escolha a opcoes que voce deseja fazer o pedido: ");
	scanf("%d", &option);
	if(option < 1 || option > 4){
		system("cls");
		rpedido();
	}
	system("cls");
	switch (option){
		case 1: {
			for(i = 0; i < 10; i++){
				printf("---------- CARDAPIO 70LANCHES ----------\n");
				printf("| 1 - X-Tudo                  | Valor: R$15,00|\n");
				printf("-------------------------------\n");
				printf("| 2 - X-Salada                | Valor: R$13,00|\n");
				printf("-------------------------------\n");
				printf("| 3 - Duplo-Frango            | Valor: R$16,00|\n");
				printf("-------------------------------\n");
				printf("| 4 - X-Bacon                 | Valor: R$18,00|\n");
				printf("-------------------------------\n");
				printf("Escolha uma Sanduiche: ");
				scanf("%d", &lan);
				printf("Informe a quantidade: ");
				scanf("%d", &produto[i].quantidade);
				if(lan == 1){
					strcpy(produto[i].nome, "X-Tudo");
					produto[i].valor = 15.00 * produto[i].quantidade;
					produto[i].codProd = i;
				}else if(lan == 2){
					strcpy(produto[i].nome, "X-Salada");
					produto[i].valor = 13.00 * produto[i].quantidade;
					produto[i].codProd = i;
				}else if(lan == 3){
					strcpy(produto[i].nome, "Duplo-Frango");
					produto[i].valor = 16.00 * produto[i].quantidade;
					produto[i].codProd = i;
				}else if(lan == 4){
					strcpy(produto[i].nome, "X-Bacon");
					produto[i].valor = 18.00 * produto[i].quantidade;
					produto[i].codProd = i;
				}else{
					system("cls");
					printf("Escolha uma opcao valida!");
					return rpedido();
				}
				printf("\nVocê escolheu o item: %s/quantidade: %d\n", produto[i].nome, produto[i].quantidade);
				printf("[1] - Voltar | [2] - Pedir outro produto\n");
				scanf("%d", &k);
				system("cls");
				fflush(stdin);
				if(k == 1 || k != 2){
					telaPrincipal();
					return;
				}
			}
			
			return rpedido();
			break;
		}
		
		case 2:{
			sobremesas();
			break;
		}
		
		case 3: {
			bebidas();
			break;
		}
		
		case 4: {
			telaPrincipal();
			break;
		}	
	}
	
	return 0;
}

int bebidas(){
	int Drink;
	int i;
	int k;
			for(i = 0; i < 10; i++){
				printf("---------- CARDAPIO 70LANCHES ----------\n");
				printf("| 1 - Coca-Cola              | Valor: R$8,00  |\n");
				printf("-----------------------------\n");
				printf("| 2 - Guarana-Antartica      | Valor: R$7,00  |\n");
				printf("-----------------------------\n");
				printf("| 3 - Fanta-Laranja          | Valor: R$7,00  |\n");
				printf("-----------------------------\n");
				printf("| 4 - Agua 250ml             | Valor: R$3,00  |\n");
				printf("-----------------------------\n");
				printf("Escolha uma Bebida: ");
				scanf("%d", &Drink);
				printf("Informe a quantidade: ");
				scanf("%d", &produto3[i].quantidade);
				if(Drink < 1 || Drink > 4){
					printf("Opcao invalida\n");
					bebidas();
				}
				else if(Drink == 1){
					strcpy(produto3[i].nome, "Coca-Cola");
					produto3[i].valor = 8.00 * produto3[i].quantidade;
					produto3[i].codProd = i;
				}else if(Drink == 2){
					strcpy(produto3[i].nome, "Guarana-Antartica");
					produto3[i].valor = 7.00 * produto3[i].quantidade;
					produto3[i].codProd = i;
				}else if(Drink == 3){
					strcpy(produto3[i].nome, "Fanta-Laranja");
					produto3[i].valor = 7.00 * produto3[i].quantidade;
					produto3[i].codProd = i;
				}else if(Drink == 4){
					strcpy(produto3[i].nome, "Agua 250ml");
					produto3[i].valor = 3.00 * produto3[i].quantidade;
					produto3[i].codProd = i;
				}
				else{
					system("cls");
					printf("Escolha uma opcao valida!");
					rpedido();
					return;
				}
				printf("\nVocê escolheu o item: %s/quantidade: %d\n", produto3[i].nome, produto3[i].quantidade);
				printf("[1] - Voltar | [2] - Pedir outro produto\n");
				scanf("%d", &k);
				system("cls");
				fflush(stdin);
				if(k == 1 || k!= 2){
					telaPrincipal();
					return;
				}
			}
			
			return rpedido();
}

int sobremesas(){
			int sob;
			int i;
			int k;
			
			for(i = 0; i < 10; i++){
				printf("-------------------CARDAPIO 70 LANCHES ------------------------------------\n");
				printf("| 1 - Mousse                | Valor: R$5,00           |\n");
				printf("--------------------------------------------------------\n");
				printf("| 2 - Torta de Frango       | Valor: R$9,00           |\n");
				printf("--------------------------------------------------------\n");
				printf("| 3 - Sorvetes              | Valor: R$4,00           |\n");
				printf("--------------------------------------------------------\n");
				printf("| 4 - Pudin                 | Valor: R$6,00           |\n");
				printf("--------------------------------------------------------\n");
				printf("Escolha uma Refeicao: ");
				scanf("%d", &sob);
				printf("Informe a quantidade: ");
				scanf("%d", &produto2[i].quantidade);
				if(sob == 1){
					strcpy(produto2[i].nome, "Mousse");
					produto2[i].valor = 5.00 * produto2[i].quantidade;
				}else if(sob == 2){
					strcpy(produto2[i].nome, "Torta de Frango");
					produto2[i].valor = 9.00 * produto2[i].quantidade;
				}else if(sob == 3){
					strcpy(produto2[i].nome, "Sorvetes");
					produto2[i].valor = 4.00 * produto2[i].quantidade;
				}else if(sob == 4){
					strcpy(produto2[i].nome, "Pudin");
					produto2[i].valor = 6.00 * produto2[i].quantidade;
				}else{
					printf("Escolha uma opcao valida!");
					return rpedido();
				}
				printf("\nVoce adicionou o item: %s com a quantidade de %d\n", produto2[i].nome, produto2[i].quantidade);
				printf("[1] - Voltar | [2] - Pedir outro produto\n");
				scanf("%d", &k);
				system("cls");
				fflush(stdin);
				if(k == 1 || k != 2){
					telaPrincipal();
					return;
				}
			}
			
			return rpedido();
}

//Função de criação de alteração do pedido
int alterpedido(){
	printf("Alterar pedido");

}

//Função de criação de consultar pedido
int consulpedido(){
	int i;
	int retorno;
	printf("Seus pedidos \n\n");
	printf("Lanches: \n");
	for(i = 0; i < 10; i++){
		
		printf("%d %s | R$%.2f\n",produto[i].quantidade, produto[i].nome, produto[i].valor);
	}
	printf("Sobremesas: \n");
	for(i = 0; i < 10; i++){
		printf("%d %s | R$%.2f\n",produto2[i].quantidade, produto2[i].nome, produto2[i].valor);
	}
	printf("Bebidas: \n");
	for(i = 0; i < 10; i++){
		printf("%d %s | R$%.2f\n",produto3[i].quantidade, produto3[i].nome, produto3[i].valor);
	}

	//Soma dos valores da conta
	//printf("%.2f\n", produto[0].valor + produto[1].valor);
	float totalC = 0;
	float totalC2 = 0;
	float totalC3 = 0;

	for (i = 0; i < 10; i++)
	{
		totalC += produto[i].valor;
		totalC2 += produto2[i].valor;
		totalC3 += produto3[i].valor;

	}
	
	printf("Valor total %.2f\n", totalC + totalC2 + totalC3);

	printf("Pressione 0 para voltar!\n");
	scanf("%d", &retorno);
	system("cls");
	if(retorno != 0){
		system("cls");
		printf("Informe uma opcao valida!\n");
		consulpedido();
	}else{
		rpedido();
	}
}
