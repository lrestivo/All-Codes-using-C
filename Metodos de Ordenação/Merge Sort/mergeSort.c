#include <stdlib.h>

void intercala(int p, int q, int r, int v[]){
	int i, j, k, aux[r-p];
	i = p;	j = q;	k = 0;
	printf("p: %d, q: %d, r: %d\n", p, q, r);

	while(i < q && j < r){
		if(v[i] <= v[j]) {
            printf("v[i]: %d <= v[j]: %d\n", v[i], v[j]);
		    aux[k++] = v[i++];
        }
		else {
		    printf("v[i]: %d <= v[j]: %d\n", v[i], v[j]);
            aux[k++] = v[j++];
		}
	}
	while(i < q) aux[k++] = v[i++];
	while(j < r) aux[k++] = v[j++];
	for(i = p; i < r; ++i) v[i] = aux[i-p];
	for(i=0;i<r;i++) printf("\n %d \n", v[i]);
	free(v);
}

//void outroIntercala(int inicio, int meio, int fim, int n, int v[]){
//    int i, m, k=0, aux[n];
//    i=inicio; m=meio;
//    while(k < (n - fim-inicio)){
//        while(i < meio && v[i] <= v[m]) v[k++] = v[i++];
//        while(m < fim && v[m] <= v[i]) v[k++] = v[m++];
//    }
//    for(k = 0; k < n; k++) printf("%d DENTRO\n", aux[k]);//v[k] = aux[k];
//    free(aux);
//}

void mergeSort(int inicio, int fim, int v[]){
    if(inicio < fim-1){
        int meio = (inicio+fim)/2;
        printf("%d - meio\n", meio);
        printf("inicio: %d, meio: %d, fim: %d\n", inicio, meio, fim);
        printf("chamou inicio, meio \n");
        mergeSort(inicio, meio, v);
        printf("chamou meio, fim \n");
        mergeSort(meio, fim, v);
        printf("chamou intercala \n");
        intercala(inicio,meio,fim,v);
    }
}

void merge_interativo(int n, int v[]){
	int p, r;
	int b = 1;
	while(b < n){
		r = p + 2*b;
		if(r > n) r = n;
		intercala(p, p+b, r, v);
		p += 2*b;
	}
	b = 2*b;
}


int main(){
	int v[] = {1,4,6,1,3,5,6,7,8};
	int i, n = 9;
	for(i=0;i<n;i++) printf("%d ", v[i]);
	printf("\n");
	//intercala(0,3,7,v);
	mergeSort(0,n,v);
	//merge_interativo(n,v);
    for(i=0;i<n;i++) printf("%d ", v[i]);
	return 0;
}
