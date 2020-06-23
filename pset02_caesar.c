#include <cs50.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

char letter = 0;
char chars = 0;

int main(int argc, string argv[1])
{
    // Check if amount of arguments is different than 2
    if (argc != 2)
    {
        printf("Usage: ./caesar key\n");
        return 1;
    }

    // Get chars from command-line argument
    string argument = argv[1]; // Store the value of argv[1] in a friendlier variable
    int numberchars = strlen(argument); // Get number of characters in variable and store

    // Get each letter and check if it is a digit
    int checkchars = 0; // Store the number of loops for the letter checking

    for (checkchars = 0; checkchars < numberchars; checkchars++)
    {
        chars = argument[checkchars];
        if (isdigit(chars) == false)
        {
            printf("Usage: ./caesar key\n");
            return 1;
        }

    }
    
    // Convert string into an integer
    int i = atoi(argv[1]);

    printf("Success\n");

    // Asks for user's input to be ciphered
    string input = get_string("plaintext: ");

    printf("ciphertext: ");

    int numberinput = strlen(input); // Gets number of letters from input

    for (int checkinput = 0; checkinput < numberinput; checkinput++)
    {
        letter = input[checkinput];

        // Check if is alphabet
        if (isalpha(letter) != 0)
        {
            // Run cipher for lowercase
            if islower(input[checkinput])
            {
                printf("%c", (((input[checkinput] + i) - 97) % 26) + 97);
            }
            // Run cipher for uppercase
            else if isupper(input[checkinput])
            {
                printf("%c", (((input[checkinput] + i) - 65) % 26) + 65);
            }
        }
        else
        {
            printf("%c", input[checkinput]);
        }

    }
    printf("\n");

    return 0;
}
