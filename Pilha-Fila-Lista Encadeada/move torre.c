#include <stdlib.h>

void moveTorre(int n, char a, char b, char c)
{
    if(n>0)
    {
        moveTorre(n-1,a,c,b);
        printf("mover de %c para %c \n", a,b);
        moveTorre(n-1,c,b,a);
    }
}

int main()
{
    moveTorre(5,"a","b","c");
    return 0;
}

