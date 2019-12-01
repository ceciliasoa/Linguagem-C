#include <stdio.h>
#include <stdlib.h>
int main(void)
{
  FILE *pont_arq;
  char palavra_arquivo[40];
  char palavra[20];
  char palavra2[20];

  pont_arq = fopen("arquivo.txt", "w+");

  printf("Digite uma palavra: ");
  scanf("%s",palavra);
  printf("Digite outra palavra: ");
  scanf("%s",palavra2);

  fprintf(pont_arq,"%s\n",palavra);
  fprintf(pont_arq,"%s",palavra2);

  rewind(pont_arq);

  while(fgets(palavra_arquivo, 40, pont_arq) != NULL)
  printf("%s", palavra_arquivo);



  fclose(pont_arq);

  return(0);
}

