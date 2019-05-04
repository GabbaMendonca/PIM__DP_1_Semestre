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
#define SIZE 100





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
    ===============================
    $STRUCT_FIM_CADASTRAR_PALESTRA$
    ===============================
*/
/*
    ==================================
    $ STRUCT_INICIO_CADASTRAR_PESSOA $
    ==================================
*/

/**
 * @brief A struct contem os dados das pessoa a serem cadsatradas.
 * Para possibilitar que mais de uma pessoa possa ser cadastrada
 * foi inserido um vetor de scructs
 * 
 *      struct PESSOA pessoa[VETOR];
 * 
 * Assim o mesmo criar varios scructs podendo ser acessados atraves do
 * numero do vetor.
 * 
 * Dessa forma cada pessoa ganha um numero numero de cadastro
 * que posteriormente se torna a posição do vetor.
 * 
 */
struct PESSOA 
{   
    long  cpf;
    int  categoria;

    char nome[SIZE];
    int  idade;
    char email[SIZE];    
};

struct PESSOA pessoa[VETOR];

/**
 * @brief Registra a quantidade total de cadstro
 * 
 */
int contadorDeCadastros = 0;

/**
 * @brief Recebe o valor a ser acessdo na scruct
 * 
 */
int numCadastro = 0;

/*
    ===============================
    $ STRUCT_FIM_CADASTRAR_PESSOA $
    ===============================
*/
/*
    ============
    FIM STRUCT'S
    ============
*/








/*
    =============================
    INICIO PROTOTIPOS DAS FUNÇÕES
    =============================
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
 * a ação desejada.
 * 
 * Esta função gerencia as principais tomadas de decisão chamando as funções em na ordem a serm excutadas
 * para cadastrar uma pessoas.
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

/**
 * @brief Extrai o ano no calendario da maquina
 * 
 * @return int retorna o ano
 */
int ano();


/*
    ========================================
    $ PROTOTIPOS_FIM_CADASTRAR_PALESTRA $
    ========================================
*/
/*
    ========================================
    $ PROTOTIPOS_INICIO_CADSATRAR_PESSOA $
    ========================================
*/


/**
 * @brief Função principal que gerencia o cadastro de pessoas
 * e a que deve ser chamada no menu.
 * 
 * O programa foi montado de maneira que as funções que inserem uma informação no sistema
 * sejam independentes, de maneira que para alterar é necessario chamar a função que corresponde
 * ao mesmo.
 * 
 * Esta função gerencia as principais tomadas de decisão em cadastro de pessoas.
 * 
 */
void cadastrarPessoa();


/**
 * @brief Função contem a sequencia de cadastro.
 * 
 * @param categoria o paramento vem da função cadastar possoa e indica o tipo de pessoa a ser cadastrado.
 */
void Pessoa(int categoria);

void inserirCpf();
void inserirNome();
void inserirIdade();
void inserirEmail();

/**
 * @brief Apenas exibe o cadastro de um pessoa
 * 
 * @param numDoCadastro Recebe o ID do cadasatro a ser buscado para exibição
 */
void exibirPessoa(int numDoCadastro);

/**
 * @brief Contem a rotina de alterar dados caso ja cadastrados no sistema caso seja preciso.
 * 
 * @obs A posicao do vetor na variavel global numCadastro ja deve ter sido ajustado para a posição desejada.
 * 
 */
void alteraDadosPessoa();

/*
    ========================================
    $ PROTOTIPOS_FIM_CADSATRAR_PESSOA $
    ========================================
*/
/*
    ========================================
    $ PROTOTIPOS_INICIO_MENUS $
    ========================================
*/

void menuInicial();
void menuCadastrar();

/*
    ========================================
    $ PROTOTIPOS_INICIO_MENUS $
    ========================================
*/
/*
    ==========================
    FIM PROTOTIPOS DAS FUNÇÕES
    ==========================
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

int ano()
{
    time_t data_tempo;
    time(&data_tempo);
    struct tm *tempo = localtime(&data_tempo);
    struct tm *data = localtime(&data_tempo);

    return data->tm_year + 1900;
}




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

    

}   /* Fim cadastrarPalestra */




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


