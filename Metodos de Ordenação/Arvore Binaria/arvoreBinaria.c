#include <stdio.h>

/* Funcao que inverte Arvore Binaria - de erd para dre */

/* Estrutura da Arvore */
struct cel {
    int valor;
    struct cel *esq;
    struct cel *dir;
};
typedef struct cel no;

/* Funcao Insere na Arvore Binaria */
no * insereArvore ( int num, no *r ){
    if ( r == NULL ){
        no *novo = malloc(sizeof(no));
        novo->valor = num;
        novo->esq = NULL;
        novo->dir = NULL;

        return novo;
    }

    if (num < r->valor)
        r->esq = insereArvore(num, r->esq);
    else
        r->dir = insereArvore(num, r->dir);
    return r;
}

/* Soma valores arvore */
int somaArvore(no *r){
    int soma = 0;
    if(r != NULL){
        soma = somaArvore(r->esq) + somaArvore(r->dir) + r->valor;
        return soma;
    }else{
        return 0;
    }
}

/* Percorre Arvore Binaria */
void varreArvore (no * r){
    if (r != NULL){
        varreArvore(r->esq);
        printf( "%d ", r->valor );
        varreArvore(r->dir);
    }
}

/* Funcao Inverte Arvore */
no * inverteArvore ( no * r ){
    no *aux;
    if (r != NULL){
        r->esq = inverteArvore( r->esq );
        r->dir = inverteArvore( r->dir );

        aux = r->esq;
        r->esq = r->dir;
        r->dir = aux;
    }
    return r;
}

void main(){
    no *raiz = NULL;
    int i, vetor[7] = {4, 7, 1, 3, 6, 8, 2};
    for ( i=0; i< 7; i++ )
        raiz = insereArvore(vetor[i], raiz);
    printf("\nExibindo conteudo da arvore sem inverter ...\n");
    varreArvore(raiz);
    raiz = inverteArvore(raiz);

    printf("\n\nExibindo Arvore Invertida ...\n");
    varreArvore(raiz);

    printf("\n\nExibindo Soma Arvore ...\n");
    printf("%d",somaArvore(raiz));
}
