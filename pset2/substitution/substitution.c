#include <stdio.h>
#include <cs50.h>
#include <math.h>
#include <string.h>

int main(void)
{
    string array;
    do {
    array = get_string("26 words pattern please : ");
    } while (strlen(array) != 26);
    string array3 = get_string("ENTER YOUR WORDS: ");
    char array2;
    for (int i = 0 ; i < strlen(array3); i++)
    {
        if (array3[i] == 'a' || array3[i] == 'A')
        {
            array2 = array[0];

        } else if (array3[i] == 'b' || array3[i] == 'B')
        {
            array2 = array[1];

        } else if (array3[i] == 'c' || array3[i] == 'C')
        {
            array2 = array[2];

        } else if (array3[i] == 'd' || array3[i] == 'D')
        {
            array2 = array[3];

        } else if (array3[i] == 'e' || array3[i] == 'E')
        {
            array2 = array[4];

        } else if (array3[i] == 'f' || array3[i] == 'F')
        {
            array2 = array[5];

        } else if (array3[i] == 'g' || array3[i] == 'G')
        {
            array2 = array[6];

        } else if (array3[i] == 'h' || array3[i] == 'H')
        {
            array2 = array[7];

        } else if (array3[i] == 'i' || array3[i] == 'I')
        {
            array2 = array[8];

        } else if (array3[i] == 'j' || array3[i] == 'J')
        {
            array2 = array[9];

        } else if (array3[i] == 'k' || array3[i] == 'K')
        {
            array2 = array[10];

        } else if (array3[i] == 'l' || array3[i] == 'L')
        {
            array2 = array[11];

        } else if (array3[i] == 'm' || array3[i] == 'M')
        {
            array2 = array[12];

        } else if (array3[i] == 'n' || array3[i] == 'N')
        {
            array2 = array[13];

        } else if (array3[i] == 'o' || array3[i] == 'O')
        {
            array2 = array[14];

        } else if (array3[i] == 'p' || array3[i] == 'P')
        {
            array2 = array[15];

        } else if (array3[i] == 'q' || array3[i] == 'Q')
        {
            array2 = array[16];

        } else if (array3[i] == 'r' || array3[i] == 'R')
        {
            array2 = array[17];

        } else if (array3[i] == 's' || array3[i] == 'S')
        {
            array2 = array[18];

        } else if (array3[i] == 't' || array3[i] == 'T')
        {
            array2 = array[19];

        } else if (array3[i] == 'u' || array3[i] == 'U')
        {
            array2 = array[20];

        } else if (array3[i] == 'v' || array3[i] == 'V')
        {
            array2 = array[21];

        } else if (array3[i] == 'w' || array3[i] == 'W')
        {
            array2 = array[22];

        } else if (array3[i] == 'x' || array3[i] == 'X')
        {
            array2 = array[23];

        } else if (array3[i] == 'y' || array3[i] == 'Y')
        {
            array2 = array[24];

        } else if (array3[i] == 'z' || array3[i] == 'Z')
        {
            array2 = array[25];

        } else //if (array3[i] == '.' || array3[i] == ',' || array3[i] != ' ')
        {
            printf("%c", array3[i]);

        }
        printf("%c", array2);



    }
    printf("\n");
}