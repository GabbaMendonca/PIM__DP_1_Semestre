/**
* @file Projeto do PIM
*
* @brief Projeto completo do PIM com as funções integradas
*
* @autor(es): Gabriel S. Mendonça, Gabriel A. Maranhão,
*             Lucas Apolonio.
*
* @warning Documentar código é muito importante.
* @todo - Lista do que implementar
* @bug  - Lista de bugs conhecidos
* @Copyright (c) Autores do Projeto. Todos os Direitos reservados.
*/


#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>


#include "_Terminal.h"


#define VETOR 10

#define MIN 3
#define MED 50
#define MAX 100





/*
    ========
    STRUCT'S
    ========
*/
/*
    ====================================
    $ STRUCT_INICIO_CADASTRAR_PALESTRA $
    ====================================
*/

/* 
    inicializando estruturas de variaveis
*/

/**
 * @brief A struct contem os dados das palestras a serem cadsatradas.
 * Para possibilitar que mais de uma pessoa possa ser cadastrada
 * foi inserido um vetor de scructs
 * 
 *      struct PALESTRA palestra[VETOR];
 * 
 * Assim o mesmo criar varios scructs podendo ser acessados atraves do
 * numero do vetor.
 * 
 * Dessa forma cada palestra ganha um numero de cadastro
 * que posteriormente se torna a posição do vetor.
 * 
 */
struct PALESTRA
{
    char nomePalestra[MED];
    char campus[MED];

    int dia;
    int mes;
    int ano;
    
    int hora;
    int min;
    
};

struct PALESTRA palestra[VETOR];

/**
 * @brief Registra a quantidade total de cadstro
 * 
 */
int contadorDePalestra = 0;

/**
 * @brief Recebe o valor a ser acessdo na scruct
 * 
 */
int numPalestra = 0;


/*
    ================
    $STRUCT_FIM_CADASTRAR_PALESTRA$
    ================
*/





/*
    ======================
    PROTOTIPOS DAS FUNÇÕES
    ======================
*/
/*
    ========================================
    $ PROTOTIPOS_INICIO_CADASTRAR_PALESTRA $
    ========================================
*/

/**
 * @brief Função principal que gerencia o cadastro de palestras
 * e a que deve ser chamada no menu.
 * 
 * O programa foi montado de maneira que as funções que inserem uma informação no sistema
 * sejam independentes, de maneira que para alterar é necessario chamar a função que corresponde
 * ao mesmo.
 * 
 * Esta função gerencia as principais tomadas de decisão em cadastro de pessoas.
 * 
 */
void cadastrarPalestra();

void inserirPalestra();
void inserirCampus();
void inserirData();

/**
 * @brief Apenas exibe os dados da palestra de acordo com o valor na veriavel numPalestra
 * 
 */
void exibirPalestra();


/**
 * @brief Contem a rotina de alterar dados caso ja cadastrados no sistema caso seja preciso.
 * 
 *      OBS : A posicao do vetor na variavel global numPalestra ja deve ter sido ajustado para a posição desejada.
 * 
 */
void alteraDadosPalestra();
    

/*
    =====================================
    $ PROTOTIPOS_FIM_CADASTRAR_PALESTRA $
    =====================================
*/











/*
    =======
    FUNÇÕES
    =======
*/
/*
    ====================================
    $ FUNCAO_INICIO_CADASTRAR_PALESTRA $
    ====================================
*/


/* FUNÇÃO DE RETONA O ANO ATUAL NA MAQUINA */

/**
 * @brief Extrai o ano no calendario da maquina
 * 
 * @return int retorna o ano
 */
int ano()
{
    time_t data_tempo;
    time(&data_tempo);
    struct tm *tempo = localtime(&data_tempo);
    struct tm *data = localtime(&data_tempo);

    return data->tm_year + 1900;
}

/* FIM NA FUNÇÃO ANO */




void cadastrarPalestra()
{

    LIMPA_TERM
    printf("Numero da Palestra : %d\n", (contadorDePalestra + 1));
    numPalestra = contadorDePalestra;

    inserirPalestra();
    inserirCampus();
    
    inserirData();

    int aux;
    aux = 0;

    do
    {
        LIMPA_TERM
        exibirPalestra();
        
        printf("\n\nDados estão corretos ? ( S / N ) : ");

        char opc2;
        opc2 = getchar();
        fflush(stdin);

        switch(opc2)
        {
            case 's':
            case 'S':

                printf("Dados gravados com sucesso !\n");
                // GRAVAR DADOS
                contadorDePalestra++;
                printf("Pressione ENTER para sair ... !");
                getchar();
            return;

            case 'n':
            case 'N':
                alteraDadosPalestra();
            break;

            default:
                printf("Opcão invalida!");
            break;
        }
    }
    while(1);

    

}

