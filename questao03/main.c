/*!
 * @header      main.c
 * @abstract    Questao03
 * @discussion  Crie uma aplicação que solicite ao utilizador 
 *              um número inteiro positivo n e que mostre ao utilizador
 *              o resultado do somatório dos inteiros 
 *              pares existentes no intervalo [0;n]
 * 
 * @author      Daniel Torres <a17442|at|alunos.ipca.pt>
 * @link        Daniel Torres GIT <https://github.com/nargotik>
 * @ref         some reference
 * @version     1.0 7 de Novembro de 2018
 */


#include <stdio.h>


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


int main()
{
    int n;
    do {
        printf("Indique um numero inteiro:");
        scanf("%d",&n);
    } while (!( n>=0 ));
    
    unsigned int somatorio=0;

    for (int i=0 ;i<=n ;i++) {
        
        if (is_par(i))
            somatorio = somatorio + i;
        
    }

    
    printf("Somatorio dos pares: %u - ",somatorio );
}

