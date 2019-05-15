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
//     scanf("%d%*c", &teatro.filas);
//     //printf("\n");
//     fflush(stdin);

//     printf("\tColunas: ");
//     scanf("%d%*c", &teatro.colunas);
//     fflush(stdin);
//     printf("\n\n");




//     printf("\n\n\n");
//     /* 
//         Validando parametros recebidos
//     */

//     if (teatro.filas < 1 || teatro.colunas < 1)
//     {
//         printf("** Erro: Parametro invalido **\n");
//         //return (NULL);
//     }
// }





void matriz()
{
    teatro.filas++;
    teatro.colunas++;

    /*
        *** ALOCA MATRIZ ***

        Aloca a matriz dinamicamente da memoria.
    */

    int **pointer; /* Ponteiro para inteiros */


    /*
        Aloca o vetor para a posição de filas  
    */
    pointer = (int **)calloc(teatro.filas, sizeof(sizeof(int *)));


    /*
        Aloca o vetor para a posição de colunas
    */

    for (int n = 0; n < teatro.colunas; n++)
    {
        pointer[n] = (int *)calloc(teatro.colunas, sizeof(int));
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

    for (int i = 1; i < teatro.filas; i++)
    {
        pointer[i][0] = 64 + i;
    }


    /* 
        Carrega a fila 0 com os numeros dos lugares 1,2,3,4 ...
    */

    for (int j = 1; j < teatro.colunas; j++)
    {
        pointer[0][j] = j;
    }


    /*
        Carrega todo o resto da matriz com hufen ( ) - espaço - a partir da posição [1][1]
    */

    for (int i = 1; i < teatro.filas; i++)
    {
        for (int j = 1; j < teatro.colunas; j++)
        {
            pointer[i][j] = 32;
        }
    }


    teatro.matriz = pointer;

    teatro.filas--;
    teatro.colunas--;
}


void mostrarMatriz()
{

    int i, j;

    teatro.filas++;
    teatro.colunas++;

    printf("TEATRO\n\n");


    /* Preenche o espaço natriz[0][0] com dois pontos */
    printf("%c%c%c%c%c%c%c%c%c%c", 58, 58, 58, 58, 58, 58, 58, 58, 58, 58);


    /* Carrega na tela a fila 0 onde mostra o numero de cada coluna */
    for (j = 1; j < teatro.colunas; j++)
    {
        printf("[- %d -]", teatro.matriz[0][j]);
    }


    /* Mostra a matriz na tela */

    // Laço responsavel por iniciar as fila da matriz
    for (i = 1; i < teatro.filas; i++)
    {

        // mostar a coluna 0 apresentando as letras respectivas de cada fila
        printf("\n Fila %c | ", teatro.matriz[i][0]);

        // Laço responsavel por mostrar as colunas da matriz
        for (j = 1; j < teatro.colunas; j++)
        {
            if (teatro.matriz[i][j] == 120)
            {
                printf("[ -%c- ]", teatro.matriz[i][j]);
            }
            else
            {
                printf("[  %c  ]", teatro.matriz[i][j]);
            }
        }
    }


    teatro.capacidade = (teatro.filas - 1) * (teatro.colunas - 1);

    /*
        Dados do teaotro para o usuario
    */
    printf("\n\nCapacidade %d Lugares", teatro.capacidade);

    printf("\n\n X - Ocupado(s)");
    printf("  \n @ - Deficiente(s)");
    printf("  \n R - Reservado(s)");

    printf("\n");

    teatro.filas--;
    teatro.colunas--;
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

        // matriz[fila][coluna]
        if (Filas < 'A' ||
            Filas > (teatro.filas + 'A') ||
            Colunas < 1 ||
            Colunas > (teatro.colunas + 1))
        {
            printf("Este lugar não exite !!!\n");
            printf("Pessione ENTER para continuar ... ");
            getchar();
            return;
        }
        else
        {
            //if (teatro.matriz[(Colunas - 64)][(Filas - 64)] == 32)
            //Colunas = 64 - Colunas;
            Filas = Filas - 64;
            
            if (teatro.matriz[Filas][Colunas] == 32)
            {
                teatro.matriz[Filas][Colunas] = 'X';
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