#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#include "_Terminal.h"
#include "_prototipos.h"

/*
    =======
    FUNÇÕES
    =======
*
/*
    ====================================
    $ FUNCAO_INICIO_TEMPO $
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

/*
    ====================================
    $ FUNCAO_FIM_TEMPO $
    ====================================
*/



/*
    ====================================
    $ FUNCAO_INICIO_CADASTRAR_PALESTRA $
    ====================================
*/

void cadastrarPalestra()
{

    LIMPA_TERM
    printf("Numero da Palestra : %d\n", (contadorDePalestra));
    numPalestra = contadorDePalestra - 1;

    inserirPalestra();
    inserirCampus();
    
    inserirData();

    int aux;
    aux = 0;

    do
    {
        LIMPA_TERM
        exibirPalestra(contadorDePalestra);
        
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


        exibirPalestra(contadorDePalestra);
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

        exibirPalestra(contadorDePalestra);
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

        exibirPalestra(contadorDePalestra);
        printf("\n");

        printf("Data \n\n");

        do
        {
            printf("Digite apenas o Ano : ");
            scanf("%d%*c", &palestra[numPalestra].ano);

                if (palestra[numPalestra].ano >= ano() && palestra[numPalestra].ano < (ano() + 10))
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

        exibirPalestra(contadorDePalestra);
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

        exibirPalestra(contadorDePalestra);
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

        exibirPalestra(contadorDePalestra);
        printf("\n");
}




void exibirPalestra(int numDaPalestra)
{

    numPalestra = numDaPalestra - 1;

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
    printf("Numero do Cadastro : %d\n\n", contadorDeCadastros);
    numCadastro = contadorDeCadastros - 1;

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
        exibirPessoa();
        
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
    exibirPessoa();
    printf("\n\n");
    inserirCpf();

    LIMPA_TERM
    exibirPessoa();
    printf("\n\n");
    inserirNome();

    LIMPA_TERM
    exibirPessoa();
    printf("\n\n");
    inserirIdade();

    LIMPA_TERM
    exibirPessoa();
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





void exibirPessoa()
{   

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



/*
    ======
*/




void alteraDadosPessoa()
{
    
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
    printf("( 1 ) >>> CPF ............... : %ld\n", pessoa[numCadastro].cpf);
    printf("( 2 ) >>> Nome .............. : %s\n",   pessoa[numCadastro].nome);
    printf("( 3 ) >>> Idade ............. : %d\n", pessoa[numCadastro].idade);
    printf("( 4 ) >>> Email ............. : %s\n",   pessoa[numCadastro].email);
    printf("( 5 ) >>> Categoria ......... : %s\n",   categoria);

    printf("\n( 0 ) <<< Voltar\n");

    printf("\nDigite a opcção que deseja alterar ? : ");

    int opc;
    scanf("%d%*c", &opc);
    printf("\n");

    
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

        case 5:
            inserirCategoria();
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


void validarPalestra()
{   

    time_t data_tempo;
    time(&data_tempo);
    
    struct tm *tempo = localtime(&data_tempo);

    if (palestra[numPalestra].lugaresOcupados >= palestra[numPalestra].qtdMaxLugares)
    {
        goto ESGOTADA;
    }

    if (palestra[numPalestra].ano < ano())
    {
        goto MINISTRADA;
    }
    else 
    {
        if(palestra[numPalestra].ano == ano())
        {
            if(palestra[numPalestra].mes < tempo->tm_mon+1)
            {
                goto MINISTRADA;
            }
            else
            { 
                if(palestra[numPalestra].dia < tempo->tm_mday)
                {
                    goto MINISTRADA;
                }
                else
                {
                    return;
                }
            }
        }
        else
        {
            return;
        }
    }
    
    

    MINISTRADA:
    
        printf("\n");
        printf("\n ALERTA !!!");
        printf("\n Pelestra ja foi ministrada !!!");

        printf("\n\n Pressione enter para escolher outra palestra ...");
        getchar();
        pesquisarPalestra();

    ESGOTADA:

        printf("\n");
        printf("\n ALERTA !!!");
        printf("\n Pelestra esta esgotada !!!");

        printf("\n\n Pressione enter para escolher outra palestra ...");
        getchar();
        pesquisarPalestra();

}

void pesquisarPalestra()
{
    LIMPA_TERM
    if(palestra[0].dia == 0)
    {
        printf("Nenhuma palestra esta cadastrada");
    }
    else
    {
        mostarTodasAsPalestras();

        printf("\n(0) <<< Voltar\n");

        printf("\nDigite o numero da palestra para ver os detalhes : ");

        int opc;
        scanf("%d%*c", &opc);
        fflush(stdin);

        if (opc == 0)
        {
            menuPesquisar();
        }

        exibirPalestra(opc);

        validarPalestra();

        printf("\n\nDeseja confirmar  ? ( S / N ) : ");

        char opc2;
        opc2 = getchar();
        fflush(stdin);

        switch(opc2)
        {
            case 's':
            case 'S':

                menu6();
                // printf("Função ainda não produzida!");
                // getchar();
                // getchar();
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

//(Trello - Atividade 006) : https://trello.com/c/z2Bv6kdl

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

        printf("\n(0) <<< Voltar\n");

        printf("\nDigite o ID da pessoa para ver os detalhes : ");

        int opc;
        scanf("%d%*c", &opc);
        fflush(stdin);

        if (opc == 0)
        {
            menuPesquisarPessoa();
        }

        numCadastro = opc - 1;
        exibirPessoa();

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
            numCadastro = i;
            exibirPessoa();
            return;
        }
    }

    printf("Não encontrei !");
    return;
}


void pesquisarPorID()
{
    LIMPA_TERM
    printf("Digite um ID : ");

    int ID;
    scanf("%d%*c", &ID);

    numCadastro = ID - 1;
    exibirPessoa();
}


/*
    ======================================
    $ FUNCAO_FIM_PESQUISA_DE_PESSOA $
    ======================================
*/

/*
    =================================
    $ FUNCAO_INICIO_EDITAR_CADASTRO $
    =================================
*/

void editarCadastro()
{
    alteraDadosPessoa();
}

void inserirCategoria()
{

    printf("(1) >>> Usuario Comum\n");
    printf("(2) >>> Professor\n");
    printf("(3) >>> Convidado\n");
    printf("(4) >>> Deficiente\n\n");

    printf("Digite a catogoria : ");
    
    int opc;
    scanf("%d%*c", &opc);
    fflush(stdin);

    if(opc > 0 && opc < 5)
    {
        pessoa[numCadastro].categoria = opc;
    }
    else
    {
        printf("Categoria invalida\n\n");
    }
    
}

/*
    =================================
    $ FUNCAO_INICIO_EDITAR_CADASTRO $
    =================================
*/
