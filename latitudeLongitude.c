#include <stdio.h>
#include <math.h>
#include <stdlib.h>

int main( )
{
float x1, x2,y1, y2;
float distancia; /* Declaração de Variaveis */

printf("digite sua latitude\n");
scanf("%f", &x1);
printf("Digite a latitude do seu pet\n");
scanf("%f", &x2);
printf("digite sua longitude\n");
scanf("%f", &y1);
printf("digite a longitude de seu pet\n");
scanf("%f", &y2); /* Entrada de dados */


distancia=sqrt(((x2-x1)*(x2-x1))+((y2-y1)*(y2-y1)))*(111.195); /* Distancia entre dois pontos do plano cartesiano */
distancia=distancia*1000;
printf("A distancia entre os pontos e %.2f metros\n", distancia);


system("pause");

return (0);
}
