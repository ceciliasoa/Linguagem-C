#include <stdio.h>
#include <stdlib.h>

struct tprodutos
{
	int codigo;
	char descricao[50];
	float valor;
};
struct tno
{
	struct tprodutos dado;
	struct tno *prox;
};

char menu();
void Incluir_Dados();
int Incluir_Codigo();
void Incluir();
void Listar();
void Consutar();
struct tno * Buscar();
void Alterar();
void Pausar();

int main (void)
{
	struct tno * lista = NULL , * p;
	char opcao;  
	do
	{
		system("cls");
		opcao = menu();
		switch(opcao)
		{
			case '1':
			    Incluir(&lista, p);
				break;
			case '2':
				Listar(lista, &p);
				break;
			case '3':
				Consutar(lista, &p);
				break;
			case '4':
				Alterar(lista, &p);
				break;
		}
	}while (opcao != '0') ;
	p = lista;
	while (p != NULL)
	{
		p = p->prox;
		free(lista);
		lista = p;
	}
	return 0;
}
char menu ()
{
	char opcao;
	printf("[1] Incluir\n");
	printf("[2] Listar\n");
	printf("[3] Consultar\n");
	printf("[4] Alterar\n");
	printf("[0] Sair\n> ");
	fflush(stdin);
	scanf("%c", &opcao);
	return opcao;
}
int Incluir_Codigo() 
{
	int codigo;
	printf("Digite o codigo do produto...:\n> ");
	scanf("%d", &codigo);
	return codigo; 
}
void Incluir_Dados (struct tno *novo)
{
	printf("Digite a descricao do produto:\n> ");
	fflush(stdin);
	gets(novo->dado.descricao );
	printf("Digite o valor do produto....:\n> ");
	scanf("%f", &(novo->dado.valor));
}
void Listar(struct tno *list, struct tno **novo)
{
	(*novo) = list;
	printf("----------------------------------------------\n");
	printf("|Codigo     |Descricao            |Valor     |\n");
	while ((*novo) != NULL) 
	{	
		printf("|%-10d |%-20s |%-10.2f|\n", (*novo)->dado.codigo, (*novo)->dado.descricao, (*novo)->dado.valor);
		(*novo) = (*novo)->prox;
	}
	printf("----------------------------------------------\n");
	Pausar();
}
void Incluir(struct tno **list, struct tno *novo)
{
	novo = (struct tno *) malloc(sizeof(struct tno));
	novo->dado.codigo = Incluir_Codigo();
	Incluir_Dados(novo);
	novo->prox =  (*list);
	(*list) = novo;
}
struct tno * Buscar (struct tno **novo, int codigo)
{
	while ((*novo) != NULL)
	{
		if (codigo == ((*novo)->dado.codigo))
			return (*novo);
		(*novo) = (*novo)->prox;
	}
	return (*novo) = NULL;
}
void Consutar(struct tno *list, struct tno **novo)
{
	(*novo) = list; 
	if(((*novo) = Buscar (&(*novo), Incluir_Codigo())) == NULL)
		printf("Codigo nao encontrado !!!!");
	else
	{
		printf("----------------------------------------------\n");
		printf("|Codigo     |Descricao            |Valor     |\n");
		printf("|%-10d |%-20s |%-10.2f|\n", (*novo)->dado.codigo, (*novo)->dado.descricao, (*novo)->dado.valor);
		printf("----------------------------------------------\n");
	}
	Pausar();
}
void Alterar(struct tno *list, struct tno **novo)
{
	(*novo) = list; 
	if(((*novo) = Buscar (&(*novo), Incluir_Codigo())) == NULL)
		printf("Codigo nao encontrado !!!!");
	else
	{
		(*novo)->dado.codigo = Incluir_Codigo();
		Incluir_Dados((*novo));
		printf("Alteracao concluida !!!!");
	}
	Pausar();
}

void Pausar()
{
	fflush(stdin);
	getchar();
}
