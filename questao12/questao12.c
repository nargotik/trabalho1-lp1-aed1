/*!
 * @header      questao12.c
 * @abstract    Questao12 functions.
 * @author      Daniel Torres <a17442|at|alunos.ipca.pt>
 * @link        Daniel Torres GIT <https://github.com/nargotik>
 * @version     1.0 29 de Novembro de 2018
 * 
 * */
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

#include "questao12.h"

/**
 * Mostra valores finais pedidos na solução
 * 
 * @param min temperatura minima
 * @param max temperatura maxima
 * @param med temperatura media
 * @param escala_orig escala de origem
 * @param escala_dest escala de destino
 */
void mostraValores(int min, int max, float med,int escala_orig, int escala_dest) {
    printf("\n\n"
           "    |--------\t|-----------\t\n"
           "    | ORIGEM \t| CONVERSAO \t\n"
           "    |--------\t|-----------\t\n"
           "    | %s\t| %s\t\n", 
            (escala_orig == ENUM_K ? "KELVIN ":"CELSIUS"),
            (escala_dest == ENUM_C ? "CELSIUS":"KELVIN ")
            );
    printf("MIN-| %.2f\t| %.2f\t\n", (float)min, converterTempetatura(min,escala_orig,escala_dest));
    printf("MAX-| %.2f\t| %.2f\t\n", (float)max, converterTempetatura(max,escala_orig,escala_dest));
    printf("MED-| %.2f\t| %.2f\t\n", (float)med, converterTempetatura(med,escala_orig,escala_dest));
}

/**
 * Verifica qual a temperatura máxima
 * 
 * @param temperaturas
 * @param sz
 * @param escala_orig
 * @return 
 */
int maxTemperaturas(int temperaturas[MAX_TEMPERATURAS][ESCALAS], int sz, int escala_orig) {
    int max = temperaturas[0][escala_orig];
    for (int i = 0; i < sz; i++) {
        if (temperaturas[i][escala_orig] > max) max = temperaturas[i][escala_orig];
    }
    return max;
}

/**
 * Verifica qual a temperatura minima
 * 
 * @param temperaturas
 * @param sz
 * @param escala_orig
 * @return 
 */
int minTemperaturas(int temperaturas[MAX_TEMPERATURAS][ESCALAS], int sz, int escala_orig) {
    int min = temperaturas[0][escala_orig];
    for (int i = 0; i < sz; i++) {
        if (temperaturas[i][escala_orig] < min) min = temperaturas[i][escala_orig];
    }
    return min;
}

/**
 * Verifica qual a média das temperaturas
 * 
 * @param temperaturas
 * @param sz
 * @param escala_orig
 * @return 
 */
float mediaTemperaturas(int temperaturas[MAX_TEMPERATURAS][ESCALAS], int sz, int escala_orig) {
    int somatorio=0;
    for (int i = 0; i < sz; i++) {
        somatorio += temperaturas[i][escala_orig];
    }
    return ((sz > 0) ? (somatorio / (float)sz) : 0);
}

/**
 * Mostras as temperaturas em forma de tabela mostrando qual a escala original
 * @param temperaturas array das temperaturas
 * @param sz apontador para o final do array
 * @param escala_orig escala original
 */
void mostraTemperaturas(int temperaturas[MAX_TEMPERATURAS][ESCALAS], int sz, int escala_orig) {
    printf("| K%s\t| C%s\t|\n",(escala_orig == ENUM_K ? "*":""),(escala_orig == ENUM_C ? "*":""));
    for (int i = 0; i < sz; i++) {
        printf("| %d%s\t| %d%s\t|\n",
                temperaturas[i][ENUM_K],(escala_orig == ENUM_K ? "*":""),
                temperaturas[i][ENUM_C],(escala_orig == ENUM_C ? "*":"")
                );
    }
}

/**
 * Lê n de temperaturas e colcoa num array
 * 
 * @param temperaturas array de temperaturas
 * @param n numero de temperaturas a ler
 * @param sz apontador do ultimo elemento do array
 * @param escala_orig valor da escala de origem (ver enum tipo_temperatura)
 * @param escala_dest valor da escala de destino (ver enum tipo_temperatura)
 * @return apontador do ultimo elemento do array modificado
 */
int lerTemperaturas(int temperaturas[MAX_TEMPERATURAS][ESCALAS], int n , int sz, int escala_orig, int escala_dest) {

    for (int i = 0; i < n; i++) {
        printf("Temperatura %d ",sz+1);
        
        temperaturas[sz][escala_orig] = lerTemperatura(escala_orig);
        
        // Preenche a temperatura convertida
        temperaturas[sz][escala_dest] = 
                converterTempetatura(
                    temperaturas[sz][escala_orig],
                    escala_orig, 
                    escala_dest
                );
                
        sz++;
    }
    return sz;
}

/**
 * Função que mediante a escala lê uma dada temperatura
 * @param escala_orig escala de origem (ver enum tipo_temperatura)
 * @return Temperatura Lida
 */
int lerTemperatura(int escala_orig) {
    return (escala_orig == ENUM_K) ? lerKelvin() : lerCelsius();
}

/**
 * Lê uma temperatura Kelvin
 * @return Temperatura Lida
 */
int lerKelvin() {
    return lerInteiro("[Kelvin]: ", MIN_KELVIN, MAX_KELVIN);;
}

/**
 * Lê uma temperatura Celsius
 * @return Temperatura Lida
 */
int lerCelsius() {
    return lerInteiro("[Celsius]: ", MIN_CELSIUS, MAX_CELSIUS);;
}

/**
 * Converte uma temperatura entre escalas
 * @param valor valor a converter
 * @param escala_orig valor da escala de origem (ver enum tipo_temperatura)
 * @param escala_dest valor da escala de destino (ver enum tipo_temperatura)
 * @return valor convertido
 */
float converterTempetatura(int valor, int escala_orig, int escala_dest) {
    // Converte de Kelvin para Celsius
    if (escala_orig == ENUM_K && escala_dest == ENUM_C) {
        return(valor-273);
    }
    // Converte de Celsius para Kelvin
    if (escala_orig == ENUM_C && escala_dest == ENUM_K) {
        return(valor+273);
    }
    return(0);
}


/**
 * Le um inteiro
 * @param msg
 * @return 
 */
int lerInteiro(char* msg, int min, int max) {
    int numero=0;
    int res = 0;
    do { 
        printf("%s",msg);
        res = scanf(" %d", &numero);   // res=1 se valor válido
        getchar();
        if (res==0 || !(numero>=min && numero<=max)) puts("Valor inválido!");
    } while (res != 1 || !(numero>=min && numero<=max) )  ;
    return(numero);
}

/**
 * Le um char mediante regras de scanf
 * @param msg
 * @param rule
 * @return 
 */
char lerChar(char* msg, char* rule) {
    char sentinela='-';
    int res = 0;
    do { 
        printf("%s",msg);
        res = scanf(rule, &sentinela);   // res=1 se o sentinela estiver nos parametros
        getchar();
        if (res==0) puts("Valor inválido!");
    } while (res != 1);
    return(toupper(sentinela));
}
