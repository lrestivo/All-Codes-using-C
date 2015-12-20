#include <stdio.h>
#include <stdlib.h>


void grafoArquivo(int matriz[3][3], char url[]){
    FILE *arquivo; //CRIA PONTEIRO DO TIPO FILE
    arquivo = fopen(url,"r"); //ABRE ARQUIVO

    if(!arquivo){ //VERIFICA SE O ARQUIVO EXISTE
        printf("erro ao ler.\n");//MENSAGEM NO PROMPT
        getchar();//ESPERA TECLA ENTER
        exit(0);//SAI DO PROGRAMA
    }

/** VARRO ARQUIVO RECUPERANDO AS COMBINAÇÕES**/
    char tmp1, tmp2;

    while( fscanf(arquivo, "%c", &tmp1)!= EOF ){ //ENQUANTO O ARQUIVO NÃO FOR NULO, VAI PEGANDO OS CARACTERES
        if(tmp1 == ',') continue;//SE FOR VIRGULA PULA
        fscanf(arquivo, "%c", &tmp2);//RECUPERA SEGUNDO CARACTER
        matriz[tmp2-65][tmp1-65] = 1; //SUBTRAIO VALOR DA TABELA ASCII
    }

    fclose(arquivo); //FECHA ARQUIVO
}

void grafoVetor(int matriz[][3],int linhas, char conj[][2]){
    int i;
    for(i=0; i<linhas; i++){
        matriz[ conj[i][0]-65 ][ conj[i][1]-65 ] = 1;
    }
}

int main()
{
/** INICIA MATRIZ COM 0 EM TODAS POSIÇÕES **/
    int graf[3][3];
    char notacao[][2] ={ {'A','B'},
                         {'A','C'},
                         {'B','A'},
                         {'B','C'},
                         {'C','A'},
                         {'C','B'} };
    int i, j;

//PREENCHE COM ZERO EM TODAS POSIÇOES
    for(i=0;i<3;i++){
        for(j=0;j<3;j++){
            graf[j][i] = 0;
        }
    }

    //grafoArquivo(graf, "grafo.txt");
    grafoVetor(graf, 6, notacao);

/******** IMPRIME A MATRIZ **********/
    for(i=0;i<3;i++){
        printf("\n");
        for(j=0;j<3;j++){
            printf(" %d ", graf[j][i]);
        }
    }

    printf("\n\n");
    system("pause");
    return 0;
}
