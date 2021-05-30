#include <stdio.h>
#include <cs50.h>
#include <math.h>
#include <string.h>


int letters(int k, string s); // return functions
int words(int k1, string s); // return functions
int sentences(int k3, string s); // return functions

int main(void) // the main func
{
    int a = 0; // variable to count the number of letters returning from letters func
    int b = 0; // variable to count the number of words returning from words func
    int c = 0; // variable to count the number of sentences returning from sentences func
    int k = 0; // variable for letters function
    float index; // a float variable for the Coleman-Liau law
    float L; // varible for the average of letters per 100 words
    float S; // variable for the average of sentences per 100 words
    int k1 = 1; // variable for words function
    int k2 = 0; // variable for sentences function
    string sentence = get_string("Write your sentence please: "); // user input

    //printf("Letters : %i\n", letters(k, sentence));
    //printf("Words : %i\n", words(k1, sentence));
    //printf("Sentences : %i\n", sentences(k2, sentence));

    a = a + letters(k, sentence); // saving the letters value in a

    b = b + words(k1, sentence); // saving the words value in b

    c = c + sentences(k2, sentence); // saving the sentences value in c

    L = round(a * 100 / b); // operations for letters AVG in 100 words
    S = round(c * 100 / b); // operations for sentences AVG in 100 words
    index = (0.0588 * L) - (0.296 * S) - 15.8; // operations for the Coleman-Liau law
    //printf("%0.f\n", index);
    if (index < 1) // if statment for grading the sentences.
    {
        printf("Before Grade 1\n");
    }
    else if (index > 16)
    {
        printf("Grade 16+\n");
    }
    else
    {
        printf("Grade %0.f\n", index);
    }
}

int letters(int k, string s)
{
    for (int i = 0; i < strlen(s); i++) // a for loop to determine the number of letters
    {
        if ((s[i] >= 'a' && s[i] <= 'z') || (s[i] >= 'A' && s[i] <= 'Z')) //states the letters
        {
            k++;
        }
    }
    return k; //returning the results
}


int words(int k1, string s)
{
    for (int i = 0; i < strlen(s); i++) //a for loop to determine the number of words
    {
        if (s[i] == ' ') //states the relation between words and spaces.
        {
            k1++;
        }
    }
    return k1; //returning the final answer
}

int sentences(int k3, string s)
{
    for (int i = 0; i < strlen(s); i++) // a for loop to determine the number of sentences
    {
        if (s[i] == '.' || s[i] == '!' || s[i] == '?') // states the rule of sentence.
        {
            k3++;
        }
    }
    return k3; //returning the final answer
}