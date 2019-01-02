/*!
 * @header      main.c
 * @abstract    Questao10.
 * @discussion  Reimplemente a questão 5 para que possa ser 
 *              reutilizada noutros contextos, i.e. com outros 
 *              intervalos de pesos
 * 
 *              5- Desenvolva um programa que receba os pesos de um conjunto 
 *              indefenido de pessoas e que mostre na consola a quantidade 
 *              de pessoas com peso entre 50 e 80 quilogramas. 
 *              Reflita acerca da melhor condição de paragem para este caso. 
 * 
 * @author      Daniel Torres <a17442|at|alunos.ipca.pt>
 * @link        Daniel Torres GIT <https://github.com/nargotik>
 * @version     1.0 26 de Novembro de 2018
 */

#include <stdio.h>
#include <stdlib.h>

/**
 * Função que lê um valor inserido por scanf e devolve o 
 * mesmo caso esteja no intervalo definido
 * @param minimo minimo para o valor
 * @param maximo maximo para o valor
 * @param paragem valor de paragem
 * @return retorna o valor inserido caso estena na condicao
 */
int lerDados(int minimo, int maximo, int paragem) {
    int userinput = 0;
    
    if (maximo < minimo) return 0;

    (void)scanf("%d",&userinput);
    if (userinput == paragem) 
        return paragem;
    else if (userinput >= minimo && userinput <= maximo ) 
        return userinput;
    else
        return 0;
}

/**
 * Main function
 */
int main()
{
    int peso = 0, contador=0, contador_condicao=0;
    
    /*
     Leitura e inicialização de variaveis de configuração
     */
    int min = 50, max = 80, paragem = -1;
    printf("Insira peso do min intervalo:");
    (void)scanf("%d",&min);
    printf("Insira peso do max intervalo:");
    (void)scanf("%d",&max);
    printf("Indique qual o valor para paragem:");
    (void)scanf("%d",&paragem);
    

    
    printf("(Insira Valores) \n"
            "Termine com o valor %d\n",paragem);
    do {
        
        printf("Insira o peso %d :",++contador);
        peso = lerDados(min,max,paragem);
        
        if (peso >= min && peso <= max)
            contador_condicao++;      
        
    } while (peso != paragem);

    printf("Inseriu %d pesos no total, "
            "entre os quais %d estao entre os %dkg e %dkg"
            ,contador-1,contador_condicao,min,max);
}

