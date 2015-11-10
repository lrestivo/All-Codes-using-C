#include <stdlib.h>


void selectionSort(int v[], int n){
	int i,j, menor;
	for(i = 0; i < n-1; i++){
		menor = i;
		for (j = (i+1); j < n; j++){
			if(v[j] < v[menor]){
				menor = j;
			}
		}
		if(menor != i){
			int temp = v[i];
			v[i] = v[menor];
			v[menor] = temp;
        }
	}
}


int main()
{
    int v[] = {7,13,10,2,5,8,1};
	int n = 7;
	int i;
	for(i=0;i<n;i++) printf("%d ", v[i]);
	printf("\n");
    selectionSort(v, n);
    for(i=0;i<n;i++) printf("%d ", v[i]);
	return 0;
}