void inserirData()
{    
    LIMPA_TERM

        /*
            Evita aparecer lixo quando mostrar a exibir a palestra
        */
        palestra[numPalestra].dia = 0;
        palestra[numPalestra].mes = 0;
        palestra[numPalestra].ano = 0;
        palestra[numPalestra].hora = 0;
        palestra[numPalestra].min = 0;


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




void exibirPalestra()
{

    LIMPA_TERM
    printf("Nome da Paletra ... : %s\n", palestra[numPalestra].nomePalestra);
    printf("Campus ............ : %s\n", palestra[numPalestra].campus);
    printf("Data .............. : %d / %d / %d - %d : %d\n", palestra[numPalestra].dia, palestra[numPalestra].mes, palestra[numPalestra].ano, palestra[numPalestra].hora, palestra[numPalestra].min);

}        





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

/*
    =================================
    $ FUNCAO_FIM_CADASTRAR_PALESTRA $
    =================================
*/
/*
    ====================================
    $ FUNCAO_INICIO_CADASTRAR_PESSOA $
    ====================================
*/

void cadastrarPessoa()
{

    LIMPA_TERM
    printf("Numero do Cadastro : %d\n\n", (contadorDeCadastros + 1));
    numCadastro = contadorDeCadastros;

    printf("Você quer cadastrar um ?\n\n");

    printf("(1) >>> Usuario Comum\n");
    printf("(2) >>> Professor\n");
    printf("(3) >>> Convidado\n");
    printf("(4) >>> Deficiente\n\n");

    printf("(0) <<< Voltar\n\n");

    int opc;
    printf("Opção: ");
    scanf("%d%*c", &opc);
    fflush(stdin);

        switch (opc)
        {
            case 0:
                return;

            case 1:
                Pessoa(1);
            break;

            case 2:
                Pessoa(2);
            break;

            case 3:
                Pessoa(3);
            break;

            case 4:
                Pessoa(4);
            break;

            default:
                break;
        }


/*
    ======
*/


    do
    {
        LIMPA_TERM
        exibirPessoa(contadorDeCadastros);
        
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
                contadorDeCadastros++;
                printf("Pressione ENTER para sair ... !");
                getchar();
            return;

            case 'n':
            case 'N':
                alteraDadosPessoa();
            break;

            default:
                printf("Opcão invalida!");
            break;
        }
    }
    while(1);


}




/*
    ======
*/




void Pessoa(int categoria)
{
    pessoa[numCadastro].categoria = categoria;

    LIMPA_TERM
    exibirPessoa(contadorDeCadastros);
    printf("\n\n");
    inserirCpf();

    LIMPA_TERM
    exibirPessoa(contadorDeCadastros);
    printf("\n\n");
    inserirNome();

    LIMPA_TERM
    exibirPessoa(contadorDeCadastros);
    printf("\n\n");
    inserirIdade();

    LIMPA_TERM
    exibirPessoa(contadorDeCadastros);
    printf("\n\n");
    inserirEmail();

}

void inserirCpf()
{
    printf("Digite seu CPF: ");
    scanf("%ld%*c", &pessoa[numCadastro].cpf);
    fflush(stdin);
}

void inserirNome()
{   
    printf("Digite seu nome: ");
    fgets(pessoa[numCadastro].nome, SIZE, stdin);
    fflush(stdin);
}

void inserirIdade()
{
    printf("Digite sua idade: ");
    scanf("%d%*c", &pessoa[numCadastro].idade);
    fflush(stdin);
}

void inserirEmail()
{
    printf("Digite seu email: ");
    fgets(pessoa[numCadastro].email, SIZE, stdin);
    fflush(stdin);
}




/*
    ======
*/





void exibirPessoa(int numDoCadastro)
{   

    numCadastro = numDoCadastro - 1;

    char categoria[16];
    
    if(pessoa[numCadastro].categoria == 1)
    {
        strcpy(categoria, "Usuario Comum");
    }
    if(pessoa[numCadastro].categoria == 2)
    {
        strcpy(categoria, "Professor");
    }
    if(pessoa[numCadastro].categoria == 3)
    {
        strcpy(categoria, "Convidado");
    }
    if(pessoa[numCadastro].categoria == 4)
    {
        strcpy(categoria, "Deficiente");
    }
    

    LIMPA_TERM
    printf("CPF ............... : %ld\n", pessoa[numCadastro].cpf);
    printf("Nome .............. : %s\n",   pessoa[numCadastro].nome);
    printf("Idade ............. : %d\n", pessoa[numCadastro].idade);
    printf("Email ............. : %s\n",   pessoa[numCadastro].email);
    printf("Categoria ......... : %s\n",   categoria);

}



