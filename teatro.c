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












/*
    =======
    FUNÇÕES
    =======
*/


/*
    ************************************
    $ INICIO_FUNCOES_TEATRO $
    ====================================
*/


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

    if( teatro.filas    == 0 ||
        teatro.colunas  == 0 )
    {
        printf("*** NÃO HÁ NENHUM CAMPUS CADASTRADO ***");
        menuInicial();
    }

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



bool reservarUmAssento(int categoria)
{
    int Coluna;
    char Fila, f;

    LIMPA_TERM
    mostrarMatriz();

    do
    {

        printf("\n");
        printf("\n--------------------------------------");
        printf("\nNão queria estar aqui ???");
        printf("\nDigite 0 (zero) para sair da seleção de lugares ...");
        printf("\n--------------------------------------");

        printf("\n\n Qual a fila do assento ??? : ");
        scanf("%c%*c", &Fila);
        fflush(stdin);

        if(Fila == '0')
        {
            return false;
        }

        printf(" Qual a coluna do assento ??? : ");
        scanf("%d%*c", &Coluna);
        fflush(stdin);

        if(Coluna == 0)
        {
            return false;
        }




        Fila = toupper(Fila);




        // matriz[fila][coluna]

        if (Fila    < 'A'                   ||
            Fila    > ( teatro.filas + 'A' )||
            Coluna  < 1                     ||
            Coluna  > ( teatro.colunas + 1 ) )
        {

            printf("Este lugar não exite !!!\n");
            printf("Pessione ENTER para continuar ... ");
            getchar();

            return false;

        }



        if ( reservar(Fila, Coluna, categoria) )
        {
            LIMPA_TERM
            mostrarMatriz();

            printf("\n\nConfirmar a reserva no assento %c%d ? [S / N] : ", Fila , Coluna);

            char opc2;
            opc2 = getchar();
            fflush(stdin);

            switch(opc2)
            {
                case 's':
                case 'S':

                    cadastrarTicket(Fila, Coluna);
                    
                    printf("\n\n");
                    printf("Dados gravados com sucesso !\n");

                    contadorDeTickets++;
                    printf("Pressione ENTER para exibir o ticket ... !");
                    getchar();
                    getchar();

                    LIMPA_TERM
                    exibirTicket();

                    printf("Pressione qualquer tecla para contuniar ... !!!");
                    getchar();
                    getchar();

                return true;

                case 'n':
                case 'N':
                    
                    limparAssento(Fila, Coluna);

                    return false;
                break;

                default:
                    printf("Opcão invalida!");
                break;
            }


        }
        else
        {
            return false;
        }
        


    }
    while(true);
}


bool reservar(char Fila, int Coluna, int categoria)
{
    Fila = Fila - 64;

    /*
        Usuario comum
    */
    if( categoria == 1 )
    {
        if (teatro.matriz[Fila][Coluna] == '@' ||
            teatro.matriz[Fila][Coluna] == 'R' || 
            teatro.matriz[Fila][Coluna] == 'x' )
        {
            goto ERRO;
        }
        else
        {
            goto OK;
        }
    }
    
    /*
        Professor e convidado
    */
    if( categoria == 2 || categoria == 3 )
    {
        if (teatro.matriz[Fila][Coluna] == '@' || 
            teatro.matriz[Fila][Coluna] == 'x' )
        {
            goto ERRO;
        }
        else
        {
            goto OK;
        }
    }

    /*
        Deficiente
    */
    if( categoria == 4 )
    {
        if (teatro.matriz[Fila][Coluna] == 'R' ||
            teatro.matriz[Fila][Coluna] == 'x' )
        {
            goto ERRO;
        }
        else
        {
            goto OK;
        }
    }


    ERRO:

    LIMPA_TERM

    printf("\n");
    printf("\n--------------------------------------\n");
    printf(" Epa ... Você não pode reservar o assento %c%d !\n", (Fila + 64) , Coluna);
    printf(" Escolha outro assento ...\n\n");
    printf(" Pressione ENTER para continuar ...");
    printf("\n--------------------------------------");
    printf("\n");

    getchar();
    return false;

    OK:

    teatro.matriz[Fila][Coluna] = 'x';
    return true;

}


void limparAssento(char Fila, int Coluna)
{
    Fila = Fila - 64;
    teatro.matriz[Fila][Coluna] = ' ';
}

/*
    ====================================
    $ FIM_FUNCOES_TEATRO $
    ************************************
*/
