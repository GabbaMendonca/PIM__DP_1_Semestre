
/*  Faz com que o comando de limpar a tela funcione em Lunix e Win
    Usar o camando LIMPA_TERM para limpara tela do terminal.
*/
#if defined(_WIN32) || defined(WIN32)
#define LIMPA_TERM system("cls");
#else
#define LIMPA_TERM system("clear");
#endif