void alteraDadosPessoa()
{
    LIMPA_TERM
    printf("( 1 ) >>> CPF ............... : %ld\n", pessoa[numCadastro].cpf);
    printf("( 2 ) >>> Nome .............. : %s\n",   pessoa[numCadastro].nome);
    printf("( 3 ) >>> Idade ............. : %d\n", pessoa[numCadastro].idade);
    printf("( 4 ) >>> Email ............. : %s\n",   pessoa[numCadastro].email);
    printf("( 5 ) >>> Categoria ......... : %d\n",   pessoa[numCadastro].categoria);

    printf("\n( 0 ) <<< Voltar\n");

    printf("\nDigite a opcção que deseja alterar ?");

    int opc;
    scanf("%d%*c", &opc);

    
    switch (opc)
    {
        case 0:
            return;

        case 1:
            inserirCpf();
        break;

        case 2:
            inserirNome();
        break;

        case 3:
            inserirIdade();
        break;

        case 4:
            inserirEmail();
        break;

        default:
            printf("Opc invalida");
        break;
    }
}

/*
    ====================================
    $ FUNCAO_FIM_CADASTRAR_PESSOA $
    ====================================
*/
/*
    ======================================
    $ FUNCAO_INICIO_PESQUISA_DE_PALESTRA $
    ======================================
*/

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

}


