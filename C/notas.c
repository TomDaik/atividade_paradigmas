#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

#define NUM_BIMESTRES 4
#define NOTAS_POR_BIMESTRE 3
#define TOTAL_NOTAS (NUM_BIMESTRES * NOTAS_POR_BIMESTRE)
#define NOTA_APROVACAO 7.0
#define NOTA_RECUPERACAO 5.0

void bubble_sort(float arr[], int n);
float calcular_media(const float notas[], int n);
float calcular_mediana(float notas[], int n);
float calcular_desvio_padrao(const float notas[], int n, float media);
void definir_status(float media, char status[]);
void obter_input(float notas[]);

void bubble_sort(float arr[], int n) {
    int i, j;
    float temp;
    for (i = 0; i < n - 1; i++) {
        for (j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

float calcular_media(const float notas[], int n) {
    float soma = 0.0;
    int i;
    for (i = 0; i < n; i++) {
        soma = soma + notas[i];
    }
    return soma / n;
}

float calcular_mediana(float notas[], int n) {
    bubble_sort(notas, n);

    if (n % 2 == 1) {
        return notas[n / 2];
    } else {
        int meio1 = n / 2 - 1;
        int meio2 = n / 2;
        return (notas[meio1] + notas[meio2]) / 2.0;
    }
}

float calcular_desvio_padrao(const float notas[], int n, float media) {
    float soma_quadrados_diferencas = 0.0;
    int i;
    float diferenca;

    for (i = 0; i < n; i++) {
        diferenca = notas[i] - media;
        soma_quadrados_diferencas = soma_quadrados_diferencas + (diferenca * diferenca);
    }

    float variancia = soma_quadrados_diferencas / (n - 1); 

    return sqrt(variancia);
}

void definir_status(float media, char status[]) {
    if (media >= NOTA_APROVACAO) {
        strcpy(status, "Aprovado");
    } else if (media >= NOTA_RECUPERACAO) {
        strcpy(status, "Recuperacao");
    } else {
        strcpy(status, "Reprovado");
    }
}

void obter_input(float notas[]) {
    int i, j;
    float nota_temp;

    printf("\n--- Entrada de Notas ---\n");
    for (i = 0; i < NUM_BIMESTRES; i++) {
        printf("\nBIMESTRE %d\n", i + 1);

        for (j = 0; j < NOTAS_POR_BIMESTRE; j++) {
            printf("Digite a nota %d (0.0 a 10.0): ", j + 1);
            
            if (scanf("%f", &nota_temp) != 1) {
                printf("Erro: Entrada invalida. Por favor, reinicie o programa.\n");
                exit(EXIT_FAILURE);
            }
            
            if (nota_temp < 0.0 || nota_temp > 10.0) {
                 printf("Aviso: Nota fora do intervalo (0.0-10.0). Ajustando para 5.0.\n");
                 nota_temp = 5.0;
            }

            notas[i * NOTAS_POR_BIMESTRE + j] = nota_temp;
        }
    }
}

int main() {
    float notas[TOTAL_NOTAS];
    float notas_para_mediana[TOTAL_NOTAS];
    
    float media_final;
    float mediana_final;
    float desvio_padrao_final;

    char status_final[20];

    printf("==========================================\n");
    printf("  SIMULADOR ESCOLAR IMPERATIVO EM C\n");
    printf("==========================================\n");
    obter_input(notas);

    media_final = calcular_media(notas, TOTAL_NOTAS);

    memcpy(notas_para_mediana, notas, TOTAL_NOTAS * sizeof(float));

    mediana_final = calcular_mediana(notas_para_mediana, TOTAL_NOTAS);
    
    desvio_padrao_final = calcular_desvio_padrao(notas, TOTAL_NOTAS, media_final);

    definir_status(media_final, status_final);

    printf("\n==========================================\n");
    printf("              RESULTADOS FINAIS\n");
    printf("==========================================\n");
    printf("Notas inseridas (na ordem original): \n");
    for (int i = 0; i < TOTAL_NOTAS; i++) {
        printf("[%.2f] ", notas[i]);
    }
    printf("\nNotas Ordenadas (usadas na Mediana): \n");
    for (int i = 0; i < TOTAL_NOTAS; i++) {
        printf("[%.2f] ", notas_para_mediana[i]);
    }
    printf("\n------------------------------------------\n");
    printf("MEDIA GERAL (Média):             %.2f\n", media_final);
    printf("PONTO MEDIO (Mediana):           %.2f\n", mediana_final);
    printf("DISPERSAO (Desvio Padrao):       %.2f\n", desvio_padrao_final);
    printf("STATUS FINAL:                    %s\n", status_final);
    printf("==========================================\n");

    return 0;
}