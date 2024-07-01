    #include <stdio.h>
    #include <stdlib.h>
    #include <string.h>
    #include <locale.h>

    #define number 50
    #define max_funcionarios 100
    #define MAX_RESERVAS 100


/** Estrutura que representa uma data com dia, mês e ano. */

    typedef struct {
        int dia;
        int mes;
        int ano;
    }DATA;


/** Estrutura que representa um cliente com código, nome, sobrenome, endereço e telefone. */

    typedef struct {
        int codigo;
        char nome[40], sobrenome[50];
        char endereco[100];
        int telefone;
    }CLIENTE;


/** Estrutura que representa um funcionário com código, nome, sobrenome, telefone, cargo e salário. */

    typedef struct {
        int codigo;
        char nome[40], sobrenome[50];
        int telefone;
        char cargo[30];
        float salario;
    }FUNCIONARIO;


/** Estrutura que representa uma estadia com código, datas de entrada e saída, número de diárias, código do cliente e número do quarto. */

    typedef struct {
        int codigo;
        DATA entrada;
        DATA saida;
        int diarias;
        int codigoCliente;
        int numeroQuarto;

    }ESTADIA;


/** Estrutura que representa um quarto com número, quantidade de hóspedes, valor da diária e status. */

    typedef struct{
        int numeroQuarto;
        int quantidadeHospedes;
        float valorDiaria;
        char status[15];
    }QUARTO;


/** Estrutura que representa uma reserva com código do cliente, código da estadia, número do quarto, datas de entrada e saída e número de diárias. */

typedef struct {
    int codigoCliente;
    int codigoEstadia;
    int numeroQuarto;
    DATA entrada;
    DATA saida;
    int diarias;
} RESERVA;


/**Limpa o buffer de entrada para evitar problemas na leitura de dados pelo scanf. */

    void limparBuffer(){
        int c;
        while((c = getchar()) != '\n' && c != EOF);
    }


/** Verifica se um código de cliente já está cadastrado no arquivo.
* FILE *arquivo: Ponteiro para o arquivo que contém os dados dos clientes.
* int codigo: Código do cliente a ser verificado.
* Retorno: 1 se o código já existir, 0 caso contrário. */

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


/** Cadastra um novo cliente no arquivo, verificando se o código do cliente já existe.
* FILE *arquivo: Ponteiro para o arquivo que contém os dados dos clientes. */

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


/** Procura um cliente no arquivo pelo código ou nome.
* FILE *arquivo: Ponteiro para o arquivo que contém os dados dos clientes.
* int opcao: Opção de pesquisa (1 para código, 2 para nome). */

void procurarCliente(FILE *arquivo) {
    CLIENTE cliente[max_funcionarios];
    char nome[40];
    int codigo, encontrado = 0, opcao, num_cliente = 0;

    printf("\nProcurar Cliente\n");
    printf("Pesquisar por (1) Código (2) Nome? ");
    scanf("%d", &opcao);
    limparBuffer();
    rewind(arquivo);

    // Lendo os dados do arquivo
    while (fscanf(arquivo, "Código: %d\n", &cliente[num_cliente].codigo) == 1) {
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
                printf("\nCliente Encontrado:\n");
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
        printf("Cliente não encontrado!\n");
    }
}


/** Verifica se um código de funcionário já existe no arquivo.
* arquivo (FILE*): Ponteiro para o arquivo que contém os registros dos funcionários.
* codigo (int): Código do funcionário que se deseja verificar.
* Retorna 1 se o código já existe, caso contrário, retorna 0. */

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


/** Cadastra um novo funcionário no arquivo.
*arquivo (FILE*): Ponteiro para o arquivo onde os registros dos funcionários serão armazenados. */

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

