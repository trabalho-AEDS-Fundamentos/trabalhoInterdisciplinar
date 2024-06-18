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
typedef struct DATA{
    int dia;
    int mes;
    int ano;
}DATA;

typedef struct CLIENTE{
    int codigo;
    char nome[40], sobrenome[50];
    char endereco[100];
    int telefone;
}CLIENTE;

typedef struct FUNCIONARIO{
    int codigo;
    char nome[40], sobrenome[50];
    int telefone;
    char cargo[30];
    int salario;
}FUNCIONARIO;

typedef struct ESTADIA{
    int codigo;
    DATA entrada;
    DATA saida;
    int diarias;
    int codigoQuarto;

}ESTADIA;

typedef struct QUARTO{
    int codigoQuarto;
    int quantidadeHospedes;
    int valorDiaria;
    int status;
}QUARTO;

CLIENTE criarCliente(CLIENTE *cliente){
    printf("Código do cliente:");
    scanf("%d",-> cliente.codigo);
    printf("Nome do Cliente: ");
    scanf("%s",& cliente.nome);
    printf("Sobrenome do cliente");
    scanf("%s",& cliente.sobrenome);
    printf("Endereço do cliente");
}

ESTADIA reservarEstadia(){
}

QUARTO criarQuarto(){
}

void hotelInfo(){
    printf("Informações do Hotel\n\n");
    printf("Localização: Centro de Itacaré - Bahia\n");
    printf("Início da diária: 14:00\n");
    printf("Fim da diária: 12:00\n");
    printf("Sejam bem-vindos ao Hotel Descanso Garantido!\nTenham uma ótima estadia!");
}

int opt(){
    printf("O que deseja fazer?\n");
    printf("(1) Informações do Hotel\n(2)Cadastrar Cliente\n(3) Cadastrar Quarto(4) Cadastrar Funcionário\n(5) Reservar Estadia\n(6) Finalizar");
}



int main()
{
    CLIENTE cliente[number];
    QUARTO quarto[number];
    ESTADIA estadia[number];
    FUNCIONARIO funcionario[number];
    printf("\n\n___|Hotel Descanso Gárantido|___\n\n");

}
