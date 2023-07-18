#include <stdio.h> // Biblioteca de comunica��o com usu�rio
#include <stdlib.h> // Biblioteca de aloca��o de espa�o em mem�ria
#include <locale.h> // Biblioteca de aloca��o de texto por regi�o
#include <string.h> // Biblioteca respons�vel por gerenciar as string

	int registro()
	{
		char arquivo[40];
		char CPF[40];
		char nome[40];
		char sobrenome[40];
		char cargo[40];
		
		printf("Voc� escolheu o Incluir Registro de Nomes\n\n\n");
		
		printf("Digite o CPF a ser cadastrado: ");
		scanf("%s",CPF);
		
		strcpy(arquivo,CPF); // Respons�vel por copiar os valores dos string
	
		FILE *file; // cria o arquivo
		file = fopen(arquivo, "w"); // cria o arquivo
		fprintf(file,CPF); // salva o valor da vari�vel
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
		setlocale(LC_ALL,"Portuguese"); // Defini��o de idiomas

		char CPF[40];
		char conteudo[200];
						
		printf("Voc� escolheu o Consulta de Nomes\n\n");
	
		printf("Digite o CPF a ser consultado: ");
		scanf("%s", CPF);
		
		FILE *file; // cria o arquivo
		file = fopen(CPF, "r"); // cria o arquivo
		
		if(file == NULL)
		{
		 printf("N�o foi poss�vel abrir o arquivo. Arquivo n�o localizado!.\n\n");	
		}	
		
		while(fgets(conteudo, 200, file) != NULL)
		{
			printf("\nEssas s�o as informa��es do usu�rio: ");
			printf("%s", conteudo);
			printf("\n\n");
		}
		fclose(file); // fecha o arquivo	
		system ("pause");		
	}
	
	int deletar()
	{
		printf("Voc� escolheu o Deletar Nomes\n\n");
		
		char CPF[40];
		
		printf("Digite o CPF a ser deletado: ");
		scanf("%s", CPF);
		
		remove(CPF);
		
		FILE *file; // cria o arquivo
		file = fopen(CPF,"r");  // fun��o de abrir arquivo	
		
		if(file == NULL)
		{
			printf("Usu�rio n�o encontrado no sistema!. \n");
			system ("pause");	
		}				
	}


int main()
{
	int opcao=0; // Defini��o das vari�veis
	int laco=1;
	char senhadigitada[10]="a";
	
	printf("### Cart�rio da EBAC ###\n\n");
	printf("Login de administrador!\n\n\ ");
	printf("Digite a sua senha: ");
	scanf("%s",senhadigitada);
	
	//if(senhadigitada[10] == "admin")
	{
		for(laco=1;laco=1;) // Instru��o para o sistema operacional n�o encerrar o App. Pare encerrar usu�rio precisa clicar no X
		{
	
			system("cls"); // vari�vel para limpar o sistema
		
			setlocale(LC_ALL,"Portuguese"); // Defini��o de idiomas
	
			printf("### Cart�rio da EBAC ###\n\n"); // �nicio do Menu
			printf("Escolha a op��o desejada no menu:\n\n");
			printf("\t1 - Registrar Nomes\n");
			printf("\t2 - Consultar Nomes\n");
			printf("\t3 - Deletar Nomes\n\n");
			printf("\t4 - Sair do sistema!\n\n");
			printf("Op��o selecionada: "); // Fim do Menu
	
			scanf("%d", &opcao); // Armazenando escolhas do usu�rio
		
			system("cls"); // vari�vel para limpar o sistema
		
				switch(opcao) // switch case melhor op��o para menu
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
					printf("Esta op��o n�o Existe\n\n");
					system ("pause");
					break;	
				}
		}				
	}
	//else
		printf("senha incorreta!");
}
