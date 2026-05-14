#include <stdio.h>
#include <string.h>

#define MAX 100

// Estrutura do cliente
struct Cliente {
    int id;
    char nome[50];
    char telefone[20];
};

int main() {
    struct Cliente clientes[MAX];
    int total = 0;
    int opcao = 0;

    while (opcao != 5) {
        printf("\n===== SISTEMA DE CLIENTES =====\n");
        printf("1 - Cadastrar cliente\n");
        printf("2 - Listar clientes\n");
        printf("3 - Buscar cliente\n");
        printf("4 - Excluir clientes\n");
        printf("5 - Sair\n");
        printf("Escolha uma opcao: ");

        scanf("%d", &opcao);
        getchar(); // limpar buffer

        // CADASTRAR
        if (opcao == 1) {

            if (total < MAX) {

                clientes[total].id = total + 1;

                printf("Nome: ");
                fgets(clientes[total].nome, 50, stdin);
                clientes[total].nome[strcspn(clientes[total].nome, "\n")] = '\0';

                printf("Telefone: ");
                fgets(clientes[total].telefone, 20, stdin);
                clientes[total].telefone[strcspn(clientes[total].telefone, "\n")] = '\0';

                total++;

                printf("Cliente cadastrado com sucesso!\n");
            } else {
                printf("Limite de clientes atingido!\n");
            }
        }

        // LISTAR
        else if (opcao == 2) {
            if (total == 0) {
                printf("Nenhum cliente cadastrado.\n");

            } else {
                printf("\n--- LISTA DE CLIENTES ---\n");
                for (int i = 0; i < total; i++) {
                    printf("ID: %d\n", clientes[i].id);
                    printf("Nome: %s\n", clientes[i].nome);
                    printf("Telefone: %s\n", clientes[i].telefone);
                    printf("-------------------------\n");
                }
            }
        }

        // BUSCAR
        else if (opcao == 3) {

            char busca[50];
            int encontrado = 0;

            printf("Digite o nome para busca: ");

            fgets(busca, 50, stdin);
            busca[strcspn(busca, "\n")] = '\0';

            for (int i = 0; i < total; i++) {

                if (strcmp(clientes[i].nome, busca) == 0) {
                    printf("\nCliente encontrado:\n");
                    printf("ID: %d\n", clientes[i].id);
                    printf("Nome: %s\n", clientes[i].nome);
                    printf("Telefone: %s\n", clientes[i].telefone);
                    encontrado = 1;
                }
            }

            if (encontrado == 0) {
                printf("Cliente nao encontrado.\n");
            }
        }

        // EXCLUIR
        else if (opcao == 4) {
            int idbuscar;
            int encontrado = 0;

            printf("Digite o ID do cliente para exclusao: ");
            scanf("%d", &idbuscar);
            getchar();

            for (int i = 0; i < total; i++) {
                if (clientes[i].id == idbuscar) {

                    for (int y = i; y < total - 1; y++) {
                        clientes[y] = clientes[y + 1];
                    }

                    total--;

                    // Reorganizar ID
                    for (int u = 0; u < total; u++) {
                        clientes[u].id = u + 1;
                    }

                    encontrado = 1;

                    printf("Cliente excluido com sucesso!\n");
                    break;
                }
            }

            if (encontrado == 0) {
                printf("Cliente nao encontrado.\n");
            }
        }

        // OPÇÃO INVÁLIDA
        else if (opcao != 5) {
            printf("Opcao invalida!\n");
        }
    }

    printf("Encerrando sistema...\n");
    return 0;
}

// Executar código: .\cadastro.exe
