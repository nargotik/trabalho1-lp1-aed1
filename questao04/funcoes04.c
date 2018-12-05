/*!
 * @header      funcoes.c
 * @abstract    Funcoes da Questao04
 * @author      Daniel Torres <a17442|at|alunos.ipca.pt>
 * @version     1.0 7 de Novembro de 2018
 */

#include "funcoes04.h"


/**
 * Retorna e calcula a maior capicua da multiplicacao de 2 numeros
 * @param de valor de ex:1
 * @param ate valor até ex:100
 * @param maior1 apontador para armazenar o primeiro valor maior
 * @param maior2 apontador para armazenar o segundo valor maior
 * @return maior capicua da multiplicacao de 2 numeros
 */
unsigned long int maior_capicua(int de, int ate,unsigned int *maior1,unsigned int *maior2) {
    // Variavel para armazenar multiplciacao
    unsigned long int multiplicacao,maior_capicua=0;
    
    //int ciclos=0; // For benchmarking
    
    // Verifica se o até*até é a maior capicua
    multiplicacao = ate*ate;
    if ( is_capicua(multiplicacao) ) {
        *maior1 = ate;
        *maior2 = ate;
        maior_capicua = multiplicacao;
    }
    
    for (int primeiro = ate; primeiro >= de; primeiro--) {
        
        // Se a multiplicacao for menos que a maior capicua faz break e nao faz proximo for
        multiplicacao = primeiro * (primeiro-1);
        if ( multiplicacao < maior_capicua) break;
        
        // Apenas vai testar a multiplicacao do primeiro * primeiro-1....de
        for (int segundo = (primeiro-1); segundo >= de; segundo--) {
            //ciclos++; // For benchmarking
            
            // Se a multiplicacao for menos que a maior capicua sai fora do for
            multiplicacao = primeiro * segundo;
            if ( multiplicacao < maior_capicua) break;
            
            // Verifica se o numero multiplicado é igual ao invertido.

            if ( is_capicua(multiplicacao) && multiplicacao > maior_capicua ) {
                *maior1 = primeiro;
                *maior2 = segundo;
                maior_capicua = multiplicacao;
            }
            
        }
    }
    //printf("ciclos: %d",ciclos);
    /* BenchMarks
     * 
     * Maior capicua de 100 a 999
     * Ciclos: 6116 vs 810000(900^2)
     * Maior capicua 993 x 913 = 906609
     * 
     * Maior capicua de 100000 a 999999
     * ciclos: 856412 vs 810000000000(900000^2)
     * Maior capicua 999999 x 757913 = 1997997991
     * 
     * Maior capicua de 10000000 a 99999999
     * ciclos: 32999 vs 8100000000000000(90000000^2)
     * Maior capicua 99999999 x 99967043 = 314868413
     */
    return maior_capicua;
}


/*!
 * Funcao para inverter um numero inteiro
 * @function inverte
 * @param valor
 * @return valor inverso
 */
int inverte(int valor)
{  
   int inversa=0;
   do 
   {
      inversa   = inversa * 10 + (valor%10);
      valor     = valor / 10;
   } while( valor>0 );
   return (inversa);
}

/**
 * Devolve 0 se não é capicua ou 1 se é capicua
 * @param numero
 * @return valor booleano da opecação
 */
int is_capicua(int numero) {
    return (inverte(numero) == numero);
}
