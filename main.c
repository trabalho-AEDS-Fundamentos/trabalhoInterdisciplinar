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
    int salario;
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
    int codigoQuarto;
    int quantidadeHospedes;
    int valorDiaria;
    int status;
}QUARTO;

void limparBuffer(){
    int c;
    while((c = getchar()) != '\n' && c != EOF);
}


CLIENTE cadastrarCliente(FILE *arquivo){
    CLIENTE cliente;
    printf("\n__Cadastro de Cliente__\n\n");

    printf("Código do cliente:");
    scanf("%d", &cliente.codigo);
    limparBuffer();

    printf("Nome do Cliente: ");
    fgets(cliente.nome, sizeof(cliente.nome), stdin);
    cliente.nome[strcspn(cliente.nome, "\n")] = '\0';

    printf("Sobrenome do cliente: ");
    fgets(cliente.sobrenome, sizeof(cliente.sobrenome), stdin);
    cliente.sobrenome[strcspn(cliente.sobrenome, "\n")] = '\0';

    printf("Endereço do cliente: ");
    fgets(cliente.endereco, sizeof(cliente.endereco), stdin);
    cliente.endereco[strcspn(cliente.endereco, "\n")] = '\0';

    printf("Telefone do cliente: ");
    scanf("%d", &cliente.telefone);
    limparBuffer();

    // Escrever os dados do cliente no arquivo
    fprintf(arquivo, "Código: %d\n", cliente.codigo);
    fprintf(arquivo, "Nome: %s\n", cliente.nome);
    fprintf(arquivo, "Sobrenome: %s\n",cliente.sobrenome);
    fprintf(arquivo, "Endereço: %s\n", cliente.endereco);
    fprintf(arquivo, "Telefone: %d\n", cliente.telefone);
    fprintf(arquivo, "---------------------\n");
}

FUNCIONARIO cadastrarFuncionario(FILE *arquivo){

    printf("Cadastro do Funcionário \n");

    printf("Código do funcionário");
    scanf("%d",& FUNCIONARIO.codigo);
    limparBuffer();

    printf("Nome do funcionário: ");
    fgets(funcionario.nome, sizeof(funcionario.nome), stdin);
    funcionario.nome[strcspn(funcionario.nome, "\n")] = '\0';
    limparBuffer();

    printf("Sobrenome do funcionário: ");
    fgets(funcionario.nome, sizeof(funcionario.sobrenome), stdin);
    funcionario.sobrenome[strcspn(funcionario.sobrenome, "\n")] = '\0';
    limparBuffer();

    printf("Telefone do funcionário: ");
    scanf("%d",&FUNCIONARIO.telefone);
    limparBuffer();

    printf("Cargo do funcionário: ");
    fgets(funcionario.nome, sizeof(funcionario.cargo), stdin);
    funcionario.cargo[strcspn(funcionario.cargo, "\n")] = '\0';
    limparBuffer();

    //Escrevendo os dados do funcionário no arquivo.
    fprintf(arquivo, "Código: %d\n", funcionario.codigo);
    fprintf(arquivo, "Nome: %s\n", funcionario.nome);
    fprintf(arquivo, "Sobrenome: %s\n", funcionario.sobrenome);
    fprintf(arquivo, "Telefone: %d\n", funcionario.telefone);
    fprintf(arquivo, "Cargo: %s\n", funcionario.cargo);
    fprintf(arquivo, "Salário: %d\n", funcionario.salario);


}

ESTADIA reservarEstadia(){

    int numeroquarto;
    printf("Reserva de Estadia \n");

    printf("Código da Estadia: ");
    scanf("%d",&ESTADIA.codigo);
    limparBuffer();

    printf("Código do Cliente: ");
    scanf("%d",&ESTADIA.codigoCliente);
    limparBuffer();

    printf("Data de entrada (Dia/Mês/Ano)");
    scanf("%d %d %d", & ESTADIA.entrada.dia, &ESTADIA.entrada.mes, &ESTADIA.entrada.ano);
    limparBuffer();

    printf("Data de saída (Dia/Mês/Ano)");
    scanf("%d %d %d",& ESTADIA.saida.dia, & ESTADIA.saida.mes, &ESTADIA.saida.ano);
    limparBuffer();

    printf("Quantidade de Diárias: ");
    scanf("%d",&ESTADIA.diarias);
    limparBuffer();

    printf("Número do quarto: ");
    scanf("%d",&numeroquarto);

    //falta procurar o quarto no arquivo

}

QUARTO cadastrarQuarto(FILE *arquivo){

    printf("Cadastrar Quarto \n");
    printf("Código do Quarto: ");
    scanf("%d",&QUARTO.codigoQuarto);
    limparBuffer();

    printf("Quantidade de hóspedes: ");
    scanf("%d", &QUARTO.quantidadeHospedes);
    limparBuffer();

    printf("Valor da diária: ");
    scanf("%d",&QUARTO.valorDiaria);
    limparBuffer();

    //Escrevendo os dados do quarto no arquivo.
    fprintf(arquivo, "Código: %d \n", QUARTO.codigoQuarto);
    fprintf(arquivo, "Quantidade de Hóspedes: %d \n", QUARTO.quantidadeHospedes);
    fprintf(arquivo, "Valor da diária %d \n", QUARTO.valorDiaria);

}


/**Função que escreve as informações básicas do hotel.
   Como parâmetro, temos o ponteiro do valor da diária.
*/
void hotelInfo(float *valor){
    printf("Informações do Hotel\n\n");
    printf("Localização: Centro de Itacaré - Bahia\n");
    printf("Valor da diária: R$%.2f\n", *valor);
    printf("Início da diária: 14:00\n");
    printf("Fim da diária: 12:00\n");
    printf("Sejam bem-vindos ao Hotel Descanso Garantido!\nTenham uma ótima estadia!\n\n");
}

int opt(int *resp){
    printf("O que deseja fazer?\n");
    printf("(1) Informações do Hotel\n(2)Cadastrar Cliente\n(3) Cadastrar Quarto\n(4) Cadastrar Funcionário\n(5) Reservar Estadia\n(6) Finalizar\n");
    scanf("%d", resp);

    return *resp;
}



int main()
{
    int resp = 0;
    float valorDiaria = 100.0;
    FILE *arquivoCliente, *arquivoFuncionario;


    printf("\n\n___|Hotel Descanso Gárantido|___\n\n", setlocale(LC_ALL, ""));
    printf("Seja bem-vindo ao nosso sistema de Auto-Atendimento!\n");

    while(resp != 6){
    int response = opt(&resp);
    int numClientes = 0;
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
        numClientes++;
        break;
    case 3:
        cadastrarQuarto();
        break;
    case 4:
        cadastrarFuncionario();
        break;
    case 5:
        reservarEstadia();
        break;
    case 6:
        printf("Finalizando acesso...");
        break;
    default:
        printf("Insira um valor válido!");
        break;
    }
    }

}
