#include <stdio.h>

void ordena(int v[],int inicio, int meio, int fim){
    int g = meio;
    int k=0, m[fim];
    while(meio <= fim){
       if(v[meio]<=v[inicio]){
            m[k]=v[meio];
            meio++;
            k++;
       }
       else{
            m[k]=v[inicio];

            inicio++;
            k++;
       }
       if(inicio==g){
            break;
       }

    }

    if(inicio==g){
        if(k<fim){
            while (k<=fim){
                m[k]=v[meio];
                meio++;
                k++;
            }
        }
        else{
            while (k<=fim){
                m[k]=v[inicio];
                inicio++;
                k++;
            }
        }
    }



    for(k=0; k<fim;k++){
        v[k]=m[k];
    }

}
int main(){

    int v[12]={1,4,6,7,8,10,1,3,5,6,7,8};
    //int v[9]={1,4,6,1,3,5,6,7,8};
    int inicio=0;
    int meio = 6;
    int fim = 12;
    int i;
    ordena(v,inicio,meio,fim);
    //ordena(v,inicio,meio,fim);
    for (i = 0;i<fim;i++){
        printf("%i\n",v[i]);

    }
    system("pause");
    return 0;
}
