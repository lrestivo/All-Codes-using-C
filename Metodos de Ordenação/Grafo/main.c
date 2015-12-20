/**
* Developed by Marcelo In�cio
* Estrutura de Dados
* Lista Adjac�ncia
* utilizando conceitos de grafo
*/
#include <stdio.h>
#include <stdlib.h>
/* Estrutura estudada em aula*/
typedef struct celula {
    int cont;
    struct celula *seg;
} No;

/*
* Fun��o que inicializa uma lista de ponteiros
* Prametros: vetor de ponteiro do tipo No e o tamanho da lista
*/
void initLista(No *lista[], int tam){
    int i;
    for(i=0; i<tam; i++){
        lista[i] = malloc(sizeof(No)); //para cada posi��o reserva um espa�o em mem�ria
        lista[i]->cont = 0; //inicia contador com valor zero
        lista[i]->seg = NULL; //e todo pr�ximo como nulo
    }
}
/*
* Fun��o que preenche a lista com suas respecivas arestas
* Parametros: um vetor de ponteiros do tipo No,
*             uma posi��o do tipo INT e um valor do tipo INT
*/
void empilha(No *lista[], int posicao, int valor){
    No *novo = malloc(sizeof(No)); //reserva espa�o para um novo vertice
    novo->cont = valor;

    if( !lista[posicao]->seg ){ //se for nulo entra na condi��o
        novo->seg = NULL;
        lista[posicao]->seg = novo;
    }else{ // se n�o for nulo
        novo->seg = lista[posicao]->seg;
        lista[posicao]->seg = novo;
    }
    lista[posicao]->cont++; //incrementa contador da lista
}
/*
* Fun��o que imprime os valores de uma lista
* Parametros: um vetor de ponteiros do tipo No e o tamanho do tipo INT
*/
void imprimeLista(No *lista[], int tam){
    int i;
    printf("|POSICAO \t|QTD \t|VERTICES");
    for(i=0; i<tam; i++){
        No *aux;
        printf("\n posicao[%d] \t%d ==> ", i, lista[i]->cont);
        for( aux = lista[i]->seg; aux != NULL; aux = aux->seg ){
            printf("%d -> ", aux->cont);
        }
        printf(" null ");
    }
}


int main()
{
    int i;
    No *lista[6];

    int arestas[4][2] = { {1,2},
                          {1,4},
                          {2,5},
                          {3,4} };
/** Inicializa lista */
    initLista(lista, 6);

/** Preenche lista */
    for(i=0; i<4; i++){
        empilha(lista, arestas[i][0], arestas[i][1]);
    }
/** Imprime a lista */
    imprimeLista(lista, 6);


    printf("\n\n");
    system("pause");
    return 0;
}
