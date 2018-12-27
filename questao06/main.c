/*!
 * @header      main.c
 * @abstract    Questao06
 * @discussion  Foi efetuado um questionário a um número indeterminado de 
 *              estudantes numa universidade. A todos os estudantes foi 
 *              solicitado o género, a idade e se está a gostar ou não do 
 *              curso que está a frequentar. Implemente uma aplicação capaz 
 *              de calcular e informar:
 *                  - O número de estudantes entrevistados;
 *                  - Percentagem de estudantes de género feminino e masculino;
 *                  - Quantidade de estudantes de género masculino 
 *                    com menos de 23 anos e que não gostam do curso 
 *                    que estão a frequentar.
 * @author      Daniel Torres <a17442|at|alunos.ipca.pt>
 * @link        Daniel Torres GIT <https://github.com/nargotik>
 * @version     1.0 15 de Novembro de 2018
 */


#include <stdio.h>
#include <ctype.h>

    
char lerChar(char* msg, char* rule);
int lerInteiro(char* msg);
void lerEstudante(int runtime[]);
void lerEstudantes(int runtime[]);
void mostraResultados(int runtime[]);

/*!
 * @function    main
 */
int main()
{
    
    // runtime[0] ==> Numero de estudantes
    // runtime[1] ==> Masculinos
    // runtime[2] ==> Femininos
    // runtime[3] ==> Numero de estudantes M sub23 insatisfeitos
    int runtime[4] = {0 ,0 ,0 ,0};
    lerEstudantes(runtime);
    mostraResultados(runtime);

}

void mostraResultados(int runtime[]) {
    float perc_masc=0,perc_fem=0;
    perc_fem  = (float)runtime[2] * (float)100 / runtime[0];
    perc_masc = (float)runtime[1] * (float)100 / runtime[0];
    printf("==============================\n"
           "Numero de estudantes entrevistados: %d\n"
           "Percentagem Masculinos %.2f\n"
           "Percentagem Femininos %.2f\n"
           "Numero Maculinos Sub23 que nao gostam do curso: %d\n",
           runtime[0],
           perc_masc,
           perc_fem,
           runtime[3]
           );
}
/**
 * Lê estudantes até o utilizador pretender parar
 * Sendo uma leitura de um numero indeterminado e não sendo necessário 
 * armazenar dados dos estudantes
 * @return runtime results
 */
void lerEstudantes(int runtime[]) {
    char sentinela='S';
    int res = 0;
    do { 
        
        lerEstudante(runtime);
        
        puts("Deseja continuar a inserir dados (S/N)?");
        res = scanf(" %[Ss]", &sentinela);   // res=1 se o sentinela for s ou S
        
    } while (res == 1);
}



/**
 * Le os dados de um estudante
 * @param array dos settings
 */
void lerEstudante(int runtime[]) {
    char genero,satisfeito;
    int idade;
    runtime[0]++;
    printf("============== Estudante %d ==============\n",runtime[0]);
    // Genero
    genero      = lerChar("Genero M/F :"," %1[fFmM]");
    // Idade
    idade       = lerInteiro("Idade: ");
    // Está a gostar ?
    satisfeito  = lerChar("Esta a gostar do curso S/N :"," %1[SsNn]");
    printf("============ Fim Estudante %d =============\n",runtime[0]);
    
    
    (genero == 'M') ? runtime[1]++ : runtime[2]++;
    if (genero=='M' && idade < 23 && satisfeito == 'N') 
        runtime[3]++;
}

/**
 * Le um inteiro
 * @param msg
 * @return 
 */
int lerInteiro(char* msg) {
    int numero=0;
    int res = 0;
    do { 
        printf("%s",msg);
        res = scanf(" %d", &numero);   // res=1 se valor válido
        getchar();
        if (res==0) puts("Valor inválido\n");
    } while (res != 1);
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
        if (res==0) puts("Valor inválido\n");
    } while (res != 1);
    return(toupper(sentinela));
}
