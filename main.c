#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>

#define number 50
#define max_funcionarios 100

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
    int numeroQuarto;

}ESTADIA;

typedef struct{
    int numeroQuarto;
    int quantidadeHospedes;
    float valorDiaria;
    char status[15];
}QUARTO;


void limparBuffer(){
    int c;
    while((c = getchar()) != '\n' && c != EOF);
}

int verificarNumeroQuarto(FILE *arquivo, int numero) {
    QUARTO quarto;
    rewind(arquivo); // Rewind the file to the beginning

    while (fscanf(arquivo, "Número do quarto: %d\n", &quarto.numeroQuarto) == 1) {
        fscanf(arquivo, "Quantidade de Hóspedes: %d\n", &quarto.quantidadeHospedes);
        fscanf(arquivo, "Valor da diária: %f\n", &quarto.valorDiaria);
        fscanf(arquivo, "Status: %[^\n]\n", quarto.status);
        fscanf(arquivo, "---------------------\n");

        if (quarto.numeroQuarto == numero) {
            return 1; // Número do quarto já existe
        }
    }

    return 0; // Número do quarto não encontrado
}

int verificarCodigoCliente(FILE *arquivo, int codigo){
    CLIENTE cliente;

    rewind(arquivo);

    while(fscanf(arquivo, "Código: %d\n", &cliente.codigo) == 1){
        fscanf(arquivo, "Nome: %[^\n]\n", cliente.nome);
        fscanf(arquivo, "Sobrenome: %[^\n]\n", cliente.sobrenome);
        fscanf(arquivo, "Endereço: %[^\n]\n", cliente.endereco);
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

    while(fscanf(arquivo, "Código: %d\n", &funcionario.codigo) == 1){
        fscanf(arquivo, "Nome: %[^\n]\n", funcionario.nome);
        fscanf(arquivo, "Sobrenome: %[^\n]\n", funcionario.sobrenome);
        fscanf(arquivo, "Telefone: %d\n", &funcionario.telefone);
        fscanf(arquivo, "Cargo: %[^\n]\n", funcionario.cargo);
        fscanf(arquivo, "Salário: R$%f\n", &funcionario.salario);
        fscanf(arquivo, "---------------------\n");

        if(funcionario.codigo == codigo){
            return 1;
        }
    }

    return 0;
}

int verificarCodigoEstadia(FILE *arquivo, int codigo){
    ESTADIA estadia;

    rewind(arquivo);

    while(fscanf(arquivo, "Código: %d\n", &estadia.codigo) == 1){
        fscanf(arquivo, "Data de Entrada: %02d/%02d/%02d\n", estadia.entrada.dia,estadia.entrada.mes, estadia.entrada.ano);
        fscanf(arquivo, "Data de Saída: %02d/%02d/%02d\n", estadia.saida.dia,estadia.saida.mes, estadia.saida.ano);
        fscanf(arquivo, "Diárias: %d\n", &estadia.diarias);
        fscanf(arquivo, "Código do Cliente: %d\n", &estadia.codigoCliente);
        fscanf(arquivo, "Número do Quarto: %d\n", &estadia.numeroQuarto);
        fscanf(arquivo, "---------------------\n");

        if(estadia.codigo == codigo){
            return 1;
        }
    }
    return 0;
}


/** Função criada para cadastrar um novo cliente e salvar no respectivo arquivo!
    Recebe como parâmetro o arquivo de clientes!
*/
void cadastrarCliente(FILE *arquivo){
    CLIENTE cliente;
    printf("\n_Cadastro de Cliente_\n\n");

    do{
        printf("Código do cliente:");
        scanf("%d", &cliente.codigo);
        limparBuffer();

        if(verificarCodigoCliente(arquivo, cliente.codigo)){
            printf("Código já existe! Insira um novo código!\n");
        }
    }while(verificarCodigoCliente(arquivo, cliente.codigo));

    fprintf(arquivo, "Código: %d\n", cliente.codigo);

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
void cadastrarFuncionario(FILE *arquivo){
    FUNCIONARIO funcionario;
    printf("Cadastro do Funcionário \n");

    do{
        printf("Código do funcionário: ");
        scanf("%d", &funcionario.codigo);
        limparBuffer();

        if(verificarCodigoFuncionario(arquivo, funcionario.codigo)){
            printf("Código já existe! Insira um novo código!\n");
        }
    }while(verificarCodigoFuncionario(arquivo, funcionario.codigo));

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
void cadastrarQuarto(FILE *arquivo){
    QUARTO quarto;
    char status[] = "desocupado";

    printf("Cadastrar Quarto \n");

    do{
        printf("Número do Quarto: ");
        scanf("%d", &quarto.numeroQuarto);
        limparBuffer();

        if(verificarNumeroQuarto(arquivo, quarto.numeroQuarto)){
            printf("Quarto já existe! Insira um novo quarto!\n");
        }
    } while(verificarNumeroQuarto(arquivo, quarto.numeroQuarto));

    fprintf(arquivo, "Número do quarto: %d \n", quarto.numeroQuarto);

    printf("Quantidade de hóspedes: ");
    scanf("%d", &quarto.quantidadeHospedes);
    limparBuffer();
    fprintf(arquivo, "Quantidade de Hóspedes: %d \n", quarto.quantidadeHospedes);

    printf("Valor da diária: R$");
    scanf("%f", &quarto.valorDiaria);
    limparBuffer();
    fprintf(arquivo, "Valor da diária: R$%.2f \n", quarto.valorDiaria);

    fprintf(arquivo, "Status: %s \n", status);

    fprintf(arquivo, "---------------------\n");

    printf("\nQuarto cadastrado com sucesso!\n\n");
}



void procurarFuncionario(FILE *arquivo) {
    FUNCIONARIO funcionario[max_funcionarios];
    char nome[40];
    int codigo, encontrado = 0, opcao, num_funcionario = 0;

    printf("\n Procurar Funcionário \n");
    printf("Pesquisar por (1) Código (2) Nome ? ");
    scanf("%d", &opcao);
    limparBuffer();
    rewind(arquivo);

    // Lendo os dados do arquivo
    while (fscanf(arquivo, "Código: %d\n", &funcionario[num_funcionario].codigo) != EOF) {
        fscanf(arquivo, "Nome: %[^\n]\n", funcionario[num_funcionario].nome);
        fscanf(arquivo, "Sobrenome: %[^\n]\n", funcionario[num_funcionario].sobrenome);
        fscanf(arquivo, "Telefone: %d\n", &funcionario[num_funcionario].telefone);
        fscanf(arquivo, "Cargo: %[^\n]\n", funcionario[num_funcionario].cargo);
        fscanf(arquivo, "Salário: R$%f\n", &funcionario[num_funcionario].salario);
        fscanf(arquivo, "---------------------\n");

        num_funcionario++;
    }

    if (opcao == 1) {
        printf("Digite o código do funcionário: ");
        scanf("%d", &codigo);
        limparBuffer();

        for (int i = 0; i < num_funcionario; i++) {
            if (funcionario[i].codigo == codigo) {
                encontrado = 1;
                printf("\nFuncionário Encontrado:\n");
                printf("Código: %d\n", funcionario[i].codigo);
                printf("Nome: %s\n", funcionario[i].nome);
                printf("Sobrenome: %s\n", funcionario[i].sobrenome);
                printf("Telefone: %d\n", funcionario[i].telefone);
                printf("Cargo: %s\n", funcionario[i].cargo);
                printf("Salário: R$%.2f\n", funcionario[i].salario);
                printf("\n");
                break;
            }
        }
    } else if (opcao == 2) {
        printf("Digite o nome do funcionário: ");
        fgets(nome, sizeof(nome), stdin);
        nome[strcspn(nome, "\n")] = '\0';

        for (int i = 0; i < num_funcionario; i++) {
            if (strcasecmp(funcionario[i].nome, nome) == 0) {
                encontrado = 1;
                printf("\nFuncionário Encontrado:\n");
                printf("Código: %d\n", funcionario[i].codigo);
                printf("Nome: %s\n", funcionario[i].nome);
                printf("Sobrenome: %s\n", funcionario[i].sobrenome);
                printf("Telefone: %d\n", funcionario[i].telefone);
                printf("Cargo: %s\n", funcionario[i].cargo);
                printf("Salário: R$%.2f\n", funcionario[i].salario);
                printf("\n");
            }
        }
    }

    if (!encontrado) {
        printf("Funcionário não encontrado!\n");
    }
}

void procurarCliente(FILE *arquivo){
    CLIENTE cliente[max_funcionarios];
    char nome[40];
    int codigo, encontrado = 0, opcao, num_cliente = 0;

    printf("\n Procurar Cliente \n");
    printf("Pesquisar por (1) Código (2) Nome ? ");
    scanf("%d", &opcao);
    limparBuffer();
    rewind(arquivo);

    // Lendo os dados do arquivo
    while (fscanf(arquivo, "Código: %d\n", &cliente[num_cliente].codigo) != EOF) {
        fscanf(arquivo, "Nome: %[^\n]\n", cliente[num_cliente].nome);
        fscanf(arquivo, "Sobrenome: %[^\n]\n", cliente[num_cliente].sobrenome);
        fscanf(arquivo, "Endereço: %[^\n]\n", cliente[num_cliente].endereco);
        fscanf(arquivo, "Telefone: %d\n", &cliente[num_cliente].telefone);
        fscanf(arquivo, "---------------------\n");

        num_cliente++;
    }

    if (opcao == 1) {
        printf("Digite o código do cliente: ");
        scanf("%d", &codigo);
        limparBuffer();

        for (int i = 0; i < num_cliente; i++) {
            if (cliente[i].codigo == codigo) {
                encontrado = 1;
                printf("\Cliente Encontrado:\n");
                printf("Código: %d\n", cliente[i].codigo);
                printf("Nome: %s\n", cliente[i].nome);
                printf("Sobrenome: %s\n", cliente[i].sobrenome);
                printf("Endereço: %s\n", cliente[i].endereco);
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
                printf("Código: %d\n", cliente[i].codigo);
                printf("Nome: %s\n", cliente[i].nome);
                printf("Sobrenome: %s\n", cliente[i].sobrenome);
                printf("Endereço: %s\n", cliente[i].endereco);
                printf("Telefone: %d\n", cliente[i].telefone);
                printf("\n");
            }
        }
    }

    if (!encontrado) {
        printf("Funcionário não encontrado!\n");
    }
}

int dataMenorOuIgual(DATA data1, DATA data2){
   if(data1.ano < data2.ano){
        return 1;
   }else if(data1.ano > data2.ano){
        return 0;
   }else{
        if(data1.mes < data2.mes){
            return 1;
        }else if(data1.mes > data2.mes){
            return 0;
        }else{
            if(data1.dia <= data2.dia){
                return 1;
            }else{
                return 0;
            }
        }
   }
}

int dataMaiorOuIgual(DATA data1, DATA data2){
    if(data1.ano > data2.ano){
        return 1;
   }else if(data1.ano < data2.ano){
        return 0;
   }else{
        if(data1.mes > data2.mes){
            return 1;
        }else if(data1.mes < data2.mes){
            return 0;
        }else{
            if(data1.dia >= data2.dia){
                return 1;
            }else{
                return 0;
            }
        }
   }
}

int quartoEstaDisponivel(FILE *arquivoEstadia, int numeroQuarto, DATA entrada, DATA saida){
    ESTADIA estadia;
    rewind(arquivoEstadia);

    while(fscanf(arquivoEstadia, "Código: %d\n", &estadia.codigo) == 1){
        fscanf(arquivoEstadia, "Data de Entrada: %d/%d/%d\n", &estadia.entrada.dia, &estadia.entrada.mes, &estadia.entrada.ano);
        fscanf(arquivoEstadia, "Data de Saída: %d/%d/%d\n", &estadia.saida.dia, &estadia.saida.mes, &estadia.saida.ano);
        fscanf(arquivoEstadia, "Diárias: %d\n", &estadia.diarias);
        fscanf(arquivoEstadia, "Código do Cliente: %d\n", &estadia.codigoCliente);
        fscanf(arquivoEstadia, "Número do Quarto: %d\n", &estadia.numeroQuarto);
        fscanf(arquivoEstadia, "---------------------\n");

        if(estadia.numeroQuarto == numeroQuarto &&
           ((dataMaiorOuIgual(entrada, estadia.entrada) && dataMenorOuIgual(entrada, estadia.entrada)) ||
            (dataMaiorOuIgual(saida, estadia.saida) && dataMenorOuIgual(saida, estadia.saida)) ||
        (dataMenorOuIgual(entrada, estadia.entrada) && dataMaiorOuIgual(saida, estadia.saida)))){
            return 0;
        }
    }

    return 1;
}

void quartosDisponiveis(FILE *arquivoQuarto, FILE *arquivoEstadia, int qntHospedes, DATA entrada, DATA saida){
    QUARTO quarto;
    rewind(arquivoQuarto);
    char status[] = "desocupado";
    char status2[] = "ocupado";

    printf("Quartos disponíveis: \n\n");
    while(fscanf(arquivoQuarto, "Número do quarto: %d\n", &quarto.numeroQuarto) == 1){
        fscanf(arquivoQuarto, "Quantidade de Hóspedes: %d\n", &quarto.quantidadeHospedes);
        fscanf(arquivoQuarto, "Valor da diária: %f\n", &quarto.valorDiaria);
        fscanf(arquivoQuarto, "Status: %[^\n]\n", quarto.status);
        fscanf(arquivoQuarto, "---------------------\n");

        if(quarto.quantidadeHospedes >= qntHospedes &&
           quartoEstaDisponivel(arquivoEstadia, quarto.numeroQuarto, entrada, saida) && (strcmp(quarto.status, status2) == 0)){
            printf("Número do quarto: %d\n", quarto.numeroQuarto);
            printf("Quantidade de Hóspedes: %d\n", quarto.quantidadeHospedes);
            printf("Valor da diária: R$%.2f\n", quarto.valorDiaria);
            printf("---------------------\n");
           }
    }
}


void reservarEstadia(FILE *arquivoQuarto, FILE *arquivoCliente, FILE *arquivoEstadia){
    ESTADIA estadia;
    QUARTO quarto;
    CLIENTE cliente;
    int qntHospedes;
    char status[] = "desocupado";
    char status2[] = "ocupado";

    arquivoCliente = fopen("clientes.txt", "r");
    if(arquivoCliente == NULL){
        printf("Erro ao abrir o arquivo!");
    }

    do{
        printf("Digite o código do cliente: ");
        scanf("%d", &estadia.codigoCliente);
        limparBuffer();

        if(verificarCodigoCliente(arquivoCliente, cliente.codigo) == 0){
            printf("Esse cliente não está cadastrado! Insira um código válido!\n");
        }

    }while(verificarCodigoCliente(arquivoCliente, cliente.codigo)== 0);

    fclose(arquivoCliente);

    printf("Digite quantos hospédes irão se hospedar: ");
    scanf("%d", &qntHospedes);

    printf("Data de Entrada: (dd/mm/aaaa)");
    scanf("%d/%d/%d", &estadia.entrada.dia, &estadia.entrada.mes, &estadia.entrada.ano);

    printf("Data de saída: (dd/mm/aaaa)");
    scanf("%d/%d/%d", &estadia.saida.dia, &estadia.saida.mes, &estadia.saida.ano);

    quartosDisponiveis(arquivoQuarto, arquivoEstadia, qntHospedes, estadia.entrada, estadia.saida);

    do{
        printf("Número do Quarto: ");
        scanf("%d", &estadia.numeroQuarto);
        limparBuffer();

        if(!verificarNumeroQuarto(arquivoQuarto, estadia.numeroQuarto)){
            printf("Quarto não encontrado! Insira um quarto válido!\n");
        }
    }while(!verificarNumeroQuarto(arquivoQuarto, estadia.numeroQuarto));

    if(!quartoEstaDisponivel(arquivoEstadia, estadia.numeroQuarto, estadia.entrada, estadia.saida)){
        printf("Quarto não está disponível nessa data!\n");
        return;
    }
    //
    int dias = 0;
    if(estadia.entrada.mes == estadia.saida.mes){
        dias = estadia.saida.dia - estadia.entrada.dia;
    }else{
        dias += (30 - estadia.entrada.dia);
        int meses = estadia.saida.mes - (estadia.entrada.mes + 1);
        dias = dias + (meses * 30) + estadia.saida.dia;
    }

    estadia.diarias = dias;

    do{
        printf("Digite o código da estadia: ");
        scanf("%d", &estadia.codigo);
        limparBuffer();

        if(verificarCodigoEstadia(arquivoEstadia, estadia.codigo)){
            printf("Já existe uma estadia com esse código! Insira um novo código!");
        }
    }while(verificarCodigoEstadia(arquivoEstadia, estadia.codigo));

    fprintf(arquivoEstadia, "Código: %d\n", &estadia.codigo);
    fprintf(arquivoEstadia, "Data de Entrada: %02d/%02d/%02d\n", estadia.entrada.dia,estadia.entrada.mes, estadia.entrada.ano);
    fprintf(arquivoEstadia, "Data de Saída: %02d/%02d/%02d\n", estadia.saida.dia,estadia.saida.mes, estadia.saida.ano);
    fprintf(arquivoEstadia, "Diárias: %d\n", estadia.diarias);
    fprintf(arquivoEstadia, "Código do Cliente: %d\n", estadia.codigoCliente);
    fprintf(arquivoEstadia, "Número do Quarto: %d\n", estadia.numeroQuarto);
    fprintf(arquivoEstadia, "---------------------\n");

    printf("\nEstadia reservada com sucesso!\n\n");

}


void baixaEstadia(){}

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
 printf("\nMenu Principal\n");
    printf("(1) Informações do Hotel\n(2) Cadastrar Cliente\n(3) Cadastrar Quarto\n(4) Cadastrar Funcionário\n(5) Reservar Estadia\n(6) Pesquisar cliente\n(7) Pesquisar Funcionário\n(8) Finalizar\n");
    scanf("%d", resp);

    return *resp;
}


int main()
{
    int resp = 0;
    float valorDiaria = 100.0;
    FILE *arquivoCliente, *arquivoFuncionario, *arquivoQuarto, *arquivoEstadia;


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
        arquivoEstadia = fopen("estadia.txt", "a+");
        arquivoCliente = fopen("clientes.txt", "a+");
        arquivoQuarto = fopen("quartos.txt", "a+");
        if(arquivoEstadia == NULL || arquivoCliente == NULL || arquivoQuarto == NULL){
            printf("Erro ao abrir o arquivo.\n");
        }
        reservarEstadia(arquivoQuarto, arquivoCliente, arquivoEstadia);
        fclose(arquivoCliente);
        fclose(arquivoEstadia);
        fclose(arquivoQuarto);
        break;
    case 6:
        arquivoCliente = fopen("clientes.txt", "r");
        if(arquivoCliente == NULL){
            printf("Erro ao abrir o arquivo.\n");
        }
        procurarCliente(arquivoCliente);
        fclose(arquivoCliente);
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
