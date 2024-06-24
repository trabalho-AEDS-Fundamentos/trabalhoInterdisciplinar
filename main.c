#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>

#define number 50
#define max_funcionarios 100

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

int verificarNumeroQuarto(FILE *arquivo, int numero) {
    QUARTO quarto;
    rewind(arquivo); // Rewind the file to the beginning

    while (fscanf(arquivo, "N�mero do quarto: %d\n", &quarto.numeroQuarto) == 1) {
        fscanf(arquivo, "Quantidade de H�spedes: %d\n", &quarto.quantidadeHospedes);
        fscanf(arquivo, "Valor da di�ria: %d\n", &quarto.valorDiaria);
        fscanf(arquivo, "Status: %[^\n]\n", quarto.status);
        fscanf(arquivo, "---------------------\n");

        if (quarto.numeroQuarto == numero) {
            return 1; // N�mero do quarto j� existe
        }
    }

    return 0; // N�mero do quarto n�o encontrado
}

int verificarCodigoCliente(FILE *arquivo, int codigo){
    CLIENTE cliente;

    rewind(arquivo);

    while(fscanf(arquivo, "C�digo: %d\n", &cliente.codigo) == 1){
        fscanf(arquivo, "Nome: %[^\n]\n", cliente.nome);
        fscanf(arquivo, "Sobrenome: %[^\n]\n", cliente.sobrenome);
        fscanf(arquivo, "Endere�o: %[^\n]\n", cliente.endereco);
        fscanf(arquivo, "Telefone: %d\n", &cliente.telefone);
        fscanf(arquivo, "---------------------\n");

        if(cliente.codigo == codigo){
            return 1;
        }
    }

    return 0;
}

int verificarCodigoFuncionario(FILE *arquivo, int codigo){
    FUNCIONARIO funcionario;

    rewind(arquivo);

    while(fscanf(arquivo, "C�digo: %d\n", &funcionario.codigo) == 1){
        fscanf(arquivo, "Nome: %[^\n]\n", funcionario.nome);
        fscanf(arquivo, "Sobrenome: %[^\n]\n", funcionario.sobrenome);
        fscanf(arquivo, "Telefone: %d\n", &funcionario.telefone);
        fscanf(arquivo, "Cargo: %[^\n]\n", funcionario.cargo);
        fscanf(arquivo, "Sal�rio: R$%f\n", &funcionario.salario);
        fscanf(arquivo, "---------------------\n");

        if(funcionario.codigo == codigo){
            return 1;
        }
    }

    return 0;
}



/** Fun��o criada para cadastrar um novo cliente e salvar no respectivo arquivo!
    Recebe como par�metro o arquivo de clientes!
*/
void cadastrarCliente(FILE *arquivo){
    CLIENTE cliente;
    printf("\n_Cadastro de Cliente_\n\n");

    do{
        printf("C�digo do cliente:");
        scanf("%d", &cliente.codigo);
        limparBuffer();

        if(verificarCodigoCliente(arquivo, cliente.codigo)){
            printf("C�digo j� existe! Insira um novo c�digo!\n");
        }
    }while(verificarCodigoCliente(arquivo, cliente.codigo));

    fprintf(arquivo, "C�digo: %d\n", cliente.codigo);

    printf("Nome do Cliente: ");
    fgets(cliente.nome, sizeof(cliente.nome), stdin);
    cliente.nome[strcspn(cliente.nome, "\n")] = '\0';
    fprintf(arquivo, "Nome: %s\n", cliente.nome);

    printf("Sobrenome do cliente: ");
    fgets(cliente.sobrenome, sizeof(cliente.sobrenome), stdin);
    cliente.sobrenome[strcspn(cliente.sobrenome, "\n")] = '\0';
    fprintf(arquivo, "Sobrenome: %s\n",cliente.sobrenome);

    printf("Endere�o do cliente: ");
    fgets(cliente.endereco, sizeof(cliente.endereco), stdin);
    cliente.endereco[strcspn(cliente.endereco, "\n")] = '\0';
    fprintf(arquivo, "Endere�o: %s\n", cliente.endereco);

    printf("Telefone do cliente: ");
    scanf("%d", &cliente.telefone);
    limparBuffer();
    fprintf(arquivo, "Telefone: %d\n", cliente.telefone);

    fprintf(arquivo, "---------------------\n");

    printf("\nCliente cadastrado com sucesso!\n\n");
}


