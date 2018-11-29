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
#include "funcoes03.h"


int main()
{
    int n=-1;
    do {
        printf("Indique um numero inteiro:");
        scanf("%d",&n);
        getchar(); // Limpa \n do buffer stdin
    } while (!( n>=0 ));
    
    unsigned int somatorio=0;

    for (int i=0 ;i<=n ;i++) {
        
        if (is_par(i))
            somatorio = somatorio + i;
        
    }

    
    printf("Somatorio dos pares: %u - \n",somatorio );
}

