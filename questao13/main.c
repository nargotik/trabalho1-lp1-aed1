/*!
 * @header      main.c
 * @abstract    Questao13.
 * @discussion  Programa principal.
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
#include "menu.h"

/*!
 * @function    main
 */
int main()
{
    ProgramData parametros;
    parametros.total_leituras = 0;
    parametros.total_sensores = 0;
    
    Sensor Sensores[MAX_SENSORES];
    
    Leitura Leituras[MAX_LEITURAS];
//    Leitura *Leituras = malloc(MAX_LEITURAS * sizeof(Leitura));

    DashBoard(Sensores, &parametros, Leituras);

    return (EXIT_SUCCESS);
}

