#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>


int main() {

    // Configurando caracteres especiais do português
    setlocale(LC_ALL, "Portuguese");

    // Abertura do arquivo
    FILE *arq = fopen("relatorio/relatorio.txt", "w");
    if (arq == NULL) { // Verifica se o arquivo foi aberto corretamente
        perror("\nErro ao abrir o arquivo\n");
        return 1;
    }

    // Declaração de variáveis
    int dias_de_anuncio;
    float orcamento_diario, orcamento_total;
    char status_do_criativo__temp__ = '\0';
    char status_do_criativo[4];


    // Leitura dos parâmetros
    printf("\nQuantos dias de anúncio serão feitos?\n");
    scanf("%d", &dias_de_anuncio);

    printf("\nQual será o orçamento diário?\n");
    printf("R$ "); scanf(" %f", &orcamento_diario);
    
    // Limpar o buffer do teclado
    int c;
    while( (c = getchar()) != '\n' && c != EOF) {}
        while(status_do_criativo__temp__ != 's' && status_do_criativo__temp__ != 'n'){
            printf("\nOs criativos já estao no drive? (s/n)\n");
            scanf(" %c", &status_do_criativo__temp__);

            // Limpa novamente o buffer do teclado
            while( (c = getchar()) != '\n' && c != EOF) {}
        }

    if(status_do_criativo__temp__ == 's') {
        strcpy(status_do_criativo, "SIM");
    }
    if(status_do_criativo__temp__ == 'n') {
        strcpy(status_do_criativo, "NÃO");
    }

    // Cálculo do orçamento total
    orcamento_total = dias_de_anuncio * orcamento_diario;

    fprintf(arq, "Relatório de demanda de anúncios em Meta Ads\n");
    fprintf(arq, "Quantidade de dias que rodarão anúncios:\t %d\n", dias_de_anuncio);
    fprintf(arq, "Orçamento diário:\t R$ %.2f\n", orcamento_diario);
    fprintf(arq, "Orçamento total total:\t R$ %.2f\n", orcamento_total);
    fprintf(arq, "Criativos já foram enviados?:\t %s", status_do_criativo);

    // Fecha o arquivo
    fclose(arq);

    return 0;
}