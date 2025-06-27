#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// protótipos
void cadastro_cliente();
void cadastro_produto();
void venda();
void listar_clientes();
void listar_produtos();
void excluir_cliente();
void excluir_produto();
void editar_cliente();
void editar_produto();
void relatorio_vendas();

#define MAX 10

// structs
typedef struct {
   char nome[50];
   char cpf[12];
   int idade;
} Cliente;

typedef struct {
   char nome[50];
   float preco;
   int codigo;
} Produto;

typedef struct {
    char cpf_cliente[15];
    int cod_produto;
    int quantidade;
} Venda;

typedef struct {
    char cpf_cliente[15];
    char forma[20];
} Pagamento;

Cliente clientes[MAX];
Produto produtos[MAX];
Venda vendas[MAX];
Pagamento pagamentos[MAX];

int total_clientes = 0;
int total_produtos = 0;

void limpar_linha(char *linha) {
    linha[strcspn(linha, "\n")] = 0;
}

int main()
{
    int opcao;

    do {
        printf("\nMenu Principal:\n");
        printf("0 = sair\n");
        printf("1 = cadastrar clientes\n");
        printf("2 = cadastrar produtos\n");
        printf("3 = efetuar uma venda\n");
        printf("4 = listar os clientes\n");
        printf("5 = listar os produtos\n");
        printf("6 = excluir um cliente\n");
        printf("7 = excluir um produto\n");
        printf("8 = editar um cliente\n");
        printf("9 = editar um produto\n");
        printf("10 = relatorio de vendas\n");
        printf("Escolha uma opcao:\n");
        scanf("%d", &opcao); getchar();

        switch(opcao) {
            case 1: cadastro_cliente(); break;
            case 2: cadastro_produto(); break;
            case 3: venda(); break;
            case 4: listar_clientes(); break;
            case 5: listar_produtos(); break;
            case 6: excluir_cliente(); break;
            case 7: excluir_produto(); break;
            case 8: editar_cliente(); break;
            case 9: editar_produto(); break;
            case 10: relatorio_vendas(); break;
            case 0:
                printf("Encerrando o programa...\n");
                break;
            default:
                printf("Opcao Invalida, escolha outra\n");
                break;
        }

    } while(opcao != 0);
    return 0;
}

void cadastro_cliente() {
    if (total_clientes >= MAX) {
        printf("Limite de clientes atingido.\n");
        return;
    }
    printf("Bem vindo ao cadastro de cliente\n");
    printf("Informe o nome do cliente:\n");
    fgets(clientes[total_clientes].nome, 50, stdin); limpar_linha(clientes[total_clientes].nome);
    printf("Informe a idade do cliente:\n");
    scanf("%d", &clientes[total_clientes].idade); getchar();
    printf("Informe o cpf do cliente(somente numeros):\n");
    fgets(clientes[total_clientes].cpf, 12, stdin); limpar_linha(clientes[total_clientes].cpf);
    total_clientes++;
    printf("Cliente cadastrado com sucesso!\n");
}

void cadastro_produto() {
    if (total_produtos >= MAX) {
        printf("Limite de produtos atingido.\n");
        return;
    }
    printf("Bem vindo ao cadastro de produto\n");
    printf("Informe o nome do produto:\n");
    fgets(produtos[total_produtos].nome, 50, stdin); limpar_linha(produtos[total_produtos].nome);
    printf("Informe o codigo do produto:\n");
    scanf("%d", &produtos[total_produtos].codigo); getchar();
    printf("Informe o valor unitario do produto:\n");
    scanf("%f", &produtos[total_produtos].preco); getchar();
    total_produtos++;
    printf("Produto cadastrado com sucesso!\n");
}

void venda() {
    char cpf[12];
    int codigo, quantidade;

    printf("CPF do cliente: ");
    fgets(cpf, 12, stdin); limpar_linha(cpf);
    printf("Codigo do produto: ");
    scanf("%d", &codigo); getchar();
    printf("Quantidade: ");
    scanf("%d", &quantidade); getchar();

    int cliente_encontrado = 0, produto_index = -1;

    for (int i = 0; i < total_clientes; i++) {
        if (strcmp(clientes[i].cpf, cpf) == 0) cliente_encontrado = 1;
    }
    for (int i = 0; i < total_produtos; i++) {
        if (produtos[i].codigo == codigo) produto_index = i;
    }

    if (!cliente_encontrado || produto_index == -1) {
        printf("Cliente/Produto nao encontrado.\n");
        return;
    }

    char forma_pagamento[20];
    printf("Forma de pagamento (pix/dinheiro/boleto/cartao): ");
    fgets(forma_pagamento, 20, stdin); limpar_linha(forma_pagamento);

    for (int i = 0; i < MAX; i++) {
        if (vendas[i].cpf_cliente[0] == '\0') {
            strcpy(vendas[i].cpf_cliente, cpf);
            vendas[i].cod_produto = codigo;
            vendas[i].quantidade = quantidade;
            strcpy(pagamentos[i].cpf_cliente, cpf);
            strcpy(pagamentos[i].forma, forma_pagamento);
            printf("Venda registrada com pagamento via: %s\n", forma_pagamento);
            return;
        }
    }

    printf("Limite de vendas atingido.\n");
}

