    #include <stdio.h>
    #include <stdlib.h>
    #include <string.h>
    #include <locale.h>

    #define number 50
    #define max_funcionarios 100
    #define MAX_RESERVAS 100


/** Estrutura que representa uma data com dia, m�s e ano. */

    typedef struct {
        int dia;
        int mes;
        int ano;
    }DATA;


/** Estrutura que representa um cliente com c�digo, nome, sobrenome, endere�o e telefone. */

    typedef struct {
        int codigo;
        char nome[40], sobrenome[50];
        char endereco[100];
        int telefone;
    }CLIENTE;


/** Estrutura que representa um funcion�rio com c�digo, nome, sobrenome, telefone, cargo e sal�rio. */

    typedef struct {
        int codigo;
        char nome[40], sobrenome[50];
        int telefone;
        char cargo[30];
        float salario;
    }FUNCIONARIO;


/** Estrutura que representa uma estadia com c�digo, datas de entrada e sa�da, n�mero de di�rias, c�digo do cliente e n�mero do quarto. */

    typedef struct {
        int codigo;
        DATA entrada;
        DATA saida;
        int diarias;
        int codigoCliente;
        int numeroQuarto;

    }ESTADIA;


/** Estrutura que representa um quarto com n�mero, quantidade de h�spedes, valor da di�ria e status. */

    typedef struct{
        int numeroQuarto;
        int quantidadeHospedes;
        float valorDiaria;
        char status[15];
    }QUARTO;


/** Estrutura que representa uma reserva com c�digo do cliente, c�digo da estadia, n�mero do quarto, datas de entrada e sa�da e n�mero de di�rias. */

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


/** Verifica se um c�digo de cliente j� est� cadastrado no arquivo.
* FILE *arquivo: Ponteiro para o arquivo que cont�m os dados dos clientes.
* int codigo: C�digo do cliente a ser verificado.
* Retorno: 1 se o c�digo j� existir, 0 caso contr�rio. */

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


/** Cadastra um novo cliente no arquivo, verificando se o c�digo do cliente j� existe.
* FILE *arquivo: Ponteiro para o arquivo que cont�m os dados dos clientes. */

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


/** Procura um cliente no arquivo pelo c�digo ou nome.
* FILE *arquivo: Ponteiro para o arquivo que cont�m os dados dos clientes.
* int opcao: Op��o de pesquisa (1 para c�digo, 2 para nome). */

void procurarCliente(FILE *arquivo) {
    CLIENTE cliente[max_funcionarios];
    char nome[40];
    int codigo, encontrado = 0, opcao, num_cliente = 0;

    printf("\nProcurar Cliente\n");
    printf("Pesquisar por (1) C�digo (2) Nome? ");
    scanf("%d", &opcao);
    limparBuffer();
    rewind(arquivo);

    // Lendo os dados do arquivo
    while (fscanf(arquivo, "C�digo: %d\n", &cliente[num_cliente].codigo) == 1) {
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
                printf("\nCliente Encontrado:\n");
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
        printf("Cliente n�o encontrado!\n");
    }
}


/** Verifica se um c�digo de funcion�rio j� existe no arquivo.
* arquivo (FILE*): Ponteiro para o arquivo que cont�m os registros dos funcion�rios.
* codigo (int): C�digo do funcion�rio que se deseja verificar.
* Retorna 1 se o c�digo j� existe, caso contr�rio, retorna 0. */

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


/** Cadastra um novo funcion�rio no arquivo.
*arquivo (FILE*): Ponteiro para o arquivo onde os registros dos funcion�rios ser�o armazenados. */

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

