/*!
 * @header      main.c
 * @abstract    Questao05
 * @discussion  Desenvolva um programa que receba os pesos de um conjunto 
 *              indefenido de pessoas e que mostre na consola a quantidade 
 *              de pessoas com peso entre 50 e 80 quilogramas. 
 *              Reflita acerca da melhor condição de paragem para este caso. 
 * 
 * @author      Daniel Torres <a17442|at|alunos.ipca.pt>
 * @link        Daniel Torres GIT <https://github.com/nargotik>
 * @version     1.0 15 de Novembro de 2018
 */


#include <stdio.h>


int main(int argc , char* argv[])
{
    int peso = 0, contador=0, contador_condicao=0;
    puts("(Insira Valores) \n"
            "Termine com o valor -1\n");
    do {
        printf("Insira o peso %d :",++contador);
        scanf(" %d",&peso);
        if (peso>=50 && peso<=80)
            contador_condicao++;    
    } while (peso >= 0);

    printf("Inseriu %d pesos no total, "
            "entre os quais %d estao entre os 50kg e 80kg"
            ,contador-1,contador_condicao);
}

