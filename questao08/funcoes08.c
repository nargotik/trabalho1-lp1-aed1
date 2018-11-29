/*!
 * @header      funcoes08.c
 * @abstract    Funcoes da Questao08
 * @author      Daniel Torres <a17442|at|alunos.ipca.pt>
 * @link        Daniel Torres GIT <https://github.com/nargotik>
 * @version     1.0 7 de Novembro de 2018
 */


/**
 * Função para verificar se um numero é par
 * 
 * @param value valor a verificar
 * @return 1 se par 
 */
int is_par(int value) {
    return(( value % 2 ) == 0 );
}

/**
 * Função para verificar se um numero é impar
 * 
 * @param value valor a verificar
 * @return 1 se impar 
 */
int is_impar(int value) {
    return(( value % 2 ) != 0 );
}

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
