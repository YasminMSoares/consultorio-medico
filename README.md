# 🏥 Consultório Médico - Sistema de Gerenciamento

## Introdução

Projeto desenvolvido em C utilizando listas duplamente encadeadas para gerenciar consultas médicas e os medicamentos prescritos em cada uma.
O sistema possui um menu interativo, grava e lê informações a partir de arquivos de texto e possibilita diversas operações para organização dos dados.

## 📌 Funcionalidades

Cada **consulta** está ligada a informações como paciente, médico, data e uma lista de medicamentos. As operações principais incluem:<br/>
✔️ Cadastro de consultas<br/>
✔️ Listagem de consultas cadastradas<br/>
✔️ Busca de consultas por ID ou paciente<br/>
✔️ Remoção de consultas<br/>
✔️ Adição de medicamentos a uma consulta<br/>
✔️ Listagem de medicamentos de cada consulta<br/>
✔️ Marcar uma consulta como favorita<br/>
✔️ Geração de relatórios gerais<br/>
✔️ Salvamento e carregamento em arquivos de texto<br/>

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

```C
Consulta* criarConsulta(int id, const char *paciente, const char *medico, const char *data, int favorita);
```
Recebe os dados de uma consulta médica: <br/>
- id: número inteiro representando o identificador único da consulta, <br/>
- paciente: string com o nome do paciente, <br/>
- medico: string com o nome do médico responsável, <br/>
- data: string com a data da consulta no formato desejado, <br/>
- favorita: inteiro (0 ou 1) indicando se a consulta é marcada como favorita. <br/>
Cria dinamicamente uma nova estrutura Consulta com os dados fornecidos.<br/>
Devolve um ponteiro para o tipo Consulta representando a nova consulta criada. <br/>

```C
void listarConsultas(Consulta *inicio);
```
Recebe um ponteiro para o início da lista encadeada de consultas (`inicio`). <br/>
Percorre toda a lista de consultas, imprimindo os dados de cada consulta: <br/>
- id,<br/>
- paciente,<br/>
- médico,<br/>
- data,<br/>
- status de favorita.
Não devolve nenhum valor (tipo `void`), apenas exibe as informações das consultas na saída padrão.<br/>

```C
void liberarConsultas(Consulta *inicio);
```
Recebe um ponteiro para o início da lista encadeada de consultas (`inicio`).<br/>
Percorre toda a lista de consultas e libera a memória alocada para cada nó da lista, incluindo os dados armazenados em strings, garantindo que não haja vazamento de memória.<br/>
Não devolve nenhum valor (tipo `void`), apenas libera os recursos utilizados pela lista de consultas.<br/>

```C
Consulta* carregarDados(const char *arquivoConsultas, const char *arquivoMedicamentos);
```
Recebe dois caminhos de arquivos: <br/>
- `arquivoConsultas`: string com o caminho do arquivo que contém os dados das consultas,<br/>
- `arquivoMedicamentos`: string com o caminho do arquivo que contém os dados dos medicamentos.
Lê os dados dos arquivos e cria dinamicamente uma lista encadeada de consultas, associando cada consulta aos medicamentos correspondentes, se houver.<br/>
Devolve um ponteiro para o tipo Consulta representando o início da lista carregada com todos os dados.<br/>

```C
void salvarDados(Consulta *inicio, const char *arquivoConsultas, const char *arquivoMedicamentos);
```
Recebe:<br/>
- `inicio`: ponteiro para o início da lista encadeada de consultas,<br/>
- `arquivoConsultas`: string com o caminho do arquivo onde os dados das consultas devem ser salvos,<br/>
- `arquivoMedicamentos`: string com o caminho do arquivo onde os dados dos medicamentos devem ser salvos.
Percorre toda a lista de consultas e escreve os dados das consultas e seus medicamentos correspondentes nos arquivos especificados, permitindo que os dados sejam persistidos para uso futuro.<br/>
Não devolve nenhum valor (tipo `void`), apenas salva os dados nos arquivos fornecidos.<br/>

```C
Consulta* removerConsulta(Consulta *inicio, int id);
```
Recebe:<br/>
- `inicio`: ponteiro para o início da lista encadeada de consultas,<br/>
- `id`: inteiro representando o identificador da consulta que deve ser removida.
Procura na lista encadeada a consulta com o `id` especificado, remove-a da lista e libera a memória ocupada por essa consulta.<br/>
Devolve um ponteiro para o início da lista atualizada de consultas (pode ser diferente do ponteiro original se a primeira consulta for removida).<br/>

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
