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


Sensor geraSensorRandom(codigo_t cod);
int random_number(int min_num, int max_num);

/*!
 * @result      An integer result of this function.
 */
int main(int argc, char** argv)
{
    Sensor sensores[MAX_SENSORES];
    ProgramData parametros;
    
    int aux_leituras;
    codigo_t aux_cod;
    for (int i=0;i < 15; i++) {
        aux_cod = i + 100;
        sensores[i] = geraSensorRandom(aux_cod);
        
        aux_leituras = MAX_LEITURAS / random_number(8,15);
        
        parametros.total_leituras = 0;
        parametros.total_sensores = i+1;
    
        writeSensores(sensores, parametros.total_sensores);
        writeParametros(parametros);
        
        for (int r=0; r < aux_leituras ; r++) {
            // GERA MAX_LEITURAS / random_number(8,10) para cada sensor
            escreverLeitura(
                aux_cod, 
                random_number(0,120), 
                sensores, 
                parametros);
        }
        writeParametros(parametros);
    }

    return (EXIT_SUCCESS);
}

Sensor geraSensorRandom(codigo_t cod) {
    Sensor aux;
    aux.cod = cod;
    aux.zona = random_number(0,5);
    aux.total_leituras = 0;
    aux.UltimaLeitura.ano = 0;
    aux.UltimaLeitura.dia = 0;
    aux.UltimaLeitura.mes = 0;
    aux.UltimaLeitura.hr = 0;
    aux.UltimaLeitura.min = 0;
    aux.UltimaLeitura.seg = 0;
    aux.ativo = 1;
    return aux;
}


int random_number(int min_num, int max_num) {
    int result = 0;


    srand(time(NULL));
    result = rand() % max_num + min_num;
    return result;
}