#include <stdio.h>
#include <stdlib.h>
#include <cs50.h>
#include <stdint.h>



int main(int argc, char *argv[])
{
    int i = 0; // a variable to add the jpg(s).
    bool jpg = false; // a boolean variable to determine whethere there is a jpg file or not
    if (argc != 2) // rules of getting only one input
    {
        printf("Wrong input\n");
        return 1;
    }
    FILE *file = fopen(argv[1], "r"); // a FILE variable which opens and read the input
    FILE *file2; // a file variable for our output
    // a condition if the input file is empty
    if (file == NULL)
    {
        printf("EMPTY");
        return 1;
    }
    // allocating an address which contains 512 bytes of information times the size of chars and store it in Heap.
    unsigned char *buffer = malloc(512 * sizeof(char));
    // a while condition to read the input file
    while (fread(buffer, sizeof(char), 512, file))
    {
        // statement that shows if a file is jpg or not
        if (buffer[0] == 0xff && buffer[1] == 0xd8 && buffer[2] == 0xff && (buffer[3] & 0xf0) == 0xe0)
        {
            if (!jpg)
            {
                jpg = true;
            }
            char filename[8]; // an array of 8 cuz there should be 8 characters for a ???.jpg file
            sprintf(filename, "%03i.jpg", i++); // print the filename with 3 integer name starting from 000.
            file2 = fopen(filename, "w"); // opens the output file for writing
            if (file2 == NULL)
            {
                return 1;
            }
            fwrite(buffer, 512, 1, file2); // writes in the output file.


        }
        else if (jpg)
        {
            fwrite(buffer, 512, 1, file2);
        }

    }
    fclose(file); // close the input file
    fclose(file2); // close the output file
    free(buffer); // free the memory of buffer to stop the leaking memories.
}
