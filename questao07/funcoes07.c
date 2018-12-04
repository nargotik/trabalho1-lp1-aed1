/*!
 * @header      funcoes.c
 * @abstract    Funcoes para a resolucao da Questao07.
 * @author      Daniel Torres <a17442|at|alunos.ipca.pt>
 * @link        Daniel Torres GIT <https://github.com/nargotik>
 * @ref         Crivo de Eratóstenes
 *                  https://pt.wikipedia.org/wiki/Crivo_de_Erat%C3%B3stenes
 * @version     1.0 26 de Novembro de 2018
 */

#include "funcoes07.h"




/*!
 * Função que verifica se um dado numero é primo
 * @param n Numero
 * @return boolean
 */
bool is_prime(int n) {
    
    // O 1 e o 2 é primo
    if (n==2) 
        return true;
    if (n==1)
        return true;
    
    // Todos os pares não sao primos
    if (n%2 == 0)
        return false;
    // Proximos numeros primos
    if (n==3 || n==5 || n==7 || n==11 || n==13 || n== 17 || n==19)
        return true;
    // Verifica o resto da divisao por um deles possivel
    if (n%3==0 || n%5==0 || n%7==0 || n%11==0 || n%13==0 || n%17==0 || n%19==0 )
        return false;

    // Caso nao seja um caso destes itera
    // Para i=19 ate i<=sqrt(n)
    int tocheck = sqrt(n);//n / 2; // se n>n/2 entao n % n > 0
    for (int i = 19; i <= tocheck; i = i + 2) { // Os pares ja foram todos verificados
        // Verifica se é divisivel por i
        if (n % i ==0)
            return false;
    }
    return true;
}

/**
 * Função que gera uma quantidade de numeros aleatorios definida nos parametros
 * @param min numero minimo a gerar
 * @param max numero maximo a gerar
 * @param numeros quantidade de numeros
 * @return pointer do array de numeros
 */
int * gera_sequencia(int min, int max, int numeros) {
    int *numero_aleatorio;
    
    numero_aleatorio = (int*) calloc(numeros, sizeof(int));
    
    srand((unsigned) time(NULL));
    
    for (int i=0; i < numeros ;i++) 
        numero_aleatorio[i] = rand() % max + min;
    
    
    return numero_aleatorio;
    
}
