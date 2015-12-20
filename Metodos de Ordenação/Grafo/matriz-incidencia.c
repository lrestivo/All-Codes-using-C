#include <stdio.h>
#include <stdlib.h>

void grafoArquivo(int matriz[][4], char url[]){
/** DADOS DE ENTRADA COM TRATAMENTO**/
    FILE *arquivo; //CRIA PONTEIRO DO TIPO FILE
    arquivo = fopen(url,"r"); //ABRE ARQUIVO

    if(!arquivo){ //VERIFICA SE O ARQUIVO EXISTE
        printf("erro ao ler.\n");//MENSAGEM NO PROMPT
        getchar();//ESPERA TECLA ENTER
        exit(0);//SAI DO PROGRAMA
    }

/** RECUPERA E SET AS COMBINAÇÕES DO ARQUIVO **/
    char tmp1, tmp2;
    int k = 0; //CONTADOR PARA COLUNA
    while( fscanf(arquivo, "%c", &tmp1)!= EOF ){ //ENQUANTO CHEGAR NO FIM DO ARQUIVO VAI PEGANDO OS CARACTERES, RECUPERA PRIMEIRO CARACTER
        if(tmp1 == ',') continue;//SE ENCONTRAR VIRGULA, VOLTA NO WHILE
        fscanf(arquivo, "%c", &tmp2);//RECUPERA SEGUNDO CARACTER
        matriz[tmp1-65][k] = +1; //SUBTRAIO VALOR DA TABELA ASCII, SET NA [LINHA][COLUNA]
        matriz[tmp2-65][k++] = -1;//SET NA [LINHA][COLUNA]
        printf("  %c%c\t",tmp1,tmp2);
    }

    fclose(arquivo); //FECHA ARQUIVO

}

void grafoVetor(int matriz[][4], int linhas, char conj[][2]){
    int i;
    for(i=0; i<linhas; i++){
        matriz[ conj[i][0]-65 ][ i ] = 1; //[LINHA][COLUNA]
        matriz[ conj[i][1]-65 ][ i ] = -1;
        printf("  %c%c\t",conj[i][0],conj[i][1]);
    }
}

int main()
{
    int grafo[4][4]; //grafo[arestas][vertice]
    int i, j;

    char conjunto[][2] = { {'A','B'},
                           {'A','D'},
                           {'D','B'},
                           {'D','C'} };

/** INICIA MATRIZ COM 0 EM TODAS POSIÇÕES **/
    for(i=0;i<4;i++){
        for(j=0;j<4;j++){
            grafo[j][i] = 0; //PREENCHE COM ZERO
        }
    }

    //grafoArquivo(grafo, "grafo.txt");
    grafoVetor(grafo, 4, conjunto);

/******** IMPRIME MATRIZ **********/
    for(i=0;i<4;i++){
        printf("\n\n%c",i+65);
        for(j=0;j<4;j++){
            printf("  %d\t", grafo[i][j]);
        }
    }

    printf("\n");
    return 0;
}
