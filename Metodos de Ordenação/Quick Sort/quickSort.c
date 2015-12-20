#include <stdlib.h>

int separa(int inicio, int fim, int v[]){
    int esq, dir, pivo, aux;
    esq = inicio;
    dir = fim;
    pivo = v[inicio];
    while(esq < dir){
        while(v[esq] <= pivo){
            esq++;
            printf("esq ++\n");
        }
        while(v[dir] > pivo) {
            dir--;
            printf("dir --\n");
        }
        if(esq < dir){
            printf("troca\n");
            aux = v[esq];
            v[esq] = v[dir];
            v[dir] = aux;
        }
    }
    v[inicio] = v[dir];
    v[dir] = pivo;
    return dir;
}

int separa2 (int p, int r, int v[]){
    int c = v[p];
    int i = p+1;
    int j = r, t;
    while (i <= j) {
        if (v[i] <= c){
            ++i;
        }
        else if (c < v[j]){
            --j;
        }
        else {
            t = v[i];
            v[i] = v[j];
            v[j] = t;
            ++i;
            --j;
      }
   }
   // agora i == j+1
   v[p] = v[j];
   v[j] = c;
   return j;
}
void quickSort(int inicio, int fim, int v[]){
    int pivo;
    if(fim > inicio){
        pivo = separa2(inicio, fim, v);
        printf("pivo: %d\n", pivo);
        quickSort(inicio, pivo-1, v);
        quickSort(pivo+1, fim, v);
    }
}


int main(){
	int v[] = {7,10,13,2,5,8,11,19,1,3,10,28};
	int v2[] = {7,10,13,2,5,8,11};
	int i, n = 7;
	quickSort(0,3,v2);
	for(i=0;i<n;i++) printf("%d ", v[i]);
	return 0;
}
