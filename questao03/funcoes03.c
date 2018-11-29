/*!
 * @header      funcoes03.c
 * @abstract    Funcoes da Questao03
 * 
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
 * @return 1 se par 
 */
int is_impar(int value) {
    return(( value % 2 ) != 0 );
}