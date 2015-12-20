#include <stdlib.h>
#include <stdio.h>

void insereHeap(int m, int v[]){
    int f = m+1;
    while(f > 1 && v[f/2] < v[f]){
        int t = v[f/2];
        v[f/2] = v[f];
        v[f] = t;
        f = f/2;
    }
}

void sacodeHeap(int m, int v[]){
    int f = 2;
    while(f <= m){
        if(f < m && v[f] < v[f+1]) ++f;
        if(v[f/2] >= v[f]) break;
        int t = v[f/2];
        v[f/2] = v[f];
        v[f] = t;
        f *=2;
    }
}

void heapSort2(int v[], int n){
	int m;
	for(m = 1; m < n; m++) insereHeap(m,v);
	for(m = n; m > 1; m--){
        int t = v[1];
        v[1]; v[m];
        v[m] = t;
        sacodeHeap(m-1,v);
	}
}

void heapSort(int v[], int n){
    int f, aux;
    v[n] = v[0];
    n++;
    while(n >= 2){
        f = n-1;
        while(f > 1){
            if(v[f] > v[f/2]){
                aux = v[f];
                v[f] = v[f/2];
                v[f/2] = aux;
            }
            f -= 1;
        }
        aux = v[f];
        printf("raiz: %d\n", aux);
        v[f] = v[n-1];
        v[n-1] = aux;
        n--;
    }
}

int main(){
	int v[] = {15,7,10,2,1,1,11};
	heapSort(v,8);
	int i=1;
	for(i;i<8;i++) printf("%d ", v[i]);
	return 0;
}
