/*!
 * @header      main.c
 * @abstract    Questao01 do trabalho pratico
 * 
 * @discussion  
 *              INSTRUÇÕES DE DECISÃO 
 *              (não deve usar instruções de repetição nem estruturas)
 *              Crie uma aplicação que solicite a idade de 5 pessoas, 
 *              apresente a média dessas idades e a 
 *              soma das idades acima dos 20 anos. 
 * 
 * @author      Daniel Torres <a17442|at|alunos.ipca.pt>
 * @link        Daniel Torres GIT <https://github.com/nargotik>
 * @version     1.0 7 de Novembro de 2018
 */


#include <stdio.h>
//#include <stdlib.h>


int ler_idade(int pessoa);

/*!
 * @function    main
 * @abstract    Funcão principal
 */
int main()
{
    // Soma das idades acima dos 20 anos 
    int soma_idades_20=0;
    // Idade
    int idade=0;
    // Soma das Idade 
    int soma=0;
    // Media
    float media=0;
    // Contador das idades
    int idades = 0;
    
    // Ler idade da pessoa 1
    idades++;
    idade = ler_idade(idades);
    if (idade>20) 
        soma_idades_20 += idade;
    soma += idade;

    
    
    // Ler a proxima idade 
    idades++; // (2)
    idade = ler_idade(idades);
    if (idade>20) 
        soma_idades_20 += idade;
    soma += idade;
    
    
    
    /// Ler a proxima idade
    idades++; // (3)
    idade   = ler_idade(idades);
    if (idade>20) 
        soma_idades_20 += idade;
    soma    += idade;

    
    
    // Ler a proxima idade
    idades++; // (4)
    idade   = ler_idade(idades);
    if (idade>20) 
        soma_idades_20 += idade;
    soma    += idade;
    
    
    
    // Ler a proxima idade
    idades++; // (5)
    idade   = ler_idade(idades);
    if (idade>20) 
        soma_idades_20 += idade;
    soma    += idade;

    
    
    printf( "-----------------------------------------\n"
            "Resultados: \n"
            "===========================================\n");
   
    media = soma / (float) idades;
    printf("Media de idades: %.2f \n",media); 
    
    printf("-------\n");
    printf("Soma das idades acima de 20: %d \n",soma_idades_20); 
    printf("===========================================\n");
}



/**
 * Le e verifica dados da idade
 * Verificacoes idade entre 0 e 120
 * 
 * @param pessoa id da pessoa a ler (apenas para mostrar)
 * @return idade da pessoa 
 */
int ler_idade(int pessoa) 
{
    int idade = -999;
    // Pessoa pessoa
    printf("Insira a idade da pessoa %d:", pessoa);
    (void)scanf(" %d",&idade);
    
    getchar(); // Limpa \n do buffer stdin
    if (idade>=0 && idade<=120) {
        return idade;
    }
    else {
        printf("-- Erro de inserção de dados (pessoa: %d) -- \n",pessoa);
        return ler_idade(pessoa);
    }
}