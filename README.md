# **PONTIFÍCIA UNIVERSIDADE CATÓLICA DE MINAS GERAIS**
INSTITUTO DE CIÊNCIAS EXATAS E INFORMÁTICA

UNIDADE EDUCACIONAL PRAÇA DA LIBERDADE

Bacharelado em Engenharia de Software

# **Hotel Descanso Garantido**

Trabalho interdisciplinar das disciplinas: Algoritmos e Estrutura de Dados e Fundamentos de Engenharia de Software.

## Membros da equipe:
**Guilherme de Almeida Rocha Vieira**

**Lucas Gonçalves Dolabela**

## Introdução:

Software desenvolvido para facilitar a organização e melhorar a praticidade de cadastro de hóspedes para o Hotel Descanso Garantido

## Backlog do produto: 
Requisitos levantados para criação do sistema e quadro Kanban para organização das tarefas: 

https://github.com/orgs/trabalho-AEDS-Fundamentos/projects/1

## Sprints:

![image](https://github.com/trabalho-AEDS-Fundamentos/trabalhoInterdisciplinar/assets/104731949/8e0a3666-d861-423f-9677-9ac7283750fe)

A imagem acima mostra a Reunião do Planejamento da Sprint 1

Data da Sprint 1 - Até 22/06

![WhatsApp Image 2024-06-21 at 16 54 02_38be4158](https://github.com/trabalho-AEDS-Fundamentos/trabalhoInterdisciplinar/assets/104731949/56772271-6ed3-40ff-92b3-ddb51e6bfe56)

Essa imagem mostra uma reunião para tirarmos algumas dúvidas e resolver alguns problemas encontrados durante a implementação do código!

![image](https://github.com/trabalho-AEDS-Fundamentos/trabalhoInterdisciplinar/assets/104731949/f70d6934-3160-4a07-9127-07f06d30f2c3)


A imagem acima mostra a Reunião do Planejamento da Sprint 2

![image](https://github.com/trabalho-AEDS-Fundamentos/trabalhoInterdisciplinar/assets/104731949/17985e70-85a3-4ce4-87ac-7b10065d3575)

Essa imagem mostra a evolução no quadro Kanban em relação às tarefas das Sprints!


Data da Sprint 2 - Até 25/06

![image](https://github.com/trabalho-AEDS-Fundamentos/trabalhoInterdisciplinar/assets/104731949/607e37cc-6c57-4863-9be5-ac21d9efc394)

A imagem acima mostra a Reunião do Planejamento da Sprint 3

![image](https://github.com/trabalho-AEDS-Fundamentos/trabalhoInterdisciplinar/assets/104731949/e41f9a47-0b82-40fa-95d4-04e94b8b7b53)

Essa imagem mostra a evolução no quadro Kanban em relação às tarefas das Sprints!

Data da Sprint 3 - Até 28/06

## Lista de Assinaturas:

As funções e parâmetros utilizados no sistema foram:

1. void LimparBuffer()
   * Função para efetuar a limpeza do Buffer, permitindo a leitura após o uso do scanf(). Função sem retorno!
     
2. int verificarCodigoCliente(FILE *arquivoCliente, int codigo)
   * Função que verifica se o código do cliente já existe, impedindo o cadastro de mais de um cliente com o mesmo código, recebe como parâmetros o arquivo o qual os clientes são cadastrados e o código que foi inserido. A função retorna um código que apresenta os seguintes estados:
     0. Se o código não existe.
     1. Se já existe um cliente com esse código.
    
3. void cadastrarCliente(FILE *arquivoCliente)
   * Função que realiza o cadastro de clientes e salva no arquivo passado como parâmetro. Recebe como parâmetro o arquivo o qual os clientes serão cadastrados. Função sem retorno;
  
4. void procurarCliente(FILE *arquivoCliente)
   * Função que realiza a busca por determinado cliente, via código ou nome, no arquivo passado como parâmetro. Recebe como parâmetro o arquivo o qual os clientes estão cadastrados. Função sem retorno;

5. int verificarCodigoFuncionario(FILE *arquivoCliente, int codigo)
   * Função que verifica se o código do funcionário já existe, impedindo o cadastro de mais de um funcionário com o mesmo código, recebe como parâmetros o arquivo o qual os funcionários são cadastrados e o código que foi inserido. A função retorna um código que apresenta os seguintes estados:
     0. Se o código não existe.
     1. Se já existe um cliente com esse código.
    
6. void cadastrarFuncionario(FILE *arquivoFuncionario)
   * Função que realiza o cadastro de funcionários e salva no arquivo passado como parâmetro. Recebe como parâmetro o arquivo o qual os funcionários serão cadastrados. Função sem retorno;
  
7. void procurarFuncionario(FILE *arquivoFuncionario)
   * Função que realiza a busca por determinado cliente, via código ou nome, no arquivo passado como parâmetro. Recebe como parâmetro o arquivo o qual os clientes estão cadastrados. Função sem retorno;
  
8. int verificarNumeroQuarto(FILE *arquivoQuarto, int numero)
   * Função que verifica se o número do quarto já existe, impedindo mais de um quarto com a mesma numeração! Recebe como parâmetros o arquivo o qual os quartos são cadastrados e o número do quarto que foi inserido. A função retorna um código que apresenta os seguintes estados:
     0. Se o número do quarto não existe.
     1. Se já existe um quarto com determinado número.

9. void cadastrarQuarto(FILE *arquivoQuarto)
    * Função que realiza o cadastro de quartos e salva no arquivo passado como parâmetro. Recebe como parâmetro o arquivo o qual os quartos serão cadastrados. Função sem retorno;

10. int dataMenorOuIgual(DATA data1, DATA data2)
    * Função que compara duas datas e verifica se a primeira (data1) é menor do que a segunda (data2). Recebe como parâmetro a primeira data (data1), do tipo DATA, que tem como estrutura: dia, mês e ano, e recebe a segunda data(data2), também do tipo DATA. A função retorna um código que apresenta os seguintes estados:
     0. Se a data1 não for menor ou igual a data2
     1. Se a data1 for menor ou igual a data2
   
11. int dataMaiorOuIgual(DATA data1, DATA data2)
    * Função que compara duas datas e verifica se a primeira (data1) é maior do que a segunda (data2). Recebe como parâmetro a primeira data (data1), do tipo DATA, que tem como estrutura: dia, mês e ano, e recebe a segunda data(data2), também do tipo DATA. A função retorna um código que apresenta os seguintes estados:
     0. Se a data1 não for menor ou igual a data2
     1. Se a data1 for menor ou igual a data2

12. int quartoEstaDisponivel(FILE *arquivoEstadia, int numeroQuarto, DATA entrada, DATA saida)
    * Função que verifica se um quarto está disponível para reserva em um período específico. Recebe como parâmetro o arquivo estadia, que contém todos os dados das estadias, o número do quarto a ser verificado, a data de entrada e de saída do tipo DATA. A função retorna um código que apresenta os seguintes estados:
      0. Se o quarto não estiver disponível
      1. Se o quarto está disponível

13. void quartosDisponiveis(FILE *arquivoQuarto, FILE *arquivoEstadia, int quantidadeHospedes, DATA entrada, DATA saida)
    * Função que lista os quartos disponíveis para hospedagem, a partir da leitura dos dados do arquivo Quarto, considerando a quantidade de hóspedes, data de entrada e saída e o status do quarto. Recebe como parâmetros o arquivo o qual os quartos estão cadastrados, arquivo estadia, que contém os dados das estadias, quantidade de Hóspedes inseridos, a data de entrada e saída desejadas; Não possui retorno.

15. int verificarCodigoEstadia(FILE *arquivoEstadia, int codigo)
    * Função que verifica se o código da estadia já existe, impedindo mais de uma estadia com o mesmo código! Recebe como parâmetros o arquivo o qual as estadias são cadastrados e o código da estadia inserido. A função retorna um código que apresenta os seguintes estados:
     0. Se o código da estadia não existe.
     1. Se já existe uma estadia com determinado número.

16. float calcularValorEstadia(FILE *arquivoQuarto, FILE *arquivoEstadia, int codigoCliente)
    * Função que calcula o valor total da estadia de um cliente, mutiplicando a quantidade de diárias pelo valor da diária do quarto. Recebe como parâmetros os arquivos do quarto e da estadia para leitura e o código do cliente, para calcular o valor de sua estadia. Retorna o valor total.
   
17. int compararDatas(DATA d1, DATA d2)
    * Função que compara duas datas, recebe duas datas do tipo DATA e retorna a diferença entre elas (anos, meses, dias)
   
18. int reservasConflitam(RESERVA r1, RESERVA r2)
    * Função que verifica se duas reservas conflitam, ou seja, se há sobreposição de datas para o mesmo quarto. Recebe como parâmetros duas reservas do tipo RESERVA. A função retorna:
      0. Se não houver conflito.
      1. Se houver conflito na reserva. 

19. void reservarEstadiaParaData(FILE *arquivoQuarto, FILE *arquivoCliente, FILE *arquivoEstadia)
     * Função que realiza a reserva de uma estadia para um cliente, verificando a disponibilidade dos quartos, salva no arquivo passado como parâmetro e atualiza o status do quarto para ocupado. Recebe como parâmetro o arquivo que contém os dados dos quartos, o arquivo que contém os dados dos cliente e o arquivo o qual as estadias serão cadastrados. Função sem retorno;

20. void darBaixaEstadia(FILE *arquivoEstadia, FILE *arquivoQuarto)
    * Função que dá baixa em uma estadia, removendo-a e modificando o status do quarto para desocupado. Recebe como parâmetros o arquivo o qual as estadias estão cadastradas e o arquivo os quais os quartos estão cadatrados. Função sem retorno.

21. void ocuparQuarto(FILE *arquivoQuarto, FILE *arquivoEstadia)
    * Função que permite marcar um quarto como ocupado, quando os hóspedes fazerem o check-in. Recebe como parâmetros o arquivo os quais os quartos estão cadastrados e o arquivo o qual as estadias estão cadastradas. Função sem retorno.

22. void hotelInfo()
    * Função que retorna as Informações Principais do Hotel, tais como Localização, início e fim da diária; Não possui parâmetros e nem retorno.

23. int opt(int *resp)
    * Função que mostra o Menu Principal, com as opções do sistema. Recebe como parâmetro o ponteiro do endereço de resp e retorna o valor do ponteiro de resp.

24. int main()
    * Função principal que inicializa os arquivos e tem uma estrutura de repetição que permite a escolha do que o usuário quer fazer no sistema, sendo essas opções:
      - Informações do Hotel
      - Cadastrar Cliente
      - Cadastrar Quarto
      - Cadastrar Funcionário
      - Reservar Estadia
      - Pesquisar Cliente
      - Pesquisar Funcionário
      - Baixar Estadia
      - Ocupar Quarto
      - Finalizar
## Casos de Teste:
  
  | Teste | Entradas | Resultado Esperado | Resultado |
  | ----- | -------- | ------------------ | --------- |
  | Cadastro Cliente | Código: 1 / Nome: Guilherme / Sobrenome: Vieira / Endereço: Av Afonso Pena / Telefone: 99876523| Cliente cadastrado | Cliente Cadastrado |
  | Cadastro Cliente - Código Existente| Código: 1 / Nome: Pedro / Sobrenome: Santana / Endereço: Av Nossa Senhora do Carmo / Telefone: 998732154 | Já possui um cliente com esse código | Já possui um cliente com esse código |
  | Cadastrar Quarto | Número: 101 / Hóspedes: 4 / Diária: 350 | Quarto Cadastro | Quarto Cadastrado |
  | Cadastrar Quarto - Número Repetido | Número: 101 / Hóspedes: 6 / Diária: 500 | Já existe um quarto com esse número | Já existe um quarto com esse número |
  | Cadastrar Funcionário | Código: 1 / Nome: Pedro / Sobrenome: Afonso / Telefone: 987632154 / Cargo: Gerente / Salário: 20000 | Funcionário cadastrado com sucesso |  Funcionário cadastrado com sucesso |
  | Cadastrar Funcionário - Código Existente | Código: 1 / Nome: Caio / Sobrenome: Oliveira / Telefone: 987587324 / Cargo: Cozinheiro / Salário: 5000 | Já existe funcionário com esse código |  Já existe funcionário com esse código | 
  | Reservar Estadia | Código Cliente: 1 / Hóspedes: 4 / Entrada: 10/07/2024 / Saída: 20/07/2024 / Número Quarto: 101 / Código da Estadia: 1 | Estadia reservada com sucesso | Estadia reservada com sucesso|
| Reservar Estadia - Código cliente não existente | Código Cliente: 100 / Hóspedes: 4 / Entrada: 01/12/2024 / Saída: 10/12/2024 / Número Quarto: 101 / Código da Estadia: 4 | Esse cliente não está cadastrado! | Esse cliente não está cadastrado! |
| Reservar Estadia - Quantidade de Hóspedes maior do que a capacidade dos quartos | Código Cliente: 2 / Hóspedes: 40 / Entrada: 10/08/2024 / Saída: 30/08/2024 / Número Quarto: 101 / Código da Estadia: 2 | Nenhum quarto disponível! | Nenhum quarto disponível! |
| Reservar Estadia - Número do quarto não existente | Código Cliente: 1 / Hóspedes: 4 / Entrada: 05/01/2025 / Saída: 15/01/2025 / Número Quarto: 1001 / Código da Estadia: 1 | Quarto não encontrado! | Quarto não encontrado! |
| Reservar Estadia - Código de estadia repetido | Código Cliente: 3 / Hóspedes: 4 / Entrada: 15/10/2024 / Saída: 25/10/2024 / Número Quarto: 102 / Código da Estadia: 1 | Já existe uma estadia com esse código! | Já existe uma estadia com esse código! |
| Pesquisar Cliente - Código| Opção: 1 / Código Cliente: 1 | Mostra as informações desse cliente | Mostrou as informações desse cliente |
| Pesquisar Cliente - Código não existente| Opção: 1 / Código Cliente: 100 | Cliente não encontrado | Cliente não encontrado |
| Pesquisar Cliente - Nome| Opção: 2 / Nome do cliente: Lucas | Mostra as informações desse cliente | Mostrou as informações desse cliente |
| Pesquisar Cliente - Nome não existente| Opção: 2 / Nome do cliente: Jose | Cliente não encontrado! | Cliente não encontrado! |
| Pesquisar Funcionário - Código| Opção: 1 / Código Funcionário: 1 | Mostra as informações desse funcionário | Mostrou as informações desse funcionário |
| Pesquisar Funcionário - Código não existente| Opção: 1 / Código Cliente: 150 | Funcionário não encontrado | Funcionário não encontrado |
| Pesquisar Funcionário - Nome| Opção: 2 / Nome do cliente: Luis | Mostra as informações desse funcionário | Mostrou as informações desse funcionário |
| Pesquisar Funcionário - Nome não existente| Opção: 2 / Nome do cliente: Elias | Funcionário não encontrado! | Funcionário não encontrado! |
| Dar baixa na Estadia | Código da Estadia: 1 / Confirmar: S | Baixa realizada com sucesso | Baixa realizada com sucesso | 
| Dar baixa Estadia - Código da Estadia Não existente | Código da estadia: 999 / Estadia não encontrada | Estadia não encontrada |
| Ocupar quarto | Código Estadia: 1 | Status alterado para ocupado! | Status alterado para ocupado! |
| Ocupar quarto - Código Estadia não existente| Código Estadia: 100 | Estadia não encontrada | Estadia não encontrada |
| Menu Principal - Opção inválida | Opção: 20 | Insira uma opção válida! | Insira uma opção válida! |

