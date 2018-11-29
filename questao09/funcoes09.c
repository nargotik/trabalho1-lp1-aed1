/*!
 * @header      funcoes09.c
 * @abstract    Funcoes09
 * @author      Daniel Torres <a17442|at|alunos.ipca.pt>
 * @link        Daniel Torres GIT <https://github.com/nargotik>
 * @version     1.0 7 de Novembro de 2018
 */

// Reutiliza as funções da questao 3
#include "../questao03/funcoes03.h"

/**
 * Função somatorio questao 08
 * @param numero Numero processar
 * @return somatorio dos pares
 */
unsigned int somatorio_recursivo(int numero) {
    // Se chegar a zero ou numero for negativo retorna 0 e sai da recursividade
    if (numero <= 0) return(0);
    
    // Se for par soma o numero à proxima recursividade senao soma 0
    return ( ( is_par(numero) ? numero : 0 )  + somatorio_recursivo(numero - 1) );
}
