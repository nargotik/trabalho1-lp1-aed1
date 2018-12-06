/*!
 * @header      main.c
 * @abstract    Questao06
 * @discussion  Foi efetuado um questionário a um número indeterminado de 
 *              estudantes numa universidade. A todos os estudantes foi 
 *              solicitado o género, a idade e se está a gostar ou não do 
 *              curso que está a frequentar. Implemente uma aplicação capaz 
 *              de calcular e informar:
 *                  - O número de estudantes entrevistados;
 *                  - Percentagem de estudantes de género feminino e masculino;
 *                  - Quantidade de estudantes de género masculino 
 *                    com menos de 23 anos e que não gostam do curso 
 *                    que estão a frequentar.
 * @author      Daniel Torres <a17442|at|alunos.ipca.pt>
 * @link        Daniel Torres GIT <https://github.com/nargotik>
 * @version     1.0 15 de Novembro de 2018
 */


#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>




/*!
 * @function    main
 * @todo
 */
int main()
{
    char sentinela='S';
    do {
        //scanf(" %c",sentinela);
        puts("Deseja continuar a inserir dados (S/N)?");
        sentinela = getchar();
        //printf("%c %d",sentinela,sentinela == 'S');
        
    } while (sentinela != 'S');
    return (EXIT_SUCCESS);
}

