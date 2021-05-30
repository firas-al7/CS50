#include <stdio.h>
#include <cs50.h>
#include <bmp.h>


int main(void)
{
    string name = get_string("What is your name?\n"); // The String variable which asks for user to input their name

    printf("Hello, %s\n", name); // Says Hello to the person's name, %s attaches the variable to text

    char *c = "HELLO";
    printf("%s\n", c);

}