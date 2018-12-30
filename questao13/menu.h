/* 
 * File:   menu.h
 * Author: Daniel Torres <a17442|at|alunos.ipca.pt>
 *
 * Created on 30 de Dezembro de 2018
 */

#ifndef MENU_H
#define MENU_H
#include "sensors.h"
#include "sensors-readings.h"

// Function declaration 
void Menu_0(Sensor sensores[],ProgramData *parametros,Leitura readings[]);
void Menu_1(Sensor sensores[],ProgramData *parametros,Leitura readings[]);
void DashBoard(Sensor sensores[],ProgramData *parametros,Leitura readings[]);
void Menu_0_3(Sensor sensores[],ProgramData *parametros);
void Menu_0_4();
void Menu_0_2(Sensor sensores[],ProgramData *parametros);

#endif /* MENU_H */

