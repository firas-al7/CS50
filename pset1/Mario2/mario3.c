#include <stdio.h>
#include <cs50.h>

int main(void){
    int height; //make a variable

    do{
      height = get_int("Please determine your height\n"); //get an input from the user
    } while (height < 1 || height > 8); // determine the rules of only accepting 1 to 8
    int o = height;
    for (int i =1; i<=height; i++) //making the loops
    {
        int k = i; // make a variable name 'k' and save integer i into it.
        while (k < height) // by doing this we are making spaces between the lines
        {
            printf(" ");
            k++;
        }
        for(int j = 1; j<= height; j++) // another loop which provides the hashes
        {
            if (i>=j) //by doing this we are saying to go from 1 to 8 but if we put i<=j, it will go from 8 to 1 (reverse)
            {
            printf("#");
            }

        }
        printf("\n"); // printing a new line

    }

// Let computer asks the ser for  height between 1 & 8.

// If the user input were less than 1 or greater than 8, then go back to line number 1.

// Let an integer be 1 and calls it (i).

// Let and integer be 1 and calls it (j).

// make a loop under another loop

// in interior loop, lets print hashtags in condition that j is less than the input number and increase j by 1, then go back to the main loop

// in the main loop print an empty line which directs to another line. and increase i by 1.

// excute the loop after the two integers were equal to the input number.



}