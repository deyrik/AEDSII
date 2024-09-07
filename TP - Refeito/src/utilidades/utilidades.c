#include "utilidades.h"

void mostrarMenu() {
    printf("\nMenu de Opções:\n");
    printf("1 - Pesquisar termos\n");
    printf("2 - Mostrar qtd/iddoc de todas as palavras\n");
    printf("3 - Executar calculo de relevância\n");
    printf("4 - Vericar quantidade de inserções\n");
    printf("0 - Sair\n");
    printf("Escolha uma opção: ");
}

void limpaTerminal(){
    printf("\033[H\033[J"); //posiciona o cursor no inicio do terminal (posiçao \033[h) e limpa a partir dai (\033[j)
}

// void espera(int segundos){
//     sleep(segundos);
// }

void mudaCor(int num){
    switch (num){

         //muda a cor no prieiro "" e depois reseta o terminal com o comando: \x1b[0m;

    case 1://VERMELHO
        printf("\x1b[31m\x1b[0m");
        break;

    case 2://AZUL
        printf("\x1b[34m\x1b[0m");
        break;


    case 3://VERDE
        printf("\x1b[32m\x1b[0m");
        break;
    
    default:
        break;    
	}
}