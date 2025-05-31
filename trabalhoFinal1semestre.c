#include <stdio.h>

int main()
{
	float total [4];
	int qtd [4];
	char sexo [4];
	char codCliente [4];
	int opcao = 0;
	char codConsulta;
	int encontrado = 0;
	char resposta;
	float valor = 0;
	int valorAbaixo = 0;
	int valorAcima = 0;
	int qtdHomens = 0;
	float valorMulher = 0;
	float valorTotal = 0;
	float media = 0;
	float maisCaro = 0;
	int qtdTotal = 0;
	int qtdSemSexo = 0;
	int totalCodigo [7] = {0};
	int maisVendas = 0;
	char codigoMaisVendido = 'A';

	for(int i = 0; i<4; i++) {
		printf("\nDigite o total do pedido: ");
		scanf("%f", &total[i]);
		while(total[i] < 0) {
			printf("O valor está incorreto, informe um valor positivo: ");
			scanf("%f", &total[i]);
		}
		printf("Digite a quantidade de produtos: ");
		scanf("%i", &qtd[i]);
		while(qtd[i] <= 0) {
			printf("A quantidade está incorreta, informe um valor positivo não neutro: ");
			scanf("%i", &qtd[i]);
		}
		printf("Informe o sexo do cliente (m, f ou n): ");
		scanf(" %c", &sexo[i]);
		while(sexo[i] != 'm' && sexo[i] != 'f' && sexo[i] != 'n' ) {
			printf("O sexo está incorreto, informe m, f ou n: ");
			scanf(" %c", &sexo[i]);
		}
		printf("Informe o código do do cliente (A até) G): ");
		scanf(" %c", &codCliente[i]);
		while(codCliente[i] != 'A' && codCliente[i] != 'B' && codCliente[i] != 'C' && codCliente[i] != 'D' && codCliente[i] != 'E' && codCliente[i] != 'F' && codCliente[i] != 'G') {
			printf("O código está incorreto, informe uma letra de A até G: ");
			scanf(" %c", &codCliente[i]);
		}
		if(i != 3) {
			printf("Perfeito, os dados foram salvos. Vamos para o próximo pedido!!\n");
		}
		else {
			printf("Todos os dados foram coletados.\n");
		}
	}

	do {
		printf("\nMenu:\n");
		printf("\nOpção 0\n");
		printf("Pesquisar um pedido\n");
		printf("\nOpção 1\n");
		printf("Ver informações de todos os pedidos\n");
		printf("\nEscolha a opção (Qualquer outro número para sair): ");
		scanf("%d", &opcao);

		if(opcao == 0) {
			printf("Informe o código do cliente (A até) G): ");
			scanf(" %c", &codConsulta);
			for(int i = 0; i<4; i++) {
				if(codCliente[i] == codConsulta) {
					encontrado = 1;
					printf("\nPedido %i:\n", i+1);
					printf("Total do pedido: %.2f\n", total[i]);
					printf("Quantidade do pedido: %i\n", qtd[i]);
					printf("Sexo do cliente do pedido: %c\n", sexo[i]);
				}
			}
			if(encontrado == 0) {
				printf("Não foi encontrado pedido com esse código.");
			}
			encontrado = 0;
			printf("Gostaria de voltar ao menu? (S ou N) " );
			scanf(" %c", &resposta);
			if(resposta == 'N') {
				printf("Operação encerrada.");
				return 0;
			}
		}

		if(opcao == 1) {
			valorAbaixo = 0;
			valorAcima = 0;
			qtdHomens = 0;
			valorMulher = 0;
			valorTotal = 0;
			media = 0;
			maisCaro = 0;
			qtdTotal = 0;
			qtdSemSexo = 0;
			maisVendas = 0;
			codigoMaisVendido = 'A';
			for(int i = 0; i < 7; i++) totalCodigo[i] = 0;

			printf("Informe um valor: ");
			scanf("%f", &valor);
			for(int i = 0; i<4; i++) {
				if(total[i]<valor) {
					valorAbaixo++;
				}
			}
			printf("Temos %i pedido(s) abaixo de %.2f.\n", valorAbaixo, valor);
			for(int i = 0; i<4; i++) {
				if(total[i]>35) {
					valorAcima++;
				}
			}
			printf("Temos %i pedido(s) acima de 35,00.\n", valorAcima);
			for(int i = 0; i<4; i++) {
				if(sexo[i] == 'm') {
					qtdHomens++;
				}
			}
			printf("Temos %i compradores homens.\n", qtdHomens);
			for(int i = 0; i<4; i++) {
				if(sexo[i] == 'f') {
					valorMulher = valorMulher + total[i];
				}
			}
			printf("Foi comprado %.2f por mulheres.\n", valorMulher);
			for(int i = 0; i<4; i++) {
				valorTotal = valorTotal + total[i];
			}
			media = valorTotal / 4;
			printf("%.2f C) a média dos pedidos.\n", media);
			for(int i = 0; i<4; i++) {
				if(total[i]>maisCaro) {
					maisCaro = total[i];
				}
			}
			printf("%.2f C) o valor do pedido mais caro.\n", maisCaro);
			for(int i = 0; i<4; i++) {
				qtdTotal = qtdTotal + qtd[i];
			}
			printf("A quantidade total de itens vendidos C) %i.\n", qtdTotal);
			for(int i = 0; i<4; i++) {
				if(sexo[i] == 'n') {
					qtdSemSexo++;
				}
			}
			printf("%i itens comprados por pessoas que preferiram não falar o sexo.\n", qtdSemSexo);
			for(int i = 0; i < 4; i++) {
				switch(codCliente[i]) {
				case 'A':
					totalCodigo[0]++;
					break;
				case 'B':
					totalCodigo[1]++;
					break;
				case 'C':
					totalCodigo[2]++;
					break;
				case 'D':
					totalCodigo[3]++;
					break;
				case 'E':
					totalCodigo[4]++;
					break;
				case 'F':
					totalCodigo[5]++;
					break;
				case 'G':
					totalCodigo[6]++;
					break;
				}
			}
			for(int i = 0; i < 7; i++) {
				if(totalCodigo[i] > maisVendas) {
					maisVendas = totalCodigo[i];
					codigoMaisVendido = 'A' + i;
				}
			}
			printf("O código mais vendido C): %c com %i vendas.\n", codigoMaisVendido, maisVendas);
			printf("Gostaria de voltar ao menu? (S ou N) " );
			scanf(" %c", &resposta);
			if(resposta == 'N') {
				printf("OperaC'C#o encerrada.");
				return 0;
			}
		}

	} while(opcao == 0 || opcao == 1);

	printf("\nMuito obrigado, volte sempre!");
	return 0;
}
