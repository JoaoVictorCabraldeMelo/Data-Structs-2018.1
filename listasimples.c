#include <stdio.h>
#include <stdlib.h>
#include "listasimples.h"



elemento* aloca_elemento(int dado){

	elemento* element = malloc(sizeof(elemento));

	element->info = dado;
	element->proximo = NULL;

	return element; 
}

Lista* aloca_lista() {

	Lista* lista = malloc(sizeof(Lista));

	lista->inicio = NULL;
	lista->fim = NULL;

	return lista;
}

void libera_lista(Lista* lista){

	elemento* aux = lista->inicio;

	while(aux != NULL){

		lista->inicio = lista->inicio->proximo;
		free(aux);
		aux = lista->inicio;
	}

	free(lista);

}


int verifica_lista(Lista* lista){
	if(lista->inicio == NULL && lista->fim == NULL){
		printf("Lista esta Vazia\n");
		return -1;
	}
	else {
		printf("Lista nao esta Vazia\n");
		return 1;
	}
}


void inserir_elemento(int dado, Lista* lista){

	if(verifica_lista(lista) < 0){
		elemento* element = aloca_elemento(dado);
		lista->inicio = element;
		lista->fim = element;
	}

	else {

		elemento* atual = lista->inicio;
		
		while(atual->proximo != NULL){
			atual = atual->proximo;
		}

		elemento* element = aloca_elemento(dado);

		atual->proximo = element;

		element->proximo = NULL;

		lista->fim = element;
		
	}

}

void mostra_lista(Lista* lista){
	elemento* indice = lista->inicio;
	int i = 0;

	while(indice != NULL){
		printf("Indice da lista=%d Numero=%d\n", i, indice->info);
		indice = indice->proximo;
		i++;
	}
}

void main () {
	int i, valor;
	Lista* lista = aloca_lista();

	for(i = 0; i < 5;i++){
		printf("Valor pra se colocar na lista: ");
		scanf("%d", &valor);
		printf("\n");

		inserir_elemento(valor,lista);
	}

	mostra_lista(lista);

	libera_lista(lista);
}