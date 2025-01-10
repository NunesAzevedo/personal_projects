#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>

#define TAM_NOME_EMPRESA 20
#define TAM_NOME_PROJETO 50


#define DEBUGGING 0
// #define DEBUGGING 1

void limpaBufferTeclado()
{
    int c;
    while( (c = getchar()) != '\n' && c != EOF) {}
}

int main()
{
    // Configurando caracteres especiais do português
    setlocale(LC_ALL, "Portuguese");

    // Abertura do arquivo
    FILE *relatorio = fopen("./relatorio/relatorio.txt", "wt+");
    if (relatorio == NULL) 
    { // Verifica se o arquivo foi aberto corretamente
        perror("\n*********\nErro ao abrir o arquivo\n*********\n");
        return 1;
    }

    // Declaração de variáveis
    int dias_de_anuncio;
    int quantidadeDeProjetos;
    float orcamento_diario, orcamento_total;
    // char status_do_criativo__temp__ = '\0';
    // char status_do_criativo[4];
    char* nomeDaEmpresa = (char*) malloc(TAM_NOME_EMPRESA * sizeof(char));
    if(nomeDaEmpresa == NULL)
    {
        perror("Erro ao alocar o ponteiro: nomeDaEmpresa");
        return 1;
    }

    // Leitura dos parâmetros
    printf("\nNome da empresa:\n");
    scanf("%s", nomeDaEmpresa);
    fprintf(relatorio, "==========================================================\n");
    fprintf(relatorio, "Relatório de demanda de anúncios em Meta Ads\n");
    fprintf(relatorio, "==========================================================\n");
    fprintf(relatorio, "Empresa: %s\n", nomeDaEmpresa);
    fprintf(relatorio, "---------------------------------------------------------\n");
    free(nomeDaEmpresa);

    printf("\nQuantos projetos?\n");
    scanf("%d", &quantidadeDeProjetos);

    for (int i = 1; i <= quantidadeDeProjetos; i++)
    {
        char* nomeDoProjeto = (char*) malloc(quantidadeDeProjetos * sizeof(char));
        if(nomeDoProjeto == NULL)
        {
            perror("Erro ao alocar o ponteiro: nomeDoProjeto");
            return 1;
        }

        printf("\nNome do %dº projeto:\n", i);
        gets(nomeDoProjeto);
        limpaBufferTeclado();

        if (DEBUGGING) printf("[DEBUG]: nomeDoProjeto[%d]: %s\n", i, nomeDoProjeto);

        printf("\nQuantos dias de anúncio serão feitos?\n");
        scanf("%d", &dias_de_anuncio);
        limpaBufferTeclado();

        printf("\nQual será o orçamento diário?\n"); 
        scanf("%f", &orcamento_diario);
        limpaBufferTeclado();

        // status_do_criativo__temp__ = '.'; // Coloca valor padrão
        // while(status_do_criativo__temp__ != 's' && status_do_criativo__temp__ != 'n'){
        //     printf("\nOs criativos já estao no drive? (s/n)\n");
        //     scanf(" %c", &status_do_criativo__temp__);
        //     limpaBufferTeclado();
        // }

        // if(status_do_criativo__temp__ == 's') {
        //     strcpy(status_do_criativo, "SIM");
        // }
        // if(status_do_criativo__temp__ == 'n') {
        //     strcpy(status_do_criativo, "NÃO");
        // }

        // Cálculo do orçamento total
        orcamento_total = dias_de_anuncio * orcamento_diario;
        fprintf(relatorio, "Projeto: %s\n", nomeDoProjeto);
        fprintf(relatorio, "Quantidade de dias que rodarão anúncios:.. %d\n"     , dias_de_anuncio);
        fprintf(relatorio, "Orçamento diário:......................... R$ %.2f\n", orcamento_diario);
        fprintf(relatorio, "Orçamento total total:.................... R$ %.2f\n", orcamento_total);
        // fprintf(relatorio, "Criativos já foram enviados?:............. %s\n"     , status_do_criativo);
        fprintf(relatorio, "---------------------------------------------------------\n");

        nomeDoProjeto = NULL;
        free(nomeDoProjeto);
    }

    // Fecha o arquivo
    fclose(relatorio);
    return 0;
}