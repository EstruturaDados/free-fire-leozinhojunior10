#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h> // Para medir tempo de execução

#define MAX_ITENS 10

typedef struct {
    char nome[30];
    char tipo[20];
    int quantidade;
} Item;

Item mochila[MAX_ITENS];
int totalItens = 0;

void inserirItem();
void removerItem();
void listarItens();
void buscarItem();

// Protótipos adicionais para vetor e lista
void inserirItemVetor();
void removerItemVetor();
void ordenarVetor();
void buscarSequencialVetor();
void buscarBinariaVetor();

// Protótipos para lista encadeada
void inserirItemLista();
void removerItemLista();
void listarItensLista();
void buscarItemLista();

int main() {
    int opcao;

    do {
        printf("
========== SISTEMA DE INVENTÁRIO =========\n");
        printf("Escolha o tipo de estrutura:
");
        printf("1. Vetor de Itens
");
        printf("2. Lista Encadeada
");
        printf("0. Sair
");
        printf("Escolha uma opção: "););
        printf("1. Inserir Item\n");
        printf("2. Remover Item\n");
        printf("3. Listar Itens\n");
        printf("4. Buscar Item\n");
        printf("0. Sair\n");
        printf("Escolha uma opção: ");
        scanf("%d", &opcao);
        getchar();

        switch (opcao) {
            case 1:
                inserirItem();
                break;
            case 2:
                removerItem();
                break;
            case 3:
                listarItens();
                break;
            case 4:
                buscarItem();
                break;
            case 0:
                printf("Saindo do sistema... Até mais!\n");
                break;
            default:
                printf("Opção inválida! Tente novamente.\n");
        }

    } while(opcao != 0);

    return 0;
}

void inserirItem() {
    if (totalItens >= MAX_ITENS) {
        printf("Mochila cheia! Não é possível adicionar mais itens.\n");
        return;
    }

    Item novoItem;
    printf("\nDigite o nome do item: ");
    fgets(novoItem.nome, 30, stdin);
    novoItem.nome[strcspn(novoItem.nome, "\n")] = '\0';

    printf("Digite o tipo do item (ex: arma, munição, cura): ");
    fgets(novoItem.tipo, 20, stdin);
    novoItem.tipo[strcspn(novoItem.tipo, "\n")] = '\0';

    printf("Digite a quantidade: ");
    scanf("%d", &novoItem.quantidade);
    getchar();

    mochila[totalItens] = novoItem;
    totalItens++;

    printf("Item adicionado com sucesso!\n");
    listarItens();
}

void removerItem() {
    char nome[30];
    printf("\nDigite o nome do item a remover: ");
    fgets(nome, 30, stdin);
    nome[strcspn(nome, "\n")] = '\0';

    for (int i = 0; i < totalItens; i++) {
        if (strcmp(mochila[i].nome, nome) == 0) {
            for (int j = i; j < totalItens - 1; j++) {
                mochila[j] = mochila[j + 1];
            }
            totalItens--;
            printf("Item removido com sucesso!\n");
            listarItens();
            return;
        }
    }
    printf("Item não encontrado!\n");
}

void listarItens() {
    if (totalItens == 0) {
        printf("\nA mochila está vazia.\n");
        return;
    }

    printf("\nItens na mochila:\n");
    for (int i = 0; i < totalItens; i++) {
        printf("%d - Nome: %s | Tipo: %s | Quantidade: %d\n",
               i + 1, mochila[i].nome, mochila[i].tipo, mochila[i].quantidade);
    }
}

void buscarItem() {
    char nome[30];
    printf("\nDigite o nome do item para buscar: ");
    fgets(nome, 30, stdin);
    nome[strcspn(nome, "\n")] = '\0';

    for (int i = 0; i < totalItens; i++) {
        if (strcmp(mochila[i].nome, nome) == 0) {
            printf("Item encontrado!\n Nome: %s | Tipo: %s | Quantidade: %d\n",
                   mochila[i].nome, mochila[i].tipo, mochila[i].quantidade);
            return;
        }
    }
    printf("Item não encontrado!\n");
}

/* ======================================================
   Módulo avançado: Priorização e montagem dos componentes
   - Implementa estruturas e algoritmos de ordenação
   - Contabiliza comparações e tempo de execução
   - Busca binária sobre ordenação por nome
   ====================================================== */

#define MAX_COMPONENTES 20

typedef struct {
    char nome[30];
    char tipo[20];
    int prioridade; // 1 (mais baixo) .. 10 (mais alto)
} Componente;

// Protótipos das funções do módulo de componentes
void cadastrarComponentes(Componente comp[], int *n);
void mostrarComponentes(Componente comp[], int n);
long bubbleSortNome(Componente comp[], int n); // retorna número de comparações
long insertionSortTipo(Componente comp[], int n);
long selectionSortPrioridade(Componente comp[], int n);
int buscaBinariaPorNome(Componente comp[], int n, const char chave[], long *comparacoes);

// Função auxiliar para remover newline de fgets
void trim_newline(char *s) {
    s[strcspn(s, "
")] = '
