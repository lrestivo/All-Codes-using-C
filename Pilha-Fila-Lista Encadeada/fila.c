#include <stdio.h>
#include <stdlib.h>

struct cel
{
    int cont;
    struct cel *prox;
};

typedef struct cel celula;

void insere(celula *s, celula *t, int x)
{
    celula *nova = malloc(sizeof(celula));
    nova->cont = x;
    nova->prox = NULL;
    if (s->prox == NULL)
    {
        s->prox = nova;
        t->prox = nova;
    }
    else
    {
        t->prox->prox = nova;
        t->prox = nova;
    }
}

int remover (celula *s)
{
    int x;
    celula *lixo;
    lixo = s->prox;
    s->prox = lixo->prox;
    x = lixo->cont;
    free(lixo);
    return x;
}

void imprime(celula *s)
{
    celula *aux;
    aux = s->prox;
    while (aux != NULL)
    {
        printf("\nValor: %d\n",aux->cont);
        aux = aux->prox;
    }
}

int main()
{
    celula *s;
    s = malloc(sizeof(celula));
    s->prox = NULL;

    celula *t;
    t = malloc(sizeof(celula));
    t->prox = NULL;

    int x = -1;
    while (x != 0)
    {
        printf ("\n1 para inserir um elemento na fila.\n"
        "2 para remover um elemento da fila.\n"
        "3 para imprimir os elementos na fila.\n"
        "0 para sair\n"
        "Digite a operação desejada:  ");
        scanf ("%d", &x);
        switch(x)
        {
            case 1:
                system ("cls");
                int y = 1;
                int num = 0;

                while (y != 0)
                {
                    printf ("\nDigite um número para inserir na fila: ");
                    scanf ("%d", &num);
                    insere (s, t, num);
                    printf ("\nDeseja continuar inserindo? 1 - para sim e 0 para nao: ");
                    scanf ("%d", &y);
                    system ("cls");
                }
                break;
            case 2:
                system ("cls");
                y = 1;
                num = 0;
                while (y != 0)
                {
                    num = remover(s);
                    printf ("\nRemovido item: %d",num);
                    printf ("\nDeseja continuar removendo? 1 - para sim e 0 para nao: ");
                    scanf ("%d", &y);
                    system ("cls");
                }
                break;
            case 3:
                imprime(s);
                break;
        }
    }
    return 0;
}
