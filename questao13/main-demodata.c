/*!
 * @header      main-demodata.c
 * @abstract    Aplicação para preencher os ficheiros da questao 13
 *              de dados random
 * @author      Daniel Torres <a17442|at|alunos.ipca.pt>
 * @link        Daniel Torres GIT <https://github.com/nargotik>
 * @version     1.0 29 de Dezembro de 2018
 */



#include <stdio.h>
#include <stdlib.h>
#include "main.h"
#include "sensors-readings.h"
#include "sensors.h"
#include "funcoes13.h"

/*!
 * @result      An integer result of this function.
 */
int main(int argc, char** argv)
{
    
    
    return (EXIT_SUCCESS);
}

Sensor geraSensorRandom() {
    Sensor sensores;
    sensores.cod = 1;
    sensores.zona = 1;
    sensores.total_leituras = 0;
    sensores.UltimaLeitura.ano = 0;
    sensores.UltimaLeitura.dia = 0;
    sensores.UltimaLeitura.mes = 0;
    sensores.UltimaLeitura.hr = 0;
    sensores.UltimaLeitura.min = 0;
    sensores.UltimaLeitura.seg = 0;
}
