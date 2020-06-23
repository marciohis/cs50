#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <math.h>

int main(void)
{
    // Prompts user for input
    string text = get_string("Text: \n");

    // Count total number of chars in text
    int total_chars = strlen(text);

    // How many alphanumeric chars?
    int specialchar = 0;
    int characters = 0;

    for (int check_chars = 0; check_chars < total_chars; check_chars++) // Loop for checking until total_chars
    {
        char character = text[check_chars]; // Checks every character from the total_chars array
        if (isalnum(character) == false)    // Check if is alphanumeric
        {
            specialchar = specialchar + 1;  // Add number of non-alphanumeric characters in the variable
        }
        else
        {
            characters = characters + 1;    // Add number of characters in the variable spaces
        }

    }

    // How many words?
    int numberspaces = 0;

    for (int check_spaces = 0; check_spaces < total_chars; check_spaces++)  // Loop for checking spaces until total_char
    {
        char space = text[check_spaces];    // Checks every character from the total_chars array
        if (space == ' ')   // Check if is space
        {
            numberspaces = numberspaces + 1;    // Add number of spaces in the variable
        }
    }

    int words = numberspaces + 1;   // Add variable words, that are amount of spaces plus the last word

    // How many sentences?
    int numbersentences = 0;

    for (int check_sentences = 0; check_sentences < total_chars; check_sentences++) // Loop for checking punctuation until total_char
    {
        char punctuation = text[check_sentences];   // Checks every character from the total_chars array
        if (punctuation == '!' || punctuation == '?' || punctuation == '.') // Check if is punctuation
        {
            numbersentences = numbersentences + 1;  // Add number of punctuations in the variable
        }
    }
    
    // Applying the Coleman-Liau index
    
    // Define L as the average number of characters per 100 words
    float L = 100 * (float) characters / words;

    // Define S as the average number of sentences per 100 words
    float S = 100 * (float) numbersentences / words;

    // Using the index
    int index = round(0.0588 * L - 0.296 * S - 15.8);
    
    // Outputting reading level
    if (index < 1)
    {
        printf("Before Grade 1\n");
    }
    else if (index > 16)
    {
        printf("Grade 16+\n");
    }
    else
    {
        printf("Grade %i\n", index);
    }
}
