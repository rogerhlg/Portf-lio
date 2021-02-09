//Roger Henrique email:rogerhlg@outlook.com	#término 12:00
//Amanda Scremin email:amandascremin23 
#include <stdio.h>
#include <string.h>

#define MAX 3

typedef struct{
	char nome[40];
	char ingrediente[40];
	int tempo;
} receita;

int pos=-1;
receita receitas[MAX];


void addReceita(char nome[40], char ingrediente[40], int tempo){
	if(pos>=MAX-1){
		printf("ERRO! VETOR DE RECEITAS ESTA CHEIO!");
	}
	else
		
		pos++;
		strcpy(receitas[pos].nome, nome);
		strcpy(receitas[pos].ingrediente,ingrediente);
		receitas[pos].tempo = tempo;	
}

void listarReceitas(){
	int i;
	for(i=0;i<=pos;i++){
		printf("\nReceita: %d",i+1);
		printf("\nNome: %s",receitas[i].nome);
		printf("\nIngrediente: %s",receitas[i].ingrediente);
		printf("\nTempo: %d\n\n",receitas[i].tempo);
	}
}

int calcMediaTempo(char ingredientes[40]){
	int i,medio=0,x=0;
	
	for(i=0;i<=MAX-1;i++){
		if(strcmp(ingredientes, receitas[i].ingrediente)==0){
			medio=medio+receitas[i].tempo;
			x++;
		}
	}
		if(x>0){
			medio=medio/x;
			return medio;
		}
		return -1;
	
}

int buscaRec(char nomerec[40]){
    int i, a=0;
    printf("\n");
    for(i=0; i<=pos; i++){
          if(strcmp(nomerec, receitas[i].ingrediente) == 0)
        {
            printf("%s\n", receitas[i].nome);
            printf("%s\n", receitas[i].ingrediente);
            printf("%d\n", receitas[i].tempo);
            printf("\n\n");
            a++;
        }
    }
    if(a==0){
        printf("\nReceita nao encontrada!\n\n");
    }
    return 0;
}


void ordenaReceitas(){
	int i,j,topo=pos,aux;
	char nome[40],ingrediente[40];
	for(j=0;j<=topo;topo--){
		for(i=0;i<=pos-1;i++){
			if(receitas[i].tempo>receitas[i+1].tempo)
			{
				aux=receitas[i+1].tempo;
				strcpy(nome, receitas[i+1].nome);
				strcpy(ingrediente, receitas[i+1].ingrediente);
				
				receitas[i+1].tempo=receitas[i].tempo;
				strcpy(receitas[i+1].nome, receitas[i].nome);
				strcpy(receitas[i+1].ingrediente, receitas[i].ingrediente);
				
				receitas[i].tempo=aux;
				strcpy(receitas[i].nome, nome);
				strcpy(receitas[i].ingrediente, ingrediente);
				
			}
			
		}
	}
}

int buscaNome(char nomereceita[40]){
    int i, a=0;
    printf("\n");
    for(i=0; i<=pos; i++){
          if(strcmp(nomereceita, receitas[i].nome) == 0)
        {
            printf("Indice: %d\n", i);
            printf("%s\n", receitas[i].nome);
            printf("%s\n", receitas[i].ingrediente);
            printf("%d\n", receitas[i].tempo);
            printf("\n\n");
            a++;
            break;
        }
    }
    if(a==0){
        printf("\nReceita nao encontrada!\n\n");
    }
    return 0;
}

int main(){
	char nome[40],ingrediente[40];
	int op,tempo;
	do{
		printf("\n1-Adicionar Receitas\n2-Calcular tempo medio de preparo com um ingrediente\n3-Listar receitas com um ingrediente\n4-Buscar receita pelo nome\n5-Ordenar receitas\n6-Listar receitas\n9-Sair\n");
		printf("\n\nInsira a opcao desejada: ");
   		scanf("%d",&op);
   		fflush(stdin);
		switch(op){
			case 1:
				printf("\n\nInsira o nome da receita: ");
				fflush(stdin);
				gets(nome);
				fflush(stdin);
				
				printf("\nInsira o ingrediente PRINCIPAL: ");
				fflush(stdin);
				gets(ingrediente);
				fflush(stdin);
				printf("\nInsira o tempo médio da receita: ");
				scanf("%d",&tempo);

				addReceita(nome,ingrediente,tempo);
				
			break;
			
			case 2:
				printf("Desejar calcular o tempo medio de qual ingrediente? ");
				fflush(stdin);
				gets(ingrediente);
				fflush(stdin);
				tempo=calcMediaTempo(ingrediente);
				if(tempo==-1){
					printf("\nIngrediente nao encontrado\n");
				}
				else
					printf("\nTempo medio das receitas: %d min\n",tempo);
				
			break;
			
			case 3:
                printf("\n\nInforme o nome do ingrediente que deseja localizar: ");
                fflush(stdin);
                gets(ingrediente);
                fflush(stdin);

                buscaRec(ingrediente);
            break;
			
			case 4:
                printf("\n\nInforme o nome da receita que deseja localizar: ");
                fflush(stdin);
                gets(nome);
                fflush(stdin);

                buscaNome(nome);
            break;
			
			case 5:
				ordenaReceitas();
			break;
			
			case 6:
				listarReceitas();
			break;
			
			
			
		}
		
		
	}while(op!=9);
	
	return 0;
}
