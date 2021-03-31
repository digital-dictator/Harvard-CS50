#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>
int shift(char c);
int main(int argc, string argv[])
{
    // convert text lenght to char to make into an array
    if (argc != 2 || *argv[1] < 64 || *argv[1] > 122) 
    {
        printf("Wrong Input!!! \n");
        return 1;
    }
    else if (*argv[1] > 90 && *argv[1] < 97)
    {
        printf("Wrong Input!!! \n");
        return 1;
    }
    else
    {
        string text = get_string("Plaintext: ");
        int key;
        //counter for iterating over the key word
        int j = 0;
        //This runs through each of the char in the array and adds the key to each of the elements
        printf("ciphertext: ");
        for (int i = 0; i < strlen(text); i++)
        {
            //get the key number from the key word            
            key = shift(argv[1][j]);
            //if Lowercase
            if (text[i] >= 97 && text[i] <= 122)
            {      
                printf("%c", ((text[i] - 'a' + key) % 26 + 'a'));
                //Moves to next letter in key
                j++;
            }
            //If Uppercase
            else if (text[i] >= 65 && text[i] <= 90) 
            {
                printf("%c", ((text[i] - 'A' + key) % 26 + 'A'));
                //Moves to next letter in key
                j++;
            }
            else 
            {
                //This will print out any other ascii code like spaces and periods
                printf("%c", text[i]);
            }
            //This if statement is bringing j back to 0 which is the beginning of the key when the key runs out of numbers
            if (strlen(argv[1]) == j)
            {
                j = 0;
            }
        }
        printf("\n");
        return 0;
    }
}
//shift function
int shift(char c)
{
    int i = tolower(c) - 'a';
    return i;
}




