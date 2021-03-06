/**
* @file Projeto do PIM - Projto Integrado Multidisciplinar
*
* @brief Este projeto academico foi desenvolvido pelos alunos da UNIP para o PIM.
* O objetivo geral cadastrar uma pessoa para assistir uma palestra e gerar um ticket.
*
* @autor(es):   Gabriel S. Mendonça,
*               Gabriel A. Maranhão,
*               Lucas Apolonio,
*               Alexandre.
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


#include "_prototipos.h"
#include "_Terminal.h"


/*
    ======================================
    $ FUNCAO_INICIO_MENUS $
    ======================================
*/

// MENU 6 - (Trello - Atividade 014) : https://trello.com/c/lsOI0ECR
void menu6()
{
    do
    {
        printf("\n------------------------------");
        printf("\n (1) >>> Reservar um assento");
        printf("\n (2) >>> Editar Palestra");
        printf("\n (0) <<< Voltar\n\n");

        printf("Digite uma opção : ");

        int opc;
        scanf("%d%*c", &opc);

        switch(opc)
        {
            case 1:
                pesquisarPessoa();
            break;
                
            case 2:
                alteraDadosPalestra();
            break;

            case 0:
                return;

            default:
                printf("Opção Invalida !!!");
            break;
        }
    }
    while(1);
}

// MENU 4 - (Trello - Atividade 007) : https://trello.com/c/cX8Maj2L
void menu4()
{
    
    do
    {
        printf("\n------------------------------");
        printf("\n (1) >>> Editar Cadastro");
        printf("\n (2) >>> Excluir Cadastro");
        printf("\n (3) >>> Reservar um Assento");
        printf("\n (0) <<< Voltar\n\n");

        printf("Digite uma opção : ");

        int opc;
        scanf("%d%*c", &opc);

        switch(opc)
        {
            case 1:
                editarCadastro();
                exibirPessoa();
            break;
                
            case 2:
                
            break;
                
            case 3:
            
                if( reservarUmAssento(pessoa[ID_Pessoa].categoria) )
                {
                    menuInicial();
                }
                else
                {   
                    LIMPA_TERM
                    exibirPessoa();
                    menu4();
                }
                
            break;

            case 0:
                return;

            default:
                printf("Opção Invalida !!!");
            break;
        }
    }
    while(1);
}


// Pesquisar Pessoa - (Trello - Atividade 006) : https://trello.com/c/z2Bv6kdl
void menuPesquisarPessoa()
{   
    do
    {   
        LIMPA_TERM
        printf("\n-==-=-------------------------");
        printf("\n MENU 2.1 PESQUISAR PESSOA \n");
        printf("\n (1) >>> Pesquisar por ID");
        printf("\n (2) >>> Pesquisar por CPF");
        printf("\n (3) >>> Exibir todas as pessoas cadastradas");
        printf("\n\n (0) <<< Voltar\n\n");
        
        printf("Digite uma opção : ");

        int opc;
        scanf("%d%*c", &opc);

        switch(opc)
        {
            case 1:
                pesquisarPorID();
            return;
                
            case 2:
                pesquisarPorCPF();
            return;
                
            case 3:
                exibirTodasAsPessoasCadastradas();
            return;

            case 0:
                menuPesquisar();

            default:
                printf("Opção Invalida !!!");
            break;
        }
    }
    while(1);
}



// MENU 03 - Pesquisar (Trello - Atividade 005) : https://trello.com/c/2hHh8WCf
void menuPesquisar()
{
    int opc;

    do
    {
        LIMPA_TERM
        printf("\n-==---------------------------");
        printf("\n MENU 2 PESQUISAR \n");
        printf("\n (1) >>> Pesquisar Pessoa");
        printf("\n (2) >>> Pesquisar Palestra");
        printf("\n (3) >>> Pesquisar Ticket");
        printf("\n (0) <<< Sair");

        printf("\n\n Escolha uma opação : ");
        scanf("%d%*c", &opc);

        switch (opc)
        {
        case 1:
            pesquisarPessoa();
            break;

        case 2:
            pesquisarPalestra();
            break;

        case 3:
            pesquisarTicket();
            break;

        case 4:
            printf("Função ainda não produzida!");
            //Caminho Menu E-mail
            break;

        case 0:
            menuInicial();
            //exit(1);
            //break;

        default:
            printf("Opação invalida !");
            break;
        }

    } while (opc != 0);
}


/*
    Menu Cadastar - (Trello - Atividade 002 : https://trello.com/c/TMGlx26w)
*/
void menuCadastrar()
{
    //Varivaveis locais
    int opc;

    do
    {
        LIMPA_TERM
        printf("\n-=----------------------------");
        printf("\n MENU CADASTRAR \n");
        printf("\n (1) >>> Cadastrar Pessoa");
        printf("\n (2) >>> Cadastrar Palestra");
        printf("\n\n (0) <<< Voltar");

        printf("\n\n Escolha uma opação : ");
        scanf("%d%*c", &opc);

        switch (opc)
        {
        case 1:
            cadastrarPessoa();
            break;

        case 2:
            cadastrarPalestra();
            break;

        case 0:
            return;
            break;

        default:
            printf("Opção invalida !!!");
            break;
        }

    } while (opc != 0);
}


