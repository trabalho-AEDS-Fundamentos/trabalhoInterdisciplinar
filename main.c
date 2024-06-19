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
    int codigoQuarto;

}ESTADIA;

typedef struct{
    int codigoQuarto;
    int quantidadeHospedes;
    int valorDiaria;
    int status;
}QUARTO;

CLIENTE cadastrarCliente(CLIENTE *cliente){
    printf("Código do cliente:");
    scanf("%d", &cliente->codigo);
    printf("Nome do Cliente: ");
    scanf("%s", cliente->nome);
    printf("Sobrenome do cliente");
    scanf("%s", cliente->sobrenome);
    printf("Endereço do cliente");
}

FUNCIONARIO cadastrarFuncionario(){
}

ESTADIA reservarEstadia(){
}

QUARTO cadastrarQuarto(){
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

    return resp;
}



int main()
{
    int resp = 0;
    float valorDiaria = 100.0;
    CLIENTE cliente[number];
    QUARTO quarto[number];
    ESTADIA estadia[number];
    FUNCIONARIO funcionario[number];
    printf("\n\n___|Hotel Descanso Gárantido|___\n\n", setlocale(LC_ALL, ""));
    printf("Seja bem-vindo ao nosso sistema de Auto-Atendimento!\n");

    while(resp != 6){
    int response = opt(&resp);
    switch(response){
    case 1:
        hotelInfo(&valorDiaria);
        break;
    case 2:
        cadastrarCliente(cliente);
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
