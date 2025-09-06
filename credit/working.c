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

  // primeira volta
  while (number >0) //number = 4539148803436467 → entra
  {
    digit = number % 10; //4539148803436467 % 10 = 7
    if (count % 2 == 0) // count = 0 -> par
    { sum += digit; }   // sum = 0 + 7 = 7
    else{
      int doubled = digit * 2; // numero par não passa aqui
      if (doubled > 9) // numero par não passa aqui
      {
        doubled -= 9; // numero par não passa aqui
      }
      sum += doubled;
    }
    number /=10; // 4539148803436467 / 10 = 453914880343646 -> incia como novo number porixma volta
    count ++; // avança a posição p/próximo número
    //count inciou no 0, count = 0+1=1
  }

  // segunda volta

  int sum = 7;
  int digit;
  int count = 1;
  while (number >0) //number = 453914880343646 → entra
  {
    digit = number % 10; //453914880343646 % 10 = 6
    if (count % 2 == 0) // 1 % 2 = 1 -> ímpar
    { sum += digit; }   // não soma pq é impar
    else{
      int doubled = digit * 2; // 6 * 2 = 12
      if (doubled > 9) // 12 > 9
      {
        doubled -= 9; // 12-9= 3
      }
      sum += doubled; // 7 + 3 = 10 -> será sum=10 na terceira volta
    }
    number /=10; // 453914880343646 / 10 = 45391488034364 ->incia como novo number porixma volta
    count ++; //  1 + 1 = 2, count=2 -> próxima posição
  }

  return (sum % 10 == 0); //este return serve para validar cartão
  //caso a soma final for multiplo de 10 é válido
}

string card_type(long number)
{
  int length = 0;
  long n = number;

  while(n > 0)
  {
    n /= 10;
    length ++; //conforme vou diminuindo o "n" aumenta o lenght
    // no fim da primeira contagem temos length=1, no fim será 15
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
  //tart / 10 == 4| serve para quando start tem dois digitos
  { return "VISA";}
  else
  { return "INVALID";}
}