/*!
 * @header      main.c
 * @abstract    Questao04
 * @discussion  
 *              
 * @author      Daniel Torres <a17442|at|alunos.ipca.pt>
 * @link        Daniel Torres GIT <https://github.com/nargotik>
 * @ref         some reference
 * @version     1.0 7 de Novembro de 2018
 */

#include <stdio.h>
#include "funcoes04.h"


/*!
 * @function    main
 * @abstract    main program function.
 */
int main() {
    // Variavel para armazenar a maior capicua
    unsigned int maior1,maior2;

    // Variavel para armazenar multiplciacao
    unsigned int capicua;
    
    capicua = maior_capicua(100,999,&maior1,&maior2);
    
    printf("Maior capicua %u x %u = %u\n",maior1,maior2,capicua);
}