/** Fun��o criada para cadastrar um novo funcion�rio e salvar no respectivo arquivo!
    Recebe como par�metro o arquivo de funcion�rios!
*/
void cadastrarFuncionario(FILE *arquivo){
    FUNCIONARIO funcionario;
    printf("Cadastro do Funcion�rio \n");

    do{
        printf("C�digo do funcion�rio: ");
        scanf("%d", &funcionario.codigo);
        limparBuffer();

        if(verificarCodigoFuncionario(arquivo, funcionario.codigo)){
            printf("C�digo j� existe! Insira um novo c�digo!\n");
        }
    }while(verificarCodigoFuncionario(arquivo, funcionario.codigo));

    fprintf(arquivo, "C�digo: %d\n", funcionario.codigo);

    printf("Nome do funcion�rio: ");
    fgets(funcionario.nome, sizeof(funcionario.nome), stdin);
    funcionario.nome[strcspn(funcionario.nome, "\n")] = '\0';
    fprintf(arquivo, "Nome: %s\n", funcionario.nome);

    printf("Sobrenome do funcion�rio: ");
    fgets(funcionario.sobrenome, sizeof(funcionario.sobrenome), stdin);
    funcionario.sobrenome[strcspn(funcionario.sobrenome, "\n")] = '\0';
    fprintf(arquivo, "Sobrenome: %s\n", funcionario.sobrenome);

    printf("Telefone do funcion�rio: ");
    scanf("%d", &funcionario.telefone);
    limparBuffer();
    fprintf(arquivo, "Telefone: %d\n", funcionario.telefone);

    printf("Cargo do funcion�rio: ");
    fgets(funcionario.cargo, sizeof(funcionario.cargo), stdin);
    funcionario.cargo[strcspn(funcionario.cargo, "\n")] = '\0';
    fprintf(arquivo, "Cargo: %s\n", funcionario.cargo);

    printf("Sal�rio do funcion�rio: R$");
    scanf("%f", &funcionario.salario);
    limparBuffer();
    fprintf(arquivo, "Sal�rio: R$%.2f\n", funcionario.salario);

    fprintf(arquivo, "---------------------\n");

    printf("\nFuncion�rio cadastrado com sucesso!\n\n");
}


/** Fun��o criada para cadastrar um novo quarto e salvar no respectivo arquivo!
    Recebe como par�metro o arquivo de quartos!
*/
void cadastrarQuarto(FILE *arquivo){
    QUARTO quarto;
    char status[] = "desocupado";

    printf("Cadastrar Quarto \n");

    do{
        printf("N�mero do Quarto: ");
        scanf("%d", &quarto.numeroQuarto);
        limparBuffer();

        if(verificarNumeroQuarto(arquivo, quarto.numeroQuarto)){
            printf("Quarto j� existe! Insira um novo quarto!\n");
        }
    } while(verificarNumeroQuarto(arquivo, quarto.numeroQuarto));

    fprintf(arquivo, "N�mero do quarto: %d \n", quarto.numeroQuarto);

    printf("Quantidade de h�spedes: ");
    scanf("%d", &quarto.quantidadeHospedes);
    limparBuffer();
    fprintf(arquivo, "Quantidade de H�spedes: %d \n", quarto.quantidadeHospedes);

    printf("Valor da di�ria: ");
    scanf("%d", &quarto.valorDiaria);
    limparBuffer();
    fprintf(arquivo, "Valor da di�ria: %d \n", quarto.valorDiaria);

    printf("Status: ");
    fgets(quarto.status, sizeof(quarto.status), stdin);
    quarto.status[strcspn(quarto.status, "\n")] = '\0';
    fprintf(arquivo, "Status: %s \n", status);

    fprintf(arquivo, "---------------------\n");

    printf("\nQuarto cadastrado com sucesso!\n\n");
}



