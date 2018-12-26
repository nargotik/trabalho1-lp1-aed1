/*!
 * @header      main.c
 * @abstract    Questao04
 * @discussion  
 *              
 * @author      Daniel Torres <a17442|at|alunos.ipca.pt>
 * @link        Daniel Torres GIT <https://github.com/nargotik>
 * @version     1.0 7 de Novembro de 2018
 */

#include <stdio.h>
#include "funcoes04.h"

#define INICIO 100
#define FIM 999

/*!
 * @function    main
 * @abstract    main program function.
 */
int main()
{
    // Variavel para armazenar a maior capicua
    unsigned int maior1,maior2;

    // Variavel para armazenar multiplciacao 
    tipo_capicua capicua;
    
    capicua = maior_capicua(INICIO,FIM,&maior1,&maior2);
    
    printf("Maior capicua %u x %u = %llu\n",maior1,maior2,capicua);
}


