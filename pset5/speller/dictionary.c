// Implements a dictionary's functionality

#include <stdbool.h>

#include "dictionary.h"
#include <ctype.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>


#define HASH_MAX 1000

// Represents a node in a hash table
typedef struct node
{
    char word[LENGTH + 1];
    struct node *next;
}
node;

// Number of buckets in hash table
const unsigned int N = HASH_MAX;

// Hash table
node *table[N];

//number of words
unsigned int num = 0;

// a true false stetment for unload function
bool b = false;

// Returns true if word is in dictionary else false
bool check(const char *word)
{
    // a temporary array to copy
    char word2[strlen(word)];
    // copy function
    strcpy(word2, word);
    // an if statement to change to loweercases
    for (int j = 0; word2[j] != '\0'; j++)
    {
        word2[j] = tolower(word[j]);
    }
    int i = hash(word2);
    if (table[i] != NULL)
    {
        for (node *ptr = table[i]; ptr != NULL; ptr = ptr->next)
        {
            if (strcmp(ptr->word, word2) == 0)
            {
                return true;
            }
        }
    }
    return false;
}

// Hashes word to a number
unsigned int hash(const char *word)
{
    int sum = 0;
    for (int j = 0; word[j] != '\0'; j++)
    {
        sum += word[j];
    }
    return sum % HASH_MAX;
}

// Loads dictionary into memory, returning true if successful else false
bool load(const char *dictionary)
{
    // a function to open and read the file
    FILE *file = fopen(dictionary, "r");
    if (file == NULL)
    {
        return false;
    }
    // emptying the array
    for (int j = 0; j < HASH_MAX; j++)
    {
        table[j] = NULL;
    }
    char word[LENGTH + 1];
    // a pointer
    node *ptr2;
    // a function to scan the file from first to end
    while (fscanf(file, "%s", word) != EOF)
    {
        num++;
        do
        {
            //allocatiing a mmoery
            ptr2 = malloc(sizeof(node));
            if (ptr2 == NULL)
            {
                // freeing the memory
                free(ptr2);
            }
        }
        while (ptr2 == NULL);
        strcpy(ptr2->word, word);
        int i = hash(word);
        ptr2->next = table[i];
        table[i] = ptr2;
    }
    fclose(file);
    b = true;
    return true;
}

// Returns number of words in dictionary if loaded else 0 if not yet loaded
unsigned int size(void)
{
    if (!b)
    {
        return 0;
    }
    return num;
}

// Unloads dictionary from memory, returning true if successful else false
bool unload(void)
{
    if (!b)
    {
        return false;
    }
    for (int j = 0; j < HASH_MAX; j++)
    {
        if (table[j] != NULL)
        {
            node *ptr = table[j];
            while (ptr != NULL)
            {
                node *ptr3 = ptr;
                ptr = ptr->next;
                free(ptr3);
            }
        }
    }
    return true;
}
