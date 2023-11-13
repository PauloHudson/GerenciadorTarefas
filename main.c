#include "funcoes.h"
#include <stdio.h>

int main() {
  int continuar = 1;
  struct ListaTarefas lista[100];
  int tamanho = 0;
  int teste = 0;
  char categoriaParaExcluir[100];
  char descricaoParaExcluir[255];

  do {
    MostrarNaTela();

    scanf("%d", &continuar);

    switch (continuar) {
    case 1:
      obterDadosTarefa(&lista);
      salvarDados(&lista, "tarefas.bin");
      break;
    case 2:
      printf("\n");
      ListarTarefas(lista, tamanho);
      break;
    case 3:
      printf("   Digite a categoria da tarefa que deseja excluir: ");
      scanf(" %[^\n]", categoriaParaExcluir);

      printf("   Digite a descrição da tarefa que deseja excluir: ");
      scanf(" %[^\n]", descricaoParaExcluir);

      int tarefaExcluida = excluirTarefaPorCategoriaEDescricao(
          "tarefas.bin", categoriaParaExcluir, descricaoParaExcluir);

      if (tarefaExcluida) {
        printf("   Tarefa com categoria '%s' e descrição '%s' excluída com "
               "sucesso.\n",
               categoriaParaExcluir, descricaoParaExcluir);
      } else {
        printf("Nenhuma tarefa com categoria '%s' e descrição '%s' foi "
               "encontrada.\n",
               categoriaParaExcluir, descricaoParaExcluir);
      }
      break;
    case 4:
      printf("\n");
      alterarTarefa("tarefas.bin");
      break;
    case 5:
      printf("\n");
      filtrarPorPrioridade("tarefas.bin");
      break;
    case 0:
      printf("\n   Opção 0 - Sair\n");
      break;
    default:
      printf("\n   Digite uma opção válida\n");
    }

  } while (continuar != 0);

  return 0;
}
