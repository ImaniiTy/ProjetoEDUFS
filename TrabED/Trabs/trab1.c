#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Reg {
	char nomeProduto[50];
	float preco;
	void *prox;
}ProdutoL;

void incluir(ProdutoL *p) {
	ProdutoL *aux, *auxAnt;
	int continuar = 1;
	while (continuar == 1) {
		aux = (ProdutoL *) malloc(sizeof(ProdutoL));
		printf("nome: \n");
		scanf(" %s", aux->nomeProduto);
		fflush(stdin);
		printf("preco: \n");
		scanf(" %f", &aux->preco);
		fflush(stdin);
		if(p->prox == NULL) {
			aux->prox = p->prox;
			p->prox = aux;

		}
		else {
			auxAnt->prox = aux;
			aux->prox = NULL;
		}
		auxAnt = aux;
		printf("incluir outro?\n");
		scanf(" %d", &continuar);
		fflush(stdin);
	}
}

void imprimir(ProdutoL *p) {
	ProdutoL *aux;
	aux = p->prox;
	float soma = 0;
	do {
		printf("%s\n", aux->nomeProduto);
		printf("%f\n", aux->preco);
		soma += aux->preco;
		aux = aux->prox;

	} while (aux != NULL);
	printf("Soma parcial: %0.2f \n", soma);
}

void excluir(ProdutoL *p) {
	ProdutoL *aux, *auxAnt;
	aux = p;
	printf("digitar nome do produto: \n");
	char nome[50];
	scanf(" %s", nome);
	do {
		auxAnt = aux;
		aux = aux->prox;
	} while(aux != NULL && strcmp(nome, aux->nomeProduto) != 0 );
	if (aux == NULL) {
		printf("produto nao existe \n");
	}
	else {
		auxAnt->prox = aux->prox;
		free(aux);
	}
}

int main() {
	ProdutoL *lista, *inicio, *fim;
	lista = malloc(sizeof(ProdutoL));
	lista->prox = NULL;
	incluir(lista);
	excluir(lista);
	imprimir(lista);
	return 0;
}
