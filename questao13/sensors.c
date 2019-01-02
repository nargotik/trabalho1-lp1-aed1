/*!
 * @header      sensors.c
 * @abstract    Questao13.
 * @discussion  Funções utilziadas para tratamento de sensores.
 * @author      Daniel Torres <a17442|at|alunos.ipca.pt>
 * @link        Daniel Torres GIT <https://github.com/nargotik>
 * @version     1.0 29 de Dezembro de 2018
 */

#include <stdio.h>
#include <stdlib.h>
#include "sensors.h"
#include "funcoes13.h"


/**
 * Verifica o Total de Sensores atraves do tamanho do ficheiro leituras
 * @return 
 */
int totalSensores() {
    FILE *af;
    af = fopen(SENSORS_FILENAME,"rb+");
    
    int total_sensores = fsize(af) / sizeof(Sensor);
    
    if (af == NULL) {
      // Impossivel abrir o ficheiro ficheiro nao existe (Inicializa)
      total_sensores = -1;
    } else {
      fclose(af);
    } 
    return total_sensores;
}

/**
 * Editar um sensor
 * @param sensores
 * @param total
 * @return 
 */
int editarSensor(Sensor sensores[],int total) {
    
    mostraSensores(sensores,total);
    codigo_t codigo = lerInteiro("Codigo do Sensor a Editar [0-1000]:",0,1000);
    
    int idx = existeSensor(
            codigo,
            sensores, 
            total
    );
    if (idx != -1) {
        // Pode editar
        mostraCabecalho("EDITAR SENSOR");
        sensores[idx].zona  = lerInteiro("Zona do Sensor [0-100]:",0,100);
        sensores[idx].ativo = lerInteiro("Activo [0-1]:",0,1);
        
        // Grava os sensores no ficheiro
        writeSensores(sensores, total);
        return 1;
    } else {
        notice("Sensor nao existe\n");
    }
    return 0;
}


/**
 * Remove um sensor
 * @param sensores
 * @param parametros
 * @return 
 */
int removerSensor(Sensor sensores[],ProgramData *parametros) {
    int removidos = 0;
    codigo_t codigo = lerInteiro("Codigo do Sensor a Remover [0-1000]:",0,1000);
    
    int idx = existeSensor(
            codigo,
            sensores, 
            parametros->total_sensores
    );
    
    if (idx != -1) {
        if (sensores[idx].total_leituras > 0) {
            // Não pode apagar pois tem leituras
            sensores[idx].ativo = 0;
            
            removidos = -2;
        } else {
            // Pode apagar pois nao tem leituras
            sensores[idx] = sensores[ parametros->total_sensores - 1 ];
            
            refreshParametros(parametros);
            
            parametros->total_sensores--;
            
            removidos = 1;
        }
        
        
        // Grava os parametros no ficheiro
        writeParametros(*parametros);
        
        // Grava os sensores no ficheiro
        writeSensores(sensores, parametros->total_sensores);
        
    } else {
        notice("Notice: Sensor não encontrado!");
    }
    return removidos;
}


/**
 * Mostra os sensores e ultimas leituras
 * @param sensores
 * @param total
 */
void mostraSensores(Sensor sensores[],int total) {
    mostraCabecalho("LISTAGEM SENSORES");
    printf("IX \tCOD \tACT \tL \tZN\tULTIMA LEITURA\n");
    for (int i = 0; i < total; i++) {
        
        printf("%d \t%d \t%d \t%d \t%d\t",
                i,
                sensores[i].cod,
                sensores[i].ativo,
                sensores[i].total_leituras,
                sensores[i].zona
                );
        printf("%d-%d-%d %d:%d:%d\n",
                sensores[i].UltimaLeitura.ano,
                sensores[i].UltimaLeitura.mes,
                sensores[i].UltimaLeitura.dia,
                sensores[i].UltimaLeitura.hr,
                sensores[i].UltimaLeitura.min,
                sensores[i].UltimaLeitura.seg
                
                );
    }
    //mostraRodape("LISTAGEM SENSORES");
}


/**
 * insere um Sensor
 * @param sensores
 * @param parametros
 * @return -2 se sensores atingiram o limite / 1 caso tenha sido inserido 1 sensor / 0 caso nao tenha sido inserido
 */
int insereSensor(Sensor sensores[],ProgramData *parametros) {
    if (parametros->total_sensores >= (MAX_SENSORES) ) 
        return -2;

    
    // Le um sensor
    sensores[parametros->total_sensores] = leSensor();
    
    //printf("tot.%d",parametros->total_sensores);
    // Verifica se já existe
    int idx = existeSensor(
            sensores[parametros->total_sensores].cod,
            sensores, 
            parametros->total_sensores
    );
    if (idx == -1) {
        // Para prevenir incoerencias com o total_leituras
        refreshParametros(parametros);
        
        // O sensor não existe grava o sensor e incrementa o total_sensores
        parametros->total_sensores++;
        
        // Grava os parametros no ficheiro
        writeParametros(*parametros);
        
        // Grava os sensores no ficheiro
        writeSensores(sensores, parametros->total_sensores);
        
        return 1;
    } else {
        // Sensor já existe pergunta se quer fazer update
        // @todo
        
        return 0;
    }
    
    return 0;
}


/**
 * Le um sensor
 * @return 
 */
Sensor leSensor() {
    Sensor aux;
    aux.cod                 = lerInteiro("Codigo do Sensor [0-1000]:",0,1000);
    aux.zona                = lerInteiro("Zona do Sensor [0-100]:",0,100);
    aux.ativo               = TRUE;
    aux.UltimaLeitura.ano   = 0;
    aux.UltimaLeitura.mes   = 0;
    aux.UltimaLeitura.dia   = 0;
    aux.UltimaLeitura.hr    = 0;
    aux.UltimaLeitura.min   = 0;
    aux.UltimaLeitura.seg   = 0;
    return aux;
}


/**
 * Verifica se um sensor já existe
 * @param cod
 * @param sensores
 * @param total
 * @return 
 */
int existeSensor(codigo_t cod, Sensor sensores[], int total) {
    for (int i = 0; i < total; i++) {
        if (sensores[i].cod == cod)
            return i;
    }
    return -1;
}

/**
 * Le do ficheiro SENSORS_FILENAME
 * @param sensores
 * @return 
 */
int readSensores(Sensor sensores[], int total) {
  FILE *af;
  int nlidos;

  // Abertura para modo binário
  af = fopen(SENSORS_FILENAME,"rb");
  if (af == NULL) {
      // Impossivel abrir o ficheiro ficheiro nao existe (Inicializa)
      nlidos = -1;
  } else{
    nlidos = fread(&sensores[0], sizeof(Sensor), total , af);
    
    fclose(af);
  }
  return nlidos; 
}

/**
 * Escreve no ficheiro SENSORS_FILENAME os sensores
 * @param sensores
 * @return 
 */
int writeSensores(Sensor sensores[], int total) {
  FILE *af;
  int nescritos=0;

  // Abertura para modo binário
  af = fopen(SENSORS_FILENAME,"wb");
  if (af == NULL) {
      // Impossivel abrir o ficheiro ficheiro nao existe (Inicializa)
      nescritos = -1;
  } else{
    nescritos = fwrite(&sensores[0], sizeof(Sensor), total , af);	
    
    fclose(af);
  }
  return nescritos; 
}
