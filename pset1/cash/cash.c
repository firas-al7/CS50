#include <stdio.h>
#include <cs50.h>
#include <math.h>

int main(void)
{
    int a=0; //a variable for counting quarters
    int b=0; //a variable for counting dimes
    int c=0; //a variable for counting nickels
    int d=0; //a variable for counting pennies
    int change1; // an integer for our main value in cents
    int c1; // helps to count the quarters
    int c2; // helps to count the dimes
    int c3; // helps to count the nickels
    int c4; // helps to count the pennies
    float change; // our main variable which gets the change in dollar
    printf("Available coins:\n1-quarters\n2-dimes\n3-nickels\n4-pennies\n"); // just to show the type of coins
    do
    {
        change = get_float("Enter your change please\n"); // gets the input in float
        printf("%0.2f\n", change); // shows the input on 2 decimal points.
    }
    while (change < 0);// a do while loop for user to input non-negative number.
    change1 = round(change * 100); // change the input from dollar to cents.
    while (change1 > 0) // a while loop for our change
    {
        if (change1 >= 25) // an statement for quarters
        {
            c1 = change1 / 25;
            change1 = change1 % 25; // save the new change by saving the remainder
            a = a + c1; // counting...

        }
        if (change1 >= 10)
        {
            c2 = change1 / 10;
            change1 = change1 % 10; // save the new change by saving the remainder
            b = b + c2; // counting...
        }
        if (change1 >= 5)
        {
            c3 = change1 / 5;
            change1 = change1 % 5; // save the new change by saving the remainder
            c = c + c3; //counting
        }
        if (change1 >= 1)
        {
            c4 = change1 / 1;
            change1 = change1 % 1; // save the new change by saving the remainder
            d = d + c4; //counting...
        }
        break; // ends the loop


    }
    printf("%i quarters\n", a); // prints the number of quarters.
    printf("%i dimes\n", b); // prints the number of dimes.
    printf("%i nickels\n", c); // prints the number of nickels.
    printf("%i pennies\n", d); // prints the number of pennies.

}