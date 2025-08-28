#include <cs50.h>
#include <stdio.h>

int main(void)
{

  int cents;

  do
  {
    cents = get_int("Changed owed: ");
  }
  while (cents <=0);

  int coins = 0;
  
  int quartes = cents / 25;
  coins += quartes;
  cents = cents % 25;

  int dimes = cents / 10;
  coins += dimes;
  cents = cents % 10;

  int nickels = cents / 5;
  coins += nickels;
  cents = cents % 5;

  int pennies = cents / 1;
  coins += pennies;
  cents = cents % 1;

  printf("Total coins: %i\n", coins);

  if (quartes > 0)
  printf("%i coins 25¢\n", quartes);
  if (dimes > 0)
  printf("%i coins 10¢\n", dimes);
  if (nickels > 0)
  printf("%i coins 5¢\n", nickels);
  if (pennies > 0)
  printf("%i coins 1¢\n", pennies);
}