/** Procura por um funcion�rio no arquivo de dados dos funcion�rios, permitindo a busca por c�digo ou nome.
* arquivo (FILE*): Ponteiro para o arquivo que cont�m os registros dos funcion�rios. */

    void procurarFuncionario(FILE *arquivo) {
    FUNCIONARIO funcionario[max_funcionarios];
    char nome[40];
    int codigo, encontrado = 0, opcao, num_funcionario = 0;

    printf("\nProcurar Funcion�rio\n");
    printf("Pesquisar por (1) C�digo (2) Nome ? ");
    scanf("%d", &opcao);
    limparBuffer();
    rewind(arquivo);

    // Lendo os dados do arquivo
    while (fscanf(arquivo, "C�digo: %d\n", &funcionario[num_funcionario].codigo) == 1) {
        fscanf(arquivo, "Nome: %[^\n]\n", funcionario[num_funcionario].nome);
        fscanf(arquivo, "Sobrenome: %[^\n]\n", funcionario[num_funcionario].sobrenome);
        fscanf(arquivo, "Telefone: %d\n", &funcionario[num_funcionario].telefone);
        fscanf(arquivo, "Cargo: %[^\n]\n", funcionario[num_funcionario].cargo);
        fscanf(arquivo, "Sal�rio: R$%f\n", &funcionario[num_funcionario].salario);
        fscanf(arquivo, "---------------------\n");

        num_funcionario++;

        if (num_funcionario >= max_funcionarios) {
            printf("Limite m�ximo de funcion�rios atingido.\n");
            break;
        }
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


/** Verifica se um n�mero de quarto j� existe no arquivo de dados dos quartos.
* arquivo (FILE*): Ponteiro para o arquivo que cont�m os registros dos quartos.
* numero (int): N�mero do quarto que se deseja verificar.
* Retorna 1 se o n�mero do quarto j� existe no arquivo caso contr�rio  retorna 0 se o n�mero do quarto n�o for encontrado no arquivo. */

    int verificarNumeroQuarto(FILE *arquivo, int numero) {
        QUARTO quarto;

        // Posiciona no in�cio do arquivo
        rewind(arquivo);

        // Vari�vel para indicar se encontrou o n�mero do quarto
        int encontrado = 0;

        // L� cada registro do arquivo
        while (fscanf(arquivo, "N�mero do quarto: %d\n", &quarto.numeroQuarto) == 1) {
            fscanf(arquivo, "Quantidade de H�spedes: %d\n", &quarto.quantidadeHospedes);
            fscanf(arquivo, "Valor da di�ria: R$%f\n", &quarto.valorDiaria);
            fscanf(arquivo, "Status: %[^\n]\n", quarto.status);
            fscanf(arquivo, "---------------------\n");

            // Verifica se o n�mero do quarto � igual ao n�mero passado como par�metro
            if (quarto.numeroQuarto == numero) {
                encontrado = 1;
                break;
            }
        }

        return encontrado;
    }


/**Cadastra um novo quarto no arquivo de dados dos quartos.
* arquivo (FILE*): Ponteiro para o arquivo onde os registros dos quartos ser�o armazenados. */

    void cadastrarQuarto(FILE *arquivo) {
        QUARTO quarto;
        char status[] = "desocupado";
        int numeroValido;

        do{
            printf("N�mero do quarto: ");
            scanf("%d", &quarto.numeroQuarto);

            int existe = verificarNumeroQuarto(arquivo, quarto.numeroQuarto);
            if(existe == 1){
                printf("J� existe um quarto com esse n�mero!\n");
                numeroValido = 0;
            }else{
                numeroValido = 1;
            }
        }while(numeroValido != 1);

        fprintf(arquivo, "N�mero do quarto: %d\n", quarto.numeroQuarto);

        printf("Quantidade de h�spedes: ");
        scanf("%d", &quarto.quantidadeHospedes);
        fprintf(arquivo, "Quantidade de H�spedes: %d\n", quarto.quantidadeHospedes);

        printf("Valor da di�ria: R$");
        scanf("%f", &quarto.valorDiaria);
        fprintf(arquivo, "Valor da di�ria: R$%.2f\n", quarto.valorDiaria);

        fprintf(arquivo, "Status: %s\n", status);
        fprintf(arquivo, "---------------------\n");
        printf("Quarto registrado com sucesso!\n\n");


    }


/** Compara duas datas para verificar se a primeira � menor ou igual � segunda.
* data1 (DATA): Primeira data a ser comparada.
* data2 (DATA): Segunda data a ser comparada.
* Retorna 1 se a primeira data for menor ou igual � segunda caso contr�rio retorna 0 se a primeira data for maior que a segunda. */

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


/** Compara duas datas para verificar se a primeira � menor ou igual � segunda.
* data1 (DATA): Primeira data a ser comparada.
* data2 (DATA): Segunda data a ser comparada.
* Retorna 1 se a primeira data for menor ou igual � segunda caso contr�rio retorna 0 se a primeira data for maior que a segunda. */

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

/** Verifica se um quarto est� dispon�vel para um determinado per�odo.
* arquivoEstadia (FILE*): Ponteiro para o arquivo que cont�m os registros das estadias.
* numeroQuarto (int): N�mero do quarto a ser verificado.
* entrada (DATA): Data de entrada desejada.
* saida (DATA): Data de sa�da desejada.
* Retorna 1 se o quarto estiver dispon�vel no per�odo especificado caso contr�rio retorna 0 se o quarto n�o estiver dispon�vel no per�odo especificado. */

    int quartoEstaDisponivel(FILE *arquivoEstadia, int numeroQuarto, DATA entrada, DATA saida) {
    ESTADIA estadia;
    rewind(arquivoEstadia);
    while (fscanf(arquivoEstadia, "C�digo: %d\n", &estadia.codigo) == 1) {
        fscanf(arquivoEstadia, "Data de Entrada: %d/%d/%d\n", &estadia.entrada.dia, &estadia.entrada.mes, &estadia.entrada.ano);
        fscanf(arquivoEstadia, "Data de Sa�da: %d/%d/%d\n", &estadia.saida.dia, &estadia.saida.mes, &estadia.saida.ano);
        fscanf(arquivoEstadia, "Di�rias: %d\n", &estadia.diarias);
        fscanf(arquivoEstadia, "C�digo do Cliente: %d\n", &estadia.codigoCliente);
        fscanf(arquivoEstadia, "N�mero do Quarto: %d\n", &estadia.numeroQuarto);
        fscanf(arquivoEstadia, "---------------------\n");

        if (estadia.numeroQuarto == numeroQuarto &&
            (entrada.ano <= estadia.saida.ano && entrada.mes <= estadia.saida.mes && entrada.dia <= estadia.saida.dia) &&
            (saida.ano >= estadia.entrada.ano && saida.mes >= estadia.entrada.mes && saida.dia >= estadia.entrada.dia)) {
            return 0;
        }
    }
    return 1;
}


/** Exibe os quartos dispon�veis para uma determinada quantidade de h�spedes e per�odo.
* arquivoQuarto (FILE*): Ponteiro para o arquivo que cont�m os registros dos quartos.
* arquivoEstadia (FILE*): Ponteiro para o arquivo que cont�m os registros das estadias.
* qntHospedes (int): Quantidade de h�spedes desejada.
* entrada (DATA): Data de entrada desejada.
* saida (DATA): Data de sa�da desejada.*/

void quartosDisponiveis(FILE *arquivoQuarto, FILE *arquivoEstadia, int qntHospedes, DATA entrada, DATA saida) {
    QUARTO quarto;
    RESERVA reserva;
    int disponivel;

    rewind(arquivoQuarto);
    printf("Quartos dispon�veis:\n");
    while (fscanf(arquivoQuarto, "N�mero do quarto: %d\n", &quarto.numeroQuarto) == 1) {
        fscanf(arquivoQuarto, "Quantidade de H�spedes: %d\n", &quarto.quantidadeHospedes);
        fscanf(arquivoQuarto, "Valor da di�ria: R$%f\n", &quarto.valorDiaria);
        fscanf(arquivoQuarto, "Status: %[^\n]\n", quarto.status);
        fscanf(arquivoQuarto, "---------------------\n");

        if (quarto.quantidadeHospedes >= qntHospedes) {
            disponivel = 1;
            rewind(arquivoEstadia);
            while (fscanf(arquivoEstadia, "C�digo: %d\n", &reserva.codigoEstadia) == 1) {
                fscanf(arquivoEstadia, "Data de Entrada: %02d/%02d/%02d\n", &reserva.entrada.dia, &reserva.entrada.mes, &reserva.entrada.ano);
                fscanf(arquivoEstadia, "Data de Sa�da: %02d/%02d/%02d\n", &reserva.saida.dia, &reserva.saida.mes, &reserva.saida.ano);
                fscanf(arquivoEstadia, "Di�rias: %d\n", &reserva.diarias);
                fscanf(arquivoEstadia, "C�digo do Cliente: %d\n", &reserva.codigoCliente);
                fscanf(arquivoEstadia, "N�mero do Quarto: %d\n", &reserva.numeroQuarto);
                fscanf(arquivoEstadia, "---------------------\n");

                if (quarto.numeroQuarto == reserva.numeroQuarto && reservasConflitam(reserva, (RESERVA) { .entrada = entrada, .saida = saida })) {
                    disponivel = 0;
                    break;
                }
            }
            if (disponivel) {
                printf("N�mero do quarto: %d\n", quarto.numeroQuarto);
                printf("Quantidade de H�spedes: %d\n", quarto.quantidadeHospedes);
                printf("Valor da di�ria: R$%.2f\n", quarto.valorDiaria);
                printf("---------------------\n");
            }
        }
    }
}


/** Verifica se um c�digo de estadia j� existe no arquivo de dados das estadias.
* arquivo (FILE*): Ponteiro para o arquivo que cont�m os registros das estadias.
* codigo (int): C�digo da estadia que se deseja verificar.
* Retorna 1 se o c�digo j� existe no arquivo.
* Retorna 0 se o c�digo n�o for encontrado no arquivo. */

    int verificarCodigoEstadia(FILE *arquivo, int codigo){
        ESTADIA estadia;

        rewind(arquivo);

        while(fscanf(arquivo, "C�digo: %d\n", &estadia.codigo) == 1){
            fscanf(arquivo, "Data de Entrada: %02d/%02d/%02d\n", estadia.entrada.dia,estadia.entrada.mes, estadia.entrada.ano);
            fscanf(arquivo, "Data de Sa�da: %02d/%02d/%02d\n", estadia.saida.dia,estadia.saida.mes, estadia.saida.ano);
            fscanf(arquivo, "Di�rias: %d\n", &estadia.diarias);
            fscanf(arquivo, "C�digo do Cliente: %d\n", &estadia.codigoCliente);
            fscanf(arquivo, "N�mero do Quarto: %d\n", &estadia.numeroQuarto);
            fscanf(arquivo, "---------------------\n");

            if(estadia.codigo == codigo){
                return 1;
            }
        }
        return 0;
    }


/** Calcula o valor total da estadia de um cliente espec�fico, multiplicando a quantidade de di�rias pelo valor da di�ria do quarto correspondente.
* arquivoQuarto (FILE*): Arquivo que cont�m os dados dos quartos.
* arquivoEstadia (FILE*): Arquivo que cont�m os dados das estadias.
* codigoCliente (int): C�digo do cliente cuja estadia ser� calculada.
* (float): Valor total da estadia do cliente. */

float calcularValorEstadia(FILE *arquivoQuarto, FILE *arquivoEstadia, int codigoCliente) {
    ESTADIA estadia;
    QUARTO quarto;
    float valorTotal = 0.0;

    rewind(arquivoEstadia);
    rewind(arquivoQuarto);

    while (fscanf(arquivoEstadia, "C�digo: %d\n", &estadia.codigo) == 1) {
        fscanf(arquivoEstadia, "Data de Entrada: %02d/%02d/%02d\n", &estadia.entrada.dia, &estadia.entrada.mes, &estadia.entrada.ano);
        fscanf(arquivoEstadia, "Data de Sa�da: %02d/%02d/%02d\n", &estadia.saida.dia, &estadia.saida.mes, &estadia.saida.ano);
        fscanf(arquivoEstadia, "Di�rias: %d\n", &estadia.diarias);
        fscanf(arquivoEstadia, "C�digo do Cliente: %d\n", &estadia.codigoCliente);
        fscanf(arquivoEstadia, "N�mero do Quarto: %d\n", &estadia.numeroQuarto);
        fscanf(arquivoEstadia, "---------------------\n");

        if (estadia.codigoCliente == codigoCliente) {
            while (fscanf(arquivoQuarto, "N�mero do quarto: %d\n", &quarto.numeroQuarto) == 1) {
                fscanf(arquivoQuarto, "Quantidade de H�spedes: %d\n", &quarto.quantidadeHospedes);
                fscanf(arquivoQuarto, "Valor da di�ria: R$%f\n", &quarto.valorDiaria);
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


/** Compara duas datas e retorna a diferen�a entre elas.
*d1 (DATA): Primeira data.
*d2 (DATA): Segunda data.
* (int): Diferen�a entre as datas (anos, meses, dias). */

int compararDatas(DATA d1, DATA d2) {
    if (d1.ano != d2.ano) return d1.ano - d2.ano;
    if (d1.mes != d2.mes) return d1.mes - d2.mes;
    return d1.dia - d2.dia;
}


/** Verifica se duas reservas conflitam, ou seja, se h� sobreposi��o de datas para o mesmo quarto.
* r1 (RESERVA): Primeira reserva.
* r2 (RESERVA): Segunda reserva.
* (int): 1 se houver conflito, 0 caso contr�rio. */

int reservasConflitam(RESERVA r1, RESERVA r2) {
    if (r1.numeroQuarto != r2.numeroQuarto) return 0;
    if (compararDatas(r1.saida, r2.entrada) <= 0 || compararDatas(r2.saida, r1.entrada) <= 0) return 0;
    return 1;
}


/** Permite que um cliente fa�a uma reserva para uma determinada data, verificando conflitos e disponibilidade.
* arquivoQuarto (FILE*): Arquivo que cont�m os dados dos quartos.
* arquivoCliente (FILE*): Arquivo que cont�m os dados dos clientes.
* arquivoEstadia (FILE*): Arquivo que cont�m os dados das estadias.
* reservas (RESERVA[]): Vetor de reservas.
* totalReservas (int*): Ponteiro para o total de reservas. */

void reservarEstadiaParaData(FILE *arquivoQuarto, FILE *arquivoCliente, FILE *arquivoEstadia, RESERVA reservas[], int *totalReservas) {
    RESERVA novaReserva;
    int qntHospedes;
    printf("\n_Reservar Estadia para uma Data_\n");

    do {
        printf("Digite o c�digo do cliente: ");
        scanf("%d", &novaReserva.codigoCliente);
        limparBuffer();
        if (!verificarCodigoCliente(arquivoCliente, novaReserva.codigoCliente)) {
            printf("Esse cliente n�o est� cadastrado! Insira um c�digo v�lido!\n");
        }
    } while (!verificarCodigoCliente(arquivoCliente, novaReserva.codigoCliente));

    printf("Digite quantos h�spedes ir�o se hospedar: ");
    scanf("%d", &qntHospedes);
    limparBuffer();

    printf("Data de Entrada (dd/mm/aaaa): ");
    scanf("%d/%d/%d", &novaReserva.entrada.dia, &novaReserva.entrada.mes, &novaReserva.entrada.ano);
    limparBuffer();

    printf("Data de Sa�da (dd/mm/aaaa): ");
    scanf("%d/%d/%d", &novaReserva.saida.dia, &novaReserva.saida.mes, &novaReserva.saida.ano);
    limparBuffer();

    quartosDisponiveis(arquivoQuarto, arquivoEstadia, qntHospedes, novaReserva.entrada, novaReserva.saida);

    do {
        printf("Digite o n�mero do quarto desejado: ");
        scanf("%d", &novaReserva.numeroQuarto);
        limparBuffer();
        if (!verificarNumeroQuarto(arquivoQuarto, novaReserva.numeroQuarto)) {
            printf("Esse quarto n�o est� cadastrado! Insira um n�mero v�lido!\n");
        } else if (!quartoEstaDisponivel(arquivoEstadia, novaReserva.numeroQuarto, novaReserva.entrada, novaReserva.saida)) {
            printf("Esse quarto j� est� reservado para as datas escolhidas! Escolha outro quarto ou outra data.\n");
        }
    } while (!verificarNumeroQuarto(arquivoQuarto, novaReserva.numeroQuarto) || !quartoEstaDisponivel(arquivoEstadia, novaReserva.numeroQuarto, novaReserva.entrada, novaReserva.saida));

    do {
        printf("Digite o c�digo da estadia: ");
        scanf("%d", &novaReserva.codigoEstadia);
        limparBuffer();
        if (verificarCodigoEstadia(arquivoEstadia, novaReserva.codigoEstadia)) {
            printf("Esse c�digo de estadia j� est� em uso! Insira um c�digo v�lido!\n");
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
    fprintf(arquivoEstadia, "C�digo: %d\n", novaReserva.codigoEstadia);
    fprintf(arquivoEstadia, "Data de Entrada: %02d/%02d/%02d\n", novaReserva.entrada.dia, novaReserva.entrada.mes, novaReserva.entrada.ano);
    fprintf(arquivoEstadia, "Data de Sa�da: %02d/%02d/%02d\n", novaReserva.saida.dia, novaReserva.saida.mes, novaReserva.saida.ano);
    fprintf(arquivoEstadia, "Di�rias: %d\n", novaReserva.diarias);
    fprintf(arquivoEstadia, "C�digo do Cliente: %d\n", novaReserva.codigoCliente);
    fprintf(arquivoEstadia, "N�mero do Quarto: %d\n", novaReserva.numeroQuarto);
    fprintf(arquivoEstadia, "---------------------\n");
    fclose(arquivoEstadia);

    printf("Reserva realizada com�sucesso!\n");
}


/** D� baixa em uma estadia, marcando o quarto correspondente como desocupado.
* arquivoEstadia (FILE*): Arquivo que cont�m os dados das estadias.
* arquivoQuarto (FILE*): Arquivo que cont�m os dados dos quartos. */

void darBaixaEstadia(FILE *arquivoEstadia, FILE *arquivoQuarto) {
    int codigoEstadia, encontrado = 0;
    QUARTO quarto;
    ESTADIA estadia;

    printf("\n__Dar Baixa na Estadia__\n");

    printf("Digite o c�digo da estadia para dar baixa: ");
    scanf("%d", &codigoEstadia);
    limparBuffer();

    FILE *tempFile = fopen("temp.txt", "w");
    if (tempFile == NULL) {
        printf("Erro ao abrir arquivo tempor�rio!\n");
        return;
    }
    FILE *tempFile1 = fopen("temp1.txt", "w");
    if (tempFile1 == NULL) {
        printf("Erro ao abrir arquivo tempor�rio!\n");
        return;
    }

    rewind(arquivoEstadia);

    while (fscanf(arquivoEstadia, "C�digo: %d\n", &estadia.codigo) == 1) {
        fscanf(arquivoEstadia, "Data de Entrada: %d/%d/%d\n", &estadia.entrada.dia, &estadia.entrada.mes, &estadia.entrada.ano);
        fscanf(arquivoEstadia, "Data de Sa�da: %d/%d/%d\n", &estadia.saida.dia, &estadia.saida.mes, &estadia.saida.ano);
        fscanf(arquivoEstadia, "Di�rias: %d\n", &estadia.diarias);
        fscanf(arquivoEstadia, "C�digo do Cliente: %d\n", &estadia.codigoCliente);
        fscanf(arquivoEstadia, "N�mero do Quarto: %d\n", &estadia.numeroQuarto);
        fscanf(arquivoEstadia, "---------------------\n");

        if (estadia.codigo == codigoEstadia) {
            encontrado = 1;

            rewind(arquivoQuarto);
            while (fscanf(arquivoQuarto, "N�mero do quarto: %d\n", &quarto.numeroQuarto) == 1) {
                fscanf(arquivoQuarto, "Quantidade de H�spedes: %d\n", &quarto.quantidadeHospedes);
                fscanf(arquivoQuarto, "Valor da di�ria: R$%f\n", &quarto.valorDiaria);
                fscanf(arquivoQuarto, "Status: %[^\n]\n", quarto.status);
                fscanf(arquivoQuarto, "---------------------\n");

                if (quarto.numeroQuarto == estadia.numeroQuarto) {
                    fprintf(tempFile, "N�mero do quarto: %d\n", quarto.numeroQuarto);
                    fprintf(tempFile, "Quantidade de H�spedes: %d\n", quarto.quantidadeHospedes);
                    fprintf(tempFile, "Valor da di�ria: R$%.2f\n", quarto.valorDiaria);
                    fprintf(tempFile, "Status: desocupado\n");
                    fprintf(tempFile, "---------------------\n");
                } else {
                    fprintf(tempFile, "N�mero do quarto: %d\n", quarto.numeroQuarto);
                    fprintf(tempFile, "Quantidade de H�spedes: %d\n", quarto.quantidadeHospedes);
                    fprintf(tempFile, "Valor da di�ria: R$%.2f\n", quarto.valorDiaria);
                    fprintf(tempFile, "Status: %s\n", quarto.status);
                    fprintf(tempFile, "---------------------\n");
                }
            }

            printf("Estadia encontrada:\n");
            printf("C�digo: %d\n", estadia.codigo);
            printf("Data de Entrada: %02d/%02d/%02d\n", estadia.entrada.dia, estadia.entrada.mes, estadia.entrada.ano);
            printf("Data de Sa�da: %02d/%02d/%02d\n", estadia.saida.dia, estadia.saida.mes, estadia.saida.ano);
            printf("Di�rias: %d\n", estadia.diarias);
            printf("C�digo do Cliente: %d\n", estadia.codigoCliente);
            printf("N�mero do Quarto: %d\n", estadia.numeroQuarto);
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
            fprintf(tempFile1, "C�digo: %d\n", estadia.codigo);
            fprintf(tempFile1, "Data de Entrada: %02d/%02d/%02d\n", estadia.entrada.dia, estadia.entrada.mes, estadia.entrada.ano);
            fprintf(tempFile1, "Data de Sa�da: %02d/%02d/%02d\n", estadia.saida.dia, estadia.saida.mes, estadia.saida.ano);
            fprintf(tempFile1, "Di�rias: %d\n", estadia.diarias);
            fprintf(tempFile1, "C�digo do Cliente: %d\n", estadia.codigoCliente);
            fprintf(tempFile1, "N�mero do Quarto: %d\n", estadia.numeroQuarto);
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
        printf("Estadia n�o encontrada!\n");
    }
}


/** Marca um quarto como ocupado para uma estadia espec�fica.
* arquivoQuarto (FILE*): Arquivo que cont�m os dados dos quartos.
* arquivoEstadia (FILE*): Arquivo que cont�m os dados das estadias. */

void ocuparQuarto(FILE *arquivoQuarto, FILE *arquivoEstadia){
     rewind(arquivoQuarto);
    FILE *tempFile = fopen("temp.txt", "w");
    if (tempFile == NULL) {
        printf("Erro ao abrir arquivo tempor�rio!\n");
        return;
    }

    int codigoEstadia, encontrado = 0;
    ESTADIA estadia;

    printf("\n__Ocupar Quarto__\n");
    printf("Digite o c�digo da estadia a ocupar: ");
    scanf("%d", &codigoEstadia);
    limparBuffer();

    rewind(arquivoEstadia);

    while (fscanf(arquivoEstadia, "C�digo: %d\n", &estadia.codigo) == 1) {
        fscanf(arquivoEstadia, "Data de Entrada: %d/%d/%d\n", &estadia.entrada.dia, &estadia.entrada.mes, &estadia.entrada.ano);
        fscanf(arquivoEstadia, "Data de Sa�da: %d/%d/%d\n", &estadia.saida.dia, &estadia.saida.mes, &estadia.saida.ano);
        fscanf(arquivoEstadia, "Di�rias: %d\n", &estadia.diarias);
        fscanf(arquivoEstadia, "C�digo do Cliente: %d\n", &estadia.codigoCliente);
        fscanf(arquivoEstadia, "N�mero do Quarto: %d\n", &estadia.numeroQuarto);
        fscanf(arquivoEstadia, "---------------------\n");

        if (estadia.codigo == codigoEstadia) {
            encontrado = 1;
            break;
        }
    }

    if (!encontrado) {
        printf("Estadia com c�digo %d n�o encontrada!\n", codigoEstadia);
        fclose(tempFile);
        return;
    }

    QUARTO quarto;
    while (fscanf(arquivoQuarto, "N�mero do quarto: %d\n", &quarto.numeroQuarto) == 1) {
        fscanf(arquivoQuarto, "Quantidade de H�spedes: %d\n", &quarto.quantidadeHospedes);
        fscanf(arquivoQuarto, "Valor da di�ria: R$%f\n", &quarto.valorDiaria);
        fscanf(arquivoQuarto, "Status: %[^\n]\n", quarto.status);
        fscanf(arquivoQuarto, "---------------------\n");

        if (quarto.numeroQuarto == estadia.numeroQuarto) {
            fprintf(tempFile, "N�mero do quarto: %d\n", quarto.numeroQuarto);
            fprintf(tempFile, "Quantidade de H�spedes: %d\n", quarto.quantidadeHospedes);
            fprintf(tempFile, "Valor da di�ria: R$%.2f\n", quarto.valorDiaria);
            fprintf(tempFile, "Status: ocupado\n");
            fprintf(tempFile, "---------------------\n");
        } else {
            fprintf(tempFile, "N�mero do quarto: %d\n", quarto.numeroQuarto);
            fprintf(tempFile, "Quantidade de H�spedes: %d\n", quarto.quantidadeHospedes);
            fprintf(tempFile, "Valor da di�ria: R$%.2f\n", quarto.valorDiaria);
            fprintf(tempFile, "Status: %s\n", quarto.status);
            fprintf(tempFile, "---------------------\n");
        }
    }

    fclose(arquivoQuarto);
    fclose(tempFile);
    remove("quartos.txt");
    rename("temp.txt", "quartos.txt");
}


/** Exibe informa��es gerais sobre o hotel.*/

void hotelInfo(){
    printf("Informa��es do Hotel\n\n");
    printf("Localiza��o: Centro de Itacar� - Bahia\n");
    printf("In�cio da di�ria: 14:00\n");
    printf("Fim da di�ria: 12:00\n");
    printf("Sejam bem-vindos ao Hotel Descanso Garantido!\nTenham uma �tima estadia!\n\n");
}


/** Exibe o menu principal e captura a op��o selecionada pelo usu�rio.
* resp (int*): Ponteiro para a vari�vel que armazena a op��o selecionada.
* retorna (int): Op��o selecionada. */

int opt(int *resp)
{
    printf("\nMenu Principal\n");
    printf("(1) Informa��es do Hotel\n(2) Cadastrar Cliente\n(3) Cadastrar Quarto\n(4) Cadastrar Funcion�rio\n(5) Reservar Estadia\n(6) Pesquisar Cliente\n(7) Pesquisar Funcion�rio\n(8) Dar Baixa\n(9) Ocupar Quarto\n(10) Sair\n");
    scanf("%d", resp);
    return *resp;
}


/** Fun��o principal que inicializa o sistema de auto-atendimento, exibindo o menu e executando as opera��es correspondentes at� que o usu�rio opte por sair.*/

 int main() {
    int resp = 0;
    float valorDiaria = 100.0;
    FILE *arquivoCliente, *arquivoFuncionario, *arquivoQuarto, *arquivoEstadia;
    RESERVA reservas[MAX_RESERVAS];
    int totalReservas = 0;

    setlocale(LC_ALL, ""); // Definir a localiza��o

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
                    printf("Erro ao abrir o arquivo de funcion�rios.\n");
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
                    printf("Erro ao abrir algum arquivo necess�rio.\n");
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
                    printf("Erro ao abrir o arquivo de funcion�rios para busca.\n");
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
                    printf("Erro ao abrir algum arquivo necess�rio.\n");
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
                printf("Insira um valor v�lido!\n");
                break;
        }
    }

    return 0;
}




