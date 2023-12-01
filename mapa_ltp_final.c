#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<locale.h>
#define SIZE 999

struct cadastrar{
	char nome[SIZE];
	char cpf[15];
	int setorAtendimento;
	char setor[30];
};
struct cadastrar cliente[SIZE];
int qnt = 0;
//Cadastro dos clientes
void cadastro(){
		printf("Insira o seu nome completo: \n");
		fflush(stdin);
		gets(cliente[qnt].nome);
		printf("Insira o seu CPF:\n");
		fflush(stdin);
		gets(cliente[qnt].cpf);
		system("pause");
		system("cls");
		do{
			printf("Escolha o setor de atendimento:\n1 - Abertura de Conta\n2 - Caixa\n3 - Gerente Pessoa F?sica\n4 - Gerente Pessoa Jur?dica\n");
			scanf("%d", &cliente[qnt].setorAtendimento);
			switch(cliente[qnt].setorAtendimento){
				case 1: 
					strcpy(cliente[qnt].setor,"1 - Abertura de conta");
					break;
				case 2:
					strcpy(cliente[qnt].setor, "2 - Caixa");
					break;
				case 3:
					strcpy(cliente[qnt].setor, "3 - Gerente Pessoa Física");
		 			break;
				case 4:
					strcpy(cliente[qnt].setor, "4 - Gerente Pessoa Jurídica");
					break;
				default:
					printf("[!] Opção inválida!\n");
					system("cls");
					break; 
			}
		 }while (cliente[qnt].setorAtendimento > 4);
		qnt++;
		printf("Cadastro realizado com sucesso!\n");
  		system("pause");
		system("cls");
}
//Lista de todos os registros feitos
void listar_registros(){
	int i;
	for(i=0; i<qnt; i++)
	{
		printf("Nome: %s\n", cliente[i].nome);
		printf("CPF: %s\n", cliente[i].cpf);
		printf("Tipo atendimento - %s\n", cliente[i].setor);
		printf("=============================================\n");
	}
}
//lista dos registros por setor
void listar_setor(int tipoSetor){
    int i;
    do{
    	printf("Escolha o setor de atendimento desejado:\n1 - Abertura de conta\n2 - Caixa\n3 - Gerente Pessoa Física\n4 - Gerente Pessoa Jurídica\n ");
    	scanf("%d", &tipoSetor);
		for (i = 0; i < qnt; i++) {
        	if (cliente[i].setorAtendimento == tipoSetor) {
            	printf("Nome: %s\n", cliente[i].nome);
            	printf("CPF: %s\n", cliente[i].cpf);
            	printf("Tipo Atendimento: %d - %s\n", cliente[i].setorAtendimento, cliente[i].setor);
            	printf("=============================================\n");
        	}
   	 	}
   	}while(tipoSetor > 4);
    system("pause");
}
int main()
{
	setlocale(LC_ALL, "");
    int op;
	 do {
	 	system("cls");
	 	//menu inicial
        printf("Bem-vindo ao sistema de atendimento\n1 - Solicitar Atendimento\n2 - Listar Atendimentos Registrados\n3 - Listar Atendimento por Setor\n4 - Sair\n");
        scanf("%d", &op);
        switch (op) {
            case 1:
            	system("cls");
            	printf("Opção 1 - Solicitar Atendimento\n\n");
                cadastro();
                break;
            case 2:
            	system("cls");
				printf("Opção 2 - Listar Atendimentos Registradosa\n\n");
                listar_registros();
                system("pause");
                break;
            case 3:
            	system("cls");
            	printf("Opção 3 - Listar Atendimentos por Setor\n\n");
                int tipoSetor;
                listar_setor( tipoSetor);
                break;
            case 4:
                printf("Saindo...\n");
                break;
            default:
                printf("[!] Opção inválida. Tente novamente.\n");
                system("pause");
                system("cls");
                break;
        }
    } while (op != 4);
    return 0;
}
