#include <stdio.h>
#include <stdlib.h>

struct st_lista{
	int info;
	struct st_lista* prox;
};

typedef struct st_lista fila;
fila* inicio = NULL;
fila* fim = NULL; 


fila* criarFila(){
	fila* f = (fila*) malloc(sizeof(fila));
	f -> info = 0;
	return f; 
};


void enqueue(fila* f, int v){
    fila* novo = (fila*) malloc(sizeof(fila));
    novo -> info = v;
    novo -> prox = NULL;
    
	if(inicio == NULL){
    	inicio = novo;  //Adiciona se n tiver na Fila 
    	fim = novo;
	}else{
		fim -> prox = novo; //Adicion se ja tiver Elementos 
		fim = novo;
	}
}


int dequeue (fila* f){
	if(inicio == NULL){
		printf("Fila Vazia");
		return 0 ;
	}else{
		fila* T = inicio; // Declara T Com a posição Inicial
		inicio = T -> prox;
		return T -> info; // Acredito que o Retorno Seja para apresentar o valor Removido para o usuario 
		free(T);
		if(inicio = NULL){
			printf("O ultimo item da Fila foi Removido");
		}
	
	}
}


fila* clear(fila* f){
	fila* q = inicio;
	while(q != NULL){
		fila*  T = q->prox;
		free(q);
		q = T;
	}
	free(f);
	return f;	
}

void Exibe(fila* f){
	fila* T = inicio;
	
	while(T != NULL){
		printf("%d\n", T->info);
		T = T->prox;
	}
	
}

int main(){
	int op = 0;
	int valor;
	fila* f;
	f = criarFila();

	do{
		system("cls");
		printf("Selecione a opcap: \n\n");
		printf("[1] - Inserir da fila (enqueue): \n");
		printf("[2] - Remover da fila (dequeue): \n");
		printf("[3] - Exibir: \n");
		printf("[4] - Limpar: \n");
		printf("[0] - Sair: \n");
		printf("Opcao: ");
		scanf("%d", &op);
		
		switch(op){
			case 1:
				printf("Qual valor deseja inserir na fila:");
				scanf("%d", &valor);
				enqueue(f,valor );		
				break;
			case 2:
				dequeue(f);
				break;
			case 3:
				Exibe(f);
				break;
			case 4:
				f = clear(f);
				break;
			case 0:
				printf("Opcap invalida!!");
				break;
		}
		system("pause");
	}while(op != 0);
	return 0;	
}
