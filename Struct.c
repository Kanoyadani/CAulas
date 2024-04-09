#include <stdio.h>
#include <stdlib.h> //nescessario por conta da Malloc 
#include <conio.h>
struct st_no{
	int info;
	struct st_no *prox;
};

typedef struct st_no no; 


void inicia(no *P){ //Iniciando uma lista
    P -> info = 0 ;
    P -> prox = NULL;	
};



no* insereInicio (no *P){
	no *novo = (no*) malloc(sizeof(no));
    printf("Informe o valor:");
	scanf("%d",&novo ->info);	
	novo -> prox = NULL;
	
	if(P -> info == 0 && P->prox == NULL){
		P -> info = novo -> info;
	}else{
		novo -> prox = P;
		P = novo; 
	}
	
	return P;
}


void exibe (no* P) {
	no * T = P;
	
	do{
		printf("  %d  ", T -> info);
		T = T-> prox;
	}while(T != NULL);
	printf("\n\n");
	system("pause");
}


 int main(){
 	int menu;
 	no* P = (no*) malloc(sizeof(no));  //ALoca na memoria um ponteiro para uma estrutura no
    
    inicia(P);
    
    
    
    do{
    	system("cls");
    	printf("Menu de Opcoes");
    	printf("1 - Insira um valor noInicio da lista");
    	printf("2 - Insira um valor no Final da Lista");
    	printf("3 - Exisibir lista");
    	printf("4 - Sair"); 
    	
    	scanf("%d",&menu);
      switch(menu){
	  
      case 1 : P = insereInicio(P);
              break;
      case 2 : printf("testes");
      	      break;
      case 3 : exibi(P);
	          break;
      case 4 : printf("Finalizando PRogrmana");
              break;
      default printf("Valor invalido");
	  system("pause");
      }
	}while (menu != 4);
	
	
        
	
	free(P);
	P = NULL;
	return 0;
	
	
}
