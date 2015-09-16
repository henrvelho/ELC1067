#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
    //
    char** alocarMatriz(int Linhas,int Colunas);
    void inicializaMatriz(char **matriz, int Linhas, int Colunas);
    void imprimeMatriz(char **matriz, int Linhas, int Colunas);
    void pesquisaMatriz(char **matriz);

    int main(){
        char **matriz = alocarMatriz(12,12);
        inicializaMatriz(matriz, 12, 12);
        imprimeMatriz(matriz, 12, 12);
        pesquisaMatriz(matriz);
        system("pause");

    }


    char** alocarMatriz(int Linhas,int Colunas){
        int i;
        char **matriz = (char**)malloc(Linhas * sizeof(char*));
        for (i = 0; i < Linhas; i++){
           matriz[i] = (char*) malloc(Colunas * sizeof(char));
        }
    return matriz;
    }

    void inicializaMatriz(char **matriz, int Linhas, int Colunas){
         int i, j;
         int minChar = 65, maxChar = 90;
         int caractere;
         srand(time(NULL));
         for (i=0; i< Linhas; i++){
             for(j=0; j<Colunas; j++){
                caractere = rand() % (minChar - maxChar + 1) + minChar;
                matriz[i][j] = caractere;
             }
         }
    }

    void imprimeMatriz(char **matriz, int Linhas, int Colunas){
         int i, j;
         for (i=0; i< Linhas; i++){
             printf("\n");
             for(j=0; j<Colunas; j++){
                printf(" %c ", matriz[i][j]);
             }
         }
         printf("\n");
    }

    void pesquisaMatriz(char **matriz){
        int i=0, j=0, n=0, p=0, t=0; //Contadores
        int k=0;
        char palavra[20][20];
        int encontrada;

        printf("DIGITE O NUMERO DE PALAVRAS DESEJADO: ");
    scanf("%d", &p);

    printf("DIGITE AS PALAVRAS:\n");

    for (i = 0; i < p; i++)
        scanf("%s", palavra[i]); //Armazena as palavras que serão buscadas na matriz.

    printf("RESULTADO:\n");

    for (k = 0; k < p; k++) //Para cada palavra
    {
        //Inicialmente a palavra é considerada Não-Encontrada.
        encontrada = 0;

        for (i = 0; i < n; i++) //Para cada linha da matriz
        {
            for (j = 0; j < n; j++) //Para cada coluna da matriz
            {
                if (palavra[k][0] == matriz[i][j]) //Se primeira letra for encontrada
                {
                    if (palavra[k][1] == matriz[i - 1][j]) //Se a segunda letra for encontrada acima (Norte)
                    {
                        encontrada = 1;

                        for (t = 0; t < strlen(palavra[k]); t++)
                            if (palavra[k][t] != matriz[i - t][j])
                                encontrada = 0;

                        if (encontrada)
                            break;
                    }

                    if (palavra[k][1] == matriz[i + 1][j]) //Se a segunda letra for encontrada abaixo (Sul)
                    {
                        encontrada = 1;

                        for (t = 0; t < strlen(palavra[k]); t++)
                            if (palavra[k][t] != matriz[i + t][j])
                                encontrada = 0;

                        if (encontrada)
                            break;
                    }

                    if (palavra[k][1] == matriz[i][j + 1]) //Se a segunda letra for encontrada a direita (Leste)
                    {
                        encontrada = 1;


                        for (t = 0; t < strlen(palavra[k]); t++)
                            if (palavra[k][t] != matriz[i][j + t])
                                encontrada = 0;

                        if (encontrada)
                            break;
                    }

                    if (palavra[k][1] == matriz[i][j - 1]) //Se a segunda letra for encontrada a esquerda (Oeste)
                    {
                        encontrada = 1;

                        for (t = 0; t < strlen(palavra[k]); t++)
                            if (palavra[k][t] != matriz[i][j - t])
                                encontrada = 0;

                        if (encontrada)
                            break;
                    }

                    if (palavra[k][1] == matriz[i - 1][j + 1]) //Se a segunda letra for encontrada acima-direita (Nordeste)
                    {
                        encontrada = 1;

                        for (t = 0; t < strlen(palavra[k]); t++)
                            if (palavra[k][t] != matriz[i - t][j + t])
                                encontrada = 0;

                        if (encontrada)
                            break;
                    }

                    if (palavra[k][1] == matriz[i - 1][j - 1]) //Se a segunda letra for encontrada acima-esquerda (Noroeste)
                    {
                        encontrada = 1;

                        for (t = 0; t < strlen(palavra[k]); t++)
                            if (palavra[k][t] != matriz[i - t][j - t])
                                encontrada = 0;

                        if (encontrada)
                            break;
                    }

                    if (palavra[k][1] == matriz[i + 1][j + 1]) //Se a segunda letra for encontrada abaixo-direita (Sudeste)
                    {
                        encontrada = 1;

                        for (t = 0; t < strlen(palavra[k]); t++)
                            if (palavra[k][t] != matriz[i + t][j + t])
                                encontrada = 0;

                        if (encontrada)
                            break;
                    }

                    if (palavra[k][1] == matriz[i + 1][j - 1]) //Se a segunda letra for encontrada abaixo-esquerda (Sudoeste)
                    {
                        encontrada = 1;

                        for (t = 0; t < strlen(palavra[k]); t++)
                            if (palavra[k][t] != matriz[i + t][j - t])
                                encontrada = 0;

                        if (encontrada)
                            break;
                    }
                }
            }

            if (encontrada)
                break;
        }
//printf("valor de %i", encontrada);
        //Depois da verificação ele diz se a palavra foi encontrada ou não, então passa para a verificação da próxima palavra.
        if (encontrada)
            printf("%s - PALAVRA ENCONTRADA\n", palavra[k]);
        else
            printf("%s - PALAVRA NAO ENCONTRADA\n", palavra[k]);
    }
}
