#include <stdio.h>
#include <stdbool.h>

int main ()
{
  int number;
  char pause = 'y';
  bool even;



  while(pause == 'y')
  {
  printf("Enter the number to find out if it is even: \n");
  scanf ("%d", &number);

  even = number % 2 == 0;

    if (even){
    printf ("Your number is even.\n");
  } else{
    printf ("Your number is odd.\n");
  }

  printf("Do you want to keep playing? Type 'y' or 'n'\n");
  scanf (" %c", &pause);
  }

  return 0;
}

