#include <stdlib.h>
int main();

struct celula
{
    int cont;
    struct celula *seg;
};

typedef struct celula cel;

void excluir(cel *p)
{
    cel * lixo;
    lixo = p->seg;
    p->seg = lixo->seg;
    free(lixo);
}

void addElemento(cel *p, int i)
{
    if(p==NULL)
    {
        p = malloc(sizeof(cel));
        p->cont = i;
        p->seg = NULL;
    }
    else
    {
        cel *aux;
        aux = malloc(sizeof(cel));
        aux->cont = i;
        aux->seg = p->seg;
        p->seg = aux;
    }
}

void imprime(cel *p)
{
    cel *i;
    for(i=p->seg ; i!=NULL ; i=i->seg)
    {
        printf("\n codigo: %d \n endereco: %x\n", p->cont,p->seg);
    }
}

int main()
{
    cel p;
    int i = 10;
    addElemento(&p,i);
    imprime(&p);
    return 0;
}
