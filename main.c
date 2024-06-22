#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>

#define number 50

/** Esse programa visa solucionar o problema de garantir um bom atendimentos aos clientes do Hotel Descanso Garantido,
    a partir das principais atividades hoteleiras tais como:
    - Reserva de quarto
    - Informa��es de cliente
    - Informa��es de funcion�rios!
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

    while(fscanf(arquivo, "C�digo: %d", &cliente.codigo) == 1){
        if(cliente.codigo == codigo){
            return 1;
        }
    }
}

CLIENTE cadastrarCliente(FILE *arquivo){
    CLIENTE cliente;
    printf("\n__Cadastro de Cliente__\n\n");

    do{printf("C�digo do cliente:");
    scanf("%d", &cliente.codigo);
    limparBuffer();
    }
    printf("Nome do Cliente: ");
    fgets(cliente.nome, sizeof(cliente.nome), stdin);
    cliente.nome[strcspn(cliente.nome, "\n")] = '\0';

    printf("Sobrenome do cliente: ");
    fgets(cliente.sobrenome, sizeof(cliente.sobrenome), stdin);
    cliente.sobrenome[strcspn(cliente.sobrenome, "\n")] = '\0';

    printf("Endere�o do cliente: ");
    fgets(cliente.endereco, sizeof(cliente.endereco), stdin);
    cliente.endereco[strcspn(cliente.endereco, "\n")] = '\0';

    printf("Telefone do cliente: ");
    scanf("%d", &cliente.telefone);
    limparBuffer();

    // Escrever os dados do cliente no arquivo
    fprintf(arquivo, "C�digo: %d\n", cliente.codigo);
    fprintf(arquivo, "Nome: %s\n", cliente.nome);
    fprintf(arquivo, "Sobrenome: %s\n",cliente.sobrenome);
    fprintf(arquivo, "Endere�o: %s\n", cliente.endereco);
    fprintf(arquivo, "Telefone: %d\n", cliente.telefone);
    fprintf(arquivo, "---------------------\n");

    printf("\nCliente cadastrado com sucesso!\n\n");
}

FUNCIONARIO cadastrarFuncionario(FILE *arquivo){
    FUNCIONARIO funcionario;
    printf("Cadastro do Funcion�rio \n");

    printf("C�digo do funcion�rio: ");
    scanf("%d", &funcionario.codigo);
    limparBuffer();

    printf("Nome do funcion�rio: ");
    fgets(funcionario.nome, sizeof(funcionario.nome), stdin);
    funcionario.nome[strcspn(funcionario.nome, "\n")] = '\0';

    printf("Sobrenome do funcion�rio: ");
    fgets(funcionario.sobrenome, sizeof(funcionario.sobrenome), stdin);
    funcionario.sobrenome[strcspn(funcionario.sobrenome, "\n")] = '\0';

    printf("Telefone do funcion�rio: ");
    scanf("%d", &funcionario.telefone);
    limparBuffer();

    printf("Cargo do funcion�rio: ");
    fgets(funcionario.cargo, sizeof(funcionario.cargo), stdin);
    funcionario.cargo[strcspn(funcionario.cargo, "\n")] = '\0';

    printf("Sal�rio do funcion�rio: R$");
    scanf("%f", &funcionario.salario);
    limparBuffer();

    //Escrevendo os dados do funcion�rio no arquivo.
    fprintf(arquivo, "C�digo: %d\n", funcionario.codigo);
    fprintf(arquivo, "Nome: %s\n", funcionario.nome);
    fprintf(arquivo, "Sobrenome: %s\n", funcionario.sobrenome);
    fprintf(arquivo, "Telefone: %d\n", funcionario.telefone);
    fprintf(arquivo, "Cargo: %s\n", funcionario.cargo);
    fprintf(arquivo, "Sal�rio: R$%.2f\n", funcionario.salario);
    fprintf(arquivo, "---------------------\n");

    printf("\nFuncion�rio cadastrado com sucesso!\n\n");
}

QUARTO cadastrarQuarto(FILE *arquivo){
    QUARTO quarto;
    char status[] = "desocupado";

    printf("Cadastrar Quarto \n");

    printf("N�mero do Quarto: ");
    scanf("%d", &quarto.numeroQuarto);
    limparBuffer();

    printf("Quantidade de h�spedes: ");
    scanf("%d", &quarto.quantidadeHospedes);
    limparBuffer();

    printf("Valor da di�ria: ");
    scanf("%d", &quarto.valorDiaria);
    limparBuffer();

    printf("Status: ");
    fgets(quarto.status, sizeof(quarto.status), stdin);
    quarto.status[strcspn(quarto.status, "\n")] = '\0';

    //Escrevendo os dados do quarto no arquivo.
    fprintf(arquivo, "N�mero do quarto: %d \n", quarto.numeroQuarto);
    fprintf(arquivo, "Quantidade de H�spedes: %d \n", quarto.quantidadeHospedes);
    fprintf(arquivo, "Valor da di�ria %d \n", quarto.valorDiaria);
    fprintf(arquivo, "Status: %s \n", status);
    fprintf(arquivo, "---------------------\n");

    printf("\nQuarto cadastrado com sucesso!\n\n");
}

ESTADIA reservarEstadia(){
}

/**Fun��o que escreve as informa��es b�sicas do hotel.
   Como par�metro, temos o ponteiro do valor da di�ria.
*/
void hotelInfo(){
    printf("Informa��es do Hotel\n\n");
    printf("Localiza��o: Centro de Itacar� - Bahia\n");
    printf("In�cio da di�ria: 14:00\n");
    printf("Fim da di�ria: 12:00\n");
    printf("Sejam bem-vindos ao Hotel Descanso Garantido!\nTenham uma �tima estadia!\n\n");
}

int opt(int *resp){
 printf("O que deseja fazer?\n");
    printf("(1) Informa��es do Hotel\n(2)Cadastrar Cliente\n(3) Cadastrar Quarto\n(4) Cadastrar Funcion�rio\n(5) Reservar Estadia\n(6) Pesquisar cliente\n(7) Pesquisar Funcion�rio\n(8) Finalizar\n");
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
        //procuraFuncionario();
        break;
    case 8:
        printf("Finalizando acesso...");
        break;
    default:
        printf("Insira um valor v�lido!");
        break;
    }
    }

}