/* Fim da função cadastrarPalestra */



/* Inicio das funções de controle */

void inserirPalestra()
{    
    printf("\nNome da Palestra : ");
    fgets(palestra[numPalestra].nomePalestra,MED,stdin);
}


void inserirCampus()
{   
    printf("\nCampus : ");
    fgets(palestra[numPalestra].campus,MED,stdin);
}


/* Redebe a data e valida o formato */

void inserirData()
{    
    LIMPA_TERM

        exibirPalestra();
        printf("\n");

        printf("Data \n\n");

        do
        {
            printf("Digite apenas o Dia : ");
            scanf("%d%*c", &palestra[numPalestra].dia);

                if (palestra[numPalestra].dia >  0   && 
                    palestra[numPalestra].dia <= 31  )
                {
                    break;
                }
                else
                {
                    printf("Data invalida ! \n");
                    printf("Pressione ENTER para digitar novamente ... ");
                    getchar();
                    LIMPA_TERM
                }
        }
        while(1);

        exibirPalestra();
        printf("\n");

        printf("Data \n\n");

        do
        {
            printf("Digite apenas o Mes : ");
            scanf("%d%*c", &palestra[numPalestra].mes);

                if (palestra[numPalestra].mes >  0   &&
                    palestra[numPalestra].mes <= 12  )
                {
                    break;
                }
                else
                {
                    printf("Data invalida ! \n");
                    printf("Pressione ENTER para digitar novamente ... ");
                    getchar();
                    LIMPA_TERM
                }
        }
        while(1);

        exibirPalestra();
        printf("\n");

        printf("Data \n\n");

        do
        {
            printf("Digite apenas o Ano : ");
            scanf("%d%*c", &palestra[numPalestra].ano);

                if (palestra[numPalestra].ano > ano() && palestra[numPalestra].ano < (ano() + 10))
                {
                    break;
                }
                else
                {
                    printf("Data invalida ! \n");
                    printf("Pressione ENTER para digitar novamente ... ");
                    getchar();
                    LIMPA_TERM
                }
        }
        while(1);

        exibirPalestra();
        printf("\n");

        printf("Horario \n\n");

        do
        {
            printf("Digite apenas o Hora : ");
            scanf("%d%*c", &palestra[numPalestra].hora);

                if (palestra[numPalestra].hora >= 0  &&
                    palestra[numPalestra].hora <  24 )
                {
                    break;
                }
                else
                {
                    printf("Hora invalida ! \n");
                    printf("Pressione ENTER para digitar novamente ... ");
                    getchar();
                    LIMPA_TERM
                }
        }
        while(1);

        exibirPalestra();
        printf("\n");

        printf("Horario \n\n");

        do
        {
            printf("Digite apenas o Minuto : ");
            scanf("%d%*c", &palestra[numPalestra].min);

                if (palestra[numPalestra].min >= 0   &&
                    palestra[numPalestra].min <  60  )
                {
                    break;
                }
                else
                {
                    printf("Hora invalida ! \n");
                    printf("Pressione ENTER para digitar novamente ... ");
                    getchar();
                    LIMPA_TERM
                }
        }
        while(1);

        exibirPalestra();
        printf("\n");
}









/* Esta função serve para mostrar na tela os dados a grava-los */

void exibirPalestra()
{

    LIMPA_TERM
    printf("Nome da Paletra ... : %s\n", palestra[numPalestra].nomePalestra);
    printf("Campus ............ : %s\n", palestra[numPalestra].campus);
    printf("Data .............. : %d / %d / %d - %d : %d\n", palestra[numPalestra].dia, palestra[numPalestra].mes, palestra[numPalestra].ano, palestra[numPalestra].hora, palestra[numPalestra].min);

}        

/* Fim da função exibir */



/* Apresenta o menu para a alteração dos dados inseridos */

