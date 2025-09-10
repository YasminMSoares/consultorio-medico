#ifndef CONSULTAS_H
#define CONSULTAS_H

#include "medicamentos.h"

typedef struct Consulta {
    int id;
    char paciente[100];
    char medico[100];
    char data[30];
    int favorita;
    struct Consulta *prev;
    struct Consulta *next;
    Medicamento *medicamentos;
} Consulta;

Consulta* criarConsulta(int id, const char *paciente, const char *medico, const char *data, int favorita);
void listarConsultas(Consulta *inicio);
void liberarConsultas(Consulta *inicio);
Consulta* carregarDados(const char *arquivoConsultas, const char *arquivoMedicamentos);
void salvarDados(Consulta *inicio, const char *arquivoConsultas, const char *arquivoMedicamentos);
Consulta* removerConsulta(Consulta *inicio, int id);

#endif
