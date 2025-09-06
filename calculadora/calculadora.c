#include <stdio.h>
#include <stdbool.h>

int main ()
{
  float n1;
  float n2;
  float resultado;
  char entrada[2];

  int soma;
  int divisao;
  int multiplicacao;
  int subtracao;

  printf("Escolha uma das opção para cálculo: +, -, *, / \n ");
  scanf("%c",&entrada[0]);

  soma = entrada [0] == '+';
  divisao = entrada [0] == '/';
  multiplicacao = entrada [0] == '*';
  subtracao = entrada [0] == '-';

  printf("Você escolheu : %c\n",entrada[0]);
  printf("Digite o primeiro número: \n");
  scanf("%f", &n1);

  printf("Digite o segundo número: \n");
  scanf("%f", &n2);

  if (soma){
    resultado = n1 + n2;
  printf("%.2f\n",resultado);
  } else if (divisao){
    resultado = n1 / n2;
  printf("%.2f\n",resultado);
  } else if (multiplicacao){
    resultado = n1 * n2;
  printf("%.2f\n",resultado);
  } else if (subtracao) {
    resultado = n1 - n2;
  printf("%.2f\n",resultado);
  } else{
  printf("Inválido");
  

  }

  return 0;

}
