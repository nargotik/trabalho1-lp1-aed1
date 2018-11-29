/*!
 * @header      main.c
 * @abstract    Questao08
 * @discussion  Reimplemente a questão 3 para que o cálculo do 
 *              somatório seja efetuado dentro de uma sub-rotina. 
 *              
 *              Crie uma aplicação que solicite ao utilizador 
 *              um número inteiro positivo n e que mostre ao utilizador
 *              o resultado do somatório dos inteiros 
 *              pares existentes no intervalo [0;n]
 * @author      Daniel Torres <a17442|at|alunos.ipca.pt>
 * @link        Daniel Torres GIT <https://github.com/nargotik>
 * @ref         some reference
 * @version     1.0 7 de Novembro de 2018
 */


#include <stdio.h>
#include "../questao03/funcoes03.h"
#include "funcoes08.h"




int main()
{
    int n=-1;
    do {
        printf("Indique um numero inteiro:");
        scanf(" %d",&n);
        getchar();
    } while (!( n>=0 ));
    
    printf("Soma dos pares: %u - ",somatorio(n));
}