/** Procura por um funcionário no arquivo de dados dos funcionários, permitindo a busca por código ou nome.
* arquivo (FILE*): Ponteiro para o arquivo que contém os registros dos funcionários. */

    void procurarFuncionario(FILE *arquivo) {
    FUNCIONARIO funcionario[max_funcionarios];
    char nome[40];
    int codigo, encontrado = 0, opcao, num_funcionario = 0;

    printf("\nProcurar Funcionário\n");
    printf("Pesquisar por (1) Código (2) Nome ? ");
    scanf("%d", &opcao);
    limparBuffer();
    rewind(arquivo);

    // Lendo os dados do arquivo
    while (fscanf(arquivo, "Código: %d\n", &funcionario[num_funcionario].codigo) == 1) {
        fscanf(arquivo, "Nome: %[^\n]\n", funcionario[num_funcionario].nome);
        fscanf(arquivo, "Sobrenome: %[^\n]\n", funcionario[num_funcionario].sobrenome);
        fscanf(arquivo, "Telefone: %d\n", &funcionario[num_funcionario].telefone);
        fscanf(arquivo, "Cargo: %[^\n]\n", funcionario[num_funcionario].cargo);
        fscanf(arquivo, "Salário: R$%f\n", &funcionario[num_funcionario].salario);
        fscanf(arquivo, "---------------------\n");

        num_funcionario++;

        if (num_funcionario >= max_funcionarios) {
            printf("Limite máximo de funcionários atingido.\n");
            break;
        }
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


/** Verifica se um número de quarto já existe no arquivo de dados dos quartos.
* arquivo (FILE*): Ponteiro para o arquivo que contém os registros dos quartos.
* numero (int): Número do quarto que se deseja verificar.
* Retorna 1 se o número do quarto já existe no arquivo caso contrário  retorna 0 se o número do quarto não for encontrado no arquivo. */

    int verificarNumeroQuarto(FILE *arquivo, int numero) {
        QUARTO quarto;

        // Posiciona no início do arquivo
        rewind(arquivo);

        // Variável para indicar se encontrou o número do quarto
        int encontrado = 0;

        // Lê cada registro do arquivo
        while (fscanf(arquivo, "Número do quarto: %d\n", &quarto.numeroQuarto) == 1) {
            fscanf(arquivo, "Quantidade de Hóspedes: %d\n", &quarto.quantidadeHospedes);
            fscanf(arquivo, "Valor da diária: R$%f\n", &quarto.valorDiaria);
            fscanf(arquivo, "Status: %[^\n]\n", quarto.status);
            fscanf(arquivo, "---------------------\n");

            // Verifica se o número do quarto é igual ao número passado como parâmetro
            if (quarto.numeroQuarto == numero) {
                encontrado = 1;
                break;
            }
        }

        return encontrado;
    }


/**Cadastra um novo quarto no arquivo de dados dos quartos.
* arquivo (FILE*): Ponteiro para o arquivo onde os registros dos quartos serão armazenados. */

    void cadastrarQuarto(FILE *arquivo) {
        QUARTO quarto;
        char status[] = "desocupado";
        int numeroValido;

        do{
            printf("Número do quarto: ");
            scanf("%d", &quarto.numeroQuarto);

            int existe = verificarNumeroQuarto(arquivo, quarto.numeroQuarto);
            if(existe == 1){
                printf("Já existe um quarto com esse número!\n");
                numeroValido = 0;
            }else{
                numeroValido = 1;
            }
        }while(numeroValido != 1);

        fprintf(arquivo, "Número do quarto: %d\n", quarto.numeroQuarto);

        printf("Quantidade de hóspedes: ");
        scanf("%d", &quarto.quantidadeHospedes);
        fprintf(arquivo, "Quantidade de Hóspedes: %d\n", quarto.quantidadeHospedes);

        printf("Valor da diária: R$");
        scanf("%f", &quarto.valorDiaria);
        fprintf(arquivo, "Valor da diária: R$%.2f\n", quarto.valorDiaria);

        fprintf(arquivo, "Status: %s\n", status);
        fprintf(arquivo, "---------------------\n");
        printf("Quarto registrado com sucesso!\n\n");


    }


/** Compara duas datas para verificar se a primeira é menor ou igual à segunda.
* data1 (DATA): Primeira data a ser comparada.
* data2 (DATA): Segunda data a ser comparada.
* Retorna 1 se a primeira data for menor ou igual à segunda caso contrário retorna 0 se a primeira data for maior que a segunda. */

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


/** Compara duas datas para verificar se a primeira é menor ou igual à segunda.
* data1 (DATA): Primeira data a ser comparada.
* data2 (DATA): Segunda data a ser comparada.
* Retorna 1 se a primeira data for menor ou igual à segunda caso contrário retorna 0 se a primeira data for maior que a segunda. */

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

/** Verifica se um quarto está disponível para um determinado período.
* arquivoEstadia (FILE*): Ponteiro para o arquivo que contém os registros das estadias.
* numeroQuarto (int): Número do quarto a ser verificado.
* entrada (DATA): Data de entrada desejada.
* saida (DATA): Data de saída desejada.
* Retorna 1 se o quarto estiver disponível no período especificado caso contrário retorna 0 se o quarto não estiver disponível no período especificado. */

    int quartoEstaDisponivel(FILE *arquivoEstadia, int numeroQuarto, DATA entrada, DATA saida) {
    ESTADIA estadia;
    rewind(arquivoEstadia);
    while (fscanf(arquivoEstadia, "Código: %d\n", &estadia.codigo) == 1) {
        fscanf(arquivoEstadia, "Data de Entrada: %d/%d/%d\n", &estadia.entrada.dia, &estadia.entrada.mes, &estadia.entrada.ano);
        fscanf(arquivoEstadia, "Data de Saída: %d/%d/%d\n", &estadia.saida.dia, &estadia.saida.mes, &estadia.saida.ano);
        fscanf(arquivoEstadia, "Diárias: %d\n", &estadia.diarias);
        fscanf(arquivoEstadia, "Código do Cliente: %d\n", &estadia.codigoCliente);
        fscanf(arquivoEstadia, "Número do Quarto: %d\n", &estadia.numeroQuarto);
        fscanf(arquivoEstadia, "---------------------\n");

        if (estadia.numeroQuarto == numeroQuarto &&
            (entrada.ano <= estadia.saida.ano && entrada.mes <= estadia.saida.mes && entrada.dia <= estadia.saida.dia) &&
            (saida.ano >= estadia.entrada.ano && saida.mes >= estadia.entrada.mes && saida.dia >= estadia.entrada.dia)) {
            return 0;
        }
    }
    return 1;
}


/** Exibe os quartos disponíveis para uma determinada quantidade de hóspedes e período.
* arquivoQuarto (FILE*): Ponteiro para o arquivo que contém os registros dos quartos.
* arquivoEstadia (FILE*): Ponteiro para o arquivo que contém os registros das estadias.
* qntHospedes (int): Quantidade de hóspedes desejada.
* entrada (DATA): Data de entrada desejada.
* saida (DATA): Data de saída desejada.*/

void quartosDisponiveis(FILE *arquivoQuarto, FILE *arquivoEstadia, int qntHospedes, DATA entrada, DATA saida) {
    QUARTO quarto;
    RESERVA reserva;
    int disponivel;

    rewind(arquivoQuarto);
    printf("Quartos disponíveis:\n");
    while (fscanf(arquivoQuarto, "Número do quarto: %d\n", &quarto.numeroQuarto) == 1) {
        fscanf(arquivoQuarto, "Quantidade de Hóspedes: %d\n", &quarto.quantidadeHospedes);
        fscanf(arquivoQuarto, "Valor da diária: R$%f\n", &quarto.valorDiaria);
        fscanf(arquivoQuarto, "Status: %[^\n]\n", quarto.status);
        fscanf(arquivoQuarto, "---------------------\n");

        if (quarto.quantidadeHospedes >= qntHospedes) {
            disponivel = 1;
            rewind(arquivoEstadia);
            while (fscanf(arquivoEstadia, "Código: %d\n", &reserva.codigoEstadia) == 1) {
                fscanf(arquivoEstadia, "Data de Entrada: %02d/%02d/%02d\n", &reserva.entrada.dia, &reserva.entrada.mes, &reserva.entrada.ano);
                fscanf(arquivoEstadia, "Data de Saída: %02d/%02d/%02d\n", &reserva.saida.dia, &reserva.saida.mes, &reserva.saida.ano);
                fscanf(arquivoEstadia, "Diárias: %d\n", &reserva.diarias);
                fscanf(arquivoEstadia, "Código do Cliente: %d\n", &reserva.codigoCliente);
                fscanf(arquivoEstadia, "Número do Quarto: %d\n", &reserva.numeroQuarto);
                fscanf(arquivoEstadia, "---------------------\n");

                if (quarto.numeroQuarto == reserva.numeroQuarto && reservasConflitam(reserva, (RESERVA) { .entrada = entrada, .saida = saida })) {
                    disponivel = 0;
                    break;
                }
            }
            if (disponivel) {
                printf("Número do quarto: %d\n", quarto.numeroQuarto);
                printf("Quantidade de Hóspedes: %d\n", quarto.quantidadeHospedes);
                printf("Valor da diária: R$%.2f\n", quarto.valorDiaria);
                printf("---------------------\n");
            }
        }
    }
}


/** Verifica se um código de estadia já existe no arquivo de dados das estadias.
* arquivo (FILE*): Ponteiro para o arquivo que contém os registros das estadias.
* codigo (int): Código da estadia que se deseja verificar.
* Retorna 1 se o código já existe no arquivo.
* Retorna 0 se o código não for encontrado no arquivo. */

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


/** Calcula o valor total da estadia de um cliente específico, multiplicando a quantidade de diárias pelo valor da diária do quarto correspondente.
* arquivoQuarto (FILE*): Arquivo que contém os dados dos quartos.
* arquivoEstadia (FILE*): Arquivo que contém os dados das estadias.
* codigoCliente (int): Código do cliente cuja estadia será calculada.
* (float): Valor total da estadia do cliente. */

float calcularValorEstadia(FILE *arquivoQuarto, FILE *arquivoEstadia, int codigoCliente) {
    ESTADIA estadia;
    QUARTO quarto;
    float valorTotal = 0.0;

    rewind(arquivoEstadia);
    rewind(arquivoQuarto);

    while (fscanf(arquivoEstadia, "Código: %d\n", &estadia.codigo) == 1) {
        fscanf(arquivoEstadia, "Data de Entrada: %02d/%02d/%02d\n", &estadia.entrada.dia, &estadia.entrada.mes, &estadia.entrada.ano);
        fscanf(arquivoEstadia, "Data de Saída: %02d/%02d/%02d\n", &estadia.saida.dia, &estadia.saida.mes, &estadia.saida.ano);
        fscanf(arquivoEstadia, "Diárias: %d\n", &estadia.diarias);
        fscanf(arquivoEstadia, "Código do Cliente: %d\n", &estadia.codigoCliente);
        fscanf(arquivoEstadia, "Número do Quarto: %d\n", &estadia.numeroQuarto);
        fscanf(arquivoEstadia, "---------------------\n");

        if (estadia.codigoCliente == codigoCliente) {
            while (fscanf(arquivoQuarto, "Número do quarto: %d\n", &quarto.numeroQuarto) == 1) {
                fscanf(arquivoQuarto, "Quantidade de Hóspedes: %d\n", &quarto.quantidadeHospedes);
                fscanf(arquivoQuarto, "Valor da diária: R$%f\n", &quarto.valorDiaria);
                fscanf(arquivoQuarto, "Status: %[^\n]\n", quarto.status);
                fscanf(arquivoQuarto, "---------------------\n");

                if (quarto.numeroQuarto == estadia.numeroQuarto) {
                    valorTotal += estadia.diarias * quarto.valorDiaria;
                    break;
                }
            }
        }
    }

    return valorTotal;
}


/** Compara duas datas e retorna a diferença entre elas.
*d1 (DATA): Primeira data.
*d2 (DATA): Segunda data.
* (int): Diferença entre as datas (anos, meses, dias). */

int compararDatas(DATA d1, DATA d2) {
    if (d1.ano != d2.ano) return d1.ano - d2.ano;
    if (d1.mes != d2.mes) return d1.mes - d2.mes;
    return d1.dia - d2.dia;
}


/** Verifica se duas reservas conflitam, ou seja, se há sobreposição de datas para o mesmo quarto.
* r1 (RESERVA): Primeira reserva.
* r2 (RESERVA): Segunda reserva.
* (int): 1 se houver conflito, 0 caso contrário. */

int reservasConflitam(RESERVA r1, RESERVA r2) {
    if (r1.numeroQuarto != r2.numeroQuarto) return 0;
    if (compararDatas(r1.saida, r2.entrada) <= 0 || compararDatas(r2.saida, r1.entrada) <= 0) return 0;
    return 1;
}


/** Permite que um cliente faça uma reserva para uma determinada data, verificando conflitos e disponibilidade.
* arquivoQuarto (FILE*): Arquivo que contém os dados dos quartos.
* arquivoCliente (FILE*): Arquivo que contém os dados dos clientes.
* arquivoEstadia (FILE*): Arquivo que contém os dados das estadias.
* reservas (RESERVA[]): Vetor de reservas.
* totalReservas (int*): Ponteiro para o total de reservas. */

void reservarEstadiaParaData(FILE *arquivoQuarto, FILE *arquivoCliente, FILE *arquivoEstadia, RESERVA reservas[], int *totalReservas) {
    RESERVA novaReserva;
    int qntHospedes;
    printf("\n_Reservar Estadia para uma Data_\n");

    do {
        printf("Digite o código do cliente: ");
        scanf("%d", &novaReserva.codigoCliente);
        limparBuffer();
        if (!verificarCodigoCliente(arquivoCliente, novaReserva.codigoCliente)) {
            printf("Esse cliente não está cadastrado! Insira um código válido!\n");
        }
    } while (!verificarCodigoCliente(arquivoCliente, novaReserva.codigoCliente));

    printf("Digite quantos hóspedes irão se hospedar: ");
    scanf("%d", &qntHospedes);
    limparBuffer();

    printf("Data de Entrada (dd/mm/aaaa): ");
    scanf("%d/%d/%d", &novaReserva.entrada.dia, &novaReserva.entrada.mes, &novaReserva.entrada.ano);
    limparBuffer();

    printf("Data de Saída (dd/mm/aaaa): ");
    scanf("%d/%d/%d", &novaReserva.saida.dia, &novaReserva.saida.mes, &novaReserva.saida.ano);
    limparBuffer();

    quartosDisponiveis(arquivoQuarto, arquivoEstadia, qntHospedes, novaReserva.entrada, novaReserva.saida);

    do {
        printf("Digite o número do quarto desejado: ");
        scanf("%d", &novaReserva.numeroQuarto);
        limparBuffer();
        if (!verificarNumeroQuarto(arquivoQuarto, novaReserva.numeroQuarto)) {
            printf("Esse quarto não está cadastrado! Insira um número válido!\n");
        } else if (!quartoEstaDisponivel(arquivoEstadia, novaReserva.numeroQuarto, novaReserva.entrada, novaReserva.saida)) {
            printf("Esse quarto já está reservado para as datas escolhidas! Escolha outro quarto ou outra data.\n");
        }
    } while (!verificarNumeroQuarto(arquivoQuarto, novaReserva.numeroQuarto) || !quartoEstaDisponivel(arquivoEstadia, novaReserva.numeroQuarto, novaReserva.entrada, novaReserva.saida));

    do {
        printf("Digite o código da estadia: ");
        scanf("%d", &novaReserva.codigoEstadia);
        limparBuffer();
        if (verificarCodigoEstadia(arquivoEstadia, novaReserva.codigoEstadia)) {
            printf("Esse código de estadia já está em uso! Insira um código válido!\n");
        }
    } while (verificarCodigoEstadia(arquivoEstadia, novaReserva.codigoEstadia));

    novaReserva.diarias = compararDatas(novaReserva.saida, novaReserva.entrada);


    // Adiciona a nova reserva ao array de reservas
    reservas[*totalReservas] = novaReserva;
    (*totalReservas)++;

    // Atualiza o arquivo de estadias
    arquivoEstadia = fopen("arquivo_estadia.txt", "a");
    if (arquivoEstadia == NULL) {
        printf("Erro ao abrir o arquivo de estadias.\n");
        exit(1);
    }
    fprintf(arquivoEstadia, "Código: %d\n", novaReserva.codigoEstadia);
    fprintf(arquivoEstadia, "Data de Entrada: %02d/%02d/%02d\n", novaReserva.entrada.dia, novaReserva.entrada.mes, novaReserva.entrada.ano);
    fprintf(arquivoEstadia, "Data de Saída: %02d/%02d/%02d\n", novaReserva.saida.dia, novaReserva.saida.mes, novaReserva.saida.ano);
    fprintf(arquivoEstadia, "Diárias: %d\n", novaReserva.diarias);
    fprintf(arquivoEstadia, "Código do Cliente: %d\n", novaReserva.codigoCliente);
    fprintf(arquivoEstadia, "Número do Quarto: %d\n", novaReserva.numeroQuarto);
    fprintf(arquivoEstadia, "---------------------\n");
    fclose(arquivoEstadia);

    printf("Reserva realizada com sucesso!\n");
}


/** Dá baixa em uma estadia, marcando o quarto correspondente como desocupado.
* arquivoEstadia (FILE*): Arquivo que contém os dados das estadias.
* arquivoQuarto (FILE*): Arquivo que contém os dados dos quartos. */

void darBaixaEstadia(FILE *arquivoEstadia, FILE *arquivoQuarto) {
    int codigoEstadia, encontrado = 0;
    QUARTO quarto;
    ESTADIA estadia;

    printf("\n__Dar Baixa na Estadia__\n");

    printf("Digite o código da estadia para dar baixa: ");
    scanf("%d", &codigoEstadia);
    limparBuffer();

    FILE *tempFile = fopen("temp.txt", "w");
    if (tempFile == NULL) {
        printf("Erro ao abrir arquivo temporário!\n");
        return;
    }
    FILE *tempFile1 = fopen("temp1.txt", "w");
    if (tempFile1 == NULL) {
        printf("Erro ao abrir arquivo temporário!\n");
        return;
    }

    rewind(arquivoEstadia);

    while (fscanf(arquivoEstadia, "Código: %d\n", &estadia.codigo) == 1) {
        fscanf(arquivoEstadia, "Data de Entrada: %d/%d/%d\n", &estadia.entrada.dia, &estadia.entrada.mes, &estadia.entrada.ano);
        fscanf(arquivoEstadia, "Data de Saída: %d/%d/%d\n", &estadia.saida.dia, &estadia.saida.mes, &estadia.saida.ano);
        fscanf(arquivoEstadia, "Diárias: %d\n", &estadia.diarias);
        fscanf(arquivoEstadia, "Código do Cliente: %d\n", &estadia.codigoCliente);
        fscanf(arquivoEstadia, "Número do Quarto: %d\n", &estadia.numeroQuarto);
        fscanf(arquivoEstadia, "---------------------\n");

        if (estadia.codigo == codigoEstadia) {
            encontrado = 1;

            rewind(arquivoQuarto);
            while (fscanf(arquivoQuarto, "Número do quarto: %d\n", &quarto.numeroQuarto) == 1) {
                fscanf(arquivoQuarto, "Quantidade de Hóspedes: %d\n", &quarto.quantidadeHospedes);
                fscanf(arquivoQuarto, "Valor da diária: R$%f\n", &quarto.valorDiaria);
                fscanf(arquivoQuarto, "Status: %[^\n]\n", quarto.status);
                fscanf(arquivoQuarto, "---------------------\n");

                if (quarto.numeroQuarto == estadia.numeroQuarto) {
                    fprintf(tempFile, "Número do quarto: %d\n", quarto.numeroQuarto);
                    fprintf(tempFile, "Quantidade de Hóspedes: %d\n", quarto.quantidadeHospedes);
                    fprintf(tempFile, "Valor da diária: R$%.2f\n", quarto.valorDiaria);
                    fprintf(tempFile, "Status: desocupado\n");
                    fprintf(tempFile, "---------------------\n");
                } else {
                    fprintf(tempFile, "Número do quarto: %d\n", quarto.numeroQuarto);
                    fprintf(tempFile, "Quantidade de Hóspedes: %d\n", quarto.quantidadeHospedes);
                    fprintf(tempFile, "Valor da diária: R$%.2f\n", quarto.valorDiaria);
                    fprintf(tempFile, "Status: %s\n", quarto.status);
                    fprintf(tempFile, "---------------------\n");
                }
            }

            printf("Estadia encontrada:\n");
            printf("Código: %d\n", estadia.codigo);
            printf("Data de Entrada: %02d/%02d/%02d\n", estadia.entrada.dia, estadia.entrada.mes, estadia.entrada.ano);
            printf("Data de Saída: %02d/%02d/%02d\n", estadia.saida.dia, estadia.saida.mes, estadia.saida.ano);
            printf("Diárias: %d\n", estadia.diarias);
            printf("Código do Cliente: %d\n", estadia.codigoCliente);
            printf("Número do Quarto: %d\n", estadia.numeroQuarto);
            printf("---------------------\n");

            char confirmacao;
            printf("Confirmar baixa da estadia? (S/N): ");
            scanf(" %c", &confirmacao);
            limparBuffer();

            if (confirmacao == 'S' || confirmacao == 's') {
                printf("Baixa realizada com sucesso!\n");
            } else {
                printf("Baixa cancelada.\n");
            }
        } else {
            fprintf(tempFile1, "Código: %d\n", estadia.codigo);
            fprintf(tempFile1, "Data de Entrada: %02d/%02d/%02d\n", estadia.entrada.dia, estadia.entrada.mes, estadia.entrada.ano);
            fprintf(tempFile1, "Data de Saída: %02d/%02d/%02d\n", estadia.saida.dia, estadia.saida.mes, estadia.saida.ano);
            fprintf(tempFile1, "Diárias: %d\n", estadia.diarias);
            fprintf(tempFile1, "Código do Cliente: %d\n", estadia.codigoCliente);
            fprintf(tempFile1, "Número do Quarto: %d\n", estadia.numeroQuarto);
            fprintf(tempFile1, "---------------------\n");
        }
    }

    fclose(arquivoEstadia);
    fclose(tempFile);
    fclose(arquivoQuarto);
    fclose(tempFile1);
    remove("estadia.txt");
    rename("temp1.txt", "estadia.txt");
    remove("quartos.txt");
    rename("temp.txt", "quartos.txt");

    if (!encontrado) {
        printf("Estadia não encontrada!\n");
    }
}


/** Marca um quarto como ocupado para uma estadia específica.
* arquivoQuarto (FILE*): Arquivo que contém os dados dos quartos.
* arquivoEstadia (FILE*): Arquivo que contém os dados das estadias. */

void ocuparQuarto(FILE *arquivoQuarto, FILE *arquivoEstadia){
     rewind(arquivoQuarto);
    FILE *tempFile = fopen("temp.txt", "w");
    if (tempFile == NULL) {
        printf("Erro ao abrir arquivo temporário!\n");
        return;
    }

    int codigoEstadia, encontrado = 0;
    ESTADIA estadia;

    printf("\n__Ocupar Quarto__\n");
    printf("Digite o código da estadia a ocupar: ");
    scanf("%d", &codigoEstadia);
    limparBuffer();

    rewind(arquivoEstadia);

    while (fscanf(arquivoEstadia, "Código: %d\n", &estadia.codigo) == 1) {
        fscanf(arquivoEstadia, "Data de Entrada: %d/%d/%d\n", &estadia.entrada.dia, &estadia.entrada.mes, &estadia.entrada.ano);
        fscanf(arquivoEstadia, "Data de Saída: %d/%d/%d\n", &estadia.saida.dia, &estadia.saida.mes, &estadia.saida.ano);
        fscanf(arquivoEstadia, "Diárias: %d\n", &estadia.diarias);
        fscanf(arquivoEstadia, "Código do Cliente: %d\n", &estadia.codigoCliente);
        fscanf(arquivoEstadia, "Número do Quarto: %d\n", &estadia.numeroQuarto);
        fscanf(arquivoEstadia, "---------------------\n");

        if (estadia.codigo == codigoEstadia) {
            encontrado = 1;
            break;
        }
    }

    if (!encontrado) {
        printf("Estadia com código %d não encontrada!\n", codigoEstadia);
        fclose(tempFile);
        return;
    }

    QUARTO quarto;
    while (fscanf(arquivoQuarto, "Número do quarto: %d\n", &quarto.numeroQuarto) == 1) {
        fscanf(arquivoQuarto, "Quantidade de Hóspedes: %d\n", &quarto.quantidadeHospedes);
        fscanf(arquivoQuarto, "Valor da diária: R$%f\n", &quarto.valorDiaria);
        fscanf(arquivoQuarto, "Status: %[^\n]\n", quarto.status);
        fscanf(arquivoQuarto, "---------------------\n");

        if (quarto.numeroQuarto == estadia.numeroQuarto) {
            fprintf(tempFile, "Número do quarto: %d\n", quarto.numeroQuarto);
            fprintf(tempFile, "Quantidade de Hóspedes: %d\n", quarto.quantidadeHospedes);
            fprintf(tempFile, "Valor da diária: R$%.2f\n", quarto.valorDiaria);
            fprintf(tempFile, "Status: ocupado\n");
            fprintf(tempFile, "---------------------\n");
        } else {
            fprintf(tempFile, "Número do quarto: %d\n", quarto.numeroQuarto);
            fprintf(tempFile, "Quantidade de Hóspedes: %d\n", quarto.quantidadeHospedes);
            fprintf(tempFile, "Valor da diária: R$%.2f\n", quarto.valorDiaria);
            fprintf(tempFile, "Status: %s\n", quarto.status);
            fprintf(tempFile, "---------------------\n");
        }
    }

    fclose(arquivoQuarto);
    fclose(tempFile);
    remove("quartos.txt");
    rename("temp.txt", "quartos.txt");
}


/** Exibe informações gerais sobre o hotel.*/

void hotelInfo(){
    printf("Informações do Hotel\n\n");
    printf("Localização: Centro de Itacaré - Bahia\n");
    printf("Início da diária: 14:00\n");
    printf("Fim da diária: 12:00\n");
    printf("Sejam bem-vindos ao Hotel Descanso Garantido!\nTenham uma ótima estadia!\n\n");
}


/** Exibe o menu principal e captura a opção selecionada pelo usuário.
* resp (int*): Ponteiro para a variável que armazena a opção selecionada.
* retorna (int): Opção selecionada. */

int opt(int *resp)
{
    printf("\nMenu Principal\n");
    printf("(1) Informações do Hotel\n(2) Cadastrar Cliente\n(3) Cadastrar Quarto\n(4) Cadastrar Funcionário\n(5) Reservar Estadia\n(6) Pesquisar Cliente\n(7) Pesquisar Funcionário\n(8) Dar Baixa\n(9) Ocupar Quarto\n(10) Sair\n");
    scanf("%d", resp);
    return *resp;
}


/** Função principal que inicializa o sistema de auto-atendimento, exibindo o menu e executando as operações correspondentes até que o usuário opte por sair.*/

 int main() {
    int resp = 0;
    float valorDiaria = 100.0;
    FILE *arquivoCliente, *arquivoFuncionario, *arquivoQuarto, *arquivoEstadia;
    RESERVA reservas[MAX_RESERVAS];
    int totalReservas = 0;

    setlocale(LC_ALL, ""); // Definir a localização

    printf("\n\n___|Hotel Descanso Garantido|___\n\n");
    printf("Seja bem-vindo ao nosso sistema de Auto-Atendimento!\n");

    while (resp != 10) {
        opt(&resp);
        limparBuffer();

        switch (resp) {
            case 1:
                hotelInfo();
                break;
            case 2:
                arquivoCliente = fopen("clientes.txt", "a+");
                if (arquivoCliente == NULL) {
                    printf("Erro ao abrir o arquivo de clientes.\n");
                    break;
                }
                cadastrarCliente(arquivoCliente);
                fclose(arquivoCliente);
                break;
            case 3:
                arquivoQuarto = fopen("quartos.txt", "a+");
                if (arquivoQuarto == NULL) {
                    printf("Erro ao abrir o arquivo de quartos.\n");
                    break;
                }
                cadastrarQuarto(arquivoQuarto);
                fclose(arquivoQuarto);
                break;
            case 4:
                arquivoFuncionario = fopen("funcionarios.txt", "a+");
                if (arquivoFuncionario == NULL) {
                    printf("Erro ao abrir o arquivo de funcionários.\n");
                    break;
                }
                cadastrarFuncionario(arquivoFuncionario);
                fclose(arquivoFuncionario);
                break;
            case 5:
                arquivoEstadia = fopen("estadia.txt", "a+");
                arquivoCliente = fopen("clientes.txt", "a+");
                arquivoQuarto = fopen("quartos.txt", "a+");
                if (arquivoEstadia == NULL || arquivoCliente == NULL || arquivoQuarto == NULL) {
                    printf("Erro ao abrir algum arquivo necessário.\n");
                    break;
                }
                reservarEstadiaParaData(arquivoQuarto, arquivoCliente, arquivoEstadia, reservas, &totalReservas);
                fclose(arquivoCliente);
                fclose(arquivoEstadia);
                fclose(arquivoQuarto);
                break;
            case 6:
                arquivoCliente = fopen("clientes.txt", "r");
                if (arquivoCliente == NULL) {
                    printf("Erro ao abrir o arquivo de clientes para busca.\n");
                    break;
                }
                procurarCliente(arquivoCliente);
                fclose(arquivoCliente);
                break;
            case 7:
                arquivoFuncionario = fopen("funcionarios.txt", "r");
                if (arquivoFuncionario == NULL) {
                    printf("Erro ao abrir o arquivo de funcionários para busca.\n");
                    break;
                }
                procurarFuncionario(arquivoFuncionario);
                fclose(arquivoFuncionario);
                break;
            case 8:
                arquivoEstadia = fopen("estadia.txt", "a+");
                arquivoQuarto = fopen("quartos.txt", "a+");
                if (arquivoEstadia == NULL || arquivoQuarto == NULL) {
                    printf("Erro ao abrir arquivos de estadias ou quartos para dar baixa.\n");
                    break;
                }
                darBaixaEstadia(arquivoEstadia, arquivoQuarto);
                fclose(arquivoEstadia);
                fclose(arquivoQuarto);
                break;

            case 9:
                arquivoEstadia = fopen("estadia.txt", "a+");
                arquivoQuarto = fopen("quartos.txt", "a+");
                if (arquivoEstadia == NULL || arquivoQuarto == NULL) {
                    printf("Erro ao abrir algum arquivo necessário.\n");
                    break;
                }
               ocuparQuarto(arquivoQuarto, arquivoEstadia);
                fclose(arquivoEstadia);
                fclose(arquivoQuarto);
                break;
            case 10:
                printf("Saindo...");
                break;
            default:
                printf("Insira um valor válido!\n");
                break;
        }
    }

    return 0;
}




