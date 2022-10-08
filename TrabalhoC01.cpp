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