void procurarFuncionario(FILE *arquivo) {
    FUNCIONARIO funcionario[max_funcionarios];
    char nome[40];
    int codigo, encontrado = 0, opcao, num_funcionario = 0;

    printf("\n Procurar Funcion�rio \n");
    printf("Pesquisar por (1) C�digo (2) Nome ? ");
    scanf("%d", &opcao);
    limparBuffer();
    rewind(arquivo);

    // Lendo os dados do arquivo
    while (fscanf(arquivo, "C�digo: %d\n", &funcionario[num_funcionario].codigo) != EOF) {
        fscanf(arquivo, "Nome: %[^\n]\n", funcionario[num_funcionario].nome);
        fscanf(arquivo, "Sobrenome: %[^\n]\n", funcionario[num_funcionario].sobrenome);
        fscanf(arquivo, "Telefone: %d\n", &funcionario[num_funcionario].telefone);
        fscanf(arquivo, "Cargo: %[^\n]\n", funcionario[num_funcionario].cargo);
        fscanf(arquivo, "Sal�rio: R$%f\n", &funcionario[num_funcionario].salario);
        fscanf(arquivo, "---------------------\n");

        num_funcionario++;
    }

    if (opcao == 1) {
        printf("Digite o c�digo do funcion�rio: ");
        scanf("%d", &codigo);
        limparBuffer();

        for (int i = 0; i < num_funcionario; i++) {
            if (funcionario[i].codigo == codigo) {
                encontrado = 1;
                printf("\nFuncion�rio Encontrado:\n");
                printf("C�digo: %d\n", funcionario[i].codigo);
                printf("Nome: %s\n", funcionario[i].nome);
                printf("Sobrenome: %s\n", funcionario[i].sobrenome);
                printf("Telefone: %d\n", funcionario[i].telefone);
                printf("Cargo: %s\n", funcionario[i].cargo);
                printf("Sal�rio: R$%.2f\n", funcionario[i].salario);
                printf("\n");
                break;
            }
        }
    } else if (opcao == 2) {
        printf("Digite o nome do funcion�rio: ");
        fgets(nome, sizeof(nome), stdin);
        nome[strcspn(nome, "\n")] = '\0';

        for (int i = 0; i < num_funcionario; i++) {
            if (strcasecmp(funcionario[i].nome, nome) == 0) {
                encontrado = 1;
                printf("\nFuncion�rio Encontrado:\n");
                printf("C�digo: %d\n", funcionario[i].codigo);
                printf("Nome: %s\n", funcionario[i].nome);
                printf("Sobrenome: %s\n", funcionario[i].sobrenome);
                printf("Telefone: %d\n", funcionario[i].telefone);
                printf("Cargo: %s\n", funcionario[i].cargo);
                printf("Sal�rio: R$%.2f\n", funcionario[i].salario);
                printf("\n");
            }
        }
    }

    if (!encontrado) {
        printf("Funcion�rio n�o encontrado!\n");
    }
}

