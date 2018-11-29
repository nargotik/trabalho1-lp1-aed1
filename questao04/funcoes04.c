/*!
 * @header      funcoes.c
 * @abstract    Funcoes da Questao04
 * @discussion  
 *              
 * @author      Daniel Torres <a17442|at|alunos.ipca.pt>
 * @version     1.0 7 de Novembro de 2018
 */


/**
 * Retorna e calcula a maior capicua da multiplicacao de 2 numeros
 * @param de valor de ex:1
 * @param ate valor até ex:100
 * @param maior1 apontador para armazenar o primeiro valor maior
 * @param maior2 apontador para armazenar o segundo valor maior
 * @return maior capicua da multiplicacao de 2 numeros
 */
unsigned int maior_capicua(int de, int ate,unsigned int *maior1,unsigned int *maior2) {
    // Variavel para armazenar multiplciacao
    unsigned int multiplicacao,capicua=0;
    for (int primeiro = de; primeiro<=ate; primeiro++) {

        for (int segundo = de; segundo<=ate; segundo++) {
            multiplicacao = primeiro * segundo;
            
            // Verifica se o numero multiplicado é igual ao invertido.
            
            if ( is_capicua(multiplicacao) ) {
                *maior1 = primeiro;
                *maior2 = segundo;
                capicua = multiplicacao;
            }
            
        }
    }
    return capicua;
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
