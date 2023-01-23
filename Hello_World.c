#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <string.h> 

int registro() // Função responsavel por cadastrar os usuarios no sistema
{
    char arquivo[40];
    char cpf[40];
    char nome[40];
    char sobrenome[40];
    char cargo[40];
    
    printf("Digite o CPF a ser cadastrado: ");
    scanf("%s", cpf);
    
    strcpy(arquivo, cpf); // Responsável por copiar os valores das strings
    
    FILE *file; // cria o arquivo 
    file = fopen(arquivo, "w"); // cria o arquivo
    fprintf(file, cpf); // salvo o valor da variavel
    fclose(file); // fecha o arquivo
    
    // Separando os valores
    
    file = fopen(arquivo, "a");
    fprintf(file,",");
    fclose(file);
    
     // Cadastrando o nome
    
    printf("Digite o nome a ser cadastrado: ");
    scanf("%s", nome);
    
    file = fopen(arquivo, "a");
    fprintf(file,nome);
    fclose(file);
    
    // Separando os valores
    
    file = fopen(arquivo, "a");
    fprintf(file,",");
    fclose(file);
    
    // Cadastrando o sobrenome
    
    printf("Digite o sobrenome a ser cadastrado");
    scanf("%s",sobrenome);
    
    file = fopen(arquivo, "a");
    fprintf(file,sobrenome);
    fclose(file);
    
    // Separando os valores
    
    file = fopen(arquivo, "a");
    fprintf(file,",");
    fclose(file);

    // Cadastrando o cargo
    
    printf("Digite o cargo a ser cadastrado");
    scanf("%s",cargo);
    
    file = fopen(arquivo, "a");
    fprintf(file,cargo);
    fclose(file);
    
    
    system("pause");
}

int consultar()
{
    setlocale(LC_ALL, "Portuguese"); // Definindo a linguagem
    
    char cpf[40];
    char conteudo[200];
    
    printf("Digite o CPF a ser consultado: ");
    scanf("%s",cpf);
    
    FILE *file;
    file = fopen(cpf, "r");
    
    if(file == NULL)
    {
            printf("Não foi possivel abrir o arquivo, não localizado!.\n");
    } 
    
    while(fgets(conteudo, 200, file) != NULL)
    {
            printf("\n Essas são as informações do usuário: ");
            printf("%s", conteudo);
            printf("\n\n");
    }
    
    system("pause");
}

int deletar()
{
    setlocale(LC_ALL, "Portuguese"); // Definindo a linguagem
    
    char cpf[40];
    printf("Digite o CPF do usuário a ser deletado: ");
    scanf("%s",cpf);
    
    remove(cpf);
    
    FILE *file;
    file = fopen(cpf, "r");
    
    if(file == NULL)
    {
        printf("O usuário não se encontra no sistema!.\n");
        system("pause");
    }
}

int main() {
        int opcao = 0; // Definindo variáveis
        int laco=1;
        
        for(laco=1;laco=1;)
        {
        
        system("cls");

	setlocale(LC_ALL, "Portuguese"); // Definindo a linguagem
	
	printf("### Cartório da EBAC ###\n\n");//inicio do menu
	printf("Escolha a opção desejada do menu \n\n");
	printf("\t1 - Registrar nomes\n");
	printf("\t2 - Consultar nomes\n");
	printf("\t3 - Deletar nomes\n\n");
	printf("Opção: ");//fim do menu
	
	scanf("%d", &opcao); // armazenando a escolha do usuário
	
	system("cls");
	
	switch(opcao) 
	{
	   case 1:
	    registro();
	    break;
  	   
	   case 2: 
	    consultar();
	    break;
	   
	   case 3:
	    deletar();
	    break;
			
	   case 4:
	    printf("Obrigado por utilizar o sistema!\n");
	    return 0;
	    break;
	   
	   default: 
	    printf("Essa opção não está disponivel!\n");
	    system("pause");
        break;
	}
   }
}


