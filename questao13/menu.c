/*!
 * @header      menu.c
 * @abstract    Questao13.
 * @discussion  Funcoes usadas para UI de menu.
 * @author      Daniel Torres <a17442|at|alunos.ipca.pt>
 * @link        Daniel Torres GIT <https://github.com/nargotik>
 * @version     1.0 29 de Dezembro de 2018
 */

#include "funcoes13.h"
#include "menu.h"
#include <stdlib.h>
#include <stdio.h>


/**
 * MENU 0 DAS OPCOES
 * @param sensores
 * @param parametros
 * @param readings
 */
void Menu_0(Sensor sensores[],ProgramData *parametros,Leitura readings[]) {
    clearScreen();
    mostraCabecalho("--- MENU PRINCIPAL ---");
    mostraOpcao(0,"DASHBOARD");
    mostraOpcao(1,"PAINEL SENSORES");
    mostraOpcao(2,"LISTAR VALORES RUIDO P/ZONA (DIA)");
    mostraOpcao(3,"MEDIA VALORES RUIDO P/ZONA");
    mostraOpcao(4,"MEDIA VALORES RUIDO P/SENSOR");
    mostraRodape("--- MENU PRINCIPAL ---");
    int opcao = lerInteiro("OPCAO:",0,4);
    switch(opcao) {
      case 0 :
         DashBoard(sensores,parametros,readings);
         break;
      case 1 :
         Menu_1(sensores,parametros,readings);
         break;
      case 2 :
         // MEDIA DE RUIDO POR ZONA
          Menu_0_2(sensores,parametros);
          
          // Volta ao menu
          Menu_0(sensores,parametros,readings);
         break;
      case 3 :
         // MEDIA DE RUIDO POR ZONA
          Menu_0_3(sensores,parametros);
          
          // Volta ao menu
          Menu_0(sensores,parametros,readings);
         break;
      case 4 :
         // MEDIA DE RUIDO POR SENSOR
          Menu_0_4();
          
          // Volta ao menu
          Menu_0(sensores,parametros,readings);
         break;
    }
}

/**
 * MEDIA DE RUIDO POR ZONA
 * @param sensores
 * @param parametros
 * @param readings
 */
void Menu_0_2(Sensor sensores[],ProgramData *parametros) {
    zona_t zona = lerInteiro("Zona do Sensor [0-100]:",0,100);
    datahora_t data = lerDiaMesAno();
    // readLeiturasZona
    Leitura *aux_readings = malloc(MAX_LEITURAS * sizeof(Leitura));
    int total_leituras=0;
    total_leituras = readLeiturasZonaDia(aux_readings, zona, sensores, parametros->total_sensores, data);
    mostraCabecalho("VALORES MIN MAX E MEDIOS DE UMA ZONA");
    
    printf("VALOR MIN RUIDO: %d\n", minLeitura(aux_readings, total_leituras));
    printf("VALOR MAX RUIDO: %d\n", maxLeitura(aux_readings, total_leituras));
    printf("VALOR MED RUIDO: %.2f\n", mediaLeitura(aux_readings, total_leituras));
    printf("TOTAL LEITURAS: %d\n", total_leituras);
    
    // Ordena as leituras lidas
    ordenaLeituras(aux_readings, total_leituras);
    // Mostra as leituras já ordenadas
    mostraLeituras(aux_readings, total_leituras);
    
    lerInteiro("PRIMA 1 PARA VOLTAR AO MENU:",1,1);
    
    mostraRodape("VALORES MIN MAX E MEDIOS DE UMA ZONA");
}


/**
 * MEDIA DE RUIDO POR ZONA
 * @param sensores
 * @param parametros
 * @param readings
 */
void Menu_0_3(Sensor sensores[],ProgramData *parametros) {
    zona_t zona = lerInteiro("Zona do Sensor [0-100]:",0,100);
    // readLeiturasZona
    Leitura *aux_readings = malloc(MAX_LEITURAS * sizeof(Leitura));
    //int readLeiturasZona(Leitura readings[],zona_t zona, Sensor sensores[], int total_sensores)
    int total_leituras=0;
    total_leituras = readLeiturasZona(aux_readings,zona,sensores,parametros->total_sensores);
    mostraCabecalho("VALORES MIN MAX E MEDIOS DE UMA ZONA");
    printf("VALOR MIN RUIDO: %d\n", minLeitura(aux_readings, total_leituras));
    printf("VALOR MAX RUIDO: %d\n", maxLeitura(aux_readings, total_leituras));
    printf("VALOR MED RUIDO: %.2f\n", mediaLeitura(aux_readings, total_leituras));
    printf("TOTAL LEITURAS: %d\n", total_leituras);
    lerInteiro("PRIMA 1 PARA VOLTAR AO MENU:",1,1);
    mostraRodape("VALORES MIN MAX E MEDIOS DE UMA ZONA");
}

