#include <stdlib.h>

int fat(int n)
{
    if(n==0 || n==1)
    {
        return n;
    }
    else
    {
        return n*(fat(n-1));
    }
}

int main()
{
    printf("fatorial de 5 eh %d", fat(5));
    return 0;
}

