/*!
 * @header      main-sensor.c
 * @abstract    Aplicação de leituras de sensores da biblioteca.
 * @discussion  Aplicação que irá ler e escrever as leituras dos sensores.
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
 * usage programa.exe IDSENSOR VALOR
 * @function    main
 */
int main(int argc, char *argv[])
{
    ProgramData parametros = readParametros();
    
    Sensor Sensores[MAX_SENSORES];
    readSensores(Sensores,parametros.total_sensores);
    
    if (parametros.total_sensores == 0)
        err("ERRO: Nao existem sensores configurados\n");
    
    if (argc != 3) {
#ifdef DEBUG
        mostraSensores(Sensores,parametros.total_sensores);
#endif
        err("ERRO: Parametros Inválidos \n\tUSAGE:programa.exe COD_SENSOR LEITURA\n");

    }
    
    int valorLido = atoi(argv[2]);
    int codSensor = atoi(argv[1]);
    
    int leitura = 
        escreverLeitura(
            codSensor, 
            valorLido, 
            Sensores, 
            parametros);
    
    if (leitura <= 0) {
        err("ERRO: Impossivel escrever leitura (Sensor nao existe)");
#ifdef DEBUG
        mostraSensores(Sensores,parametros.total_sensores);
#endif
    } else {
        notice("OK: Leitura realizada com sucesso");
    }

    
    return (EXIT_SUCCESS);
}

