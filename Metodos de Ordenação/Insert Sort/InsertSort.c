#include <stdlib.h>

void insertSort(int v[], int n){
    int i, j, aux;
    for(i=1;i<n;i++){
        aux = v[i];
        j = i;
        while(j>= 0 && aux < v[j-1]){
            v[j] = v[j-1];
            j--;
        }
        v[j] = aux;
    }
}

int main(){
    int v[] = {2,6,9,1,4,3,0};
    int n = 7;
    int i;
    for(i = 0; i<n; i++) printf("%d ", v[i]);
    printf("\n");
    insertSort(v,n);
    for(i = 0; i<n; i++) printf("%d ", v[i]);
    return 0;
}
