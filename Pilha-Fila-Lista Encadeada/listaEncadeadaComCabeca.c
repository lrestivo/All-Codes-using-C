#include <stdio.h>
#include <stdlib.h>

//Definição da estrutura da lista
struct cel
{
    int conteudo;
    struct cel *prox;
};

//Criação de um tipo de variável do tipo da lista
typedef struct cel celula;

// Imprime o conteúdo de uma lista encadeada
// com cabeça. O endereço da primeira célula é ini.
void imprima(celula *ini)
{
    celula *p;
    for (p = ini->prox; p != NULL; p = p->prox)
        printf("%d\n",p->conteudo);
}

// Esta função recebe um inteiro x e uma lista
// encadeada ini de inteiros, com celula-cabeça.
// A função devolve o endereço de uma celula que
// contém x ou devolve NULL se tal celula não
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

//Função para buscar recursivamente em uma lista
celula *buscaR (int x, celula *ini)
{
    if (ini->prox == NULL)
        return NULL;
    if (ini->prox->conteudo == x)
        return ini->prox;
    return buscaR(x,ini->prox);
}

// Esta função insere uma nova celula em uma
// lista encadeada. A nova celula tem conteudo
// x e é inserida entre a celula apontada por
// p e a seguinte. Supõe-se que p != NULL.
void insere (int x, celula *p)
{
    celula *nova;
    nova = malloc(sizeof (celula));
    nova->conteudo = x;
    nova->prox = p->prox;
    p->prox = nova;
}

// Esta função recebe o endereço p de uma celula
// de uma lista encadeada e remove da lista
// a celula p->prox. A função supõe que
// p != NULL e p->prox != NULL.
void remover(celula *p)
{
    celula *morta;
    morta = p->prox;
    p->prox = morta->prox;
    free(morta);
}

// Esta função recebe uma lista encadeada ini,
// com cabeça, e remove da lista a primeira
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

// Esta função recebe uma lista encadeada ini,
// com cabeça, e insere na lista uma nova celula
// imediatamente antes da primeira que contém y.
// Se nenhuma celula contém y, insere a nova
// celula no fim da lista. O conteudo da nova
// celula é x.
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
    //Inicializando uma lista com cabeça
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
        "Digite a operação desejada:  ");
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
                printf("\nDeseja continuar inserindo? 1 - para sim e 0 para não: ");
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
                printf("\nDeseja continuar removendo? 1 - para sim e 0 para não: ");
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
                printf("\nDeseja continuar adicionando? 1 - para sim e 0 para não: ");
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


