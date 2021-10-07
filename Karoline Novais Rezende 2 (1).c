#include <stdio.h>
#include <locale.h>
#include <string.h>

struct cart
{
	int qt, saldo;
	char nome[100];
	
}card;

struct cart name[100];
int qtd, saldototal;

void menu();
void cadastrar();
void categoria();
void movimentar();
void visualizar();

int main(void)
{ 
menu();
system("PAUSE");
return 0;
}

void menu()
{

setlocale(LC_ALL, "Portuguese");
    
int op;

    do
    {
        system("cls");
        printf ("Olá, escolha uma das opções abaixo para continuar. :)\n\n");
        printf("1 - Cadastrar\n");
        printf("2 - Categoria de gastos\n");
        printf("3 - Movimentação financeira\n");
        printf("4 - Visualizar\n");
        printf("0 - Sair\n");
        scanf("\n%d",&op);
        
      switch(op)
    {
        case 1:
            cadastrar();
            break;
        case 2:
            categoria();
            break;
        case 3:
            movimentar();
            break;
        case 4:
            visualizar();
            break;
	}
    
    }
	while(op != 0);
    getchar ();
}

void cadastrar()
{
	system("cls");
		
	int c, saldo;
	
	printf ("Olá, seja bem-vindo.\n\nPara começar seu cadastro, primeiramente digite o número de cartão(es) a serem adicionados:");
	scanf("%d", &qtd);
	printf("\nÓtimo, vamos prosseguir!\n\n");

	for (c = 1; c <= qtd; c++)
	{
	 	printf ("Digite o nome do cartão %d:", c);
		scanf("%s", name[c].nome);
		
		printf ("Agora, digite o saldo:");
		scanf("%d", &saldo);
		
		name[c].qt = c;
		name[c].saldo = saldo;
		
		saldototal = name[c].saldo + saldototal;	
	}	
	printf ("\n\nSucesso! Tudo pronto para prosseguir. Pressione enter para retornar\n");			
	getch();
	getchar();
	
}

void categoria()
{
	int g1, g2, g3, g4, g5, gastos;
	char op, opc;
	
	system("cls");
	
	printf ("Olá novamente!\n\nAqui é onde você pode cadastrar todos seus gastos para ter um maior controle.\n\n");
	printf ("Você gostaria de começar um lançamento de gastos? (1 para sim 2 para não)\n\n");
	scanf("%s", &op);
	
	if (op == 49)
	{
		printf("Hora de começar a se planejar financeiramente!\n\n");
		printf("----------MENU DE GASTOS--------\n");
		printf("I - Alimentação\nII - Educação\nIII - Saúde\nIV - Diversão\nV - Viagens\n\n");

			printf("Total de gastos com alimentação:");
			scanf("%d", &g1);

			printf("Total de gastos com educação:");
			scanf("%d", &g2);

			printf("Total de gastos com saúde:");
			scanf("%d", &g3);

			printf("Total de gastos com diversão:");
			scanf("%d", &g4);

			printf("Total de gastos com viagens:");
			scanf("%d", &g5);
			
			gastos = g1+g2+g3+g4+g5;
			printf ("\n\nVocê gastou um total de %d\n", gastos);
			printf ("Seu saldo total é %d\n", saldototal);

			if (saldototal > gastos)
			{
			printf("Você tem debito de %d!", saldototal - gastos);
				printf("\nEnter para retornar ao menu.");
				getch();
				
			}
			if (saldototal < gastos)
			{
				printf("Você gastou %d a mais do que seu saldo disponível!", gastos - saldototal);
					
				printf ("\nGostaria de dicas financeiras? (1 para sim 2 para não)\n");
				scanf("%s", &opc);
				getch();
				if (opc==49)
				{
					system("cls");
					printf("Seja herdeiro :)\n\n");
					printf("Pressione enter para retornar ao menu inicial.");
					getch();
				}
				else
				{
					printf("Ok!\n Pressione enter para retornar ao menu inicial.");
					getch();
				}
			}
			if(saldototal==gastos)
			{
				printf("Você gastou a mesma quantia do seu saldo disponível!\n");
				getch();
			}
	}
	else
	{
		printf("Tudo bem! Quem sabe em outro momento.\nTecle enter para voltar ao menu.");
		getch();
	}
	
}

