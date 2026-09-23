#include <stdio.h>
#include <stdlib.h>

int main() {

	char nome_completo[100];
	char email[50];
	char cpf[16];
	int total_clientes;
	int dia, mes, ano;
	int salario;
	char telefone[20];

	int parcelas;
	float valor_parcela;
	float renda = 1;
	int valido = 0;
	float valor_max_financiado;
	float entrada_minima;

	float preco_veiculo = 0;
	float preco_moto = 0;
	float preco_carro = 0;
	int modelo;
	int tipo_veiculo;
	float renda_limite;

	int total_aprovados = 0;
	int total_negados = 0;

	printf("Quantos clientes deseja cadastrar? ");
	scanf("%d", &total_clientes);
	getchar();
	system("clear");

	for (int cont = 0; cont < total_clientes; cont++) {
		valido = 0;

		preco_carro = 0;
		preco_moto = 0;
		preco_veiculo = 0;

		printf("\n CADASTRO DO CLIENTE %d DE %d \n", cont + 1, total_clientes);

		printf("\n FAÇA SEU CADASTRO");

		printf("\nDigite seu nome completo:");
		fgets(nome_completo, 100, stdin);

		printf("Digite seu CPF: ");
		fgets(cpf, 16, stdin);

		printf("Digite sua data de nascimento (ex: 01/01/2000): ");
		scanf(" %d / %d / %d", &dia, &mes, &ano);
		getchar();

		printf("Digite seu email: ");
		fgets(email, 50, stdin);

		printf("Digite seu telefone: ");
		fgets(telefone, 20, stdin);

		system("clear");


		printf("\nQual e a sua faixa salarial?\n");
		printf("1 - ate 6000\n");
		printf("2 - 6000 a 15.000\n");
		printf("3 - acima de 15.000\n");
		printf("Digite sua opcao: ");
		scanf("%d", &salario);

		while (salario < 1 || salario > 3) {
			printf("Opcao invalida! Digite novamente: ");
			scanf("%d", &salario);
		}
		printf("\n  ESCOLHA SEU VEICULO \n");

		printf("\nQue tipo de veiculo deseja comprar?\n");
		printf("1 - CARRO\n");
		printf("2 - MOTO\n");
		printf("Digite sua opcao: ");
		scanf("%d", &tipo_veiculo);

		switch (tipo_veiculo) {
		case 1:
			printf("\n    CARROS DISPONIVEIS \n");

			printf("  1- Fiat Palio - 35.000,00 \n");
			printf("  2- Mobi like -70.000,00 \n");
			printf("  3- Toro Volcano - 180.000,00 \n");
			printf("  4- BMW 320i - 320.000,00 \n");
			printf("  5- Chevrolet Onix - 85.000,00 \n");

			printf("\n Digite o carro desejado \n:");
			scanf("%d", &modelo);
			if (modelo == 1) preco_carro = 35000;
			else if (modelo == 2) preco_carro = 70000;
			else if (modelo == 3) preco_carro = 180000;
			else if (modelo == 4) preco_carro = 320000;
			else if (modelo == 5) preco_carro = 85000;
			break;

		case 2:
			printf("\n      MOTOS DISPONIVEIS \n");

			printf("  1 - Yamaha R7 70th - 20.000,00 \n");
			printf("  2 - Yamaha R15 ABS - 34.000,00 \n ");
			printf("  3 - Yamaha R3 ABS Connected - 60.000,00 \n");
			printf("  4 - Honda Biz 125 - 15.000,00 \n");
			printf("  5 - Ninja 400 ABS - 36.000,00 \n");
			printf("\n Digite a moto desejada \n");
			scanf("%d", &modelo);
			if (modelo == 1) preco_moto = 20000.00;
			else if (modelo == 2) preco_moto = 34000.00;
			else if (modelo == 3) preco_moto = 60000.00;
			else if (modelo == 4) preco_moto = 15000;
			else if (modelo == 5) preco_moto = 36000;
			break;

		default:
			printf("Opcao invalida!\n");
			break;
		}

		if (tipo_veiculo == 1) {
			preco_veiculo = preco_carro;
		}
		if (tipo_veiculo == 2) {
			preco_veiculo = preco_moto;
		}
		while (valido == 0) {
			printf("Em quantas vezes quer parcelar? (24, 36 ou 48): ");
			scanf("%d", &parcelas);
			getchar();

			if (parcelas == 24 || parcelas == 36 || parcelas == 48) {
				valido = 1;
			} else {
				printf("Opcao invalida! Digite 24, 36 ou 48.\n");
			}
		}


		if (salario == 1) {
			renda = 6000;
		} else if (salario == 2) {
			renda = 12000;
		} else if (salario == 3) {
			renda = 25000;
		}
		if (preco_veiculo == 0) {
			printf("\nVeiculo ou modelo invalido. Cadastro deste cliente cancelado.\n");
			continue;
		}

		valor_parcela = preco_veiculo / parcelas;
		renda_limite = renda * 0.30;
		valor_max_financiado = renda_limite * parcelas;
		entrada_minima = preco_veiculo - valor_max_financiado;


		printf("\n         ANALISE DE FINANCIAMENTO \n");


		if (valor_parcela <= renda_limite) {
			printf("\nParabens! Financiamento APROVADO!\n");
			printf("Valor da parcela em %dx: R$ %.2f por mes\n", parcelas, valor_parcela);
			total_aprovados++;
		} else {
			printf("\nFinanciamento NEGADO! Parcela muito alta. \n");
			printf("SUGESTAO PARA APROVACAO:\n");
			printf("Para aprovar em %dx, voce precisa dar uma entrada de: R$ %.2f\n", parcelas, entrada_minima);
			total_negados++;
		}

		printf("\n          DADOS CADASTRADOS           \n");
		printf("Nome Do Cliente:\n %s", nome_completo);
		printf("Email: %s ", email);
		printf("Data De Nascimento: %d/%d/%d \n", dia, mes, ano);
		printf("Telefone: %s", telefone);
		printf("Cpf: %s \n", cpf);
		printf("Salario cadastrado: R$ \n %.2f\n", renda);


		printf("\nPressione ENTER para avançar...");
		while (getchar() != '\n');
		system("clear");
	}
	printf("\n           RELATORIO FINAL          \n");

	printf("Total de clientes processados: %d\n", total_clientes);
	printf("Total de financiamentos APROVADOS: %d\n", total_aprovados);
	printf("Total de financiamentos NEGADOS: %d\n", total_negados);


	return 0;

}
