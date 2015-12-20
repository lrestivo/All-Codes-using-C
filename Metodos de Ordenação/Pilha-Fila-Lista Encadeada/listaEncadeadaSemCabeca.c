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

void imprima(celula *ini)
{
    celula *p;
    for (p = ini; p != NULL; p = p->prox)
        printf("%d\n",p->conteudo);
}


void insere (int x, celula **p)
{
    if (*p == NULL)
    {
        *p = malloc (sizeof (celula));
        (*p)->conteudo = x;
        (*p)->prox = NULL;
    }
    else
    {
        celula *nova = malloc(sizeof (celula));
        nova->conteudo = x;
        nova->prox = (*p)->prox;
        (*p)->prox = nova;
    }
}

void remover(celula *p)
{
    celula *morta;
    morta = p->prox;
    p->prox = morta->prox;
    free(morta);
}


int main()
{

    celula *ini = NULL;
    int x = -1;
    while (x != 0)
    {
        printf("\n1 para inserir.\n"
        "2 para remover um elemento.\n"
        "3 para imprimir a lista\n"
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
                insere(valor, &ini);
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
                remover(ini);
                printf("\nDeseja continuar removendo? 1 - para sim e 0 para não: ");
                scanf("%d", &y);
                system("cls");
              }
              break;

           case 3:
             system("cls");
             imprima(ini);
             break;
        }
    }
    system("pause");
    return 0;
}


