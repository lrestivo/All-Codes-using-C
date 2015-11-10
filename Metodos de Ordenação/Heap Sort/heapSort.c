#include <stdlib.h>
#include <stdio.h>

void heapSort(int v[], int n){
	int auxN = n;
	while(auxN > 1){
		int aux;
		if(v[auxN] > v[auxN/2]){
			aux = v[auxN];
			v[auxN] = v[auxN/2];
			v[auxN] = aux;
		}
		auxN--;
	}
	v[n] = v[1];
	v--;
}

int main()
{
	int v [] = {2,8,1,4,3,6,5};
	int n = 8
	return 0; 
}