#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>

#define number 50

/** Esse programa visa solucionar o problema de garantir um bom atendimentos aos clientes do Hotel Descanso Garantido,
    a partir das principais atividades hoteleiras tais como:
    - Reserva de quarto
    - Informações de cliente
    - Informações de funcionários!
    -
    -
 */

typedef struct {
    int dia;
    int mes;
    int ano;
}DATA;

typedef struct {
    int codigo;
    char nome[40], sobrenome[50];
    char endereco[100];
    int telefone;
}CLIENTE;

typedef struct {
    int codigo;
    char nome[40], sobrenome[50];
    int telefone;
    char cargo[30];
    float salario;
}FUNCIONARIO;

typedef struct {
    int codigo;
    DATA entrada;
    DATA saida;
    int diarias;
    int codigoCliente;
    int codigoQuarto;

}ESTADIA;

typedef struct{
    int numeroQuarto;
    int quantidadeHospedes;
    int valorDiaria;
    char status[15];
}QUARTO;


void limparBuffer(){
    int c;
    while((c = getchar()) != '\n' && c != EOF);
}

int verificarCodigo(FILE *arquivo, int codigo){
    CLIENTE cliente;

    rewind(arquivo);

    while(fscanf(arquivo, "Código: %d", &cliente.codigo) == 1){
        if(cliente.codigo == codigo){
            return 1;
        }
    }
}


/** Função criada para cadastrar um novo cliente e salvar no respectivo arquivo!
    Recebe como parâmetro o arquivo de clientes!
*/
CLIENTE cadastrarCliente(FILE *arquivo){
    CLIENTE cliente;
    printf("\n__Cadastro de Cliente__\n\n");

    //do{
    printf("Código do cliente:");
    scanf("%d", &cliente.codigo);
    limparBuffer();
    fprintf(arquivo, "Código: %d\n", cliente.codigo);
   // }
    printf("Nome do Cliente: ");
    fgets(cliente.nome, sizeof(cliente.nome), stdin);
    cliente.nome[strcspn(cliente.nome, "\n")] = '\0';
    fprintf(arquivo, "Nome: %s\n", cliente.nome);

    printf("Sobrenome do cliente: ");
    fgets(cliente.sobrenome, sizeof(cliente.sobrenome), stdin);
    cliente.sobrenome[strcspn(cliente.sobrenome, "\n")] = '\0';
    fprintf(arquivo, "Sobrenome: %s\n",cliente.sobrenome);

    printf("Endereço do cliente: ");
    fgets(cliente.endereco, sizeof(cliente.endereco), stdin);
    cliente.endereco[strcspn(cliente.endereco, "\n")] = '\0';
    fprintf(arquivo, "Endereço: %s\n", cliente.endereco);

    printf("Telefone do cliente: ");
    scanf("%d", &cliente.telefone);
    limparBuffer();
    fprintf(arquivo, "Telefone: %d\n", cliente.telefone);

    fprintf(arquivo, "---------------------\n");

    printf("\nCliente cadastrado com sucesso!\n\n");
}


/** Função criada para cadastrar um novo funcionário e salvar no respectivo arquivo!
    Recebe como parâmetro o arquivo de funcionários!
*/
FUNCIONARIO cadastrarFuncionario(FILE *arquivo){
    FUNCIONARIO funcionario;
    printf("Cadastro do Funcionário \n");

    printf("Código do funcionário: ");
    scanf("%d", &funcionario.codigo);
    limparBuffer();
    fprintf(arquivo, "Código: %d\n", funcionario.codigo);

    printf("Nome do funcionário: ");
    fgets(funcionario.nome, sizeof(funcionario.nome), stdin);
    funcionario.nome[strcspn(funcionario.nome, "\n")] = '\0';
    fprintf(arquivo, "Nome: %s\n", funcionario.nome);

    printf("Sobrenome do funcionário: ");
    fgets(funcionario.sobrenome, sizeof(funcionario.sobrenome), stdin);
    funcionario.sobrenome[strcspn(funcionario.sobrenome, "\n")] = '\0';
    fprintf(arquivo, "Sobrenome: %s\n", funcionario.sobrenome);

    printf("Telefone do funcionário: ");
    scanf("%d", &funcionario.telefone);
    limparBuffer();
    fprintf(arquivo, "Telefone: %d\n", funcionario.telefone);

    printf("Cargo do funcionário: ");
    fgets(funcionario.cargo, sizeof(funcionario.cargo), stdin);
    funcionario.cargo[strcspn(funcionario.cargo, "\n")] = '\0';
    fprintf(arquivo, "Cargo: %s\n", funcionario.cargo);

    printf("Salário do funcionário: R$");
    scanf("%f", &funcionario.salario);
    limparBuffer();
    fprintf(arquivo, "Salário: R$%.2f\n", funcionario.salario);

    fprintf(arquivo, "---------------------\n");

    printf("\nFuncionário cadastrado com sucesso!\n\n");
}


/** Função criada para cadastrar um novo quarto e salvar no respectivo arquivo!
    Recebe como parâmetro o arquivo de quartos!
*/
QUARTO cadastrarQuarto(FILE *arquivo){
    QUARTO quarto;
    char status[] = "desocupado";

    printf("Cadastrar Quarto \n");

    printf("Número do Quarto: ");
    scanf("%d", &quarto.numeroQuarto);
    limparBuffer();
    fprintf(arquivo, "Número do quarto: %d \n", quarto.numeroQuarto);

    printf("Quantidade de hóspedes: ");
    scanf("%d", &quarto.quantidadeHospedes);
    limparBuffer();
    fprintf(arquivo, "Quantidade de Hóspedes: %d \n", quarto.quantidadeHospedes);

    printf("Valor da diária: ");
    scanf("%d", &quarto.valorDiaria);
    limparBuffer();
    fprintf(arquivo, "Valor da diária %d \n", quarto.valorDiaria);

    printf("Status: ");
    fgets(quarto.status, sizeof(quarto.status), stdin);
    quarto.status[strcspn(quarto.status, "\n")] = '\0';
    fprintf(arquivo, "Status: %s \n", status);

    fprintf(arquivo, "---------------------\n");

    printf("\nQuarto cadastrado com sucesso!\n\n");
}

