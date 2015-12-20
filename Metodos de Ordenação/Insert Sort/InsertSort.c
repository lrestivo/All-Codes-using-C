#include <stdlib.h>

void insertSort(int v[], int n){
    int i, j, aux;
    for(i=1;i<n;i++){
        aux = v[i];
        printf("aux: %d\n", aux);
        j = i;
        while(j>= 0 && aux < v[j-1]){
            printf("v[j] = v[j-1] : %d, %d\n", v[j],v[j-1]);
            v[j] = v[j-1];
            j--;
        }
        printf("v[j] = aux : %d, %d\n", v[j],aux);
        v[j] = aux;
    }
}

int main(){
    int v[] = {7,13,10,2,5,8,1};
    int n = 7;
    int i;
    for(i = 0; i<n; i++) printf("%d ", v[i]);
    printf("\n");
    insertSort(v,n);
    for(i = 0; i<n; i++) printf("%d ", v[i]);
    return 0;
}
