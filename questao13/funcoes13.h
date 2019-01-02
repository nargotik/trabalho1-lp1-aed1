/* 
 * File:   funcoes13.h
 * Author: Daniel Torres <a17442|at|alunos.ipca.pt>
 * 
 * Created on 29 de Dezembro de 2018
 */

#ifndef FUNCOES13_H
#define FUNCOES13_H

#include "main.h"
#include "sensors-readings.h"
#include "sensors.h"
#include <stdio.h>

// Function declaration 
int lerInteiro(char* msg, int min, int max);
char lerChar(char* msg, char* rule);
char* lerString(char* msg);
void mostraCabecalho(char* msg);
void mostraRodape(char* msg);
void mostraOpcao(int opcao,char* msg);
void notice(char* msg);
void err(char* msg);
void clearScreen();
void refreshParametros(ProgramData *parametros);
ProgramData readParametros();
int writeParametros(ProgramData aux);
int refreshData(Sensor sensores[],ProgramData *parametros,Leitura readings[]);
datahora_t lerDiaMesAno();
int fsize(FILE *fp);

#endif /* FUNCOES13_H */

