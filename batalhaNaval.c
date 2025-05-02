#include<stdio.h>

#define LINHA 10
#define COLUNA 10


int main (){

    int i,j;
    int barco=3;//numero 3 representa cada parte do barco, com 3 casas cada
    int poder=5;//numero 5 sugerido no trabalho para identificar a casa que foi danificada com o poder
    int mapa[LINHA][COLUNA];
    for (i = 0; i < LINHA; i++) {
    for (j = 0; j < COLUNA; j++) {
        mapa[i][j] = 0;//nominando cada indice do mapa com: 0
        }
    }

    //posicionamento dos barcos
    for (j=5;j<8;j++){
        mapa[5][j]=barco;
    }

    for (i=3;i<6;i++){
        mapa[i][2]=barco;
    }

    //alternativa para a diagonal secundária, fazendo o barco de cima para baixo
    /*for (i=1,j=8;i<4 && j>5;i++, j--){
        mapa[i][j]=barco;
    }*/

    //deixei a função da diagonal secundária com o barco de baixo para cima
    for (i=3,j=6;i>0 && j<9;i--, j++){
        mapa[i][j]=barco;
    }

    for (i=6,j=3;i<9 && j<6;i++, j++){
        mapa[i][j]=barco;
    }

    //definição de cada habilidade/poder
    //cone: centro dele D3 ou [2][3]
    for (i=1;i<4;i++){
            for (j=1;j<7;j++){
                if ((i==1 && j==3)||
                    (i==2 && (j>1 && j<5))||
                    (i==3 && (j>0 && j<6))){
                        mapa[i][j]=poder;//coloquei o cono sobrepondo a ponta de um barco propositalmente e a cruz também, o octaedro colocarei em espaços vazios
                }
        }
    }
        //cruz
    for (i=5;i<8;i++){
        for (j=4;j<9;j++){
            if ((i==5 && j==6)||
                (i==6 && (j>3 && j<9))||
                (i==7 && j==6)){
                    mapa[i][j]=poder;
                }
        }
    }

            //octaedro
    for (i=6;i<9;i++){
        for (j=1;j<4;j++){
            if ((i==6 && j==2)||
                (i==7 && (j>0 && j<4))||
                (i==8 && j==2)){
                    mapa[i][j]=poder;
                }
        }
    }

    printf("Esse é o mapa da Batalha Naval: \n");

    printf("\t");//pular uma casa para alinhar com a coluna da esquerda, fixa
    for (i='A';i<='J';i++){//loop para criar o cabeçalho do jogo de A a J, com 10 letras do tamanho do tabuleiro
        printf("%c\t", i);//\t para espaçamento igual entre as letras
    };
    printf("\n\n");//duas linhas puladas para criar uma "camada de proteção" com o cabeçalho e padronizar com o \t, visando melhorar o visual do jogo

    for(i=0;i<LINHA;i++){
        printf("%d\t", i+1);
            for(j=0;j<COLUNA;j++){
                printf("%d\t", mapa[i][j]);
                                }
                    printf("\n\n");//padronizar o espaçamento, deixando o visual quadrado
                        }



return 0;
}