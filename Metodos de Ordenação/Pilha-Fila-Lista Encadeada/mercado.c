#include <stdio.h>
#include <conio.h>
#include <string.h>


struct mercado{

    int x;
    struct cel * prox;
};

typedef struct mercado celula;

void naoPerecivel(celula *pt, int x){
    celula *aux;
    aux=malloc(sizeof(celula));
    aux->x=x;
    aux->prox=pt->prox;
    pt->prox=aux;
}

void perecivel(celula **s,celula **t,int x){
    celula *aux;
    aux=malloc(sizeof(celula));
    aux->x=x;
    aux->prox=NULL;

    if(*t==NULL && *s==NULL){
         *t=aux;
         *s=aux;
    }
    else{
        (*t)->prox=aux;
        *t=aux;
    }
}

int pocisao(celula *pt){
    int cont = 0;
    celula *aux=pt->prox;
    if(pt->prox==NULL){
        return cont;
    }
    cont++;
    return cont+pocisao(pt->prox);
}

void imprimir(celula *t){
    celula *p;
    if(t->prox==NULL){
        printf("vazia\n");
    }
    else{
        for(p=t->prox; p!=NULL; p=p->prox){
            printf("PRODUTO: %i\n",p->x);
        }
    }
}

void imprimirFila(celula *s){
    celula *p;
    if(s==NULL){
        printf("vazia\n");
    }
    else{
        for(p=s; p!=NULL; p=p->prox){
            printf("PRODUTO: %i\n",p->x);
        }
    }
}

int remover(celula *pt){
    celula *lixo;
    int cod = 0;
    if(pt->prox==NULL){
        printf("vazia\n");
    }
    else{
        lixo=pt->prox;
        cod= lixo->x;
        pt->prox=lixo->prox;
        free(lixo);
    }
    return cod;
}

int removerFila(celula **ps, celula **pt){
    int cod=0;
	if(*ps==NULL && *pt==NULL){
		printf("Vazio\n \n");
	}
	else if(*ps==*pt){
        celula *lixo;
        lixo=*ps;
        cod=lixo->x;
        free(lixo);
        *ps=*pt=NULL;
    }
    else{
        celula *lixo;
        lixo=*ps;
        cod=lixo->x;
        *ps=lixo->prox;
        free(lixo);
    }
    return cod;
}

void buscaEImprime (int cod, celula *ini)
{
   if(ini->prox==NULL){
        system("cls");
        printf("vazio!!!\n");
   }
   else{
        celula *p;
        int i=0;
        celula *q;
        p = ini;
        q = ini->prox;
        while (q != NULL && q->x!=cod) {
           p = q;
           q = q->prox;
           i++;
        }
        if (q != NULL) {
           int v = pocisao(ini);
           printf ("Produto: %i esta na %i posicao da pilha\n", q->x, (v-i));
        }
   }
}
void buscaEImprimeEstante (int cod, celula *ini)
{
   if(ini==NULL){
        system("cls");
        printf("vazio!!!\n");
   }
   else{
        celula *p;
        celula *q;
        p = ini;
        q = ini->prox;
        while (q != NULL && q->x!=cod) {
           p = q;
           q = q->prox;
        }
        if (q != NULL) {
           printf ("Produto: %i esta na estante\n", q->x);
        }
   }
}
void desempilhaEmpilha (int cod, celula *ini)
{
   if(ini->prox==NULL){
        printf("vazio!!!\n");
   }
   else{
        int i=0,c[15],k;
        celula *q;
        q = ini->prox;
        while (q != NULL && q->x!=cod) {
           c[i] = remover(ini);
           printf("Desempilhar produto: %i\n",c[i]);
           q = ini->prox;
           i++;
        }
        if (q != NULL) {
           remover(ini);
           for(k=i-1; k>=0; k--){
                naoPerecivel(ini,c[k]);
           }
        }
   }
}
int main(){

    celula *t;
    t=malloc(sizeof(celula));
    t->prox=NULL;

    celula *f=NULL;
    celula *s=NULL;
    int x, tipo;
    int op=0;

    do{
        printf("1:Inserir \n2:Remover Produto \n3:Imprimir \n4:Sair\nOpcao:");
        scanf("%i",&op);
        switch(op){
            case 1:
                system("cls");
                printf("Informe tipo: \n1:PRECIVEL\n2:NAO PERECIVEL\n");
                scanf("%i",&tipo);
                setbuf(stdin,NULL);
                printf("Infome codigo:");
                scanf("%i",&x);
                if(tipo==1){
                    printf("Armazenado na estante\n");
                    perecivel(&s,&f,x);
                }
                else if(tipo==2){
                    int v = pocisao(t);
                    printf("Armazenado na %i pocicao na pilha\n",v+1);
                    naoPerecivel(t,x);
                }
                break;

            case 2:
                system("cls");

                printf("Informe tipo: \n1:PRECIVEL\n2:NAO PERECIVEL\n");
                scanf("%i",&tipo);
                if(tipo==1){
                    int cod = removerFila(&s,&f);
                    printf("Produto %i foi removido da estante\n",cod);
                }
                else if(tipo==2){
                    printf("Infome codigo:");
                    scanf("%i",&x);
                    desempilhaEmpilha(x,t);
                }
                break;

            case 3:
                system("cls");
                printf("Informe tipo: \n1:PRECIVEL\n2:NAO PERECIVEL\n3:TOTAL\n");
                scanf("%i",&tipo);
                if(tipo==1){
                    printf("Infome codigo:");
                    scanf("%i",&x);
                    buscaEImprimeEstante(x,s);
                }
                else if(tipo==2){
                    printf("Infome codigo:");
                    scanf("%i",&x);
                    buscaEImprime(x,t);
                }
                else if(tipo==3){
                    printf("PRECIVEL \n");
                    imprimirFila(s);
                    printf("NAO PRECIVEL \n");
                    imprimir(t);
                }
                break;

            case 4:
                printf("Fim do programa\n");
                break;

            default:
                system("cls");
                printf("Opcao invalida!!!\n");
                break;
        }

    }while(op!=4);

    system("pause");
    return 0;
}