void pesquisarPalestra()
{

    if(palestra[0].dia == 0)
    {
        printf("Nenhuma palestra esta cadastrada");
    }
    else
    {

        mostarTodasAsPalestras();

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
}



/*
    ======================================
    $ FUNCAO_FIM_PESQUISA_DE_PALESTRA $
    ======================================
*/
/*
    ======================================
    $ FUNCAO_INICIO_PESQUISA_DE_PESSOA $
    ======================================
*/

void mostarTodasAsPessoas()
{

    printf("| Num  |  Pessoas\n\n");

    for(int i = 0; i <= contadorDeCadastros; i++)
    {
        if(i < 9)
        {
            printf("| 0%d   >  %s\n", (i + 1), pessoa[i].nome);
        }
        else
        {
            printf("| %d   >  %s\n", (i + 1), pessoa[i].nome);
        }
        
    }

}


void exibirTodasAsPessoasCadastradas()
{
    if(pessoa[0].cpf == 0)
    {
        printf("Nenhum usuario esta cadastrado");
    }
    else
    {
        mostarTodasAsPessoas();

        printf("\nDigite o ID da pessoa para ver os detalhes : ");

        int opc;
        scanf("%d%*c", &opc);
        fflush(stdin);

        exibirPessoa(opc);

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
}


void pesquisarPorCPF()
{
    printf("Digite um CPF :");

    long CPF;
    scanf("%ld%*c", &CPF);

    for(int i = 0; i <= contadorDeCadastros ;i++)
    {
        if(CPF == pessoa[i].cpf)
        {
            exibirPessoa(i);
            getchar();
            getchar();
            return;
        }
    }

    printf("Não encontrei !");
    getchar();
    getchar();
    return;
}


void pesquisarPorID()
{
    LIMPA_TERM
    printf("Digite um ID :");

    int ID;
    scanf("%d%*c", &ID);

    exibirPessoa(ID);

    getchar();
    getchar();
}


void pesquisarPessoa()
{
    LIMPA_TERM
    printf("1 >>> Pesquisar por ID\n");
    printf("2 >>> Pesquisar por CPF\n");
    printf("3 >>> Exibir todas as pessoas cadastradas\n");
    printf("0 <<< Voltar\n\n");
    
    printf("Digite uma opção :");

    int opc;
    scanf("%d%*c", &opc);

    switch(opc)
    {
        case 1:
            pesquisarPorID();
        break;
            
        case 2:
            pesquisarPorCPF();
        break;
            
        case 3:
            exibirTodasAsPessoasCadastradas();
        break;

        case 0:
            return;

        default:
            printf("Opção Invalida !!!");
        break;
    }
}




/*
    ======================================
    $ FUNCAO_FIM_PESQUISA_DE_PESSOA $
    ======================================
*/






/*
    ======================================
    $ FUNCAO_INICIO_MENUS $
    ======================================
*/

/*
    Menu Cadastro - (Trello - Atividade 002 : https://trello.com/c/TMGlx26w)
*/
void menuCadastrar()
{
    //Varivaveis locais
    int opc;

    do
    {
        LIMPA_TERM
        printf("\n------------------------------");
        printf("\n MENU CADASTRAR ");
        printf("\n (1) >>> Cadastrar Pessoa");
        printf("\n (2) >>> Cadastrar Palestra");
        printf("\n (0) <<< Voltar");

        printf("\n\n Escolha uma opação : ");
        scanf("%d", &opc);

        switch (opc)
        {
        case 1:
            cadastrarPessoa();
            break;

        case 2:
            printf("Função ainda não produzida!");
            //Caminho para Pesquisar
            break;

        case 0:
            return;
            break;

        default:
            printf("Opção invalida !");
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
        printf("\n (0) <<< Sair");

        printf("\n\n Escolha uma opação : ");
        scanf("%d", &opc);

        switch (opc)
        {
        case 1:
            menuCadastrar();
            break;

        case 2:
            printf("Função ainda não produzida!");
            //Caminho Menu Palestra;
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






// void menuPalestra()
// {
//     int opc;

//     do
//     {
//         LIMPA_TERM
//         printf("------------------------------");
//         printf("\n\tMENU PALESTRA ");
//         printf("\n(1) >>> Cadastrar Palestra");
//         printf("\n(2) >>> Pesquisar Palestra");

//         printf("\n\n(0) <<< Voltar\n\n");

//         printf("Opção: ");
//         scanf("%d%*c", &opc);
//         fflush(stdin);

//         switch (opc)
//         {
//         case 1:
//             cadastrarPalestra();
//             break;

//         case 2:
//             //Caminho Menu Palestra;
//             break;

//         case 0:
//             return;

//         default:
//             printf("\n\n\t Valor invalido !");
//             break;
//         }

//         printf("\n\n");

//     } while (1);
// }


/*
    ======================================
    $ FUNCAO_FIM_MENUS $
    ======================================
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
        palestra[j].ano = 2021 + j;

        palestra[j].hora = 11 + j;
        palestra[j].min = 21 + j;
    }

    contadorDePalestra = 9;

}


void teste_de_pessoa()
{
    strcpy(pessoa[0].nome, "Ana");
    strcpy(pessoa[1].nome, "Beatriz");
    strcpy(pessoa[2].nome, "Juliaz");
    strcpy(pessoa[3].nome, "Bianca");
    strcpy(pessoa[4].nome, "Rosa");
    strcpy(pessoa[5].nome, "Sabrina");
    strcpy(pessoa[6].nome, "Leona");
    strcpy(pessoa[7].nome, "Vayne");
    strcpy(pessoa[8].nome, "Diana");
    strcpy(pessoa[9].nome, "She-ra");

    for(int j = 0; j < 10; j++)
    {
        pessoa[j].cpf = 11111111111;
        pessoa[j].idade = 21 + j;
        pessoa[j].categoria = 1;

        strcpy(pessoa[j].email, "unip.unip@unip.com");
    }

    contadorDeCadastros = 9;
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
        
        printf("1 - Menu Inicial\n\n");

        printf("2 - Cadastrar Pessoa\n");
        printf("3 - Cadastrar Palestra\n\n");
        
        printf("4 - Pesquisar Pesssoa\n");

        printf("\n\n");
        printf("Funçoes de Teste");
        printf("\n");

        printf("10  - Popular Banco de Dados de Pessoas\n");
        printf("11  - Popular Banco de Dados de Palestras\n");
        printf("\n");
        printf("20 - Testar/Vizualizar Banco de Dados Palestra\n");
        
        
        // printf("3 - Testar Menu Cadstro\n\n");
        // printf("3 - Testar Menu Cadstro\n\n");
        // printf("3 - Testar Menu Cadstro\n\n");

        int opc;
        scanf("%d%*c", &opc);

        switch(opc)
        {
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
                pesquisarPessoa();
            break;

            case 10:
                teste_de_pessoa();
            break;

            case 11:
                teste_de_palestra();
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