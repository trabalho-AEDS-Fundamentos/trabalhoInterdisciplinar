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

    printf("C�digo do cliente:");
    scanf("%d", &cliente.codigo);
    limparBuffer();

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
}

FUNCIONARIO cadastrarFuncionario(FILE *arquivo){

    printf("Cadastro do Funcion�rio \n");

    printf("C�digo do funcion�rio");
    scanf("%d",& FUNCIONARIO.codigo);
    limparBuffer();

    printf("Nome do funcion�rio: ");
    fgets(funcionario.nome, sizeof(funcionario.nome), stdin);
    funcionario.nome[strcspn(funcionario.nome, "\n")] = '\0';
    limparBuffer();

    printf("Sobrenome do funcion�rio: ");
    fgets(funcionario.nome, sizeof(funcionario.sobrenome), stdin);
    funcionario.sobrenome[strcspn(funcionario.sobrenome, "\n")] = '\0';
    limparBuffer();

    printf("Telefone do funcion�rio: ");
    scanf("%d",&FUNCIONARIO.telefone);
    limparBuffer();

    printf("Cargo do funcion�rio: ");
    fgets(funcionario.nome, sizeof(funcionario.cargo), stdin);
    funcionario.cargo[strcspn(funcionario.cargo, "\n")] = '\0';
    limparBuffer();

    //Escrevendo os dados do funcion�rio no arquivo.
    fprintf(arquivo, "C�digo: %d\n", funcionario.codigo);
    fprintf(arquivo, "Nome: %s\n", funcionario.nome);
    fprintf(arquivo, "Sobrenome: %s\n", funcionario.sobrenome);
    fprintf(arquivo, "Telefone: %d\n", funcionario.telefone);
    fprintf(arquivo, "Cargo: %s\n", funcionario.cargo);
    fprintf(arquivo, "Sal�rio: %d\n", funcionario.salario);


}

ESTADIA reservarEstadia(){

    int numeroquarto;
    printf("Reserva de Estadia \n");

    printf("C�digo da Estadia: ");
    scanf("%d",&ESTADIA.codigo);
    limparBuffer();

    printf("C�digo do Cliente: ");
    scanf("%d",&ESTADIA.codigoCliente);
    limparBuffer();

    printf("Data de entrada (Dia/M�s/Ano)");
    scanf("%d %d %d", & ESTADIA.entrada.dia, &ESTADIA.entrada.mes, &ESTADIA.entrada.ano);
    limparBuffer();

    printf("Data de sa�da (Dia/M�s/Ano)");
    scanf("%d %d %d",& ESTADIA.saida.dia, & ESTADIA.saida.mes, &ESTADIA.saida.ano);
    limparBuffer();

    printf("Quantidade de Di�rias: ");
    scanf("%d",&ESTADIA.diarias);
    limparBuffer();

    printf("N�mero do quarto: ");
    scanf("%d",&numeroquarto);

    //falta procurar o quarto no arquivo

}

QUARTO cadastrarQuarto(FILE *arquivo){

    printf("Cadastrar Quarto \n");
    printf("C�digo do Quarto: ");
    scanf("%d",&QUARTO.codigoQuarto);
    limparBuffer();

    printf("Quantidade de h�spedes: ");
    scanf("%d", &QUARTO.quantidadeHospedes);
    limparBuffer();

    printf("Valor da di�ria: ");
    scanf("%d",&QUARTO.valorDiaria);
    limparBuffer();

    //Escrevendo os dados do quarto no arquivo.
    fprintf(arquivo, "C�digo: %d \n", QUARTO.codigoQuarto);
    fprintf(arquivo, "Quantidade de H�spedes: %d \n", QUARTO.quantidadeHospedes);
    fprintf(arquivo, "Valor da di�ria %d \n", QUARTO.valorDiaria);

}


/**Fun��o que escreve as informa��es b�sicas do hotel.
   Como par�metro, temos o ponteiro do valor da di�ria.
*/
void hotelInfo(float *valor){
    printf("Informa��es do Hotel\n\n");
    printf("Localiza��o: Centro de Itacar� - Bahia\n");
    printf("Valor da di�ria: R$%.2f\n", *valor);
    printf("In�cio da di�ria: 14:00\n");
    printf("Fim da di�ria: 12:00\n");
    printf("Sejam bem-vindos ao Hotel Descanso Garantido!\nTenham uma �tima estadia!\n\n");
}

int opt(int *resp){
    printf("O que deseja fazer?\n");
    printf("(1) Informa��es do Hotel\n(2)Cadastrar Cliente\n(3) Cadastrar Quarto\n(4) Cadastrar Funcion�rio\n(5) Reservar Estadia\n(6) Finalizar\n");
    scanf("%d", resp);

    return *resp;
}



int main()
{
    int resp = 0;
    float valorDiaria = 100.0;
    FILE *arquivoCliente, *arquivoFuncionario;


    printf("\n\n___|Hotel Descanso G�rantido|___\n\n", setlocale(LC_ALL, ""));
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
        printf("Insira um valor v�lido!");
        break;
    }
    }

}