void procurarFuncionario(FILE *arquivo)
{
    FUNCIONARIO funcionario;
    char nome[40];
    int codigo, encontrado=0, opcao;

    printf("\n Procurar Funcionário \n");
    printf("Pesquisar por (1)Código (2)Nome? ");
    scanf("%d",&opcao);
    limparBuffer();
    rewind(arquivo);
    if(opcao == 1)
    {
        printf("Dígite o código do funcionário: ");
        scanf("%d",&codigo);
        limparBuffer();
        while (fscanf(arquivo, "Código: %d\nNome: %39[^\n]\nSobrenome: %49[^\n]\nTelefone: %d\nCargo: %29[^\n]\nSalário: R$%f\n---------------------\n",&funcionario.codigo, funcionario.nome, funcionario.sobrenome, &funcionario.telefone, funcionario.cargo, &funcionario.salario) != EOF){
            if (funcionario.codigo == codigo)
            {
                encontrado = 1;
                break;
            }
    }
    }
    else if(opcao == 2)
        {
        printf("Digite o nome do funcionário: ");
        fgets(nome, sizeof(nome), stdin);
        nome[strcspn(nome, "\n")] = '\0';

        while (fscanf(arquivo, "Código: %d\nNome: %39[^\n]\nSobrenome: %49[^\n]\nTelefone: %d\nCargo: %29[^\n]\nSalário: R$%f\n---------------------\n",
                      &funcionario.codigo, funcionario.nome, funcionario.sobrenome, &funcionario.telefone, funcionario.cargo, &funcionario.salario) != EOF) {
            if (strcmp(funcionario.nome, nome) == 0) {
                encontrado = 1;
                break;
            }
        }
    }
    else
    {
        printf("Opção inválida!\n");
        return;
    }

    if (encontrado)
    {
        printf("\nFuncionário Encontrado:\n");
        printf("Código: %d\n", funcionario.codigo);
        printf("Nome: %s\n", funcionario.nome);
        printf("Sobrenome: %s\n", funcionario.sobrenome);
        printf("Telefone: %d\n", funcionario.telefone);
        printf("Cargo: %s\n", funcionario.cargo);
        printf("Salário: R$%.2f\n", funcionario.salario);
    }
    else
    {
        printf("Funcionário não encontrado.\n");
    }

}


ESTADIA reservarEstadia(){
}


/**Função que escreve as informações básicas do hotel.
   Como parâmetro, temos o ponteiro do valor da diária.
*/
void hotelInfo(){
    printf("Informações do Hotel\n\n");
    printf("Localização: Centro de Itacaré - Bahia\n");
    printf("Início da diária: 14:00\n");
    printf("Fim da diária: 12:00\n");
    printf("Sejam bem-vindos ao Hotel Descanso Garantido!\nTenham uma ótima estadia!\n\n");
}


/** Função que permite ao usuário selecionar uma das opções existentes, para assim,
realizar algo no sistema, como cadastro ou reserva*/
int opt(int *resp){
 printf("O que deseja fazer?\n");
    printf("(1) Informações do Hotel\n(2)Cadastrar Cliente\n(3) Cadastrar Quarto\n(4) Cadastrar Funcionário\n(5) Reservar Estadia\n(6) Pesquisar cliente\n(7) Pesquisar Funcionário\n(8) Finalizar\n");
    scanf("%d", resp);

    return *resp;
}


int main()
{
    int resp = 0;
    float valorDiaria = 100.0;
    FILE *arquivoCliente, *arquivoFuncionario, *arquivoQuarto;


    printf("\n\n___|Hotel Descanso Garantido|___\n\n", setlocale(LC_ALL, ""));
    printf("Seja bem-vindo ao nosso sistema de Auto-Atendimento!\n");

    while(resp != 8){
    int response = opt(&resp);
    switch(response){
    case 1:
        hotelInfo(&valorDiaria);
        break;
    case 2:
        arquivoCliente = fopen("clientes.txt", "a+");
        if(arquivoCliente == NULL){
            printf("Erro ao abrir o arquivo. \n");
            break;
        }
        cadastrarCliente(arquivoCliente);
        fclose(arquivoCliente);
        break;
    case 3:
        arquivoQuarto = fopen("quartos.txt", "a+");
        if(arquivoQuarto == NULL){
            printf("Erro ao abrir o arquivo! \n");
            break;
        }
        cadastrarQuarto(arquivoQuarto);
        fclose(arquivoQuarto);
        break;
    case 4:
        arquivoFuncionario = fopen("funcionarios.txt", "a+");
        if(arquivoFuncionario == NULL){
            printf("Erro ao abrir o arquivo.\n");
            break;
        }
        cadastrarFuncionario(arquivoFuncionario);
        fclose(arquivoFuncionario);
        break;
    case 5:
        //reservarEstadia();
        break;
    case 6:
        //procuraCliente();
        break;
    case 7:
         arquivoFuncionario = fopen("funcionarios.txt", "r");
                if(arquivoFuncionario == NULL){
                    printf("Erro ao abrir o arquivo.\n");
                    break;
                }
                procurarFuncionario(arquivoFuncionario);
                fclose(arquivoFuncionario);
        break;
    case 8:
        printf("Finalizando acesso...");
        break;
    default:
        printf("Insira um valor válido!");
        break;
    }
    }

}
