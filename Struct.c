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


//Insere inicio
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


void InsereFinal (no *P){
	
	no * novo = (no*) malloc(sizeof(no));
    
	
    
	    printf("Informe o valor:");
	     scanf("%d",&novo ->info);	
	     novo -> prox = NULL;
       
       if(P == NULL){
       	
  	    P = novo;
  	    
       }else{
          no * T = P;  
    	 while(T -> prox != NULL){ 
    	
    		T = T -> prox;
    		
		}
    	 T -> prox = novo;
	  }
	  
}

void insereMeio(no *P){
	no * novo = (no*) malloc(sizeof(no));
    no* T = P; 
    printf("Informe o valor:");
	scanf("%d",&novo ->info);	
	
	int valor;
	printf("Aonde deve ser inserido\n");
	scanf("%d",&valor);
	
	do{
	  
	  T = T -> prox;
	  
	}while(T->info != valor);
	
	novo -> prox =T;
}

//Retira Inicio
no* retirainicio(no *P){
	no* T  = P;
	P  = T -> prox;
	free(T);
	exibe(P); 
	return P;
}


//Retira Final
no* retirafim(no *P){
	no* T = P; 
	no* ANT = NULL;
	
	do{
	  ANT = T;
	  	
	  T = T -> prox;

	}while(T->prox != NULL);
	
	
	ANT-> prox = NULL;
	
	free(T);
	exibe(P); 
	return P;
}

no* retirameio(no *P){
	no* T = P; 
	no* ANT = NULL;
	int valor;
	exibe(P); 
	printf("Qual valor deve ser removido\n");
	scanf("%d",&valor);
	
	do{
	  
	  ANT = T;
	  	
	  T = T -> prox;
	  
	  

	}while(T->info != valor);
	
	ANT ->prox = T -> prox;
	T-> prox = NULL;
	
	free(T);
	exibe(P); 
	return P;
}


//Exibe
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
    	printf("Menu de Opcoes\n");
    	printf("1 - Insira um valor no Inicio da lista\n");
    	printf("2 - Insira um valor no Final da Lista\n");
    	printf("3 - Insira um valor no Meio da Lista\n");
    	printf("4 - Retira um valor no Inicio da lista\n");
    	printf("5 - Retirar um valor no Final da Lista\n");
    	printf("6 - Retirar um valor no Meio da Lista\n");
    	printf("7 - Exibir lista\n");
    	printf("8 - Sair\n"); 
    	
    	scanf("%d",&menu);
      switch(menu){
	  
      case 1 : P = insereInicio(P);
              break;
      case 2 : InsereFinal(P);
      	      break;
      case 3 : insereMeio(P);
	          break;
      case 4 : P = retirainicio(P);
              break;
      case 5: P = retirafim(P);
	          break;        
	  case 6: P = retirameio(P);
	          break;
	  case 7: exibe(P); 
	          break;
	  case8: printf("Finalizando Progrmana");
	          break ;              
      default: printf("Valor invalido");
	  system("pause");
      }
	}while (menu != 8);
	
	
	free(P);
	P = NULL;
	return 0;
	
	
}
