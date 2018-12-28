/*!
 * @header      main.c
 * @abstract    Questao12.
 * @discussion  
 * Desenvolva um programa que faça conversões entre as 
 * duas escalas de temperaturas, Kelvin, Celsius 
 * com base em dois valores de entrada: 
 * i) a escala de conversão pretendida; e 
 * ii) a lista das temperaturas.
 * As entradas 38, ’K’, significam que o utilizador 
 * pretende converter a temperatura 38 Celsius para Kelvin.
 *    - O utilizador deverá poder introduzir n temperaturas;
 *    - Deverá ser apresentada um quadro com todas as temperaturas 
 *      inseridas e a respetiva conversão, 
 *      indicando qual a escala de cada coluna apresentada;
 *      | Kelvin | Kelvin |
 *      |--|--|
 *      |10| 283|
 *      |...| ...|
 * 
 *      Considere as seguintes fórmulas: 
 *      tempC = tempK – 273 
 *      e 
 *      tempK = tempC + 273
 * 
 *      - Deverá ainda informar o utilizador acerca da média das temperaturas, 
 *        assim como a maior e a menor delas, 
 *        na escala original e de conversão;
 * @author      Daniel Torres <a17442|at|alunos.ipca.pt>
 * @link        Daniel Torres GIT <https://github.com/nargotik>
 * @version     1.0 29 de Novembro de 2018
 */


#include <stdio.h>
#include <stdlib.h>
#include "questao12.h"

/*!
 * @function    main
 * @abstract    main program function.
 * @param       argc    ....
 * @param       argv     ....
 * @result      An integer result of this function.
 */
int main()
{
    int temperaturas[MAX_TEMPERATURAS][ESCALAS]; 
    int total = 0;
    
    // Escala a ler
    char escala = lerChar("Insira a escala [K]elvin ou [C]elsius: "," %1[kKcC]");
    int escala_orig = (escala == 'K' ? ENUM_K : ENUM_C);
    int escala_dest = (escala == 'K' ? ENUM_C : ENUM_K);
    
    // Numero de temperaturas a inserir
    int  n      = lerInteiro("Insira a quantidade de temperaturas a inserir:",1 , MAX_TEMPERATURAS);
    
    
    
    total += lerTemperaturas(temperaturas, n , total, escala_orig, escala_dest);
    
    mostraTemperaturas(temperaturas, total, escala_orig);
    
    
    mostraValores(
            minTemperaturas(temperaturas,total,escala_orig),
            maxTemperaturas(temperaturas,total,escala_orig),
            mediaTemperaturas(temperaturas,total,escala_orig),
            escala_orig, 
            escala_dest
            );
    
    return (EXIT_SUCCESS);
}

