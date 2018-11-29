/*!
 * @header      main.c
 * @abstract    Questao09
 * @discussion  Calculo do somatorio de numeros pares por recursividade de função
 * @author      Daniel Torres <a17442|at|alunos.ipca.pt>
 * @link        Daniel Torres GIT <https://github.com/nargotik>
 * @version     1.0 7 de Novembro de 2018
 */


#include <stdio.h>
// Reutiliza as funções da questao 3
#include "../questao03/funcoes03.h"

#include "funcoes09.h"


void main()
{
    int n=-1;
    do {
        printf("Indique um numero inteiro:");
        scanf(" %d",&n);
        getchar();
    } while (!( n>=0 ));
    
    printf("Somatório dos pares: %u - ",somatorio_recursivo(n));
}

