#include <stdio.h>
#include <stdlib.h>
#include "tamanho.h"


int main () {


	int valor = 1, escolha = -1;

	lista* list = aloca_lista();

	while(escolha != 0){

		printf("Digite 1:Botar valor na lista// 2:Mostra a altura do valor// 3:Mostra profundida da lista// 4:Verifica se e Crescente// 5:Menor da Lista // 0:Sair\n");
		scanf("%d", &escolha);


		if(escolha == 1){
			printf("Qual valor voce vai colocar na lista:\n");
			scanf("%d", &valor);
			insere_elemento(valor,list);
			mostra_lista(list);	
		}
		else if (escolha == 2){
			mostra_altura_cel(list);
		}
		else if (escolha == 3){
			mostra_profundida(list);
		}
		else if (escolha == 4){
			verifica_crescente(list);
		}
		else if(escolha == 5){
			mostra_menor(menor_elemento(list));
		}

	}

	remove_lista(list);
	
	
	return 0;
}