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

float imprimir(ProdutoL *p) {
	ProdutoL *aux;
	aux = p->prox;
	float soma = 0;
	do {
		printf("Nome: %s     ", aux->nomeProduto);
		printf("%0.2fRS    ", aux->preco);
		printf("Quantidade: %d\n", aux->qtd);
		soma += aux->preco * aux->qtd;
		aux = aux->prox;

	} while (aux != NULL);
	return soma;
}

void incluir(ProdutoL *p) {
	ProdutoL *aux, *auxAnt;
	char continuar;
	float somaP;
	do {
		aux = (ProdutoL *) malloc(sizeof(ProdutoL));
		printf("nome: \n");
		scanf(" %s", aux->nomeProduto);
		fflush(stdin);
		printf("preco: \n");
		scanf(" %f", &aux->preco);
		fflush(stdin);
		printf("quantidade: \n");
		scanf(" %d", &aux->qtd);
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
		system("cls");
		somaP = imprimir(p);
		printf("Soma Parcial: %0.2f\n", somaP);
		printf("Finalizar?(S/N)\n");
		scanf("%c", &continuar);
		continuar = toupper(continuar);
	} while (continuar == 'N');
	system("cls");
	imprimir(p);
	printf("Valor Final: %0.2f", somaP);
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
	ProdutoL *lista;
	lista = malloc(sizeof(ProdutoL));
	lista->prox = NULL;
	int opcao;
	do {
		printf("Digite uma opcao: \n");
		scanf("%d", &opcao);
		switch (opcao) {
			case 1:
				incluir(lista);
				break;
			case 2:
				excluir(lista);
				break;
			case 3:
				break;
			case 0:
				break;
		}
	} while (opcao != 0);
	system("pause");
	return 0;
}
