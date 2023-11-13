#include "funcoes.h"
#include <stdio.h>
#include <string.h>

// menuzinho bonitinho :D
int MostrarNaTela() {
  printf("\n");
  printf("            MENU PRINCIPAL:\n");
  printf("   Bem vindo ao lista de Tarefas 500");
  printf("\n   +---------------------------------------------+ ");
  printf("\n   | (1)  - Cadastrar                            |");
  printf("\n   | (2)  - Listar                               |");
  printf("\n   | (3)  - Excluir                              |");
  printf("\n   | (4)  - Alterar                              |");
  printf("\n   | (5)  - Listar Por Prioridade                |");
  printf("\n   | (6)  - Listar Por Estado                    |");
  printf("\n   | (7)  - Listar Por Categoria                 |");
  printf("\n   | (8)  - Listar Por Prioridade e Categoria    |");
  printf("\n   | (9)  - Exportar Por Prioridade              |");
  printf("\n   | (10) - Exportar Por Categoria               |");
  printf("\n   | (11) - Exportar Por Prioridade e Categoria  |");
  printf("\n   | (0)  - Sair                                 |");
  printf("\n   +---------------------------------------------+ \n");
  printf("      Opcao: ");
  return 0;
};

// estrutura para nossa criacao de tarefas!

// funçaão para abrir e crirar o arquivo binario!
// void para não retornar nada!

// Func para entrada dos dados do usuário
// ------------------------------------------------------------------------------------------
void obterDadosTarefa(struct ListaTarefas *tarefa) {
  printf("   Digite a prioridade da tarefa: ");
  scanf("%d", &tarefa->prioridade);

  printf("   Digite a descrição da tarefa: ");
  scanf(" %[^\n]", tarefa->Descricao);

  printf("   Digite a categoria da tarefa: ");
  scanf(" %[^\n]", tarefa->Categoria);

  printf("   Digite o estado da tarefa: ");
  scanf(" %[^\n]", tarefa->Estado);
}

// Func para salvar os dados dentro do arquivo bin
// -------------------------------------------------------------------------------------------
void salvarDados(struct ListaTarefas *tarefa, const char *nomeArquivo) {
  FILE *arquivo = fopen(nomeArquivo, "ab");

  if (arquivo == NULL) {
    perror("Erro ao abrir o arquivo");
  }

  fwrite(tarefa, sizeof(struct ListaTarefas), 1, arquivo);

  fclose(arquivo);
}

// Func para listar todas as tarefas
// -------------------------------------------------------------------------------------------
void ListarTarefas(struct ListaTarefas lista[], int tamanho) {
  struct ListaTarefas dados;

  FILE *arquivo = fopen("tarefas.bin", "rb");
  if (arquivo == NULL) {
    perror("Erro ao abrir o arquivo");
    return;
  }

  int z = 1;
  // Loop para ler e listar todas as tarefas int z = 1;
  // -----------------------------------------------------------------------------------------
  while (fread(&dados, sizeof(struct ListaTarefas), 1, arquivo) == 1) {
    printf("\n   Tarefa %d:\n", z);
    z++;
    printf("   Prioridade: %d\n", dados.prioridade);
    printf("   Descrição: %s\n", dados.Descricao);
    printf("   Categoria: %s\n", dados.Categoria);
    printf("   Categoria: %s\n", dados.Estado);
  }

  printf("\n   +-------------------------------+ \n");

  fclose(arquivo);
}

// Func para excluir dados por categoria e descricao - retorna count de dado
// excluido, se == 0 nao excluiu.
// basicamente lemos o arquivo criamos um arquivo temporário com as edições
// depois subscrevemos o temporário renomeando com o mesmo nome do original,
// assim fazendoc com que os dados "excluidos temporários" se tornem os ativos.
// -------------------------------------------------------------------------------------------
int excluirTarefaPorCategoriaEDescricao(const char *nomeArquivo,
                                        const char *categoria,
                                        const char *descricao) {
  FILE *arquivo = fopen(nomeArquivo, "rb");
  if (arquivo == NULL) {
    perror("Erro ao abrir o arquivo");
  }

  FILE *temporario = fopen("temporario.bin", "wb");

  if (temporario == NULL) {
    perror("Erro ao criar arquivo temporário");
  }

  struct ListaTarefas tarefa;

  int tarefaExcluida = 0;

  while (fread(&tarefa, sizeof(struct ListaTarefas), 1, arquivo) == 1) {
    // se 0 iguais
    if (strcmp(tarefa.Categoria, categoria) == 0 &&
        strcmp(tarefa.Descricao, descricao) == 0) {

      tarefaExcluida = 1;
    } else {
      fwrite(&tarefa, sizeof(struct ListaTarefas), 1, temporario);
    }
  }

  fclose(arquivo);
  fclose(temporario);

  if (tarefaExcluida) {
    remove(nomeArquivo);
    rename("temporario.bin", nomeArquivo);
  } else {
    remove("temporario.bin");
  }

  return tarefaExcluida;
}