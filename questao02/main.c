/*!
 * @header      main.c
 * @abstract    Questao02 do trabalho pratico
 * @discussion  Uma instituição bancária pretende oferecer aos 
 *              seus melhores e mais antigos clientes um 
 *              prémio em juros de 1% sobre o saldo médio da sua 
 *              conta durante o ano. Para que possa ser 
 *              atribuído o prémio, os clientes têm se satisfazer 
 *              as seguintes condições conjuntamente: 
 *                  - O saldo médio tem que ser igual ou superior a 100.000 € e 
 *                  - A conta tem que existir há mais de 10 anos. 
 *              Além deste prémio o banco está a oferecer também, 
 *              podendo ser acrescido ao primeiro, 
 *              um prémio de acordo com o tipo de conta do 
 *              cliente e conforme a seguinte tabela:  
 * 
 *              | Codigo  Tipo de conta | Prémio em euros |
 *              | 1  Empresarial Gold | 150 |
 *              | 2  Empresarial Silver | 100 |
 *              | 3  Particular Gold | 75 |
 *              | 4  Particular Silver | 40 |
 *              | 5  Outros | 0|
 *              
 *                  Implemente uma aplicação que recolha os dados de um cliente, 
 *              tais como o saldo médio, 
 *              número de anos da conta e código de tipo de conta, 
 *              e que apresente na consola um resumo 
 *              com os dados recolhidos, juntamente com a 
 *              descrição do tipo de conta e o valor total do 
 *              prémio a que tem direito. 
 * 
 * @author      Daniel Torres <a17442|at|alunos.ipca.pt>
 * @link        Daniel Torres GIT <https://github.com/nargotik>
 * @version     1.0 7 de Novembro de 2018
 */



#include <stdio.h>
#include <string.h>

#include "questao02.h"



/*!
 * Função main
 */
int main()
{
    // Saldo Médio da conta do cliente
    float saldo_medio=0;
    
    // Anos da conta;
    int anos_conta;
    
    // Codigo da conta
    int codigo_conta;
    
    // Premio de 1% mediante antiguidade
    float premio1=0;
    
    // Premio mediante tipo de conta
    float premio2=0;
    

    
    // Le o saldo medio
    saldo_medio = ler_saldo();
    
    // Le os anos da conta
    anos_conta = ler_anos();
    
    // Lê o codigo da conta
    codigo_conta = ler_codigoconta();
    

    
    // Condição para o premio 1
    if (anos_conta>10 && saldo_medio>=100000) {
        // Atribuir um premio de 1%
        premio1 = saldo_medio * 0.01;
    }
    
    
    // Premio 2 (condição tipo de conta).
    
    premio2 = premio_conta[codigo_conta - 1];

    
    printf( "-----------------------------------------\n"
            ""
            "Resultados: \n"
            "===========================================\n");
    printf("Anos Conta %d\n",anos_conta); 
    printf("Saldo Médio %.2f\n",saldo_medio); 
    printf("Tipo de conta: %d - %s \n",codigo_conta, descricao_conta[codigo_conta - 1] ); 
    
    printf("Calculado:");
    printf("Premio 1 do valor do saldo medio: %.2f \n",premio1); 
    printf("Premio 2 tipo de conta: %.f \n", premio2 ); 
    printf("===========================================\n");
}



/**
 * Le os anos da conta
 * @return Anos da conta caso seja um valor aceitavel na condicao
 */
int ler_anos() {
    // Anos da conta;
    int anos_conta=-999;
    printf("===========================================\n");
    printf("Insira os anos da conta:");
    scanf(" %d",&anos_conta);
    
    getchar(); // Limpa \n do buffer stdin
    
    if (!(anos_conta>0)) {
        printf("-- Erro de leitura de dados -- \n");
        return ler_anos();
        
    }
    return anos_conta;
    
}



/**
 * Le o saldo médio da conta
 * @return Saldo médio caso seja um valor aceitavel na condicao
 */
float ler_saldo() {
    float saldo_medio=-999999;
    printf("===========================================\n");
    printf("Insira o saldo médio da conta:");
    scanf(" %f",&saldo_medio);
    
    getchar(); // Limpa \n do buffer stdin
    
    if (saldo_medio == -999999) {
        printf("-- Erro de leitura de dados -- \n");
        return ler_saldo();
        
    }
    return saldo_medio;
}



/**
 * Le o codigo da conta
 * @return Codigo da conta caso seja um valor aceitavel na condicao
 */
int ler_codigoconta() {
    // Para validar a ultima conta
    int ultima_conta = numero_contas;
    
    // Codigo da conta;
    int codigo_conta=-999;
    printf("===========================================\n");
    mostra_opcoes(numero_contas);
    printf("Insira o código da conta:");
    scanf(" %d",&codigo_conta);
    
    getchar(); // Limpa \n do buffer stdin
    
    if (!(codigo_conta >= 1 && codigo_conta <= ultima_conta)) {
        printf("-- Erro de leitura de dados -- \n");
        return ler_codigoconta();
        
    }
    return codigo_conta;
}



/**
 * Mostra as opções da constante descricao_conta
 * Foi utilizada recursividade para evitar o uso de ciclos
 */
void mostra_opcoes(int n) {
    printf("%d \t-\t %s\n",n,descricao_conta[n-1]);
    
    if ((n-1) != 0) mostra_opcoes(n-1);
}
