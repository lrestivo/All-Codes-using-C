void selectSort(int v[], int n){
	int i, j, menor;
	for(i=0; i < n-1; i++){
		menor = i;
		printf("menor: %d\n", menor);
		for(j=i+1; j<n; j++){
			if(v[j] < v[menor]){
                menor = j;
                printf("menor: %d\n", menor);
			}
		}
		int temp = v[i];
		printf("temp: %d\n", temp);
		v[i] = v[menor];
		v[menor] = temp;
	}
}

int main() {
	int v[] = {7,13,10,2,5,8,1};
	int n = 7;
	int i;
	for(i=0;i<n;i++) printf("%d ", v[i]);
	printf("\n");
	selectSort(v,n);
	for(i=0;i<n;i++) printf("%d ",v[i]);
}
