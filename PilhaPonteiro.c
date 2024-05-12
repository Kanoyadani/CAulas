#include <stdio.h>
#include <stdlib.h>

struct st_pilha{
	int info;
	struct st_pilha* prox;
};

typedef struct st_pilha pilha;
pilha* topo;

void push (int valor){
	pilha* novo = (pilha*) malloc(sizeof(pilha));
	novo -> info = valor; 
	novo -> prox =topo; 
	
	printf("\nnovo-> info = %d\n\n", novo->info);
	topo = novo;
} 

int vazia(pilha* topo){
	return (topo == NULL);//verifica se a pilha esta vazia
}

void pop(){
	pilha * f;
	if(vazia(topo)){
		printf("Pilha vazia");
		exit(1);
	}else{
		f = topo;
		topo = f -> prox;
		free(f);
	}
}


void limpar(){	
	if(vazia(topo)){
		printf("Pilha vazia!!\n\n");
		exit(1);
	}else{
		pilha* T = topo;
		while(T != NULL){
			topo = T->prox;
			free(T);
			T = topo;
		}
		free(topo);
	}
}

int exibetopo(pilha* topo){
	pilha* T;
	
	if(vazia(topo)){
		printf("Pilha vazia!!\n\n");
		exit(1);
	}else{
		T = topo;
		while(T != NULL){
			printf("--> %d\n", T->info);
			T = T->prox;
		}
	}
	return topo->info;
}


int main(){
	
	topo = NULL;
	int valor;

    int op;
    do{
    	system("cls");
    	printf("\n***Menu de opcoes:***\n");
    	printf("1 - Adicionar na pilha:\n");
    	printf("2 - Remover da pilha:\n");
    	printf("3 - Exibir a pilha\n");
    	printf("4 - Limpar a pilha\n");
    	printf("0 - Sair\n");
    	printf("Entre com a opcao desejada: ");
    	scanf("%d", &op);
    	switch(op){
    		case 0:
    			printf("\nSair do programa.\n");
    			break;
    		case 1:
    			printf("\nEntre com um valor para inserir na pilha: ");
    			scanf("%d", &valor);
    			push(valor);
    			break;
    		case 2:
    			pop();
    			break;
    		case 3:
    			printf("\nTopo: %d\n",  exibetopo(topo));
    			break;
    		case 4:
    			limpar();
    			break;
    		default:
    			printf("Opcao invalida!!");
		}
    	system("pause");
	}while(op != 0);

	
	return 0;
}

