#include <cs50.h>
#include <stdio.h>

int luhn(long number);
string card_type(long number);

int main(void)
{
  long number = get_long("Enter your credit card number: ");

  if (luhn(number))
  {
    printf("%s\n", card_type(number));
  }
  else{
    printf("Invalid\n");
  }
}

int luhn(long number)    
{
  int sum = 0;
  int digit;
  int count = 0;

  while (number >0)
  {
    digit = number % 10;
    if (count % 2 == 0)
    { sum += digit; }
    else{
      int doubled = digit * 2;
      if (doubled > 9)
      {
        doubled -= 9;
      }
      sum += doubled;
    }
    number /=10;
    count ++;
  }

  return (sum % 10 == 0);
}

string card_type(long number)
{
  int length = 0;
  long n = number;

  while(n > 0)
  {
    n /= 10;
    length ++;
  }

  long  start = number;
  while (start >=100)
  {
    start /=10;
  }

  if (length == 15 && (start == 34 || start == 37))
  { return "AMEX";}
  else if (length == 16 && ( start >=51 && start <=55))
  { return "MasterCard";}
  else if ((length == 13 || length == 16) && (start / 10 == 4|| start == 4))
  { return "VISA";}
  else
  { return "INVALID";}
}