//
// Created by unifpsilva on 15/08/2023.
//
struct ListaTarefas {
  int prioridade;
  char Descricao[255];
  char Categoria[100];
  char Estado[255];
};

int MostrarNaTela();
void Cadastrar(struct ListaTarefas lista[], int *tamanho, int teste);
void salvarListaBinario(struct ListaTarefas lista[], int tamanho);
void ListarTarefas(struct ListaTarefas lista[], int tamanho);
int excluirTarefaPorCategoriaEDescricao(const char *nomeArquivo,
                                        const char *categoria,
                                        const char *descricao);
void salvarDados(struct ListaTarefas *tarefa, const char *nomeArquivo);
void alterarTarefa(const char *nomeArquivo);
void filtrarPorPrioridade(const char *nomeArquivo);
void filtrarPorEstado(const char *nomeArquivo);
int compararPrioridades(const void *a, const void *b);
void filtrarPorCategoriaOrdenado(const char *nomeArquivo);
void filtrarPorPrioridadeECategoria(const char *nomeArquivo);
void exportarPorPrioridade(const char *nomeArquivo);
void exportarPorCategoria(const char *nomeArquivo);
void exportarPorPrioridadeECategoria(const char *nomeArquivo);

#ifndef UNTITLED_FUNCOES_H
#define UNTITLED_FUNCOES_H

#endif // UNTITLED_FUNCOES_H