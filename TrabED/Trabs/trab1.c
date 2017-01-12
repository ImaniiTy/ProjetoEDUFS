#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

typedef struct Reg {
	char nomeProduto[50];
	float preco;
	int qtd;
	void *prox;
}ProdutoL;

void lerReg(ProdutoL *reg) {
	printf("Nome :\n");
	fgets(reg->nomeProduto,50,stdin);
	setbuf(stdin,NULL);
	printf("valor :\n");
	scanf("%f", &reg->preco);
	setbuf(stdin,NULL);
	printf("quantidade :\n");
	scanf("%d", &reg->qtd);
	setbuf(stdin,NULL);
}

void imprimirLista(ProdutoL *lista, ProdutoL *fim) {
	ProdutoL *aux;
	float soma;
	for (aux = lista;aux != NULL;aux = aux->prox) {
		printf("Nome: %s"
			   "Preco: %0.2f\n"
			   "Quantidade: %d\n\n", aux->nomeProduto, aux->preco, aux->qtd);
		soma += aux->preco*aux->qtd;
	}
	printf("Soma parcial: %0.2f\n\n", soma);
}

void incluirLista(ProdutoL *lista, ProdutoL *fim) {
	ProdutoL *aux;
	char c;
	aux = malloc(sizeof(ProdutoL));
	aux->prox = NULL;
	lerReg(aux);
	if (lista == NULL) {
		lista = aux;
		lista->prox = aux->prox;
		fim = lista;
		fim->prox = lista->prox;
	}
	else {
		fim->prox = aux;
		fim = aux;
	}
	imprimirLista(lista,fim);
	printf("Finalizar? (S/N)\n");
	scanf(" %c", &c);
	getchar();
	c = toupper(c);
	if(c == 'N') {
		incluirLista(lista,fim);
	}
}

void excluirLista(ProdutoL *lista, ProdutoL *fim) {
	char aux[50];
	fgets(aux,50,stdin);
	setbuf(stdin,NULL);
}

int main() {
	ProdutoL *lista,*fim;
	incluirLista(lista,fim);
	return 0;
}
