#include <stdlib.h>

int shellSort(int v[], int n){
    int i, j, aux;
    int gap = 1;
    while (gap < n){
        gap = 3*gap+1;
    }
    while(gap > 1){
        gap /= 3;
        for(i = gap; i < n; i++){
            aux = v[i];
            j = i-gap;
            while(j>=0 && aux < v[j]){
                v[j+gap] = v[j];
                j -= gap;
            }
            v[j+gap] = aux;
        }
    }
}


int main(){
    int v[] = {2,6,9,1,4,3,0};
    int n = 7;
    int i;
    for(i = 0; i<n; i++) printf("%d ", v[i]);
    printf("\n");
    shellSort(v,n);
    for(i = 0; i<n; i++) printf("%d ", v[i]);
    return 0;

    return 0;
}
