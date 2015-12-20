#include <stdio.h>
#include <stdlib.h>

//Defini��o da estrutura da lista
struct cel
{
    int conteudo;
    struct cel *prox;
};

//Cria��o de um tipo de vari�vel do tipo da lista
typedef struct cel celula;

// Imprime o conte�do de uma lista encadeada
// com cabe�a. O endere�o da primeira c�lula � ini.
void imprima(celula *ini)
{
    celula *p;
    for (p = ini->prox; p != NULL; p = p->prox)
        printf("%d\n",p->conteudo);
}

// Esta fun��o recebe um inteiro x e uma lista
// encadeada ini de inteiros, com celula-cabe�a.
// A fun��o devolve o endere�o de uma celula que
// cont�m x ou devolve NULL se tal celula n�o
// existe.

celula* busca (int x, celula *ini)
{
   celula *p;
   p = ini->prox;
   //for(p=ini->prox; p!=NULL && p->conteudo != x; p = p->prox)
   while (p != NULL && p->conteudo != x)
      p = p->prox;
   return p;
}

//Fun��o para buscar recursivamente em uma lista
celula *buscaR (int x, celula *ini)
{
    if (ini->prox == NULL)
        return NULL;
    if (ini->prox->conteudo == x)
        return ini->prox;
    return buscaR(x,ini->prox);
}

// Esta fun��o insere uma nova celula em uma
// lista encadeada. A nova celula tem conteudo
// x e � inserida entre a celula apontada por
// p e a seguinte. Sup�e-se que p != NULL.
void insere (int x, celula *p)
{
    celula *nova;
    nova = malloc(sizeof (celula));
    nova->conteudo = x;
    nova->prox = p->prox;
    p->prox = nova;
}

// Esta fun��o recebe o endere�o p de uma celula
// de uma lista encadeada e remove da lista
// a celula p->prox. A fun��o sup�e que
// p != NULL e p->prox != NULL.
void remover(celula *p)
{
    celula *morta;
    morta = p->prox;
    p->prox = morta->prox;
    free(morta);
}

// Esta fun��o recebe uma lista encadeada ini,
// com cabe�a, e remove da lista a primeira
// celula que contiver y, se tal celula existir.
void buscaERemove (int y, celula *ini)
{
    celula *p, *q;
    p = ini;
    q = ini->prox;
    while (q != NULL && q->conteudo != y)
    {
        p = q;
        q = q->prox;
    }
    if (q != NULL)
    {
        p->prox = q->prox;
        free(q);
    }
}

// Esta fun��o recebe uma lista encadeada ini,
// com cabe�a, e insere na lista uma nova celula
// imediatamente antes da primeira que cont�m y.
// Se nenhuma celula cont�m y, insere a nova
// celula no fim da lista. O conteudo da nova
// celula � x.
void buscaEInsere (int x, int y, celula *ini)
{
    celula *p, *q, *nova;
    nova = malloc (sizeof(celula));
    nova->conteudo = x;
    p = ini;
    q = ini->prox;
    while(q != NULL && q->conteudo != y)
    {
        p = q;
        q = q->prox;
    }
    nova->prox = q;
    p->prox = nova;
}



int main()
{
    //Inicializando uma lista com cabe�a
    celula *ini;
    ini = malloc(sizeof(celula));
    ini->prox = NULL;

    int x = -1;
    while (x != 0)
    {
        printf("\n1 para inserir.\n"
        "2 para remover um elemento.\n"
        "3 para inserir um elemento antes de outro.\n"
        "4 para imprimir a lista\n"
        "5 para remover o ultimo \n"
        "6 para buscar\n"
        "0 para sair\n"
        "Digite a opera��o desejada:  ");
        scanf("%d", &x);
        switch (x)
        {
           case 1:
              system("cls");
              int y = 1;
              int valor = 0;
              while (y!=0)
              {
                printf("\nDigite o valor a ser inserido: ");
                scanf("%d", &valor);
                insere(valor, ini);
                printf("\nDeseja continuar inserindo? 1 - para sim e 0 para n�o: ");
                scanf("%d", &y);
                system("cls");
              }
              break;

           case 2:
              system("cls");
              y = 1;
              valor = 0;
              while (y!=0)
              {
                printf("\nDigite o item a ser inserido: ");
                scanf("%d", &valor);
                buscaERemove(valor, ini);
                printf("\nDeseja continuar removendo? 1 - para sim e 0 para n�o: ");
                scanf("%d", &y);
                system("cls");
              }

              break;

           case 3:
             system("cls");
              y = 1;
              valor = 0;
              int frente = 0;
              while (y!=0)
              {
                printf("\nDigite o item a ser inserido na lista: ");
                scanf("%d", &valor);
                printf("\nDigite o valor para inserir o novo antes deste na lista: ");
                scanf("%d", &frente);
                buscaEInsere(valor, frente, ini);
                printf("\nDeseja continuar adicionando? 1 - para sim e 0 para n�o: ");
                scanf("%d", &y);
                system("cls");
              }
              break;

            case 4:
             system("cls");
             imprima(ini);
             break;

            case 5:
                system("cls");
                remover(ini);
                break;
            case 6:
                system("cls");
                valor = 0;
                printf("\nDigite o um numero para buscar na lista: \n");
                scanf("%d", &valor);
                printf("valor encontrado: %i\n", busca(valor, ini));
                break;
        }
    }
    system("pause");
    return 0;
}


