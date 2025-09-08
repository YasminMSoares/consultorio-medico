# Consultório Médico no Terminal

## Introdução

Este projeto implementa um sistema em **C** para gerenciar **consultas médicas** e **medicamentos**, utilizando **listas duplamente encadeadas**. A interface é por terminal, com menu interativo que facilita o cadastro, listagem e persistência dos dados em arquivos.

A proposta é oferecer uma estrutura clara e modular, pronta para uso acadêmico ou como base para projetos maiores.

---

## Modelagem do Problema

Cada **consulta** está ligada a informações como paciente, médico, data e uma lista de medicamentos. As operações principais incluem:

- Cadastrar consultas
- Listar consultas existentes
- Inserir medicamentos relacionados a cada consulta
- Listar medicamentos de uma consulta
- Salvar e carregar dados automaticamente via arquivos `.txt`

A solução foi implementada com estruturas claras e modulares para facilitar manutenção e extensões futuras.

---

## Bibliotecas utilizadas

- `stdio.h` — Entrada e saída padrão (`printf`, `scanf`, `fgets`, etc.)  
- `stdlib.h` — Funções de alocação de memória (`malloc`, `free`) e controle de fluxo  
- `string.h` — Manipulação de strings (`strcpy`, `strlen`, `strcspn`)  

---

## Estruturas de Dados Utilizadas

- **Lista duplamente encadeada de Consultas** — cada nó representa uma consulta com ponteiros `prev` e `next`
- **Lista duplamente encadeada de Medicamentos** — cada consulta possui sua própria lista de medicamentos, também com `prev` e `next`

---

## Documentação do Código

### `consultas.c / consultas.h`

- `criarConsulta(int id, const char *paciente, const char *medico, const char *data, int favorita)`
  - Cria e retorna um novo nó de consulta.

- `listarConsultas(Consulta *inicio)`
  - Imprime todas as consultas armazenadas.

- `liberarConsultas(Consulta *inicio)`
  - Libera a memória de todas as consultas e seus medicamentos.

- `carregarDados(const char *arquivoConsultas, const char *arquivoMedicamentos)`
  - Carrega dados dos arquivos para as listas correspondentes.

- `salvarDados(Consulta *inicio, const char *arquivoConsultas, const char *arquivoMedicamentos)`
  - Salva consultas e medicamentos em arquivos `.txt`.

### `medicamentos.c / medicamentos.h`

- `criarMedicamento(int id, const char *nome, const char *dose, int controlado)`
  - Cria e retorna um novo nó de medicamento.

- `listarMedicamentos(Medicamento *inicio)`
  - Imprime todos os medicamentos de uma consulta.

- `liberarMedicamentos(Medicamento *inicio)`
  - Libera memória dos medicamentos de uma lista.

---

## Exemplos de Uso

```text
> 1 - Cadastrar consulta
Nome do paciente: João Silva
Nome do médico: Dr. Marcos
Data (dd/mm/aaaa hh:mm): 10/09/2025 09:00
Consulta cadastrada!

> 2 - Listar consultas
ID: 1 | Paciente: João Silva | Médico: Dr. Marcos | Data: 10/09/2025 09:00 | Favorita: 0

> 4 - Adicionar medicamento
ID da consulta: 1
Nome: Dipirona
Dose: 500mg
Controlado? (1=Sim, 0=Não): 0
Medicamento adicionado!

> 5 - Listar medicamentos
Medicamentos da consulta 1:
ID: 1 | Nome: Dipirona | Dose: 500mg | Controlado: 0

> 9 - Salvar e sair
Dados salvos com sucesso!
