#include <stdlib.h>

int shellSort(int v[], int n){
    int i, j, aux;
    int gap = 1;
    while (gap < n){
        gap = 3*gap+1;
    }
    while(gap > 1){
        gap /= 3;
        printf("gap: %d\n", gap);
        for(i = gap; i < n; i++){
            aux = v[i];
            printf("aux: %d\n", aux);
            j = i-gap;
            printf("j: %d\n", j);
            while(j>=0 && aux < v[j]){
                printf("v[j+gap]: %d = v[j]: %d\n", v[j+gap], v[j]);
                v[j+gap] = v[j];
                j -= gap;
            }
            printf("v[j+gap]: %d = aux %d\n", v[j+gap], aux);
            v[j+gap] = aux;
            int i;
            for(i = 0; i<n; i++) printf("%d ", v[i]);
            printf("\n");
        }
    }
}


int main(){
    int v[] = {7,13,10,2,5,8,1};
    int n = 7;
    int i;
    for(i = 0; i<n; i++) printf("%d ", v[i]);
    printf("\n");
    shellSort(v,n);
    for(i = 0; i<n; i++) printf("%d ", v[i]);
    return 0;

    return 0;
}
