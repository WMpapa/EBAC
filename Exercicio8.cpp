#include <stdio.h> // Biblioteca de comunicação com usuário
#include <stdlib.h> // Biblioteca de alocação de espaço em memória
#include <locale.h> // Biblioteca de alocação de texto por região
#include <string.h> // Biblioteca responsável por gerenciar as string

	int registro()
	{
		char arquivo[40];
		char CPF[40];
		char nome[40];
		char sobrenome[40];
		char cargo[40];
		
		printf("Você escolheu o Incluir Registro de Nomes\n\n\n");
		
		printf("Digite o CPF a ser cadastrado: ");
		scanf("%s",CPF);
		
		strcpy(arquivo,CPF); // Responsável por copiar os valores dos string
	
		FILE *file; // cria o arquivo
		file = fopen(arquivo, "w"); // cria o arquivo
		fprintf(file,CPF); // salva o valor da variável
		fclose(file); // fecha o arquivo
		
		file = fopen(arquivo,"a");
		fprintf(file,",");
		fclose(file); // fecha o arquivo
		
		printf("Digite o nome a ser cadastrado: ");
		scanf("%s",nome);
		
		file = fopen(arquivo,"a");
		fprintf(file,nome);
		fclose(file); // fecha o arquivo
	
		file = fopen(arquivo,"a");
		fprintf(file,",");
		fclose(file); // fecha o arquivo	
		
		printf("Digite o sobrenome a ser cadastrado: ");
		scanf("%s",sobrenome);
		
		file = fopen(arquivo,"a");
		fprintf(file,sobrenome);
		fclose(file); // fecha o arquivo
	
		file = fopen(arquivo,"a");
		fprintf(file,",");
		fclose(file); // fecha o arquivo
		
		printf("Digite o cargo a ser cadastrado: ");
		scanf("%s",cargo);
		
		file = fopen(arquivo,"a");
		fprintf(file,cargo);
		fclose(file); // fecha o arquivo
	
		file = fopen(arquivo,"a");
		fprintf(file,",");
		fclose(file); // fecha o arquivo
		system("pause");
				
	}

	int consulta()
	{
		setlocale(LC_ALL,"Portuguese"); // Definição de idiomas

		char CPF[40];
		char conteudo[200];
						
		printf("Você escolheu o Consulta de Nomes\n\n");
	
		printf("Digite o CPF a ser consultado: ");
		scanf("%s", CPF);
		
		FILE *file; // cria o arquivo
		file = fopen(CPF, "r"); // cria o arquivo
		
		if(file == NULL)
		{
		 printf("Não foi possível abrir o arquivo. Arquivo não localizado!.\n\n");	
		}	
		
		while(fgets(conteudo, 200, file) != NULL)
		{
			printf("\nEssas são as informações do usuário: ");
			printf("%s", conteudo);
			printf("\n\n");
		}
		fclose(file); // fecha o arquivo	
		system ("pause");		
	}
	
	int deletar()
	{
		printf("Você escolheu o Deletar Nomes\n\n");
		
		char CPF[40];
		
		printf("Digite o CPF a ser deletado: ");
		scanf("%s", CPF);
		
		remove(CPF);
		
		FILE *file; // cria o arquivo
		file = fopen(CPF,"r");  // função de abrir arquivo	
		
		if(file == NULL)
		{
			printf("Usuário não encontrado no sistema!. \n");
			system ("pause");	
		}				
	}


int main()
{
	int opcao=0; // Definição das variáveis
	int laco=1;
	char senhadigitada[10]="a";
	
	printf("### Cartório da EBAC ###\n\n");
	printf("Login de administrador!\n\n\ ");
	printf("Digite a sua senha: ");
	scanf("%s",senhadigitada);
	
	//if(senhadigitada[10] == "admin")
	{
		for(laco=1;laco=1;) // Instrução para o sistema operacional não encerrar o App. Pare encerrar usuário precisa clicar no X
		{
	
			system("cls"); // variável para limpar o sistema
		
			setlocale(LC_ALL,"Portuguese"); // Definição de idiomas
	
			printf("### Cartório da EBAC ###\n\n"); // Ínicio do Menu
			printf("Escolha a opção desejada no menu:\n\n");
			printf("\t1 - Registrar Nomes\n");
			printf("\t2 - Consultar Nomes\n");
			printf("\t3 - Deletar Nomes\n\n");
			printf("\t4 - Sair do sistema!\n\n");
			printf("Opção selecionada: "); // Fim do Menu
	
			scanf("%d", &opcao); // Armazenando escolhas do usuário
		
			system("cls"); // variável para limpar o sistema
		
				switch(opcao) // switch case melhor opção para menu
				{	
					case 1:
					registro();
					break;
					
					case 2:
					consulta();
					break;
									
					case 3:
					deletar();
					break;
								
					case 4:
					printf("Obrigado por utilizar o sistema!\n\n");
					return 0;
					break;
								
					default:
					printf("Esta opção não Existe\n\n");
					system ("pause");
					break;	
				}
		}				
	}
	//else
		printf("senha incorreta!");
}
