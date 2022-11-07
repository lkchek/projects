#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

int main(int argc, string argv[])
{

    // Command-line needs to take only two arguments (the user's input and the programm itself)
    if (argc != 2)
    {
        printf("Usage: ./caesar key\n");
        return 1;
    }

    // Command-line needs to take only digit characters
    string input = argv[1];
    for (int i = 0; i < strlen(input); i++)
    {
        if (!isdigit(input[i]))
        {
            printf("Usage: ./caesar key\n");
            return 1;
        }
    }

    int key = atoi(argv[1]);

    // Prompt a user for plaintext
    string plaintext = get_string("plaintext: ");
    int lenght = strlen(plaintext);

    // Encipher plaintext
    char cipher[lenght];
    for (int i = 0; i < lenght + 1; i++)
    {
        // Check if cipher contains alphabetic characters
        if (isalpha(plaintext[i]))
        {
            // Check if cipher containes lowecase characters
            if (islower(plaintext[i]))
            {
                cipher[i] = ((plaintext[i] - 'a' + key) % 26 + 'a');
            }

            // Check if cipher contains uppercase characters
            else if (isupper(plaintext[i]))
            {
                cipher[i] = ((plaintext[i] - 'A' + key) % 26 + 'A');
            }
        }

        // If it's non-alphabetic characters (commas, numbers, etc), just keep them as they are
        else
        {
            cipher[i] = plaintext[i];
        }
    }

    printf("ciphertext: %s\n", cipher);
    
    // Debugging for string input "hello"
    //printf("ciphertext: %i %i %i %i %i %i", cipher[0], cipher[1], cipher[2], cipher[3], cipher[3], cipher[4]);
    return 0;
}
