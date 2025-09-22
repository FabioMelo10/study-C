#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

int main(int argc, string argv[])
{
    // Verifica se o usuário forneceu exatamente 1 argumento (a chave)
    if (argc != 2)
    {
        printf("Usage: ./caesar key\n");
        return 1;
    }

    for (int i = 0; i < strlen(argv[1]); i++)
    {
        if (!isdigit(argv[1][i]))
        {
            printf("Usage: ./caesar key\n");
            return 1;
        }
    }

    // Converte o argumento da linha de comando para inteiro
    int key = atoi(argv[1]); // garante que a chave sempre fique entre 0-25

    // Pega o texto original
    string plaintext = get_string("plaintext:  ");

    printf("ciphertext: ");

    // Percorre cada caractere do texto
    for (int i = 0; i < strlen(plaintext); i++)
    {
        char c = plaintext[i];

        if (isupper(c))
        {
            printf("%c", (c - 'A' + key) % 26 + 'A');
        }
        else if (islower(c))
        {
            printf("%c", (c - 'a' + key) % 26 + 'a');
        }
        else
        {
            printf("%c", c); // mantém o caractere igual
        }
    }

    printf("\n");
    return 0;
}
