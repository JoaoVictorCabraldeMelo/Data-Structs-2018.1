#include <stdio.h>
#include <stdlib.h>
#include "tamanho.h"

celula* aloca_celula(int valor){
	celula* elemento = (celula *) malloc(sizeof(celula));

	elemento->dado = valor;
	elemento->prox = NULL;

	return elemento; 
}

lista* aloca_lista(){
	lista* list = (lista *) malloc(sizeof(lista));

	list->inicio = NULL;

	return list;
}

void remove_lista(lista* list){
	celula* aux = list->inicio;
	if(list->inicio != NULL){
		while(aux->prox != NULL){
			aux = list->inicio;
			free(aux);
			list->inicio = list->inicio->prox;
		}
		free(list);
	}
	else {
		printf("Lista nao possui nenhum elemento\n");
	}
}

void insere_elemento(int valor, lista* list){
	celula* aux = list->inicio;

	if(list->inicio == NULL){
		celula* novo_elemento = aloca_celula(valor);
		list->inicio = novo_elemento;
	}
	else{
		while(aux->prox != NULL){
			aux = aux->prox;
		}

		celula* novo_elemento = aloca_celula(valor);
		aux->prox = novo_elemento;
		novo_elemento->prox = NULL;

	}

}

void mostra_lista(lista* list){
	celula* aux = list->inicio;
	printf("\t\tLISTA\t\t\n");
	while(aux != NULL){
		printf("\t\t%d\t\t\n", aux->dado);
		aux = aux->prox;
	}
}

void tamanho_struct(celula celula){
	printf("O tamanho da estrutura e:%lu\n", sizeof(celula));
}


int altura_celula(int valor, lista* list){

	celula* aux = list->inicio;

	while(aux->dado != valor){
		aux = aux->prox;
	}

	int altura = 0;

	while(aux->prox != NULL){
		aux = aux->prox;
		altura++;
	}


	return altura;
}

void mostra_altura_cel(lista* list){

	int valor, altura;

	printf("Qual valor vc quer a altura ?\n");
	scanf("%d", &valor);

	if(busca(valor,list) > 0){
		
		altura = altura_celula(valor, list);

		printf("A altura do %d e: %d\n", valor, altura);

	}
}

int profundida_lista(lista* list){

	celula* aux = list->inicio;
	int prof = 1;

	while(aux->prox != NULL){
		aux = aux->prox;
		prof++;
	}

	return prof;
}

void mostra_profundida(lista* list){
	int prof = profundida_lista(list);

	printf("A profundida da lista e: %d\n", prof);
}

int busca(int x, lista* list){
	celula* aux = list->inicio;

	while(aux != NULL && aux->dado != x){
		aux = aux->prox;
	}

	if(aux == NULL){
		printf("O elemento %d nao esta na lista\n", x);
		return -1;
	}
	else if(aux->dado == x) {
		return 1;
	}
}

int verifica_crescente(lista* list){
	celula* primeiro = list->inicio;
	celula* segundo = primeiro->prox;

	while(segundo != NULL){
		if(primeiro->dado > segundo->dado){
			printf("Lista nao e crescente\n");
			return -1;
		}

		primeiro = segundo;
		segundo = segundo->prox;
	}

	printf("Lista e crescente\n");
	return 1;
}

int menor_elemento(lista* list){
	celula* aux = list->inicio;

	int menor = list->inicio->dado;

	while(aux != NULL){
		if(aux->dado < menor){
			menor = aux->dado;
		}
		aux = aux->prox;
	}

	return menor;
}

void mostra_menor(int menor){
	printf(" Esse e o menor nro da lista: %d\n", menor);
}