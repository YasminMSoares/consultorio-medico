#ifndef MEDICAMENTOS_H
#define MEDICAMENTOS_H

typedef struct Medicamento {
    int id;
    char nome[100];
    char dose[50];
    int controlado;
    struct Medicamento *prev;
    struct Medicamento *next;
} Medicamento;

Medicamento* criarMedicamento(int id, const char *nome, const char *dose, int controlado);
void listarMedicamentos(Medicamento *inicio);
void liberarMedicamentos(Medicamento *inicio);

#endif
