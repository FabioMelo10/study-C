#include <math.h>
#include <stdio.h>
#include <cs50.h>
#include <string.h>
#include <ctype.h>


int main(){

  int letters = 0;
  int words = 1;
  int sentences = 0;

  
  string word1 = get_string("type your phrase:\n");
  
  for (int i = 0; i < strlen(word1); i++ )
  {
    char c = word1[i];
    if (isalpha(c)){letters++; }
    if (c == ' '){words++; }
    if (c == '.' || c == '!' || c == '?') {sentences++;}

 
  }

    printf("Letters: %i\n",letters);
    printf("Words: %i\n", words);
    printf("Sentences: %i\n", sentences);

    float L = (float) letters / words * 100;
    float S = (float) sentences / words * 100;

    float index = 0.0588 * L - 0.296 * S - 15.8;

    int grade = round(index);
    

    printf("L: %f\n", L);
    printf("S: %f\n", S);

    if (grade < 1)
    {
      printf("Before Grade 1\n");
    } else if (grade >= 16){
      printf("Grade 16+\n");
    } else {
      printf("Grade %i\n", grade);
    }

    return 0;
}



