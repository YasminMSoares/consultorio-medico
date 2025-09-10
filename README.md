# 🏥 Consultório Médico - Sistema de Gerenciamento

## Introdução

Projeto desenvolvido em C utilizando listas duplamente encadeadas para gerenciar consultas médicas e os medicamentos prescritos em cada uma.
O sistema possui um menu interativo, grava e lê informações a partir de arquivos de texto e possibilita diversas operações para organização dos dados.

## 📌 Funcionalidades

Cada **consulta** está ligada a informações como paciente, médico, data e uma lista de medicamentos. As operações principais incluem:

✔️ Cadastro de consultas

✔️ Listagem de consultas cadastradas

✔️ Busca de consultas por ID ou paciente

✔️ Remoção de consultas

✔️ Adição de medicamentos a uma consulta

✔️ Listagem de medicamentos de cada consulta

✔️ Marcar uma consulta como favorita

✔️ Geração de relatórios gerais

✔️ Salvamento e carregamento em arquivos de texto

## Bibliotecas utilizadas

- `stdio.h` — Entrada e saída padrão (`printf`, `scanf`, `fgets`, etc.)  
- `stdlib.h` — Funções de alocação de memória (`malloc`, `free`) e controle de fluxo  
- `string.h` — Manipulação de strings (`strcpy`, `strlen`, `strcspn`)  

---

## Estruturas de Dados Utilizadas

- **Lista duplamente encadeada de Consultas** — cada nó representa uma consulta com ponteiros `prev` e `next`
- **Lista duplamente encadeada de Medicamentos** — cada consulta possui sua própria lista de medicamentos, também com `prev` e `next`

---

## 📖 Documentação do Código

### 🔹 Funções principais

criarConsulta() → Cria uma nova consulta e adiciona na lista de consultas.

listarConsultas() → Percorre a lista duplamente ligada mostrando todas as consultas cadastradas.

buscarConsultaPorID() → Procura uma consulta pelo seu identificador único.

removerConsulta() → Remove uma consulta da lista, ajustando os ponteiros da lista duplamente ligada.

adicionarMedicamento() → Insere um medicamento na lista de medicamentos de uma consulta específica.

listarMedicamentos() → Mostra todos os medicamentos associados a uma consulta.

favoritarConsulta() → Marca determinada consulta como favorita.

salvarConsultasEmArquivo() → Grava todas as consultas e seus medicamentos nos arquivos consultas.txt e medicamentos.txt.

carregarConsultasDeArquivo() → Carrega consultas e medicamentos a partir dos arquivos de texto para as listas em memória.

## 🗂️ Arquivos de Texto

-consultas.txt → Armazena as informações principais de cada consulta no formato:

ID | Paciente | Médico | Data | Favorita
1 | João Silva | Dr. Marcos | 10/09/2025 09:00 | 0

-medicamentos.txt → Lista os medicamentos de cada consulta:

ID_Consulta | Nome do Medicamento | Dosagem
1 | Amoxicilina | 500mg
1 | Ibuprofeno | 400mg

## ▶️ Exemplo de Uso

### Entrada (menu interativo)

1 - Adicionar Consulta

2 - Listar Consultas

3 - Buscar Consulta

4 - Remover Consulta

5 - Adicionar Medicamento

6 - Listar Medicamentos

7 - Favoritar Consulta

8 - Relatório Geral

0 - Sair

> 1 - Cadastrar consulta
> 
Nome do paciente: João Silva

Nome do médico: Dr. Marcos

Data (dd/mm/aaaa hh:mm): 10/09/2025 09:00

Consulta cadastrada!

> 2 - Listar consultas
> 
ID: 1 | Paciente: João Silva | Médico: Dr. Marcos | Data: 10/09/2025 09:00 | Favorita: 0

> 4 - Adicionar medicamento
> 
ID da consulta: 1

Nome: Dipirona

Dose: 500mg

Controlado? (1=Sim, 0=Não): 0

Medicamento adicionado!

> 5 - Listar medicamentos
> 
Medicamentos da consulta 1:

ID: 1 | Nome: Dipirona | Dose: 500mg | Controlado: 0

> 9 - Salvar e sair
> 
Dados salvos com sucesso!

### Saída esperada

==== Consultas Cadastradas ====

1 | João Silva | Dr. Marcos | 10/09/2025 09:00 | Favorita: Não

2 | Maria Oliveira | Dra. Ana | 12/09/2025 14:00 | Favorita: Sim

## 🔄 Andando pela Lista

O sistema percorre a lista duplamente ligada de consultas, permitindo navegar para frente e para trás, inserindo, removendo e listando dados sem perder a integridade das ligações entre nós.

## 📌 Conclusão

Este projeto proporcionou experiência prática com:

-Manipulação de listas duplamente encadeadas;

-Criação de menus interativos em C;

-Persistência de dados em arquivos de texto;

-Modularização do código com .h e .c;

-Boas práticas de versionamento com Git e GitHub.

## 🛠️ Tecnologias Utilizadas

Linguagem C

TDM-GCC / MinGW (compilador)

VS Code (editor de código)

Git & GitHub (versionamento)

## 👨‍💻 Autora

Projeto desenvolvido por Yasmin Moreira Soares – Ciência da Computação (UFU)