void alteraDadosPalestra()
{ 

    LIMPA_TERM
    //fflush(stdin);
    printf("( 1 ) >>> Nome da Paletra ... : %s", palestra[numPalestra].nomePalestra);
    printf("( 2 ) >>> Campus ............ : %s", palestra[numPalestra].campus);
    printf("( 3 ) >>> Data .............. : %d / %d / %d - %d : %d\n", palestra[numPalestra].dia, palestra[numPalestra].mes, palestra[numPalestra].ano, palestra[numPalestra].hora, palestra[numPalestra].min);

    printf("\n( 0 ) <<< Voltar\n");

    printf("\nDigite a opcção que deseja alterar ?");

    int opc;
    scanf("%d%*c", &opc);

    
    switch (opc)
    {
        case 0:
            return;

        case 1:
            inserirPalestra();
        break;

        case 2:
            inserirCampus();
        break;

        case 3:
            inserirData();
        break;

        default:
            printf("Opc invalida");
        break;
    }

}

/* Fim da função alteraDados */







void mostarTodasAsPalestras()
{

    printf("| Num  |  Palestra\n\n");

    for(int i = 0; i <= contadorDePalestra; i++)
    {
        if(i < 9)
        {
            printf("| 0%d   >  %s\n", (i + 1), palestra[i].nomePalestra);
        }
        else
        {
            printf("| %d   >  %s\n", (i + 1), palestra[i].nomePalestra);
        }
        
    }

    printf("\nDigite o numero da palestra para ver os detalhes : ");

    int opc;
    scanf("%d%*c", &opc);
    fflush(stdin);

    numPalestra = opc - 1;

    exibirPalestra();

    printf("\n\nDeseja confirmar  ? ( S / N ) : ");

    char opc2;
    opc2 = getchar();
    fflush(stdin);

    switch(opc2)
    {
        case 's':
        case 'S':

            printf("Função ainda não produzida!");
            getchar();
            getchar();
        return;

        case 'n':
        case 'N':
            printf("Função ainda não produzida!");
            getchar();
            getchar();
        break;

        default:
            printf("Opcão invalida!");
        break;
    }
}


/*
    ====================================
    $ FUNCAO_INICIO_CADASTRAR_PALESTRA $
    ====================================
*/




/*
    ============
    $$ TESTES $$
    ============
*/

void teste_de_palestra()
{
    
        strcpy(palestra[0].nomePalestra, "Ana");
        strcpy(palestra[1].nomePalestra, "Beatriz");
        strcpy(palestra[2].nomePalestra, "Juliaz");
        strcpy(palestra[3].nomePalestra, "Bianca");
        strcpy(palestra[4].nomePalestra, "Rosa");
        strcpy(palestra[5].nomePalestra, "Sabrina");
        strcpy(palestra[6].nomePalestra, "Leona");
        strcpy(palestra[7].nomePalestra, "Vayne");
        strcpy(palestra[8].nomePalestra, "Diana");
        strcpy(palestra[9].nomePalestra, "She-ra");

        for(int j = 0; j < 10; j++)
        {
            strcpy(palestra[j].campus, "UNIP");
            palestra[j].dia = 11 + j;
            palestra[j].mes = 1 + j;
            palestra[j].ano = 2021 + j;

            palestra[j].hora = 11 + j;
            palestra[j].min = 21 + j;
        }

        contadorDePalestra = 9;

}

/*
    ============
    $$ TESTES $$
    ============
*/





/*
    ==========
    $$ MAIN $$
    ==========
*/

void main()
{
    do
    {   
        LIMPA_TERM
        printf("\n\n");
        printf("1 - Testar Cadastrar Palestra\n");
        //printf("2 - Testar Cadastrar Pessoa\n");

        printf("\n\n");
        printf("Funçoes de Teste");
        printf("\n");

        printf("8 - Popular Banco de Dados de Palestras\n");
        printf("9 - Testar Banco de Dados Cadastro\n");

        
        // printf("3 - Testar Menu Cadstro\n\n");
        // printf("3 - Testar Menu Cadstro\n\n");
        // printf("3 - Testar Menu Cadstro\n\n");

        int opc;
        scanf("%d%*c", &opc);

        switch(opc)
        {
            case 1:
                cadastrarPalestra();
            break;
                
            case 2:
                //cadastrarPessoa();
            break;
                
            case 3:
                //menuPalestra();
            break;



            case 8:
                teste_de_palestra();
            break;

            case 9:
                mostarTodasAsPalestras();
            break;

            default:
                break;
        }
    }while(1);

}


/*
    ==========
    $$ MAIN $$
    ==========
*/