/**
 * MEDIA DE RUIDO POR SENSOR
 * @param sensores
 * @param parametros
 * @param readings
 */
void Menu_0_4() {
    codigo_t codigo = lerInteiro("Codigo do Sensor [0-1000]:",0,1000);
    //readLeiturasSensor
    // readLeiturasZona
    Leitura *aux_readings = malloc(MAX_LEITURAS * sizeof(Leitura));
    //int readLeiturasZona(Leitura readings[],zona_t zona, Sensor sensores[], int total_sensores)
    int total_leituras=0;
    total_leituras = readLeiturasSensor(aux_readings,codigo);
    mostraCabecalho("VALORES MIN MAX E MEDIOS DE UM SENSOR");
    
    printf("VALOR MIN RUIDO: %d\n", 
            minLeitura(aux_readings, total_leituras)
            );
    printf("VALOR MAX RUIDO: %d\n", 
            maxLeitura(aux_readings, total_leituras)
            );
    printf("VALOR MED RUIDO: %.2f\n", 
            mediaLeitura(aux_readings, total_leituras)
            );
    printf("TOTAL LEITURAS: %d\n", total_leituras);
    lerInteiro("PRIMA 1 PARA VOLTAR AO MENU:",1,1);
    
    mostraRodape("VALORES MIN MAX E MEDIOS DE UMA SENSOR");
}

/**
 * MENU 1 DAS OPCOES COM SENSORES
 * @param sensores
 * @param parametros
 * @param readings
 */
void Menu_1(Sensor sensores[],ProgramData *parametros,Leitura readings[]) {
    int aux = 0;
    
    clearScreen();
    mostraCabecalho("--- PAINEL SENSORES ---");
    mostraSensores(sensores,parametros->total_sensores);
    mostraOpcao(0,"< VOLTAR");
    mostraOpcao(1,"INSERIR SENSOR");
    mostraOpcao(2,"AUALIZAR SENSOR");
    mostraOpcao(3,"REMOVER SENSOR");
    mostraRodape("--- MENU PRINCIPAL ---");
    int opcao = lerInteiro("OPCAO:",0,3);
    switch(opcao) {
      case 0 :
          // Voltar à Dashboard
         DashBoard(sensores,parametros,readings);
         break;
      case 1 :
         // Menu de inserção de SENSOR
         aux = insereSensor(sensores, parametros);
         if (aux == -2) notice("LIMITE DE SENSORES ATINGIDO\n");
         Menu_1(sensores,parametros,readings);
         
         break;
      case 2 :
          // Editar sensor
          
         aux = editarSensor(sensores, parametros->total_sensores);
         if (aux==0) notice("IMPOSSIVEL EDITAR\n");
         Menu_1(sensores,parametros,readings);
         
         break;
      case 3 :
          
          // Remover Sensor
         aux = removerSensor(sensores, parametros);
         if (aux == -1) notice("IMPOSSIVEL REMOVER SENSOR COM LEITURAS Desactivando..\n");
         Menu_1(sensores,parametros,readings);
         break;
    }
}

/**
 * DASHBOARD
 * @param sensores
 * @param parametros
 * @param readings
 */
void DashBoard(Sensor sensores[],ProgramData *parametros,Leitura readings[]) {
    clearScreen();
    
    refreshData(sensores,parametros,readings);


    mostraCabecalho("--- DASHBOARD ---");

    mostraSensores(sensores,parametros->total_sensores);
    
    printf("VALOR MIN RUIDO: %d\n", minLeitura(readings, parametros->total_leituras));

    printf("VALOR MAX RUIDO: %d\n", maxLeitura(readings, parametros->total_leituras));
    printf("VALOR MED RUIDO: %.2f\n", mediaLeitura(readings, parametros->total_leituras));
    printf("TOTAL LEITURAS: %d\n", parametros->total_leituras);
    mostraCabecalho("--- DASHBOARD ---");
    mostraOpcao(1,"ACTUALIZAR DASHBOARD");
    mostraOpcao(0,"MENU");
    mostraRodape("--- DASHBOARD ---");
    int opcao = lerInteiro("OPCAO:",0,1);
    switch(opcao) {
      case 1 :
          DashBoard(sensores,parametros,readings);
         break;
      case 0 :
          Menu_0(sensores,parametros,readings);
         break;
    }
}

