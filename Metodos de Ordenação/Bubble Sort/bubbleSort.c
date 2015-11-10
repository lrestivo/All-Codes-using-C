	#include <stdlib.h>

void bubbleSort(int v[], int n){
    int i,j;
    for(i = n-1; i >= 1; i--){
        printf("i: %d\n", i);
        for(j = 0; j < i ; j++){
            printf("j: %d\n", j);
            if(v[j] > v[j+1]){
                int temp = v[j];
                printf("temp: %d\n", temp);
                v[j] = v[j+1];
                v[j+1] = temp;
            }
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
    	bubbleSort(v, n);
    	for(i=0;i<n;i++) printf("%d ", v[i]);
	return 0;
}

