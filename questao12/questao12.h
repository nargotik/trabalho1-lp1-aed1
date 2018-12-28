/* 
 * File:   questao12.h
 * Author: Daniel Torres <a17442|at|alunos.ipca.pt>
 *
 * Created on 29 de Novembro de 2018, 0:05
 */

#ifndef QUESTAO12_H
#define QUESTAO12_H

enum tipo_temperatura {
    ENUM_C  = 0,
    ENUM_K  = 1,
};

#define MAX_TEMPERATURAS 50
#define ESCALAS 2

#define MIN_KELVIN -100
#define MAX_KELVIN 500

#define MIN_CELSIUS -100
#define MAX_CELSIUS 500

int lerInteiro(char* msg, int min, int max);
char lerChar(char* msg, char* rule);

int lerTemperaturas(int temperaturas[MAX_TEMPERATURAS][ESCALAS], int n , int sz, int escala_orig, int escala_dest);
float converterTempetatura(int valor, int escala_orig, int escala_dest);
int lerCelsius();
int lerKelvin();
int lerTemperatura(int escala_orig);
void mostraTemperaturas(int temperaturas[MAX_TEMPERATURAS][ESCALAS], int sz, int escala_orig);
int maxTemperaturas(int temperaturas[MAX_TEMPERATURAS][ESCALAS], int sz, int escala_orig);
int minTemperaturas(int temperaturas[MAX_TEMPERATURAS][ESCALAS], int sz, int escala_orig);
float mediaTemperaturas(int temperaturas[MAX_TEMPERATURAS][ESCALAS], int sz, int escala_orig);
void mostraValores(int min, int max, float med,int escala_orig, int escala_dest);

#endif /* QUESTAO12_H */

