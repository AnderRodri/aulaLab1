#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int cadastro_cliente();
int cadastro_produto();
int venda();
void listar_clientes();
void excluir_cliente();

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

Cliente clientes[10];
Produto produtos[10];

int total_clientes = 0;
int total_produtos = 0;

int main()
{
int opcao;

    do {
        printf("Menu Principal:\n");
        printf("1 = cadastrar clientes\n");
        printf("2 = cadastrar produtos\n");
        printf("3 = efetuar uma venda\n");
        printf("4 = listar os clientes\n");
        printf("5 = excluir um cliente\n");
        printf("0 = sair\n");
        printf("Escolha uma opcao:\n");
        scanf("%d", &opcao);

        switch(opcao) {

        case 1:
        cadastro_cliente();
        break;
        case 2:
        cadastro_produto();
        break;
        case 3:
        venda();
        break;
        case 4:
        listar_clientes();
        break;
        case 5:
        excluir_cliente();
        break;
        case 0:
        printf("Encerrando o programa...\n");
        break;
        default:
        printf("Opcao Invalida, escolha outra\n");
        }

    } while(opcao != 0);
}

    int cadastro_cliente() {

    printf("Bem vindo ao cadastro de cliente\n");
    printf("Informe o nome do cliente:\n");
    scanf("%s", clientes[total_clientes].nome);
    printf("Informe a idade do cliente:\n");
    scanf("%d", &clientes[total_clientes].idade);
    printf("Informe o cpf do cliente(somente numeros):\n");
    scanf("%s", clientes[total_clientes].cpf);
    printf("Cliente cadastrado com sucesso!\nNome: %s\nIdade: %d\nCPF: %s\n", clientes[total_clientes].nome, clientes[total_clientes].idade, clientes[total_clientes].cpf);
    total_clientes++;
    }

    int cadastro_produto() {

    printf("Bem vindo ao cadastro de produto\n");
    printf("Informe o nome do produto:\n");
     scanf("%s", produtos[total_produtos].nome);
    printf("Informe o codigo do produto:\n");
    scanf("%d", &produtos[total_produtos].codigo);
    printf("Informe o valor unitário do produto:\n");
    scanf("%f", &produtos[total_produtos].preco);
    printf("Produto cadastrado com sucesso!\nNome: %s\nCodigo: %d\nValor: %.2lf\n", produtos[total_produtos].nome, produtos[total_produtos].codigo, produtos[total_produtos].preco);
    total_produtos++;
    }

    int venda() {
    char cliente[50];
    int quantidade, codigo, pagamento;
    double valor;
    printf("Bem vindo ao menu de venda\n");
    printf("Informe o codigo do produto:\n");
    scanf("%d", &codigo);
    printf("Informe a quantidade:\n");
    scanf("%d", &quantidade);
    printf("Informe o valor de venda do produto:\n");
    scanf("%lf", &valor);
    printf("Informe o cliente:\n");
    scanf("%s", cliente);
    printf("Qual o metodo de pagamento?\n1 - dinheiro\n2 - pix\n3 - cartao\n4 - crediario\n");
    scanf("%d", &pagamento);
    valor = valor * quantidade;
    switch(pagamento) {

case 1:
    printf("Venda efetuada com sucesso!\nProduto: %d\nQuantidade: %d\nValor: %.2lf\nCliente: %s\nMetodo de pagamento: Dinheiro\n", codigo, quantidade, valor, cliente);
    break;
case 2:
    printf("Venda efetuada com sucesso!\nProduto: %d\nQuantidade: %d\nValor: %.2lf\nCliente: %s\nMetodo de pagamento: PIX\n", codigo, quantidade, valor, cliente);
    break;
case 3:
    printf("Venda efetuada com sucesso!\nProduto: %d\nQuantidade: %d\nValor: %.2lf\nCliente: %s\nMetodo de pagamento: Cartao\n", codigo, quantidade, valor, cliente);
    break;
case 4:
    printf("Venda efetuada com sucesso!\nProduto: %d\nQuantidade: %d\nValor: %.2lf\nCliente: %s\nMetodo de pagamento: Crediario\n", codigo, quantidade, valor, cliente);
    break;
default:
    printf("Metodo de pagamento invalido!\n");

    }
    }

    void listar_clientes() {

   int contador = 0;
   int i = 0 ;
   printf("\nListagem de clientes cadastrados:\n\n");

    while(i < total_clientes){
    printf("%d - %s\n", contador, clientes[i].nome);
    contador++;
    i++;
   }
    }

    void excluir_cliente(){
    char nome_cliente[50];
printf("Informe o nome do cliente a ser excluído: ");
scanf("%s", nome_cliente);

int i = 0;
while (i < total_clientes && strcmp(clientes[i].nome, nome_cliente) != 0) {
    i++;
}

if (i < total_clientes) {
    for (int j = i; j < total_clientes - 1; j++) {
        clientes[j] = clientes[j + 1];
    }
    total_clientes--;
    printf("Cliente excluído com sucesso!\n");
} else {
    printf("Cliente não encontrado.\n");
}
}
