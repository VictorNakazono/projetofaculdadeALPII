//Curso: Engenharia de Software
//Disciplina: Algoritmo e Lógica de Programação II

#include <stdio.h>
#include <stdlib.h>
#include <string.h>	
#include <locale.h>

#define TAM 200

struct cidadao
{
	int codigo;
	char nome[50];
	char cpf[12];
	char vacina[20];
	char data[12];
	int lote;
};

int main() {
	setlocale(LC_ALL, "Portuguese");
	struct cidadao cadastro[TAM];
	struct cidadao pesquisa[TAM];	
	int i, j, acha, op, cont, cont2;
	char busca[12]; 
	char opcao;
	i = 0;
	cont = 0;
	cont2 = 0;
	
	op = 0;
	while (op != 4)
	{
		system("cls");
		printf("\n***Bem-vindo ao sistema de gestão de vacinas***\n");
		printf("\nPara prosseguir, escolha uma das opções abaixo:\n");
		printf("\n1 - Cadastrar Vacina\n");
		printf("2 - Listar Aplicações\n");
		printf("3 - Consultar Por CPF\n");
		printf("4 - Sair\n");
		scanf("%d", &op);
		fflush(stdin);
		if (op == 1)
		{
			system("cls");
				cadastro[i].codigo = i + 1;
				printf("Informe o nome do paciente:\n");
				scanf("%50[^\n]s", &cadastro[i].nome);
				fflush(stdin);
				printf("Informe o CPF (apenas números):\n");
				scanf("%12[^\n]s", &cadastro[i].cpf);
				fflush(stdin);
				printf("Informe a vacina aplicada:\n");
				scanf("%20[^\n]s", &cadastro[i].vacina);
				fflush(stdin);
				printf("Informe a data de aplicação:\n");
				scanf("%12[^\n]s", &cadastro[i].data);
				fflush(stdin);
				printf("Informe o lote da vacina:\n");
				scanf("%d", &cadastro[i].lote);
				fflush(stdin);
				i = i + 1;
				cont = cont +1;
				system("pause");
		}
		else
		{
			if (op == 2)
			{
				system("cls");
				for (i=0; i<cont; i++)
				{
					printf("\nCódigo: %d\n", cadastro[i].codigo);
					printf("Nome: %s\n", cadastro[i].nome);
					printf("CPF: %s\n", cadastro[i].cpf);
					printf("Vacina: %s\n", cadastro[i].vacina);
					printf("Data: %s\n", cadastro[i].data);
					printf("Número do lote: %d\n", cadastro[i].lote);
					printf("================================\n");
				}
				system("pause");
			}
			else
			{
				if (op == 3)
				{
					system("cls");
					printf("Informe o CPF que deseja pesquisar:\n");
					scanf("%12[^\n]s", &busca);
					j = 0;
					acha = 0;
					for (i=0; i<cont; i++)
					{
						if (strcmp (cadastro[i].cpf, busca) == 0) 
						{
							pesquisa[j] = cadastro[i];
							cont2 = cont2 + 1;
							acha = 1;
							j = j + 1;
						}
					}
					if (acha == 1)
					{
						for (j=0; j<cont2; j++)
						{
							printf("\nCódigo: %d\n", pesquisa[j].codigo);
							printf("Nome: %s\n", pesquisa[j].nome);
							printf("CPF: %s\n", pesquisa[j].cpf);
							printf("Vacina: %s\n", pesquisa[j].vacina);
							printf("Data: %s\n", pesquisa[j].data);
							printf("Número do lote: %d\n", pesquisa[j].lote);
						}
						cont2 = 0; 
						for (j=0; j<TAM; j++)
						{
							memset(&pesquisa[j], 0, sizeof (pesquisa[TAM])); 							
						}
					}
					else
						printf("\nCPF não encontrado\n");
						system("pause");
				}		
			}	
		}
	}
	return (0);
}
