/*
 * Autor: Gabriel de pádua 
 * Data: 30/07
 * Versão: 2.0.2
 * Descrição: criação e teste 
 * 
 * Histórico:
 *  -- -- --
 */
#include "../hash/hash.h"

int main() {
    int pesos[23];
    for (int i = 0; i < 23; i++) {
        pesos[i] = 1;
    }

    int valorAscii = Casting("a", pesos); // pesos estão valendo vezes 1;
    printf("valor de a: %d\n", valorAscii);

    // Testando agora com pesos:
    GeraPesos(pesos);
    valorAscii = Casting("a", pesos); // pesos gerados aleatoriamente 
    printf("valor de <a> com peso: %d\n", valorAscii);

    // Testando hashcode
    int code = (unsigned)Hash_code("a", pesos);
    printf("valor de hashcode de <a> com peso: %d\n", code);

    // Funcionamento das capsulas 
    pont_capsula vetor_de_heads[23] = { NULL }; // Inicializa o array com NULL


	//testando capsula que ja existe e estou add uma lista IdDcoc nela:
	int cogigoHash = Hash_code("exemplo1",pesos);
    insereCapsula(&(vetor_de_heads[cogigoHash]), "exemplo1", 1, 5);
	insere(&(vetor_de_heads[cogigoHash]->idDocQtd),2,9);// prestar atenção no modo como acesso o campo dentro da capsula com & e o caminho;

	//testando imprimir varias capsulas da mesma 
    insereCapsula(&(vetor_de_heads[cogigoHash]), "exemplo2", 2, 3);
    insereCapsula(&(vetor_de_heads[cogigoHash]), "exemplo3", 3, 8);




	//testando imprimir tudo com a tabela hash tendo mais posiçoes preenchidas
	insereCapsula(&(vetor_de_heads[cogigoHash + 1]), "exemplo4", 9, 13);
    insereCapsula(&(vetor_de_heads[cogigoHash + 1]), "exemplo5", 4, 8);
	

	 

    // Imprime todas as capsulas
    printf("Capsulas inseridas (MESMA LINHA):\n");
    imprimeCapsulas(vetor_de_heads[cogigoHash]);
	printf("FIM\n");


	printf("IMPRIMINDO ALL:\n");
	imprimeAllCapsulas((vetor_de_heads),23);
	printf("FIM DO ALL PRINT\n");

    busca(vetor_de_heads, "exemplo1", pesos);

    return 0;
}