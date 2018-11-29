/*!
 * @header      main.c
 * @abstract    Resolução Questao07.
 * @discussion  Proponha um programa capaz de gerar de forma automática 
 *              e aleatória uma sequência de 100 números inteiros 
 *              positivos entre 0 e 1000 e que apresente na consola a 
 *              soma e média dos primos existentes na sequência gerada.
 * @author      Daniel Torres <a17442|at|alunos.ipca.pt>
 * @link        Daniel Torres GIT <https://github.com/nargotik>
 * @ref         Crivo de Eratóstenes
 *                  https://pt.wikipedia.org/wiki/Crivo_de_Erat%C3%B3stenes
 * @version     1.0 26 de Novembro de 2018
 */

#include <stdio.h>

#include "questao07.h"

#include "funcoes07.h"



/*!
 * @function    main
 * @abstract    main da questao07.
 */
void main()
{
    // Nao necessario o uso de array no entanto foi utilizado com vista 
    // a uma possivel futura utilizacao da sequencia
    int *numeros_aleatorios;
    
    // Guarda o estado se é primo ou nao
    int primo;
    
    int soma_primos = 0,total_primos = 0;
    
    // Chama função que gera a quantidade necessaria.
    numeros_aleatorios = gera_sequencia(NUMERO_MIN, NUMERO_MAX, NUMEROS);
    
    for (int i=0; i < NUMEROS ;i++) {
        primo = 0;
        if ( is_prime( numeros_aleatorios[i] )) {
            soma_primos = soma_primos + numeros_aleatorios[i];
            total_primos++;
            primo = 1;
        }
        printf("Seq %d - %d %s \n",
                i+1,
                numeros_aleatorios[i],
                primo ? "(Primo)" : ""
                );
    }

    
    // Mostra resultados
    printf("\n====================================================\n"
            "Soma dos (%d) numeros primos na sequencia: %d\n"
            "Média dos numeros primos %.2f"
            "\n\n",
            total_primos,
            soma_primos,
            (total_primos != 0) ? (soma_primos / (float)total_primos) : 0
            );
        
    
}

