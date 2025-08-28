#include <cs50.h>
#include <stdio.h>

int main(void){

  int height;

  // repetir até usuário passar um valor positivo
  do
  {
    height = get_int("Height: ");
  }

  while (height < 1 || height > 8);

  // loop pelas linhas
  for (int i = 0; i < height; i++)
  {
    //spaces
    for (int j = 0; j < height - i - 1; j++)
    {
      printf(" ");
    }
    //hashes
    for (int j = 0; j < i + 1; j++)
    {
      printf("#");
    }
    //gap
    printf("  "); 

    //hashes to right
    for (int j = 0; j < i + 1; j++)
    {
      printf("#");
    }
    printf("\n");
  }
}