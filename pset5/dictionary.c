// Implements a dictionary's functionality

#include <stdbool.h>
#include <stdio.h>
#include <strings.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

#include "dictionary.h"

//declare hashtable
node *hashtable[SIZE]={NULL};

//dictionary words counter
unsigned int word_counter = 0;
bool loaded_dict = false;

unsigned int hash(const char* word)
{
    unsigned int hash = 0;valgrind ./speller texts/cat.txt
    for (int i=0; word[i]!= '\0'; i++)
    {
        hash = 31*hash + word[i];
    }
    return hash % SIZE;
}


// Number of buckets in hash table
const unsigned int N = 1;

// Hash table
node *table[N];

// Returns true if word is in dictionary else false
bool check(const char *word)
{
    //
    char cword[strlen(word)];
    strcpy(cword,word);
    for (int i = 0; word[i] != '\0'; i++)
    {
        cword[i] = tolower(cword[i]);
    }
    int index = hash(cword);
    if (hashtable[index] != NULL)
    {
        for (node* nodeptr = hashtable[index]; nodeptr != NULL; nodeptr = nodeptr -> next)
        {
            if (strcmp(nodeptr -> word, cword) == 0)
            return true;
        }
    }
    return false;
}

// Loads dictionary into memory, returning true if successful else false
bool load(const char *dictionary)
{
    //
    FILE *input_dict = fopen(dictionary,"r");
    if(input_dict == NULL)
    {
        printf("Could not open the dictionary\n");
        return false;
    }
    for (int i = 0; i < SIZE; i++)
    {
        hashtable[i] = NULL;
    }

    char word[LENGTH +1];
    node* newnodeptr;
    while (fscanf(input_dict, "%s", word) != EOF)
    {
        word_counter++;
        do
        {
            newnodeptr = malloc(sizeof(node));
            if (newnodeptr == NULL)
            {
                free(newnodeptr);
            }
        } while (newnodeptr == NULL);

        strcpy(newnodeptr -> word,word);
        int index = hash(word);
        // if (hashtable[index] == NULL)
        //{
        //    newnodeptr -> next = NULL;
        //    hashtable[index] = newnodeptr;
        //}
        //else
        //{
            newnodeptr->next = hashtable[index];
            hashtable[index] = newnodeptr;
        //}
    }
    fclose(input_dict);
    loaded_dict = true;
    return true;
}

// Returns number of words in dictionary if loaded else 0 if not yet loaded
unsigned int size(void)
{
    if (loaded_dict)
    {
        return word_counter;
    }
    return 0;
}

// Unloads dictionary from memory, returning true if successful else false
bool unload(void)
{
    if (!loaded_dict)
        return false;

    for (int i = 0; i < SIZE; i++)
    {
        if (hashtable[i] != NULL)
        {
            node* ptr = hashtable[i];
            while (ptr != NULL)
            {
                node* predptr = ptr;
                ptr = ptr -> next;
                free(predptr);
            }
        }
    }
    return true;
}