void procurarCliente(FILE *arquivo){
    CLIENTE cliente[max_funcionarios];
    char nome[40];
    int codigo, encontrado = 0, opcao, num_cliente = 0;

    printf("\n Procurar Cliente \n");
    printf("Pesquisar por (1) C�digo (2) Nome ? ");
    scanf("%d", &opcao);
    limparBuffer();
    rewind(arquivo);

    // Lendo os dados do arquivo
    while (fscanf(arquivo, "C�digo: %d\n", &cliente[num_cliente].codigo) != EOF) {
        fscanf(arquivo, "Nome: %[^\n]\n", cliente[num_cliente].nome);
        fscanf(arquivo, "Sobrenome: %[^\n]\n", cliente[num_cliente].sobrenome);
        fscanf(arquivo, "Endere�o: %[^\n]\n", cliente[num_cliente].endereco);
        fscanf(arquivo, "Telefone: %d\n", &cliente[num_cliente].telefone);
        fscanf(arquivo, "---------------------\n");

        num_cliente++;
    }

    if (opcao == 1) {
        printf("Digite o c�digo do cliente: ");
        scanf("%d", &codigo);
        limparBuffer();

        for (int i = 0; i < num_cliente; i++) {
            if (cliente[i].codigo == codigo) {
                encontrado = 1;
                printf("\Cliente Encontrado:\n");
                printf("C�digo: %d\n", cliente[i].codigo);
                printf("Nome: %s\n", cliente[i].nome);
                printf("Sobrenome: %s\n", cliente[i].sobrenome);
                printf("Endere�o: %s\n", cliente[i].endereco);
                printf("Telefone: %d\n", cliente[i].telefone);
                printf("\n");
                break;
            }
        }
    } else if (opcao == 2) {
        printf("Digite o nome do cliente: ");
        fgets(nome, sizeof(nome), stdin);
        nome[strcspn(nome, "\n")] = '\0';

        for (int i = 0; i < num_cliente; i++) {
            if (strcasecmp(cliente[i].nome, nome) == 0) {
                encontrado = 1;
                printf("\nCliente Encontrado:\n");
                printf("C�digo: %d\n", cliente[i].codigo);
                printf("Nome: %s\n", cliente[i].nome);
                printf("Sobrenome: %s\n", cliente[i].sobrenome);
                printf("Endere�o: %s\n", cliente[i].endereco);
                printf("Telefone: %d\n", cliente[i].telefone);
                printf("\n");
            }
        }
    }

    if (!encontrado) {
        printf("Funcion�rio n�o encontrado!\n");
    }
}



    ESTADIA reservarEstadia(FILE *arquivoQuarto, FILE *arquivoCliente){
        ESTADIA estadia;
        QUARTO quarto;
        CLIENTE cliente;
        int qntHospedes;

        arquivoCliente = fopen("clientes.txt", "r");
        if(arquivoCliente == NULL){
            printf("Erro ao abrir o arquivo!");
        }

        do{
            printf("Digite o c�digo do cliente: ");
            scanf("%d", &cliente.codigo);
            limparBuffer();

            if(verificarCodigoCliente(arquivoCliente, cliente.codigo) == 0){
                printf("Esse cliente n�o est� cadastrado! Insira um c�digo v�lido!\n");
            }

        }while(verificarCodigoCliente(arquivoCliente, cliente.codigo)== 0);

        fclose(arquivoCliente);

        printf("Digite quantos hosp�des ir�o se hospedar: ");
        scanf("%d", &qntHospedes);

        arquivoQuarto = fopen("quartos.txt", "a+");
        if(arquivoQuarto == NULL){
            printf("Erro ao abrir o arquivo!");
        }

        while (fscanf(arquivo, "N�mero do quarto: %d\n", &quarto.numeroQuarto) == 1) {
        fscanf(arquivo, "Quantidade de H�spedes: %d\n", &quarto.quantidadeHospedes);
        fscanf(arquivo, "Valor da di�ria: %d\n", &quarto.valorDiaria);
        fscanf(arquivo, "Status: %[^\n]\n", quarto.status);
        fscanf(arquivo, "---------------------\n");

        if (quarto.numeroQuarto == numero) {
            return 1; // N�mero do quarto j� existe
        }
    }

    return 0;

        printf("Indique o dia de entrada: ");
        scanf("%d", &estadia.entrada.dia);
        printf("Indique o m�s de entrada: ");
        scanf("%d", &estadia.entrada.mes);
        printf("Indique o ano de entrada: ");
        scanf("%d", &estadia.entrada.ano);

        printf("Indique o dia de sa�da: ");
        scanf("%d", &estadia.saida.dia);
        printf("Indique o m�s de sa�da: ");
        scanf("%d", &estadia.saida.mes);
        printf("Indique o ano de sa�da: ");
        scanf("%d", &estadia.saida.ano);





    }

void baixaEstadia(){}

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


/** Fun��o que permite ao usu�rio selecionar uma das op��es existentes, para assim,
realizar algo no sistema, como cadastro ou reserva*/
int opt(int *resp){
 printf("O que deseja fazer?\n");
    printf("(1) Informa��es do Hotel\n(2) Cadastrar Cliente\n(3) Cadastrar Quarto\n(4) Cadastrar Funcion�rio\n(5) Reservar Estadia\n(6) Pesquisar cliente\n(7) Pesquisar Funcion�rio\n(8) Finalizar\n");
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
        reservarEstadia(arquivoQuarto, arquivoCliente);
        break;
    case 6:
        arquivoCliente = fopen("clientes.txt", "r");
        if(arquivoCliente == NULL){
            printf("Erro ao abrir o arquivo.\n");
        }
        procurarCliente(arquivoCliente);
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
        printf("Insira um valor v�lido!");
        break;
    }
    }

}
