
#ifndef __PROTOTIPOS_H_
#define __PROTOTIPOS_H_

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

    int qtdMaxLugares;
    int lugaresOcupados;
};

struct PALESTRA palestra[VETOR];

/**
 * @brief Registra a quantidade total de cadstro
 * 
 */
int contadorDePalestra;

/**
 * @brief Recebe o valor a ser acessdo na scruct
 * 
 */
int numPalestra;

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
int contadorDeCadastros;

/**
 * @brief Recebe o valor a ser acessdo na scruct
 * 
 */
int numCadastro;

/*
    ===============================
    $ STRUCT_FIM_CADASTRAR_PESSOA $
    ===============================
*/








/*
    ===============================
    $ STRUCT_INICIO_TEATRO $
    ===============================
*/

/**
 * @brief Aqui estão armazenados todos os dados referente a maitriz de assentos
 * 
 * Em **matriz esta o ponteiro da matriz dinamica
 * 
 */
struct DADOS_MATRIZ
{   
    int **matriz;
    int filas, colunas;
    int capacidade;

    int qtdDefDiponivel;
    
    int qtdLugaresDef;
    int porcentagemDeLugaresDef;
};

struct DADOS_MATRIZ teatro;

/*
    ===============================
    $ STRUCT_FIM_TEATRO $
    ===============================
*/








/*
    ============
    FIM STRUCT'S
    ============
*/




/* 
    =======================================================================
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
 * @brief Apenas exibe os dados de uma palestra
 * 
 * @param numDaPalestra  Recebe o ID da palestra a ser ixibida
 */
void exibirPalestra(int numDaPalestra);


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
 * @brief Apenas exibe o cadastro de uma pessoa
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
    $ PROTOTIPOS_FIM_PESQUISA_DE_PESSOA $
    ========================================
*/
void mostarTodasAsPessoas();
void exibirTodasAsPessoasCadastradas();
void pesquisarPorCPF();
void pesquisarPorID();
void pesquisarPessoa();
/*
    ========================================
    $ PROTOTIPOS_FIM_PESQUISA_DE_PESSOA $
    ========================================
*/
/*
    ========================================
    $ PROTOTIPOS_INICIO_EDITAR_CADASTRO $
    ========================================
*/
void editarCadastro();
/*
    ========================================
    $ PROTOTIPOS_FIM_EDITAR_CADASTRO $
    ========================================
*/

/*
    ========================================
    $ PROTOTIPOS_INICIO_PESQUISAR_PALESTRA $
    ========================================
*/

void validarPalestra();
void pesquisarPalestra();
void menuPesquisar();
/*
    ========================================
    $ PROTOTIPOS_FIM__PESQUISAR_PALESTRA $
    ========================================
*/





/**
 * @brief 
 * 
 * A função aloca na memoria uma matriz dinamica
 * com numero de filas+1 e colunas+1 para o auditorio
 * e retorna uma ponteiro de matriz (m.matriz[][]).
 * 
 * 
 * 
 * A MATRIZ :
 * 
 * A matriz foi alocada de maneira dinamica na memoria, porem,
 * seus dados quantidade de lugares, filas, colunas, assim como,
 * o ponteiro que refenrencia sua posição na memoria
 * estão gurdados em uma struct no arquivo _matriz.h junto com os prototipos
 * da função assim possuindo acesso global dos dados.
 * 
 * 
 * 
 * A ALOCAÇÃO DA MEMORIA :
 *  
 * A coluna 0 serve para identificar as filas por letra,
 * sera carregado o valor de 65 a 90 equivalente A ate Z maiusculas
 * na tabela ASCII.
 *
 * 
 * A fila 0 sera usada para carregar os numeros (1,2,3,4 ... n) para identificar as colunas.
 * 
 * 
 * Desta maneira a gerando a idetificação dos lugares da forma :
 * 
 *      - Coluna A
 *      - Fila 1
 * 
 * ou seja, o assento a ser reservado sera o A1.
 * 
 *               Coluna 1 | Coluna 2 |
 *      Fila A |          |          |
 *      Fila B |          |          |
 * 
 */

void criarMatriz();

void matriz();



/**
 * @brief Mostra a matriz criada na tela do usuario
 * 
 */
void mostrarMatriz();




/**
 * @brief Calcula a porcentagem de deficientes
 * 
 */
void calculaDeficientes();



/**
 * @brief 
 * 
 * @param categoria 
 */
void inserirDadosMatriz(int categoria);


void reservarUmLugar();


int assentos(int **matrizAssentos, char fila, int coluna, int categoria);







/*
    ========================================
    $ PROTOTIPOS_INICIO_MENUS $
    ========================================
*/

void menuInicial();
void menuCadastrar();

void menu4();
void menuPesquisarPessoa();

void menu6();

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

#endif