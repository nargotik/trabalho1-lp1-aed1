
/* 
 * File:   questao04.h
 * Author: Daniel Torres <a17442|at|alunos.ipca.pt>
 * 
 * Created on 29 de Novembro de 2018
 */

#ifndef FUNCOES04_H
#define FUNCOES04_H

typedef unsigned long long int tipo_capicua; // %lu --- max: 4.294.967.295

tipo_capicua maior_capicua(int de,int ate,unsigned int *maior1,unsigned int *maior2);

tipo_capicua maior_capicua2(int de,int ate,unsigned int *maior1,unsigned int *maior2);

tipo_capicua inverte(tipo_capicua valor);

int is_capicua(tipo_capicua numero);

#endif /* QUESTAO04_H */

