/**
* Developed by Marcelo Inácio
* Estrutura de Dados
* Lista Adjacência
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
* Função que inicializa uma lista de ponteiros
* Prametros: vetor de ponteiro do tipo No e o tamanho da lista
*/
void initLista(No *lista[], int tam){
    int i;
    for(i=0; i<tam; i++){
        lista[i] = malloc(sizeof(No)); //para cada posição reserva um espaço em memória
        lista[i]->cont = 0; //inicia contador com valor zero
        lista[i]->seg = NULL; //e todo próximo como nulo
    }
}
/*
* Função que preenche a lista com suas respecivas arestas
* Parametros: um vetor de ponteiros do tipo No,
*             uma posição do tipo INT e um valor do tipo INT
*/
void empilha(No *lista[], int posicao, int valor){
    No *novo = malloc(sizeof(No)); //reserva espaço para um novo vertice
    novo->cont = valor;

    if( !lista[posicao]->seg ){ //se for nulo entra na condição
        novo->seg = NULL;
        lista[posicao]->seg = novo;
    }else{ // se não for nulo
        novo->seg = lista[posicao]->seg;
        lista[posicao]->seg = novo;
    }
    lista[posicao]->cont++; //incrementa contador da lista
}
/*
* Função que imprime os valores de uma lista
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
