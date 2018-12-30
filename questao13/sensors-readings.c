/*!
 * @header      sensors-readings.c
 * @abstract    Questao13.
 * @discussion  Funções usadas para leituras de sensores.
 * @author      Daniel Torres <a17442|at|alunos.ipca.pt>
 * @link        Daniel Torres GIT <https://github.com/nargotik>
 * @version     1.0 29 de Dezembro de 2018
 */

#include <stdio.h>
#include <stdlib.h>

#include "sensors.h"
#include "sensors-readings.h"
#include "funcoes13.h"

/**
 * Escreve uma leitura no ficheiro
 * @param cod_sensor
 * @param leitura
 * @param Sensores
 * @param parametros
 * @return 
 */
int escreverLeitura(codigo_t cod_sensor,leitura_t leitura, Sensor Sensores[], ProgramData parametros) {
    int idx_sensor = existeSensor(cod_sensor, Sensores,parametros.total_sensores);
    
    if (idx_sensor==-1 || Sensores[idx_sensor].ativo == 0) 
        return -1;
    
    // Time now functions
    time_t leituratime;
    struct tm * timeinfo;
    
    time(&leituratime);
    timeinfo = localtime ( &leituratime );
    
    // EOF  Time now functions
    
    Leitura reading;
    reading.DataHora.ano = timeinfo->tm_year + 1900;
    reading.DataHora.mes = timeinfo->tm_mon + 1;
    reading.DataHora.dia = timeinfo->tm_mday;
    reading.DataHora.hr  = timeinfo->tm_hour;
    reading.DataHora.min = timeinfo->tm_min;
    reading.DataHora.seg = timeinfo->tm_sec;
    reading.cod_sensor   = cod_sensor;
    reading.tm           = leituratime;
    reading.valor        = leitura;
    writeLeitura(reading);
    
#ifdef DEBUG
    printf ("DATA_HORA LEITURA %s", asctime (timeinfo) );
#endif
    Sensores[idx_sensor].UltimaLeitura.ano  = timeinfo->tm_year + 1900;
    Sensores[idx_sensor].UltimaLeitura.mes  = timeinfo->tm_mon + 1;
    Sensores[idx_sensor].UltimaLeitura.dia  = timeinfo->tm_mday;
    Sensores[idx_sensor].UltimaLeitura.hr   = timeinfo->tm_hour;
    Sensores[idx_sensor].UltimaLeitura.min  = timeinfo->tm_min;
    Sensores[idx_sensor].UltimaLeitura.seg  = timeinfo->tm_sec;
    Sensores[idx_sensor].ul                 = leituratime;
    Sensores[idx_sensor].total_leituras++;
    writeSensores(Sensores,parametros.total_sensores);
    
    // Refresh aos parametros
    refreshParametros(&parametros);
    parametros.total_leituras++;
    writeParametros(parametros);
    
    return 1;
}



/**
 * Escreve uma leitura no fim do ficheiro de leituras
 * @param reading
 * @return 
 */
int writeLeitura(Leitura reading) {
  FILE *af;
  int nescritos=0;

  // Abertura para modo binário
  af = fopen(LEITURAS_FILENAME,"ab+");
  if (af == NULL) {
      // Impossivel abrir o ficheiro ficheiro nao existe (Inicializa)
      nescritos = -1;
  } else{
    nescritos = fwrite(&reading, sizeof(Leitura), 1 , af);	
    
    fclose(af);
  }
  return nescritos; 
}

/**
 * Le as leituras do ficheiro
 * @param readings
 * @return numero de leituras lidas
 */
int readLeituras(Leitura readings[]) {
  FILE *af;
  int nlidos;

  // Abertura para modo binário
  af = fopen(LEITURAS_FILENAME,"rb");
  if (af == NULL) {
      // Impossivel abrir o ficheiro ficheiro nao existe (Inicializa)
      nlidos = -1;
  } else {
    int i = 0;

    while (fread(&readings[i++], sizeof(Leitura), 1, af) == 1);

    nlidos = i-1;
  
    fclose(af);
  }
  return nlidos; 
}


/**
 * Leituras por Zona
 * @param readings
 * @return numero de leituras lidas
 */
int readLeiturasZona(Leitura readings[],zona_t zona, Sensor sensores[], int total_sensores) {
  FILE *af;
  int nlidos;

  // Abertura para modo binário
  af = fopen(LEITURAS_FILENAME,"rb");
  if (af == NULL) {
      // Impossivel abrir o ficheiro ficheiro nao existe (Inicializa)
      nlidos = -1;
  } else {
    Leitura aux_leitura;
    int idx_sensor;
    int i = 0;

    while (fread(&aux_leitura, sizeof(Leitura), 1, af) == 1) {
        idx_sensor = existeSensor(aux_leitura.cod_sensor,sensores,total_sensores);
        if (idx_sensor >= 0 && sensores[idx_sensor].zona == zona) {
            readings[i++] = aux_leitura;
        }
            
    };

    nlidos = i;
  
    fclose(af);
  }
  return nlidos; 
}

