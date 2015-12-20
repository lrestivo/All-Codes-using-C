#include <stdlib.h>

int mult(a,b)
{
    if(a==0 || b==0)
    {
        return 0;
    }
    if(b==1)
    {
        return a;
    }
    else
    {
        return a + mult(a,b-1);
    }
}

int main()
{
    printf("%d",mult(2,2));
    return 0;
}
