#include <stdio.h>

void heapsort(int n, int v[]){
    int i = 1, k, p, aux;
    v[n] = v[0]; n++;
    for(k=0;k<n-1;k++){
        p = n-i;
        while(p!=1){
            if(v[p]>v[p/2]){
                printf("aux: %d\n", aux);
                aux=v[p];
                v[p]=v[p/2];
                v[p/2]=aux;
            }
            p = p-1;
        }
        printf("aux: %d\n", aux);
        aux = v[p];
        //printf("dd  %i\n",v[p]);
        v[p]=v[n-i];
        v[n-i]=aux;
        i++;
    }
}
int main()
{
    //int v[9]={1,2,3,4,5,6,7,8,9};
    //int v[10]={0,13,10,2,5,8,1,0,99,9,7};
    int v[9]={14,43,13,15,18,10,19,12,20};
    int tam=9 , i=0;
    for(i=0 ; i<9; i++){
        printf("%i ",v[i]);
    }
    printf("\n");
    heapsort(tam,v);
    for(i=1 ; i<10; i++){
        printf("%i ",v[i]);
    }
    printf("\n");
    system("pause");
    return 0;
}

