#include <stdio.h>
#include <cs50.h>
#include <string.h>
#include <ctype.h>

int points[] = {1, 3, 3, 2, 1, 4, 2, 4, 1, 8, 5, 1, 3, 1, 1, 3,
     10, 1, 1, 1, 1, 4, 4, 8, 4, 10};

char normalize_char(char c) {
  switch (c) {
    case 'á': return 'a';
    case 'Á': return 'A';
    case 'é': return 'e';
    case 'É': return 'E';
    case 'í': return 'í';
    case 'Í': return 'I';
    default: return c;

  }
}


int computer_score(string word){

  int score = 0;


  for (int i = 0; i < strlen(word); i++)
  { char letter = normalize_char(word[i]);
    if (isupper(word[i]))
    {
      int index = word[i] - 'A';
      score += points[index];
    }
    else if (islower(word[i]))
    {
      int index = word[i] - 'a';
      score += points[index];
    }

  }

  return score;

}

int main(){

  char pause = 'y';

  while (pause == 'y')
  {
  string word1 = get_string("Player 1 tell me your word:\n");
  string word2 = get_string("Player 2 tell me your word: \n");

  int score1 = computer_score(word1);
  int score2 = computer_score(word2);

    if (score1 > score2){
      printf ("Player 1 Wins!\n");
  } else if (score2 > score1){
      printf ("Player 2 Wins!\n");
  } else{
    printf("Tie, No one wins!\n");
  }

  printf("--------------\n");

  pause = get_char ("Do you want to keep playing? Type 'y' or 'n'\n");
  }

  printf("--------------\n");


  return 0;
}


// int points[] = {1, 3, 3, 2, 1, 4, 2, 4, 1, 8, 5, 1, 3, 1, 1, 3,
//      10, 1, 1, 1, 1, 4, 4, 8, 4, 10};


// int computer_score(string word){ // Fábio

//   int score = 0; //

// for (int i = 0; i < strlen(word); i++)//i+0= i<5(5 é comprimento), i=0+1
//   {
//     if (isupper(word[i])) //F
//     {
//       int index = word[i] - 'A'; // index = word[F]
//       score += points[index]; // 0 + 4 (F vale 4 pontos)
//     }
//     else if (islower(word[i]))  // não se aplica
//     {
//       int index = word[i] - 'a';// não se aplica
//       score += points[index];// não se aplica
//     }

//   }



// int points[] = {1, 3, 3, 2, 1, 4, 2, 4, 1, 8, 5, 1, 3, 1, 1, 3,
//      10, 1, 1, 1, 1, 4, 4, 8, 4, 10};


// int computer_score(string word){ // Fábio

//   int score = 4; //

// for (int i = 0; i < strlen(word); i++)//1+0= 1<5(5 é comprimento), i=1+1
//   {
//     if (isupper(word[i])) // não se aplica
//     {
//       int index = word[i] - 'A'; // não se aplica
//       score += points[index]; // 0 + 4 (F vale 4 pontos)
//     }
//     else if (islower(word[i]))  // á
//     {
//       int index = word[i] - 'a';// index = word[á]
//       score += points[index];// 4+1=5 (á vale 1 ponto)
//     }

//   }