/* 
 * File:   questao02.h
 * Author: Daniel Torres <a17442|at|alunos.ipca.pt>
 * 
 * Created on 7 de Novembro de 2018
 */

#ifndef QUESTAO02_H
#define QUESTAO02_H

#include <stdio.h>
#include <string.h>

// Declaração de constantes
const char* descricao_conta[5] = { 
    "Empresarial Gold",   // Descricao para conta tipo 1
    "Empresarial Silver", // Descricao para conta tipo 2
    "Particular Gold",    // Descricao para conta tipo 3
    "Particular Silver",  // Descricao para conta tipo 4
    "Outros"              // Descricao para conta tipo 5
};
const int premio_conta[5] = { 
    150,  // Bonus para conta tipo 1
    100,  // Bonus para conta tipo 2
    75,   // Bonus para conta tipo 3
    40,   // Bonus para conta tipo 4
    0     // Bonus para conta tipo 5
};
const int numero_contas = sizeof(descricao_conta) / sizeof(char*);

int ler_anos();
float ler_saldo();
int ler_codigoconta();
void mostra_opcoes();


#endif /* QUESTAO02_H */