void listar_clientes() {
    printf("\nListagem de clientes cadastrados:\n");
    for (int i = 0; i < total_clientes; i++) {
        printf("%d - %s\n", i + 1, clientes[i].nome);
    }
}

void listar_produtos() {
    printf("\nListagem de produtos cadastrados:\n");
    for (int i = 0; i < total_produtos; i++) {
        printf("%d - %s\n", produtos[i].codigo, produtos[i].nome);
    }
}

void excluir_cliente() {
    char nome[50];
    printf("Digite o nome do cliente que deseja EXCLUIR:\n");
    fgets(nome, 50, stdin); limpar_linha(nome);

    for (int i = 0; i < total_clientes; i++) {
        if (strcmp(clientes[i].nome, nome) == 0) {
            for (int j = i; j < total_clientes - 1; j++) {
                clientes[j] = clientes[j + 1];
            }
            total_clientes--;
            printf("--Cliente %s excluido com sucesso!\n", nome);
            return;
        }
    }
    printf("Cliente nao cadastrado!\n");
}

void excluir_produto() {
    char nome[50];
    printf("Digite o nome do produto que deseja EXCLUIR:\n");
    fgets(nome, 50, stdin); limpar_linha(nome);

    for (int i = 0; i < total_produtos; i++) {
        if (strcmp(produtos[i].nome, nome) == 0) {
            for (int j = i; j < total_produtos - 1; j++) {
                produtos[j] = produtos[j + 1];
            }
            total_produtos--;
            printf("--Produto %s excluido com sucesso!\n", nome);
            return;
        }
    }
    printf("Produto nao cadastrado!\n");
}

void editar_cliente() {
    char nome[50];
    printf("Digite o nome do cliente que deseja editar:\n");
    fgets(nome, 50, stdin); limpar_linha(nome);

    for (int i = 0; i < total_clientes; i++) {
        if (strcmp(clientes[i].nome, nome) == 0) {
            int opcao;
            printf("Qual informacao deseja editar?\n1-nome\n2-idade\n3-cpf\n");
            scanf("%d", &opcao); getchar();

            switch(opcao) {
                case 1:
                    printf("Digite o novo nome:\n");
                    fgets(clientes[i].nome, 50, stdin); limpar_linha(clientes[i].nome);
                    break;
                case 2:
                    printf("Digite a nova idade:\n");
                    scanf("%d", &clientes[i].idade); getchar();
                    break;
                case 3:
                    printf("Digite o novo cpf:\n");
                    fgets(clientes[i].cpf, 12, stdin); limpar_linha(clientes[i].cpf);
                    break;
                default:
                    printf("Opcao invalida.\n");
                    break;
            }
            printf("Cliente editado com sucesso!\n");
            return;
        }
    }
    printf("Cliente nao encontrado!\n");
}

void editar_produto() {
    char nome[50];
    printf("Digite o nome do produto que deseja editar:\n");
    fgets(nome, 50, stdin); limpar_linha(nome);

    for (int i = 0; i < total_produtos; i++) {
        if (strcmp(produtos[i].nome, nome) == 0) {
            int opcao;
            printf("Qual informacao deseja editar?\n1-nome\n2-preco\n3-codigo\n");
            scanf("%d", &opcao); getchar();

            switch(opcao) {
                case 1:
                    printf("Digite o novo nome:\n");
                    fgets(produtos[i].nome, 50, stdin); limpar_linha(produtos[i].nome);
                    break;
                case 2:
                    printf("Digite o novo preco:\n");
                    scanf("%f", &produtos[i].preco); getchar();
                    break;
                case 3:
                    printf("Digite o novo codigo:\n");
                    scanf("%d", &produtos[i].codigo); getchar();
                    break;
                default:
                    printf("Opcao invalida.\n");
                    break;
            }
            printf("Produto editado com sucesso!\n");
            return;
        }
    }
    printf("Produto nao encontrado!\n");
}

void relatorio_vendas() {
    printf("\nRelatorio de vendas:\n");
    for (int i = 0; i < MAX; i++) {
        if (vendas[i].cpf_cliente[0] != '\0') {
            char nome_cliente[50] = "Desconhecido";
            char nome_produto[50] = "Desconhecido";
            for (int j = 0; j < total_clientes; j++) {
                if (strcmp(clientes[j].cpf, vendas[i].cpf_cliente) == 0)
                    strcpy(nome_cliente, clientes[j].nome);
            }
            for (int j = 0; j < total_produtos; j++) {
                if (produtos[j].codigo == vendas[i].cod_produto)
                    strcpy(nome_produto, produtos[j].nome);
            }
            printf("Cliente: %s | Produto: %s | Qtde: %d | Pagamento: %s\n",
                nome_cliente, nome_produto, vendas[i].quantidade, pagamentos[i].forma);
        }
    }
}
