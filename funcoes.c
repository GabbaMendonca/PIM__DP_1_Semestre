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
*/
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
    ************************************
    $ INICIO_FUNCOES_PALESTRA $
    ====================================
*/

/*
    ====================================
    $ AUXILIARES_PALESTRA $
    ====================================
*/


void exibirPalestra()
{

    LIMPA_TERM
    printf("Nome da Paletra ... : %s\n", palestra[ID_Palestra].nomePalestra);
    printf("Campus ............ : %s\n", palestra[ID_Palestra].campus);
    printf("Data .............. : %d / %d / %d - %d : %d\n", palestra[ID_Palestra].dia, palestra[ID_Palestra].mes, palestra[ID_Palestra].ano, palestra[ID_Palestra].hora, palestra[ID_Palestra].min);

}        


/*
    ====================================
    $ Cadastrar_PALESTRA $
    ====================================
*/

void cadastrarPalestra()
{

    LIMPA_TERM
    printf("\n-=-==-------------------------\n");
    printf("Numero da Palestra : %d\n", (contadorDePalestra));
    ID_Palestra = contadorDePalestra - 1;

    exibirPalestra();
    inserirPalestra();

    exibirPalestra();
    inserirCampus();
    
    exibirPalestra();
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
                printf("Pressione ENTER para continuar ... !");
                getchar();
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




void inserirPalestra()
{    
    printf("\nNome da Palestra : ");
    fgets(palestra[ID_Palestra].nomePalestra,MED,stdin);
}


void inserirCampus()
{   
    printf("\nCampus : ");
    fgets(palestra[ID_Palestra].campus,MED,stdin);
}


void inserirData()
{    
    LIMPA_TERM

        /*
            Evita aparecer lixo quando mostrar a exibir a palestra
        */
        palestra[ID_Palestra].dia = 0;
        palestra[ID_Palestra].mes = 0;
        palestra[ID_Palestra].ano = 0;
        palestra[ID_Palestra].hora = 0;
        palestra[ID_Palestra].min = 0;


        exibirPalestra();
        printf("\n");

        printf("Data \n\n");

        do
        {
            printf("Digite apenas o Dia : ");
            scanf("%d%*c", &palestra[ID_Palestra].dia);

                if (palestra[ID_Palestra].dia >  0   && 
                    palestra[ID_Palestra].dia <= 31  )
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
            scanf("%d%*c", &palestra[ID_Palestra].mes);

                if (palestra[ID_Palestra].mes >  0   &&
                    palestra[ID_Palestra].mes <= 12  )
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
            scanf("%d%*c", &palestra[ID_Palestra].ano);

                if (palestra[ID_Palestra].ano >= ano() && palestra[ID_Palestra].ano < (ano() + 10))
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
            scanf("%d%*c", &palestra[ID_Palestra].hora);

                if (palestra[ID_Palestra].hora >= 0  &&
                    palestra[ID_Palestra].hora <  24 )
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
            scanf("%d%*c", &palestra[ID_Palestra].min);

                if (palestra[ID_Palestra].min >= 0   &&
                    palestra[ID_Palestra].min <  60  )
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


/*
    ====================================
    $ Editar_PALESTRA $
    ====================================
*/


void alteraDadosPalestra()
{ 

    LIMPA_TERM
    //fflush(stdin);
    printf("( 1 ) >>> Nome da Paletra ... : %s", palestra[ID_Palestra].nomePalestra);
    printf("( 2 ) >>> Campus ............ : %s", palestra[ID_Palestra].campus);
    printf("( 3 ) >>> Data .............. : %d / %d / %d - %d : %d\n", palestra[ID_Palestra].dia, palestra[ID_Palestra].mes, palestra[ID_Palestra].ano, palestra[ID_Palestra].hora, palestra[ID_Palestra].min);

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
    ====================================
    $ Pesquisar_PALESTRA $
    ====================================
*/


void pesquisarPalestra()
{
    LIMPA_TERM
    if(palestra[0].dia == 0)
    {
        printf("Nenhuma palestra esta cadastrada");
    }
    else
    {
        printf("\n-==-==------------------------\n");
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

        ID_Palestra = (opc - 1);
        exibirPalestra();

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




void mostarTodasAsPalestras()
{

    printf("| Num  |  Palestra\n\n");

    for(int i = 0; i < (contadorDePalestra - 1); i++)
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

    if (palestra[ID_Palestra].lugaresOcupados >= palestra[ID_Palestra].qtdMaxLugares)
    {
        goto ESGOTADA;
    }

    if (palestra[ID_Palestra].ano < ano())
    {
        goto MINISTRADA;
    }
    else 
    {
        if(palestra[ID_Palestra].ano == ano())
        {
            if(palestra[ID_Palestra].mes < tempo->tm_mon+1)
            {
                goto MINISTRADA;
            }
            else
            { 
                if(palestra[ID_Palestra].dia < tempo->tm_mday)
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


/*
    ====================================
    $ FIM_FUNCOES_PALESTRA $
    ************************************
*/




















/*
    ************************************
    $ INICIO_FUNCOES_PESSOA $
    ====================================
*/

/*
    ====================================
    $ Auxilares_PESSOA $
    ====================================
*/


void exibirPessoa()
{   
    char categoria[20];
    interpretadorDeCategoria( pessoa[ID_Pessoa].categoria, categoria );

    //strcpy(categoria, interpretadorDeCategoria( pessoa[ID_Pessoa].categoria ) ); 

    printf("CPF ............... : %ld\n", pessoa[ID_Pessoa].cpf);
    printf("Nome .............. : %s\n",   pessoa[ID_Pessoa].nome);
    printf("Idade ............. : %d\n", pessoa[ID_Pessoa].idade);
    printf("Email ............. : %s\n",   pessoa[ID_Pessoa].email);
    printf("Categoria ......... : %s\n",   categoria);

}


void interpretadorDeCategoria(int numDaCategoria, char * RetornaStringCategoria)
{
    
    if( numDaCategoria == 1)
    {
        strcpy(RetornaStringCategoria, "Usuario Comum");
    }
    if(numDaCategoria == 2)
    {
        strcpy(RetornaStringCategoria, "Professor");
    }
    if(numDaCategoria == 3)
    {
        strcpy(RetornaStringCategoria, "Convidado");
    }
    if(numDaCategoria == 4)
    {
        strcpy(RetornaStringCategoria, "Deficiente");
    }
}



// char *interpretadorDeCategoria(int numDaCategoria)
// {
//     char StringCategoria[20];

//     if( numDaCategoria == 1)
//     {
//         strcpy(StringCategoria, "Usuario Comum");
//     }
//     if(numDaCategoria == 2)
//     {
//         strcpy(StringCategoria, "Professor");
//     }
//     if(numDaCategoria == 3)
//     {
//         strcpy(StringCategoria, "Convidado");
//     }
//     if(numDaCategoria == 4)
//     {
//         strcpy(StringCategoria, "Deficiente");
//     }

//     return StringCategoria;
// }


/*
    ====================================
    $ Cadastrar_PESSOA $
    ====================================
*/

void cadastrarPessoa()
{
    bool _while = true;

    do
    {

        LIMPA_TERM
        printf("\n-=-=--------------------------\n");
        printf("Numero do Cadastro : %d\n\n", contadorDeCadastros);

        ID_Pessoa = contadorDeCadastros - 1;

        printf("Você quer cadastrar um ?\n\n");

        int categoria = inserirCategoria();

        if( 0 == categoria)
        {
            return;
        }
        else
        {
            inserirPessoa(categoria);
            _while = false;
        }

    }
    while(_while);




    _while = true;

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

                //palestra[ID_Palestra].lugaresOcupados = palestra[ID_Palestra].lugaresOcupados++;

                palestra[ID_Palestra].lugaresOcupados++;

                _while = false;

                printf("Pressione ENTER para continuar ... !");
                getchar();
                getchar();

            break;

            case 'n':
            case 'N':
                alteraDadosPessoa();
            break;

            default:
                printf("Opcão invalida!");
            break;
        }
    }
    while(_while);




    printf("\n\nDeseja escolher uma palestra agora ? ( S / N ) : ");

    char opc3;
    opc3 = getchar();
    fflush(stdin);

    switch(opc3)
    {

        case 's':
        case 'S':
            pesquisarPalestra();
        break;

        case 'n':
        case 'N':
            menuInicial();
        break;

        default:
            printf("Opcão invalida!");
        break;
    }
    
}




void inserirPessoa(int categoria)
{

    LIMPA_TERM
    printf("\n-=-==-------------------------\n");
    exibirPessoa();
    printf("\n\n");
    inserirCpf();

    LIMPA_TERM
    printf("\n-=-==-------------------------\n");
    exibirPessoa();
    printf("\n\n");
    inserirNome();

    LIMPA_TERM
    printf("\n-=-==-------------------------\n");
    exibirPessoa();
    printf("\n\n");
    inserirIdade();

    LIMPA_TERM
    printf("\n-=-==-------------------------\n");
    exibirPessoa();
    printf("\n\n");
    inserirEmail();

    pessoa[ID_Pessoa].categoria = categoria;

}




void inserirCpf()
{
    printf("Digite seu CPF: ");
    scanf("%ld%*c", &pessoa[ID_Pessoa].cpf);
    fflush(stdin);
}

void inserirNome()
{   
    printf("Digite seu nome: ");
    fgets(pessoa[ID_Pessoa].nome, SIZE, stdin);
    fflush(stdin);
}

void inserirIdade()
{
    printf("Digite sua idade: ");
    scanf("%d%*c", &pessoa[ID_Pessoa].idade);
    fflush(stdin);
}

void inserirEmail()
{
    printf("Digite seu email: ");
    fgets(pessoa[ID_Pessoa].email, SIZE, stdin);
    fflush(stdin);
}

int inserirCategoria()
{   
    do
    {
        printf("(1) >>> Usuario Comum\n");
        printf("(2) >>> Professor\n");
        printf("(3) >>> Convidado\n");
        printf("(4) >>> Deficiente\n\n");

        printf("(0) <<< Voltar\n\n");

        printf("Digite a catogoria : ");

        int opc;
        scanf("%d%*c", &opc);
        fflush(stdin);

        if(opc == 0)
        {
            return opc;
        }
        else if(opc > 0 && opc < 5)
        {
            return opc;
        }
        else
        {
            printf("Categoria invalida\n\n");
        }
    }
    while(true);
}


/*
    ====================================
    $ Editar_PESSOA $
    ====================================
*/


void editarCadastro()
{
    alteraDadosPessoa();
}


void alteraDadosPessoa()
{
    
    char categoria[20];
    
    interpretadorDeCategoria( pessoa[ID_Pessoa].categoria, categoria);

    LIMPA_TERM
    printf("( 1 ) >>> CPF ............... : %ld\n", pessoa[ID_Pessoa].cpf);
    printf("( 2 ) >>> Nome .............. : %s\n",   pessoa[ID_Pessoa].nome);
    printf("( 3 ) >>> Idade ............. : %d\n", pessoa[ID_Pessoa].idade);
    printf("( 4 ) >>> Email ............. : %s\n",   pessoa[ID_Pessoa].email);
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
    $ Pesquisar_PESSOA $
    ====================================
*/



void pesquisarPessoa()
{
    menuPesquisarPessoa();
    menu4();
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

        ID_Pessoa = opc - 1;
        LIMPA_TERM
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

//(Trello - Atividade 006) : https://trello.com/c/z2Bv6kdl

void mostarTodasAsPessoas()
{

    printf("| Num  |  Pessoas\n\n");

    for(int i = 0; i < (contadorDeCadastros - 1); i++)
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


void pesquisarPorCPF()
{
    printf("Digite um CPF :");

    long CPF;
    scanf("%ld%*c", &CPF);

    for(int i = 0; i <= contadorDeCadastros ;i++)
    {
        if(CPF == pessoa[i].cpf)
        {   
            ID_Pessoa = i;
            LIMPA_TERM
            exibirPessoa();
            return;
        }
    }

    printf("Não encontrei !");
    pesquisarPessoa();
}


void pesquisarPorID()
{
    LIMPA_TERM
    printf("Digite um ID : ");

    int ID;
    scanf("%d%*c", &ID);

    ID_Pessoa = ID - 1;
    exibirPessoa();
}




/*
    ====================================
    $ FIM_FUNCAO_PESSOA $
    ************************************
*/








/*
    ************************************
    $ INICIO_FUNCOES_TICKET $
    ====================================
*/

void cadastrarTicket(char Fila, int Coluna)
{

    numeroTicket = contadorDeTickets - 1;


    // Pessoa
    strcpy(ticket[numeroTicket].nomePessoa, pessoa[ID_Pessoa].nome);

    ticket[numeroTicket].CPF = pessoa[ID_Pessoa].cpf;
    ticket[numeroTicket].categoria = pessoa[ID_Pessoa].categoria;




    // Palestra
    strcpy(ticket[numeroTicket].palestra, palestra[ID_Pessoa].nomePalestra);
    // Palestrante
    ticket[numeroTicket].dia = palestra[ID_Palestra].dia;
    ticket[numeroTicket].mes = palestra[ID_Palestra].mes;
    ticket[numeroTicket].ano = palestra[ID_Palestra].ano;
    ticket[numeroTicket].hora = palestra[ID_Palestra].hora;
    ticket[numeroTicket].min = palestra[ID_Palestra].min;
    strcpy(ticket[numeroTicket].campus, palestra[ID_Pessoa].campus);




    // assento
    strcpy(&ticket[numeroTicket].fila, &Fila);
    ticket[numeroTicket].coluna = Coluna;

}

void exibirTicket()
{   

    char categoria[20];

    interpretadorDeCategoria( ticket[numeroTicket].categoria, categoria );

    printf("\n--------------- TICKET ---------------\n\n");
    
    printf("Numero do Ticket : %d\n\n", ( numeroTicket + 1 ) );


    printf(" Nome .....: %s \n", ticket[numeroTicket].nomePessoa);
    printf(" CPF ......: %ld \n", ticket[numeroTicket].CPF);
    printf(" Categoria : %s \n\n", categoria);

    printf(" Nome da Palestra : %s \n", palestra[ID_Palestra].nomePalestra);
    // Palestrante
    
    printf(" Data .....: %d / %d / %d \n", palestra[ID_Palestra].dia, palestra[ID_Palestra].mes, palestra[ID_Palestra].ano);
    printf(" Campus ...: %s \n", palestra[ID_Palestra].campus);

    printf(" Assento ..: %c%d", ticket[numeroTicket].fila, ticket[numeroTicket].coluna);

    printf("\n\n--------------------------------------\n\n");

}


/*
    ====================================
    $ FIM_FUNCAO_TICKET $
    ************************************
*/