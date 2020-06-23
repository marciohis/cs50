#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

// Declare data structure for BYTE
typedef uint8_t BYTE;

int main(int argc, char *argv[])
{
    // Validate amount of arguments
    if (argc != 2)
    {

        printf("Only one argument is accepted\n");
        return 1;
    }

    // Open file programmatically;
    FILE *file = fopen(argv[1], "r");

    // Check if given file is valid
    if (file == NULL)
    {
        printf("File %s not found or not working\n", argv[1]);
        return 2;
    }

    // Read file function

    BYTE buffer[512]; // Declare buffer array
    int counter = 0; // Counter to filename
    FILE *img = NULL; // Declare pointer to output file

    while (fread(buffer, 1, 512, file) == 512)
    {
        // Checks JPG validation bits
        if (buffer[0] == 0xff && buffer[1] == 0xd8 && buffer[2] == 0xff && (buffer[3] & 0xf0) == 0xe0)
        {
            // Check if there's an open file
            if (counter != 0)
            {
                fclose(img);
            }

            // Allocate enough memory to string filename
            char *filename = malloc(8 * sizeof(char));

            // Build filename with three letters and record to string filename
            sprintf(filename, "%03i.jpg", counter);

            // Create a new file called img and write
            img = fopen(filename, "w");

            counter++; // Used to generate correct filename
        }

        // Check if there's an open file
        if (img != NULL)
        {
            // Write information to the file
            fwrite(buffer, 1, 512, img);
        }
    }
    fclose(file);
    return 0;
}