/**
 * Leituras por codigo de sensor
 * @param readings
 * @param cod_sensor
 * @return numero de leituras
 */
int readLeiturasSensor(Leitura readings[],codigo_t cod_sensor) {
  FILE *af;
  int nlidos;

  // Abertura para modo binário
  af = fopen(LEITURAS_FILENAME,"rb");
  if (af == NULL) {
      // Impossivel abrir o ficheiro ficheiro nao existe (Inicializa)
      nlidos = -1;
  } else {
    Leitura aux_leitura;
    int i = 0;

    while (fread(&aux_leitura, sizeof(Leitura), 1, af) == 1) {
        if (aux_leitura.cod_sensor == cod_sensor) {
            readings[i++] = aux_leitura;
        }
    };

    nlidos = i;
  
    fclose(af);
  }
  return nlidos; 
}


/**
 * Leituras por Zona para um determinado dia
 * @param readings
 * @return numero de leituras lidas
 */
int readLeiturasZonaDia(Leitura readings[],zona_t zona, Sensor sensores[], int total_sensores, datahora_t dia) {
  FILE *af;
  int nlidos;

  // Abertura para modo binário
  af = fopen(LEITURAS_FILENAME,"rb");
  if (af == NULL) {
      // Impossivel abrir o ficheiro ficheiro nao existe (Inicializa)
      nlidos = -1;
  } else {
    Leitura aux_leitura;
    int idx_sensor;
    int i = 0;

    while (fread(&aux_leitura, sizeof(Leitura), 1, af) == 1) {
        idx_sensor = existeSensor(aux_leitura.cod_sensor,sensores,total_sensores);
        if (
                idx_sensor >= 0 && 
                sensores[idx_sensor].zona == zona &&
                aux_leitura.DataHora.dia == dia.dia &&
                aux_leitura.DataHora.ano == dia.ano &&
                aux_leitura.DataHora.mes == dia.mes
            ) {
            readings[i++] = aux_leitura;
        }
            
    };

    nlidos = i;
  
    fclose(af);
  }
  return nlidos; 
}



/**
 * Leitura minima de um determinado array de leituras
 * @param readings
 * @param total
 * @return 
 */
int minLeitura(Leitura readings[], int total) {
    int min = readings[0].valor;

    for (int i = 1; i < total; i++) {
        if (readings[i].valor < min)
            min = readings[i].valor;
    }
    return min;
}

/**
 * Leitura máxima de um determinado array de leituras
 * @param readings
 * @param total
 * @return 
 */
int maxLeitura(Leitura readings[], int total) {
    int max = readings[0].valor;
    
    for (int i = 1; i < total; i++) {
        if (readings[i].valor > max)
            max = readings[i].valor;
    }
    return max;
}

/**
 * Leitura média de um determinado array de leituras
 * @param readings
 * @param total
 * @return 
 */
float mediaLeitura(Leitura readings[], int total) {
    int somatorio = 0;
    for (int i = 0; i < total; i++) {
        somatorio += readings[i].valor;
    }
    return somatorio / (float)total;
}

/**
 * Ordena leituras
 * @param vetor
 * @param tamanho
 */
void ordenaLeituras(Leitura arr[], int sz) {
    Leitura temp;
    for(int i=0; i < (sz -1); i++ ) {

        for(int j=i+1; j < sz; j++) {
            
            if (arr[j].valor < arr[i].valor) {
                temp = arr[j];
                arr[j] = arr[i];
                arr[i] = temp;
            }
        } /* FOR j */
        
    } /* FOR i */
}


/**
 * Ordena leituras
 * @param vetor
 * @param tamanho
 */
void mostraLeituras(Leitura readings[], int total) { 
    mostraCabecalho("LISTAGEM LEITURAS");
    printf("COD_SENSOR \tVALOR \tDATA\n");
    for (int i = 0; i < total; i++) {
        
        printf("%d        \t%d    ",
                readings[i].cod_sensor,
                readings[i].valor
                );
        printf("%d-%d-%d %d:%d:%d\n",
                readings[i].DataHora.ano,
                readings[i].DataHora.mes,
                readings[i].DataHora.dia,
                readings[i].DataHora.hr,
                readings[i].DataHora.min,
                readings[i].DataHora.seg
                
                );
    }

}