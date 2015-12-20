#include <stdlib.h>

int main()
{
    int i,x;
    i = 20;
    x = 10;
    printf("valor i: %d endereco de i: %p",i,&i);
    printf("valor x: %d endereco de x: %p",x,&x);

    printf("\n\n");

    int *p = &i;
    int *p2 = &x;
    printf("conteudo p %p mesmo endereco de i: %p\n", p,&i);
    printf("conteudo p2 %p mesmo endereco de x: %p\n", p2,&x);

    printf("\n\n");

    *p = *p+10;
    *p2 = *p2*10;
    printf("valor *p=*p+10: %d i tem o mesmo valor: %i\n", *p,i);
    printf("valor *p2=*p2*10: %d x tem o mesmo valor: %i\n", *p2,x);

    printf("\n\n");

    int **p3;
    p3 = &p;
    printf("conteudo de p3 %p mesmo endereco de p: %p\n", p3,&p);


    *p3 = *p - *p2;
    printf("%d,%i",*p3,x);
    return 0;
}
