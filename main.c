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
    int codigoQuarto;

}ESTADIA;

typedef struct{
    int codigoQuarto;
    int quantidadeHospedes;
    int valorDiaria;
    int status;
}QUARTO;

CLIENTE cadastrarCliente(CLIENTE *cliente){
    printf("C�digo do cliente:");
    scanf("%d", &cliente->codigo);
    printf("Nome do Cliente: ");
    scanf("%s", cliente->nome);
    printf("Sobrenome do cliente");
    scanf("%s", cliente->sobrenome);
    printf("Endere�o do cliente");
}

FUNCIONARIO cadastrarFuncionario(){
}

ESTADIA reservarEstadia(){
}

QUARTO cadastrarQuarto(){
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
    printf("\n\n___|Hotel Descanso G�rantido|___\n\n", setlocale(LC_ALL, ""));
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
        printf("Insira um valor v�lido!");
        break;
    }
    }

}
