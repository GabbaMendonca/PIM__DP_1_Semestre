#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

#include "_prototipos.h"
#include "_Terminal.h"

// void criarMatriz()
// {
//     printf("CRIANDO UM TEATRO\n\n");

//     printf("Digite a quantidade de :\n\n");
//     printf("\tFilas: ");
//     scanf("%d%*c", &teatro[numMatriz].filas);
//     //printf("\n");
//     fflush(stdin);

//     printf("\tColunas: ");
//     scanf("%d%*c", &teatro[numMatriz].colunas);
//     fflush(stdin);
//     printf("\n\n");




//     printf("\n\n\n");
//     /* 
//         Validando parametros recebidos
//     */

//     if (teatro[numMatriz].filas < 1 || teatro[numMatriz].colunas < 1)
//     {
//         printf("** Erro: Parametro invalido **\n");
//         //return (NULL);
//     }
// }





void matriz()
{
    teatro[numMatriz].filas++;
    teatro[numMatriz].colunas++;

    /*
        *** ALOCA MATRIZ ***

        Aloca a matriz dinamicamente da memoria.
    */

    int **pointer; /* Ponteiro para inteiros */


    /*
        Aloca o vetor para a posição de filas  
    */
    pointer = (int **)calloc(teatro[numMatriz].filas, sizeof(sizeof(int *)));


    /*
        Aloca o vetor para a posição de colunas
    */

    for (int n = 0; n < teatro[numMatriz].colunas; n++)
    {
        pointer[n] = (int *)calloc(teatro[numMatriz].colunas, sizeof(int));
    }




    /*
        *** ALOCA MATRIZ ***
    */

    /*
        *** PREENCHENDO A MATRIZ ***
    */

    /* 
        A coluna 0 serve para identificar as filas por letra,
        sera carregado o valor de 65 a 90 equivalente A ate Z maiusculas
        na tabela ASCII.
    */

    for (int i = 1; i < teatro[numMatriz].filas; i++)
    {
        pointer[i][0] = 64 + i;
    }


    /* 
        Carrega a fila 0 com os numeros dos lugares 1,2,3,4 ...
    */

    for (int j = 1; j < teatro[numMatriz].colunas; j++)
    {
        pointer[0][j] = j;
    }


    /*
        Carrega todo o resto da matriz com hufen ( ) - espaço - a partir da posição [1][1]
    */

    for (int i = 1; i < teatro[numMatriz].filas; i++)
    {
        for (int j = 1; j < teatro[numMatriz].colunas; j++)
        {
            pointer[i][j] = 32;
        }
    }


    teatro[numMatriz].matriz = pointer;

    teatro[numMatriz].filas--;
    teatro[numMatriz].colunas--;
}


void mostrarMatriz()
{

    int i, j;

    teatro[numMatriz].filas++;
    teatro[numMatriz].colunas++;

    printf("TEATRO\n\n");


    /* Preenche o espaço natriz[0][0] com dois pontos */
    printf("%c%c%c%c%c%c%c%c%c%c", 58, 58, 58, 58, 58, 58, 58, 58, 58, 58);


    /* Carrega na tela a fila 0 onde mostra o numero de cada coluna */
    for (j = 1; j < teatro[numMatriz].colunas; j++)
    {
        printf("[- %d -]", teatro[numMatriz].matriz[0][j]);
    }


    /* Mostra a matriz na tela */

    // Laço responsavel por iniciar as fila da matriz
    for (i = 1; i < teatro[numMatriz].filas; i++)
    {

        // mostar a coluna 0 apresentando as letras respectivas de cada fila
        printf("\n Fila %c | ", teatro[numMatriz].matriz[i][0]);

        // Laço responsavel por mostrar as colunas da matriz
        for (j = 1; j < teatro[numMatriz].colunas; j++)
        {
            if (teatro[numMatriz].matriz[i][j] == 120)
            {
                printf("[ -%c- ]", teatro[numMatriz].matriz[i][j]);
            }
            else
            {
                printf("[  %c  ]", teatro[numMatriz].matriz[i][j]);
            }
        }
    }


    teatro[numMatriz].capacidade = (teatro[numMatriz].filas - 1) * (teatro[numMatriz].colunas - 1);

    /*
        Dados do teaotro para o usuario
    */
    printf("\n\nCapacidade %d Lugares", teatro[numMatriz].capacidade);

    printf("\n\n X - Ocupado(s)");
    printf("  \n @ - Deficiente(s)");
    printf("  \n R - Reservado(s)");

    printf("\n");

    teatro[numMatriz].filas--;
    teatro[numMatriz].colunas--;
}



void reservarUmLugar()
{
    int Colunas;
    char Filas;
    
    do
    {
        printf("\nQual a fila ? ");
        scanf("%c%*c", &Filas);
        fflush(stdin);

        printf("\nQual a coluna ? ");
        scanf("%d%*c", &Colunas);
        fflush(stdin);

        Filas = toupper(Filas);


        if (Filas < 'A' ||
            Filas > (teatro[numMatriz].filas + 'A') ||
            Colunas < 1 ||
            Colunas > (teatro[numMatriz].colunas + 1))
        {
            printf("Este lugar não exite !!!\n");
            printf("Pessione ENTER para continuar ... ");
            getchar();
            return;
        }
        else
        {
            if (teatro[numMatriz].matriz[Colunas - 64][Filas - 64] == 32)
            {
                teatro[numCadastro].matriz[Colunas - 64][Filas - 64] = 'X';
                return;
            }
            else
            {
                printf("Lugar ocupado");
            }
        }
    }
    while(1);
}