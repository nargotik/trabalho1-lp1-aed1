/* 
 * File:   sensors-readings.h
 * Author: Daniel Torres <a17442|at|alunos.ipca.pt>
 * 
 * Created on 29 de Novembro de 2018
 */

#ifndef SENSORS_READINGS_H
#define SENSORS_READINGS_H

#include "sensors.h"

#define MAX_LEITURAS 100000

#define LEITURAS_FILENAME "leituras.dat"

typedef struct Leitura {
    codigo_t    cod_sensor; 
    struct datahora_t  DataHora; // time_t
    datahora_t2 tm; // future use
    leitura_t   valor;
} Leitura;

// Function declaration 
int leituraTimestampUpdate(int idx_sensor,Sensor Sensores[], ProgramData parametros);
int escreverLeitura(codigo_t cod_sensor,leitura_t leitura, Sensor Sensores[], ProgramData parametros);
int writeLeitura(Leitura reading);
int readLeituras(Leitura leituras[]);
int readLeiturasZona(Leitura readings[],zona_t zona, Sensor sensores[], int total_sensores);
int readLeiturasSensor(Leitura readings[],zona_t zona);
int readLeiturasZonaDia(Leitura readings[],zona_t zona, Sensor sensores[], int total_sensores, datahora_t dia);
int minLeitura(Leitura readings[], int total);
int maxLeitura(Leitura readings[], int total);
float mediaLeitura(Leitura readings[], int total);
void ordenaLeituras(Leitura readings[], int sz);
void mostraLeituras(Leitura readings[], int total);
int totalLeituras();

#endif /* SENSORS_READINGS_H */

