#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main(int argc, string argv[])
{
    // Check if there is more than one argument, or none
    if (argc != 2)
    {
        printf("Check the provided argument.\n");
        return 1;
    }

    // Check if provided key has 26 characters
    if (strlen(argv[1]) != 26)
    {
        printf("Argument needs to be exactly 26 letters.\n");
        return 1;
    }

    // Check if provided key has only letters
    for (int i = 0; i < strlen(argv[1]); i++)
    {
        char argletter = argv[1][i];
        if (isalpha(argletter) == false)
        {
            printf("Argument is letter-only.\n");
            return 1;
        }
        
    }
    
    // Check if each letter shows only once per argument
    for (int j = 0; j < strlen(argv[1]); j++)
    {
        int k = 0;
        int validation = 0;
        
        for (k = 1; k < strlen(argv[1]); k++)
        {    
            char c = argv[1][k];
            char d = argv[1][j];
            
            if (j != k)
            {
                if (tolower(argv[1][j]) == tolower(argv[1][k]))
                {
                    validation += 1;
                    if (validation > 0)
                    {
                        printf("Key must contain unique letters.\n");
                        return 1;
                    }
                }    
            }
        }
    }
    
    // Asks input from user
    string input = get_string("plaintext: ");
    
    // Gets length of the user's input
    int length = strlen(input);
    
    printf("ciphertext: "); // Prints the required string for ciphertext
    
    // Loops until input's length is reached
    for (int m = 0; m < length; m++)
    {
        char r = input[m];
        
        
        // Checks if character is alphabetic
        if (isalpha(r) == false)
        {
            printf("%c", r); // Preserve non-alphabetic character
        }
        else
        {
            // Check character's case
            if (islower(r) != false)
            {
                r = tolower(argv[1][r - 97]);
                printf("%c", r);
            }
            else
            {
                r = toupper(argv[1][r - 65]);
                printf("%c", r);
            }
    
        }    
    }
    printf("\n");
    
}
