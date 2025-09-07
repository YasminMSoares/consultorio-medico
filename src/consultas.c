#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "consultas.h"
#include "medicamentos.h"

// Cria uma nova consulta
Consulta* criarConsulta(int id, const char *paciente, const char *medico, const char *data, int favorita) {
    Consulta *c = (Consulta*)malloc(sizeof(Consulta));
    c->id = id;
    strcpy(c->paciente, paciente);
    strcpy(c->medico, medico);
    strcpy(c->data, data);
    c->favorita = favorita;
    c->prev = NULL;
    c->next = NULL;
    c->medicamentos = NULL;
    return c;
}

// Lista consultas
void listarConsultas(Consulta *inicio) {
    if (!inicio) {
        printf("Nenhuma consulta cadastrada.\n");
        return;
    }
    Consulta *atual = inicio;
    printf("\n--- Consultas ---\n");
    while (atual) {
        printf("ID: %d | Paciente: %s | Medico: %s | Data: %s | Favorita: %d\n",
               atual->id, atual->paciente, atual->medico, atual->data, atual->favorita);
        atual = atual->next;
    }
}

// Libera memória das consultas
void liberarConsultas(Consulta *inicio) {
    Consulta *atual = inicio;
    while (atual) {
        Consulta *temp = atual;
        liberarMedicamentos(atual->medicamentos);
        atual = atual->next;
        free(temp);
    }
}

// Carrega dados de arquivos
Consulta* carregarDados(const char *arquivoConsultas, const char *arquivoMedicamentos) {
    FILE *fc = fopen(arquivoConsultas, "r");
    if (!fc) return NULL;

    Consulta *inicio = NULL;
    char linha[256];
    while (fgets(linha, sizeof(linha), fc)) {
        int id, favorita;
        char paciente[100], medico[100], data[30];
        sscanf(linha, "%d|%[^|]|%[^|]|%[^|]|%d", &id, paciente, medico, data, &favorita);
        Consulta *nova = criarConsulta(id, paciente, medico, data, favorita);

        // Inserir no final
        if (!inicio) inicio = nova;
        else {
            Consulta *atual = inicio;
            while (atual->next) atual = atual->next;
            atual->next = nova;
            nova->prev = atual;
        }
    }
    fclose(fc);

    // Carregar medicamentos
    FILE *fm = fopen(arquivoMedicamentos, "r");
    if (fm) {
        while (fgets(linha, sizeof(linha), fm)) {
            int cid, mid, controlado;
            char nome[100], dose[50];
            sscanf(linha, "%d|%[^|]|%[^|]|%d", &cid, nome, dose, &controlado);
            Consulta *atual = inicio;
            while (atual && atual->id != cid) atual = atual->next;
            if (atual) {
                Medicamento *m = criarMedicamento(mid=0, nome, dose, controlado); // ID será atualizado no main
                if (!atual->medicamentos) atual->medicamentos = m;
                else {
                    Medicamento *t = atual->medicamentos;
                    while (t->next) t = t->next;
                    t->next = m;
                    m->prev = t;
                }
            }
        }
        fclose(fm);
    }

    return inicio;
}

// Salva dados nos arquivos
void salvarDados(Consulta *inicio, const char *arquivoConsultas, const char *arquivoMedicamentos) {
    FILE *fc = fopen(arquivoConsultas, "w");
    FILE *fm = fopen(arquivoMedicamentos, "w");
    if (!fc || !fm) {
        printf("Erro ao abrir arquivos para salvar.\n");
        return;
    }
    Consulta *c = inicio;
    while (c) {
        fprintf(fc, "%d|%s|%s|%s|%d\n", c->id, c->paciente, c->medico, c->data, c->favorita);
        Medicamento *m = c->medicamentos;
        while (m) {
            fprintf(fm, "%d|%s|%s|%d\n", c->id, m->nome, m->dose, m->controlado);
            m = m->next;
        }
        c = c->next;
    }
    fclose(fc);
    fclose(fm);
    printf("Dados salvos com sucesso!\n");
}
