#ifndef __LISTASIMPLES_H__
#define __LISTASIMPLES_H__

/*Um jeito de declarar uma estrutura de uma lista simples */
typedef struct reg celula;

/*---------------------------------------------------------*/
struct reg {
	int dado;
	celula *prox;
};
/*---------------------------------------------------------*/

typedef struct {
	celula *inicio;
}lista;
/*Um ponteiro para o inicio da lista*/


void tamanho_struct(celula celula);

celula* aloca_celula(int valor);

lista* aloca_lista();

void remove_lista(lista* list);

void insere_elemento(int valor, lista* list);

void mostra_lista(lista* list);

int altura_celula(int dado, lista* list);

void mostra_altura_cel(lista* list);

int profundida_lista(lista* list);

void mostra_profundida(lista* list);

int busca(int x, lista* list);

int verifica_crescente(lista* list);

int menor_elemento(lista* list);

void mostra_menor(int menor);



#endif 