#include <stdio.h>
#include <stdlib.h>

struct cel
{
    int cont;
    struct cel *prox;
};

typedef struct cel celula;

void insere(celula *c, int x)
{
    celula *nova = malloc(sizeof(celula));
    nova->cont = x;
    nova->prox = c->prox;
    c->prox = nova;
}

int remover(celula *c)
{
    int x;
    celula *lixo;
    lixo = c->prox;
    c->prox = lixo->prox;
    x = lixo->cont;
    free(lixo);
    return x;
}

void imprime(celula *c)
{
    celula *aux;
    aux = c->prox;
    while (aux != NULL)
    {
        printf("\nValor: %d\n", aux->cont);
        aux = aux->prox;
    }
}

int somaR (celula *c)
{
    c = c->prox;
    if (c == NULL)
        return 0;
    else
        return (c->cont + somaR (c));
}


int main()
{
    celula *c;
    c = malloc(sizeof(celula));
    c->prox = NULL;

    int x = - 1;
    while (x != 0)
    {
        printf ("\n1 para inserir um elemento na pilha.\n"
        "2 para remover um elemento da pilha.\n"
        "3 para imprimir os elementos na pilha.\n"
        "4 retorna soma dos elementos na pilha.\n"
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
                    printf ("\nDigite um número para inserir na pilha: ");
                    scanf ("%d", &num);
                    insere (c, num);
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
                    num = remover(c);
                    printf ("\nRemovido item: %d",num);
                    printf ("\nDeseja continuar removendo? 1 - para sim e 0 para nao: ");
                    scanf ("%d", &y);
                    system ("cls");
                }
                break;
            case 3:
                imprime(c);
                break;
            case 4:
                printf ("\nSoma dos elementos: %d", somaR(c));
                break;
        }
    }
    return 0;
}
