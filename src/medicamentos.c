#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "medicamentos.h"

Medicamento* criarMedicamento(int id, const char *nome, const char *dose, int controlado) {
    Medicamento *m = (Medicamento*)malloc(sizeof(Medicamento));
    m->id = id;
    strcpy(m->nome, nome);
    strcpy(m->dose, dose);
    m->controlado = controlado;
    m->prev = NULL;
    m->next = NULL;
    return m;
}

void listarMedicamentos(Medicamento *inicio) {
    if (!inicio) {
        printf("Nenhum medicamento cadastrado.\n");
        return;
    }
    Medicamento *atual = inicio;
    while (atual) {
        printf("ID: %d | Nome: %s | Dose: %s | Controlado: %d\n",
               atual->id, atual->nome, atual->dose, atual->controlado);
        atual = atual->next;
    }
}

void liberarMedicamentos(Medicamento *inicio) {
    Medicamento *atual = inicio;
    while (atual) {
        Medicamento *temp = atual;
        atual = atual->next;
        free(temp);
    }
}