void movimentar()
{
int op;

void transferir();
void sacar();
void boleto();
void deposito();

		system("cls");
		
	        printf ("MOVIMENTAÇÃO FINANCEIRA\n");
	        printf ("Escolha uma opção para continuar.\n\n");
	        printf("1 - Transferir\n");
	        printf("2 - Sacar\n");
	        printf("3 - Pagar um boleto\n");
	        printf("4 - Deposito\n");
	        scanf("\n%d", &op);
	        
	      switch(op)
	    {
	        case 1:
	            transferir();
	            break;
	        case 2:
	            sacar();
	            break;
	        case 3:
	            boleto();
	            break;
	        case 4:
	            deposito();
	            break;
		}
	}
	
		void transferir()
		{
		int c, valor;	
		char nome[100]; 

		system("cls");	
		
		printf("Olá, essa é a área de transferência!\n\nDigite o nome do cartão que você gostaria de utilizar:");	
		scanf("%s", nome);
		
			for (c = 1; c <= qtd; c++)
			{
					while (strcmp(name[c].nome, nome)==0)
					{	
						printf("Digite o valor da transferência:");
						scanf("%d", &valor);
						
						if (name[c].saldo < valor)
						{
							printf ("Saldo  insuficiente! Tente novamente.");
							getch();
							break;
						}
						else 
						{
							name[c].saldo = (name[c].saldo - valor);
							printf ("Transferência realizada com sucesso!\nTecle enter para retornar.");
							getch();
							break;
						}
					}
			}			
		}
	
		void sacar()
		{
		int c, valor;	
		char nome[100]; 
	
		system("cls");	
		
		printf("Olá, essa é a área de saque!\n\nDigite o nome do cartão que você gostaria de utilizar:");	
		scanf("%s", nome);
		
			for (c = 1; c <= qtd; c++)
			{
					while (strcmp(name[c].nome, nome)==0)
					{	
						printf("Digite o valor do saque:");
						scanf("%d", &valor);
						
						if (name[c].saldo < valor)
						{
							printf ("Saldo  insuficiente! Tente novamente.");
							getch();
							break;
						}
						else 
						{
							name[c].saldo = (name[c].saldo - valor);
							printf ("Saque realizado com sucesso!\nTecle enter para retornar.");
							getch();
							break;
						}
					}
			}
		}
		
		void boleto()
		{
		int c, valor;	
		char nome[100]; 
		
		system("cls");	
		
		printf("Olá, essa é a área para pagamento de boleto!\n\nDigite o nome do cartão que você gostaria de utilizar:");	
		scanf("%s", nome);
		
			for (c = 1; c <= qtd; c++)
			{
					while (strcmp(name[c].nome, nome)==0)
					{	
						printf("Digite o valor do boleto:");
						scanf("%d", &valor);
						
						if (name[c].saldo < valor)
						{
							printf ("Saldo  insuficiente! Tente novamente.");
							getch();
							break;
						}
						else 
						{
							name[c].saldo = (name[c].saldo - valor);
							printf ("Boleto pago com sucesso!\nTecle enter para retornar.");
							getch();
							break;
						}
					}
			}		
		}
		
		void deposito()
		{
		int c, valor;	
		char nome[100]; 
		
		system("cls");	
		
		printf("Olá, essa é a área de deposito!\n\nDigite o nome do cartão que você gostaria de utilizar:");	
		scanf("%s", nome);
		
			for (c = 1; c <= qtd; c++)
			{
				while (strcmp(name[c].nome, nome)==0)
				{
					printf("Digite o valor do deposito:");
					scanf("%d", &valor);
							
					name[c].saldo = (name[c].saldo + valor);
					printf ("Deposito realizado com sucesso!\nTecle enter para retornar.");
					getch();
					break;
				}
			}
		}

void visualizar()
{
	int c;
	system("cls");
	printf ("Oi! aqui é onde você pode visualizar informações sobre todo(s) seu(s) cartão(es).\n\n");
	printf("Você possui %d cartão(es)\n\n", qtd);
	for (c = 1; c <= qtd; c++)
	{
		printf ("Cartão %s possui %d,00R$ de saldo\n\n", name[c].nome, name[c].saldo);
	}
	printf ("Pressione enter para retornar ao menu.");
	getch();
}
