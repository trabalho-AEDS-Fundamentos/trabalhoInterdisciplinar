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
    printf("C�digo do cliente:");
    scanf("%d",-> cliente.codigo);
    printf("Nome do Cliente: ");
    scanf("%s",& cliente.nome);
    printf("Sobrenome do cliente");
    scanf("%s",& cliente.sobrenome);
    printf("Endere�o do cliente");
}

ESTADIA reservarEstadia(){
}

QUARTO criarQuarto(){
}

void hotelInfo(){
    printf("Informa��es do Hotel\n\n");
    printf("Localiza��o: Centro de Itacar� - Bahia\n");
    printf("In�cio da di�ria: 14:00\n");
    printf("Fim da di�ria: 12:00\n");
    printf("Sejam bem-vindos ao Hotel Descanso Garantido!\nTenham uma �tima estadia!");
}

int opt(){
    printf("O que deseja fazer?\n");
    printf("(1) Informa��es do Hotel\n(2)Cadastrar Cliente\n(3) Cadastrar Quarto(4) Cadastrar Funcion�rio\n(5) Reservar Estadia\n(6) Finalizar");
}



int main()
{
    CLIENTE cliente[number];
    QUARTO quarto[number];
    ESTADIA estadia[number];
    FUNCIONARIO funcionario[number];
    printf("\n\n___|Hotel Descanso G�rantido|___\n\n");

}
