/* 
 * File:   main.h
 * Author: Daniel Torres <a17442|at|alunos.ipca.pt>
 *
 * Created on 29 de Dezembro de 2018
 */

#ifndef MAIN_H
#define MAIN_H


#define DEBUG 1

// Detect SO
#ifdef __unix__         
#define LINUX
#elif defined(_WIN32) || defined(WIN32) 
#define WINDOWS
#endif

#include <time.h>

#define PROGRAMDATA_FILENAME "programdata.dat"

typedef struct datahora_t {
    int dia;
    int mes;
    int ano;
    int hr;
    int min;
    int seg;
} datahora_t;
typedef time_t datahora_t2 ;
typedef int leitura_t ;
typedef int codigo_t ;
typedef int zona_t;

typedef struct ProgramData {
    int total_sensores;
    int total_leituras;
} ProgramData;



#endif /* MAIN_H */

