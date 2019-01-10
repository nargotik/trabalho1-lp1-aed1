/* 
 * File:   sensors.h
 * Author: Daniel Torres <a17442|at|alunos.ipca.pt>
 * 
 * Created on 29 de Dezembro de 2018
 */

#ifndef SENSORS_H
#define SENSORS_H

// Maximo de sensores possiveis armazenar
#define MAX_SENSORES 30

// Ficheiro que armazena os sensores
#define SENSORS_FILENAME "sensores.dat"

// Tem os tipos de dados necessários
#include "main.h"



typedef enum ativo_t { FALSE=0, TRUE = 1 } ativo_t;

typedef struct Sensor {
    codigo_t cod; 
    struct datahora_t UltimaLeitura; // time_t
    datahora_t2 ul;
    int total_leituras;
    ativo_t ativo;
    zona_t zona;
} Sensor;


// Function declaration 
int readSensores(Sensor sensores[], int total);
int writeSensores(Sensor sensores[], int total);
int existeSensor(codigo_t cod, Sensor sensores[], int total);
Sensor leSensor();
int insereSensor(Sensor sensores[],ProgramData *parametros);
void mostraSensores(Sensor sensores[],int total);
int removerSensor(Sensor sensores[],ProgramData *parametros);
int editarSensor(Sensor sensores[],int total);
int totalSensores();

#endif /* SENSORS_H */