/*
    Menu Inicial - (Trello - Atividade 002 : https://trello.com/c/TMGlx26w)
*/
void menuInicial()
{
    int opc;

    do
    {
        LIMPA_TERM
        printf("\n------------------------------");
        printf("\n MENU INICIAL \n");
        printf("\n (1) >>> Cadastrar");
        printf("\n (2) >>> Pesquisar");
        printf("\n (3) >>> Sorteio");
        printf("\n (4) >>> E-mail");
        printf("\n\n (0) <<< Sair");

        printf("\n\n Escolha uma opação : ");
        scanf("%d%*c", &opc);

        switch (opc)
        {
        case 1:
            menuCadastrar();
            break;

        case 2:
            menuPesquisar();
            break;

        case 3:
            printf("Função ainda não produzida!");
            //Caminho Menu Sorteio
            break;

        case 4:
            printf("Função ainda não produzida!");
            //Caminho Menu E-mail
            break;

        case 0:
            return;
            //exit(1);
            break;

        default:
            printf("Opação invalida !");
            break;
        }

    } while (opc != 0);
}


/*
    ======================================
    $ FUNCAO_FIM_MENUS $
    ======================================
*/




/*
    =====================================================================================
*/



/*
    ============
    $$ TESTES $$
    ============
*/

void teste_de_palestra()
{

    strcpy(palestra[0].nomePalestra, "Palestra 1");
    strcpy(palestra[1].nomePalestra, "Palestra 2");
    strcpy(palestra[2].nomePalestra, "Palestra 3");
    strcpy(palestra[3].nomePalestra, "Palestra 4");
    strcpy(palestra[4].nomePalestra, "Palestra 5");
    strcpy(palestra[5].nomePalestra, "Palestra 6");
    strcpy(palestra[6].nomePalestra, "Palestra 7");
    strcpy(palestra[7].nomePalestra, "Palestra 8");
    strcpy(palestra[8].nomePalestra, "Palestra 9");
    strcpy(palestra[9].nomePalestra, "Palestra 10");

    for(int j = 0; j < 10; j++)
    {
        strcpy(palestra[j].campus, "UNIP");
        palestra[j].dia = 11 + j;
        palestra[j].mes = 1 + j;
        palestra[j].ano = 2018 + j;

        palestra[j].hora = 11 + j;
        palestra[j].min = 21 + j;

        palestra[j].qtdMaxLugares = 99;
        palestra[j].lugaresOcupados = j + 1;
    }

    contadorDePalestra = 11;

}


void teste_de_pessoa()
{
    strcpy(pessoa[0].nome, "Ana");
    strcpy(pessoa[1].nome, "Beatriz");
    strcpy(pessoa[2].nome, "Julia");
    strcpy(pessoa[3].nome, "Bianca");
    strcpy(pessoa[4].nome, "Rosa");
    strcpy(pessoa[5].nome, "Sabrina");
    strcpy(pessoa[6].nome, "Leona");
    strcpy(pessoa[7].nome, "Vayne");
    strcpy(pessoa[8].nome, "Diana");
    strcpy(pessoa[9].nome, "She-ra");

    // printf("(1) >>> Usuario Comum\n");
    // printf("(2) >>> Professor\n");
    // printf("(3) >>> Convidado\n");
    // printf("(4) >>> Deficiente\n\n");

    for(int c = 0; c <= 2; c++)
    {
        pessoa[c].categoria = 1;
    }
    for(int c = 3; c <= 5; c++)
    {
        pessoa[c].categoria = 2;
    }
    for(int c = 6; c <= 8; c++)
    {
        pessoa[c].categoria = 3;
    }
    
    pessoa[9].categoria = 4;



    for(int j = 0; j < 10; j++)
    {
        pessoa[j].cpf = 11111111111 + j;
        pessoa[j].idade = 21 + j;

        strcpy(pessoa[j].email, "unip.unip@unip.com");
    }

    contadorDeCadastros = 11;
}

void alocar_teatro()
{
    teatro.filas = 10;
    teatro.colunas = 10;

    matriz();

    for(int j = 1; j <= 10; j++)
    {
        teatro.matriz[1][j] = 'R';
        teatro.matriz[2][j] = 'R';
    }

    for(int i = 1; i <= 5; i++)
    {
        teatro.matriz[10][i] = '@';
    }
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

    contadorDePalestra = 1;
    ID_Palestra = 0;

    contadorDeCadastros = 1;
    ID_Pessoa = 0;

    contadorDeTickets = 1;
    numeroTicket = 0;

    teatro.filas = 0;
    teatro.colunas = 0;


    do
    {   
        LIMPA_TERM
        printf("\n\n");
        
        printf("1 - Menu Inicial\n\n");

        printf("2 - Cadastrar Pessoa\n");
        printf("3 - Cadastrar Palestra\n\n");
        
        printf("4 - Pesquisar Pesssoa\n");
        printf("5 - Editar Cadastro\n");

        printf("\n\n");
        printf("Funçoes de Teste");
        printf("\n");

        printf("0 - Rodar todas as funções de teste\n\n");

        printf("10  - Popular Banco de Dados de Pessoas\n");
        printf("11  - Popular Banco de Dados de Palestras\n");
        printf("12  - Alocar teatro\n");
        printf("\n");
        printf("20 - Testar/Vizualizar Banco de Dados Palestra\n");
        
        
        // printf("3 - Testar Menu Cadstro\n\n");
        // printf("3 - Testar Menu Cadstro\n\n");
        // printf("3 - Testar Menu Cadstro\n\n");

        int opc;
        scanf("%d%*c", &opc);

        switch(opc)
        {
            case 0:
                teste_de_pessoa();
                teste_de_palestra();
                alocar_teatro();
            break;

            case 1:
                menuInicial();
            break;
                
            case 2:
                cadastrarPessoa();
            break;
                
            case 3:
                cadastrarPalestra();
            break;

            case 4:
                menuPesquisarPessoa();
            break;

            case 10:
                teste_de_pessoa();
            break;

            case 11:
                teste_de_palestra();
            break;

            case 12:
                alocar_teatro();
            break;

            case 20:
                pesquisarPalestra();
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