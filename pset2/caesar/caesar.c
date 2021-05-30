#include <stdio.h>
#include <cs50.h>
#include <math.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>


int main(int argc, string argv[]) //the Command line arugmuent with an integer and array
{
    if (argc != 2) // states our erros
    {
        printf("Usage: ./caesar key\n");
        return 1; // terminate
    }
    int n = atoi(argv[1]); // convert the argument line array to integer
    for (int i = 0; i < strlen(argv[1]); i++) // a for loop to check the chars of the argument line
    {
        if (!isdigit(argv[1][i])) // statment of an error if the array is not a digit
        {
            printf("Usage: ./caesar key\n");
            return 1; // terminate
        }
    }
    string plaintxt = get_string("ENTER your plaintxt: \n"); // get input
    int k = atoi(argv[1]); // convert the argument line array to an integer
    //printf("%i\n",k);
    if (k >= 26) // k greater equal to 26 is going above the alphabets
    {
        k = k % 26; // remainder of the secret key
    }
    for (int i = 0 ; i < strlen(plaintxt) ; i++) // a for loop for getting all the characters
    {
        if (plaintxt[i] == ' ' || plaintxt[i] == '.' || plaintxt[i] == ',' || plaintxt[i] == '!') // statement to declare the space and etc.
        {
            //printf("%c", plaintxt[i]);
            plaintxt[i] = plaintxt[i]; // keep the char
        }
        else
        {
            if (plaintxt[i] + k > 'Z' && plaintxt[i] < 'a') // statment for the characters UPPER and LOWER
            {
                int e = k - ('Z' - plaintxt[i]) - 1 ; // counting to 'Z' and turn Z to A and then count the remaining.
                plaintxt[i] = 'A' + e;
                //printf("%c\n", );
                //printf("%c\n", plaintxt[i]);
            }
            else if (plaintxt[i] + k > 'z')
            {
                int e = k - ('z' - plaintxt[i]) - 1 ; // counting to 'z' and turn z to a and then count the remaining.
                plaintxt[i] = 'a' + e;
                //printf("%c\n", );
                //printf("%c\n", plaintxt[i]);
            }
            else if (plaintxt[i] < 'Z')
            {
                plaintxt[i] = plaintxt[i] + k; // for upper cases
                //printf("%c", plaintxt[i] + k);
            }
            else if (plaintxt[i] < 'z')
            {
                plaintxt[i] = plaintxt[i] + k; // for lower cases
                //printf("%c", plaintxt[i] + k);
            }

        }



    }

    printf("ciphertext: %s\n", plaintxt); // print the whole answer in ciphertext
    // char c = 'A';
    // int s = 65 ;
    // printf("%c\n", c + 1);
    // printf("%c\n", s + 1);

}