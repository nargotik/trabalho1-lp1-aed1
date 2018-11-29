/*!
 * @header      funcoes08.c
 * @abstract    Funcoes da Questao08
 * @author      Daniel Torres <a17442|at|alunos.ipca.pt>
 * @link        Daniel Torres GIT <https://github.com/nargotik>
 * @version     1.0 7 de Novembro de 2018
 */

// Reutiliza as funções da questao 3
#include "../questao03/funcoes03.h"

/**
 * Função somatorio questao 08 usando uma subrotina
 * @param numero Numero processar
 * @return somatorio dos pares
 */
unsigned int somatorio(int numero) {
    unsigned int sum=0;
    for (int i=1 ;i<=numero ;i++) {
        if (is_par(i))
            sum += i;
    }
    return sum;
}
