/*!
 * @header      main.c
 * @abstract    Questao13.
 * @discussion  Funções usadas transvesalmente na questao13.
 * @author      Daniel Torres <a17442|at|alunos.ipca.pt>
 * @link        Daniel Torres GIT <https://github.com/nargotik>
 * @version     1.0 29 de Dezembro de 2018
 */




#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h> // exit()

#include "main.h"
#include "funcoes13.h"

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

/**
 * Mostra um cabeçalho 
 * @param msg
 */
void mostraCabecalho(char* msg) {
    printf("========== %s ==========\n",msg);
}

/**
 * Mostra opcao 
 * @param msg
 */
void mostraOpcao(int opcao,char* msg) {
    printf("   %d - %s\n",opcao,msg);
}

/*
 * Limpa o ecra
 */
void clearScreen() {
#ifdef LINUX
    // Limpa o ecrã
    printf("\x1B[2J");
    // Põe o cursor no topo
    printf("\x1B[1H");
    //(void)system("clear");
#endif
#ifdef WINDOWS
    // Limpa o ecrã
    printf("\x1B[2J");
    // Põe o cursor no topo
    printf("\x1B[1H");
    //(void)system("cls");
#endif
}

/**
 * Mostra um erro 
 * @param msg
 */
void err(char* msg) {
    fprintf(stderr, msg);
    exit(0);
}

/**
 * Mostra uma notice
 * @param msg
 */
void notice(char* msg) {
    fprintf(stdout, msg);
    fprintf(stdout, "\n");
}

/**
 * Mostra um rodape mostrar == do tamanho da msg
 * @param msg
 */
void mostraRodape(char* msg) {
    printf("==========");
    int tam = strlen(msg) + 2;
    for (int i = 0; i < tam; i++) {
        printf("=");

    }
    printf("========== \n");

}

/*
 * Relê os Parametros
 */
void refreshParametros(ProgramData *parametros) {
    ProgramData aux;
    aux = readParametros();
    parametros->total_leituras = aux.total_leituras;
    parametros->total_sensores = aux.total_sensores;
}

/**
 * Lê os parametros do programa
 * @return 
 */
ProgramData readParametros() {
  
  FILE *af;
  ProgramData aux;

  // Abertura para modo binário
  af = fopen(PROGRAMDATA_FILENAME,"rb");
  if (af == NULL) {
      // Impossivel abrir o ficheiro ficheiro nao existe (Inicializa)
      aux.total_leituras = 0;
      aux.total_sensores = 0;
      int escritos = writeParametros(aux);
      if (escritos == -1) {
          char buf[256];
          snprintf(buf, sizeof buf, "Erro de escrita no ficheiro %s", PROGRAMDATA_FILENAME);
          err(buf);
      }
          
  } else{
    (void)fread(&aux, sizeof(ProgramData), 1, af);
    
    // Para prevenir falhas vai verificar qual o tamanho de sensores e leituras no ficheiro
    aux.total_leituras = totalLeituras();
    aux.total_sensores = totalSensores();
    fclose(af);
  }
  return aux; 
}

/**
 * Escreve os parametros do programa
 * @return 
 */
int writeParametros(ProgramData aux) {
  FILE *af;

  int nescritos=0;
  
  // Para prevenir falhas vai verificar qual o tamanho de sensores e leituras no ficheiro
  aux.total_leituras = totalLeituras();
  aux.total_sensores = totalSensores();
    
  // Abertura para modo binário
  af = fopen(PROGRAMDATA_FILENAME,"wb");
  if (af == NULL) {
      nescritos = -1;
  } else{
    nescritos = fwrite(&aux, sizeof(ProgramData), 1, af);	
    
    fclose(af);
  }
  return nescritos; 
}


/**
 * 
 * @param sensores
 * @param parametros
 * @param readings
 */
int refreshData(Sensor sensores[],ProgramData *parametros,Leitura readings[]) {
    int updated = 0;
            
    ProgramData aux2 = readParametros();
    

    
    // Há leituras novas
    if (aux2.total_leituras != parametros->total_leituras) {
        // Lê as Leituras
        int lidos = readLeituras(readings);
        
        // Le os sensores
        readSensores(sensores,parametros->total_sensores);
        
        parametros->total_leituras = lidos;
        updated = 1;
    }
        

    // Há sensores novos
    if (aux2.total_sensores != parametros->total_sensores) {
        parametros->total_sensores = aux2.total_sensores;
        
        readSensores(sensores,parametros->total_sensores);
        updated = 1;
    }
    return updated;
}

/**
 * Ler um dia mes e ano
 * @return 
 */
datahora_t lerDiaMesAno() {
    datahora_t aux;
    aux.dia = lerInteiro("Insere o Dia [1-31]:",1,31);
    aux.mes = lerInteiro("Insere o Mes [1-12]:",1,12);
    aux.ano = lerInteiro("Insere o Ano [2010-2099]:",2010,2099);
    return aux;
}

/**
 * Devolve o tamanho do ficheiro em Bytes
 * @param fp
 * @return 
 */
int fsize(FILE *fp){
    // Armazena a posição inicial para colocar após leitura
    int prev = ftell(fp);
    // Procura o fim do ficheiro
    fseek(fp, 0L, SEEK_END);
    // Armazena a posição do fim do ficheiro
    int sz = ftell(fp);
    // Volta a colocar no ponto inicial
    fseek(fp,prev,SEEK_SET);
    return sz;
}
