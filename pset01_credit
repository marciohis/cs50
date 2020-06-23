#include <stdio.h>
#include <cs50.h>

unsigned long long card_number = 0;
int amount_digits = 0;
int digit01 = 0;
int digit02 = 0;
int digit03 = 0;
int digit04 = 0;
int digit05 = 0;
int digit06 = 0;
int digit07 = 0;
int digit08 = 0;
int digit09 = 0;
int digit10 = 0;
int digit11 = 0;
int digit12 = 0;
int digit13 = 0;
int digit14 = 0;
int digit15 = 0;
int digit16 = 0;
int digit1and2 = 0;
int checksum = 0;
unsigned long long copy_card_number = 0;

int main(void)

{
    // Prompt user for positive credit card number
    do
    {
        card_number = get_long_long("Type your credit card number here: \n");
    }
    while (card_number <= 0);

    // Stores each digit from copy_card_number in variables and multiplies by 2
    digit01 = ((card_number / 1000000000000000) * 2);
    digit02 = (((card_number / 100000000000000) % 10) * 2);
    digit03 = (((card_number / 10000000000000) % 10) * 2);
    digit04 = (((card_number / 1000000000000) % 10) * 2);
    digit05 = (((card_number / 100000000000) % 10) * 2);
    digit06 = (((card_number / 10000000000) % 10) * 2);
    digit07 = (((card_number / 1000000000) % 10) * 2);
    digit08 = (((card_number / 100000000) % 10) * 2);
    digit09 = (((card_number / 10000000) % 10) * 2);
    digit10 = (((card_number / 1000000) % 10) * 2);
    digit11 = (((card_number / 100000) % 10) * 2);
    digit12 = (((card_number / 10000) % 10) * 2);
    digit13 = (((card_number / 1000) % 10) * 2);
    digit14 = (((card_number / 100) % 10) * 2);
    digit15 = (((card_number / 10) % 10) * 2);
    digit16 = (card_number % 10);
    
    // Runs the checksum on odd digits and store
    checksum = (digit01 % 10) + (digit01 / 10);
    checksum = checksum + (digit03 % 10) + (digit03 / 10);
    checksum = checksum + (digit05 % 10) + (digit05 / 10);
    checksum = checksum + (digit07 % 10) + (digit07 / 10);
    checksum = checksum + (digit09 % 10) + (digit09 / 10);
    checksum = checksum + (digit11 % 10) + (digit11 / 10);
    checksum = checksum + (digit13 % 10) + (digit13 / 10);
    checksum = checksum + (digit15 % 10) + (digit15 / 10);

    // Add even digits to the checksum
    checksum = checksum + (digit02 / 2);
    checksum = checksum + (digit04 / 2);
    checksum = checksum + (digit06 / 2);
    checksum = checksum + (digit08 / 2);
    checksum = checksum + (digit10 / 2);
    checksum = checksum + (digit12 / 2);
    checksum = checksum + (digit14 / 2);
    checksum = checksum + digit16;
    
    // Validate checksum
    if ((checksum % 10) != 0)
    {
        printf("INVALID\n");
    }
    
    else
    {
        // Store card_number on another variable to be used in the validation
        copy_card_number = card_number;
    
        // Get amount of digits in card_number
        while (card_number > 0)
        {
            card_number = card_number / 10;
            amount_digits++;
        }

        // Check if amount_digits is equal to 13 (VISA card)

        if (amount_digits == 13)
        {
        
            // Check if 13-digit VISA card starts with 4.
            if ((digit04 / 2) == 4)
            {
                printf("VISA\n");
            }

            // If copy_card_number contains 13 digits but does not start with 4, print INVALID
            else
            {
                printf("INVALID\n");
            }
        }

        // Check if amount_digits is equal to 16 (VISA or MASTER card)
        if (amount_digits == 16)
        
        {

            // Check if the first two digits in copy_card_number is between 51 and 55, inclusive (MASTER card)
            digit1and2 = (copy_card_number / 100000000000000);
            if (digit1and2 >= 51 && digit1and2 <= 55)
            {
                printf("MASTERCARD\n");
            }

            // Check if the first two digits in copy_card_number is between 40 and 49, inclusive (VISA card)
            else if (digit1and2 >= 40 && digit1and2 <= 49)
            {
                printf("VISA\n");
            }

            // If copy_card_number has 16 digits but does not match VISA or MASTER conditions, print INVALID
            else
            {
                printf("INVALID\n");
            }
        }

        // Check if amount_digits is equal to 15 (AMEX)
        if (amount_digits == 15)
        {

            // Check if the first two digits in copy_card_number is 34 or 37, inclusive (AMEX card)
            digit1and2 = (copy_card_number / 10000000000000);
            if (digit1and2 == 34 || digit1and2 == 37)
            {
                printf("AMEX\n");
            }
            else
            {
                printf("INVALID\n");
            }
        }
        
        if (amount_digits != 13 && amount_digits != 15 && amount_digits != 16)
        {
            printf("INVALID\n");
        }
    }   
}
