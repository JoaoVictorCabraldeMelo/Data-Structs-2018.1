#ifndef __LISTA_SIMPLES__
#define __LISTA_SIMPLES__


typedef struct ptr{ /* Estrutura do Elemento */
	int info;
	struct ptr* proximo; 
}elemento;

typedef struct { /*Inicio e o fim da lista */
	elemento* inicio;
	elemento* fim;
}Lista;


elemento* aloca_elemento(int dado);

Lista* aloca_lista();

int verifica_lista(Lista* lista);

void inserir_elemento(int dado, Lista* lista);

void mostrar_lista(Lista* lista);

void libera_lista(Lista* lista);

void main();


#endif