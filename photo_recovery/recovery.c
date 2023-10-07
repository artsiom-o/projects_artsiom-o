#include <stdio.h>  // Standard input/output library
#include <stdlib.h> // Standard library
#include <stdint.h> // Library for fixed-width integer types

typedef uint8_t BYTE; // Define BYTE as an 8-bit unsigned integer

int main(int argc, char *argv[]) // Main function
{
    if (argc != 2) // Check if the number of command-line arguments is correct
    {
        printf("Usage: ./recover IMAGE\n"); // Print usage message
        return 1; // Return error code
    }

    FILE *input_file = fopen(argv[1], "r"); // Open the input file

    if (input_file == NULL) // Check if the file was opened successfully
    {
        printf("Sorry, could not open file\n"); // Print error message
        return 2; // Return error code
    }

    BYTE buffer[512]; // Buffer to store data blocks

    int count_image = 0; // Counter for image files

    FILE *output_file = NULL; // Output file pointer

    char *filename = malloc(8 * sizeof(BYTE)); // Allocate memory for filename

    while (fread(buffer, sizeof(BYTE), 512, input_file) == 512) // Read data blocks from the input file
    {
        if (buffer[0] == 0xff && buffer[1] == 0xd8 && buffer[2] == 0xff && (buffer[3] & 0xf0) == 0xe0) // Check if the block is the start of a new JPEG image
        {
            if (count_image != 0) // If this is not the first image
            {
                fclose(output_file); // Close the previous output file
            }
            sprintf(filename, "%03i.jpg", count_image); // Create a new filename

            count_image++; // Increment the image counter

            output_file = fopen(filename, "w"); // Open a new output file
        }

        if (output_file != NULL) // If an output file is open
        {
            fwrite(buffer, sizeof(BYTE), 512, output_file); // Write the data block to the output file
        }
    }
    
    free(filename); // Free the memory allocated for filename
    fclose(input_file); // Close the input file
    fclose(output_file); // Close the output file
    
    return 0; // Return success code
}
