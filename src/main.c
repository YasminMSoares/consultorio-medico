#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "consultas.h"
#include "medicamentos.h"

Consulta* inserirConsulta(Consulta **inicio, int id, const char *paciente, const char *medico, const char *data, int favorita) {
    Consulta *nova = criarConsulta(id, paciente, medico, data, favorita);
    if (!*inicio) {
        *inicio = nova;
    } else {
        Consulta *atual = *inicio;
        while (atual->next) atual = atual->next;
        atual->next = nova;
        nova->prev = atual;
    }
    return nova;
}

Medicamento* inserirMedicamento(Consulta *consulta, int id, const char *nome, const char *dose, int controlado) {
    Medicamento *novo = criarMedicamento(id, nome, dose, controlado);
    if (!consulta->medicamentos) {
        consulta->medicamentos = novo;
    } else {
        Medicamento *atual = consulta->medicamentos;
        while (atual->next) atual = atual->next;
        atual->next = novo;
        novo->prev = atual;
    }
    return novo;
}

// Menu 
void exibirMenu() {
    printf("\n==============================\n");
    printf("   CONSULTORIO MEDICO UFU\n");
    printf("==============================\n");
    printf("1 - Cadastrar consulta\n");
    printf("2 - Listar consultas\n");
    printf("3 - Remover consulta\n");
    printf("4 - Adicionar medicamento\n");
    printf("5 - Listar medicamentos\n");
    printf("9 - Salvar e sair\n");
    printf("Escolha uma opcao: ");
}

int main() {
    Consulta *consultas = carregarDados("data/consultas.txt", "data/medicamentos.txt");
    int opcao;

    int idConsulta = 1;
    int idMedicamento = 1;

    Consulta *tmp = consultas;
    while (tmp) {
        if (tmp->id >= idConsulta) idConsulta = tmp->id + 1;
        Medicamento *m = tmp->medicamentos;
        while (m) {
            if (m->id >= idMedicamento) idMedicamento = m->id + 1;
            m = m->next;
        }
        tmp = tmp->next;
    }

    do {
        exibirMenu();
        scanf("%d", &opcao);
        getchar(); // limpar buffer

        switch (opcao) {
            case 1: {
                char paciente[100], medico[100], data[30];
                printf("Nome do paciente: ");
                fgets(paciente, sizeof(paciente), stdin); paciente[strcspn(paciente, "\n")] = 0;

                printf("Nome do medico: ");
                fgets(medico, sizeof(medico), stdin); medico[strcspn(medico, "\n")] = 0;

                printf("Data (dd/mm/aaaa hh:mm): ");
                fgets(data, sizeof(data), stdin); data[strcspn(data, "\n")] = 0;

                inserirConsulta(&consultas, idConsulta++, paciente, medico, data, 0);
                printf("Consulta cadastrada!\n");
                break;
            }
            case 2:
                listarConsultas(consultas);
                break;
            case 3:
                int id;
                printf("Digite o ID da consulta que deseja remover: ");
                scanf(("%d", &id);
                consulta = removerConsulta(consultas, id);
                break;
            case 4: {
                if (!consultas) {
                    printf("Nenhuma consulta cadastrada!\n");
                    break;
                }
                int id;
                printf("Digite o ID da consulta: ");
                scanf("%d", &id); getchar();

                Consulta *atual = consultas;
                while (atual && atual->id != id) atual = atual->next;
                if (!atual) {
                    printf("Consulta nao encontrada!\n");
                    break;
                }

                char nome[100], dose[50];
                int controlado;
                printf("Nome do medicamento: ");
                fgets(nome, sizeof(nome), stdin); nome[strcspn(nome, "\n")] = 0;

                printf("Dose: ");
                fgets(dose, sizeof(dose), stdin); dose[strcspn(dose, "\n")] = 0;

                printf("Eh controlado? (1=Sim, 0=Nao): ");
                scanf("%d", &controlado);

                inserirMedicamento(atual, idMedicamento++, nome, dose, controlado);
                printf("Medicamento adicionado!\n");
                break;
            }
            case 5: {
                int id;
                printf("Digite o ID da consulta: ");
                scanf("%d", &id);

                Consulta *atual = consultas;
                while (atual && atual->id != id) atual = atual->next;
                if (!atual) {
                    printf("Consulta nao encontrada!\n");
                    break;
                }

                printf("Medicamentos da consulta %d:\n", id);
                listarMedicamentos(atual->medicamentos);
                break;
            }
            case 9:
                salvarDados(consultas, "data/consultas.txt", "data/medicamentos.txt");
                break;
            default:
                printf("Opcao invalida!\n");
        }

    } while (opcao != 9);

    liberarConsultas(consultas);
    return 0;
}
