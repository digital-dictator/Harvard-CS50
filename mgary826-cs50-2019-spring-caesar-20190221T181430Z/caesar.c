#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main(int argc, string argv[])
{
    //Makes sure that argc only has 2 inputs and argv[1] is a digit in ascii
    if (argc != 2 || *argv[1] < 48 || *argv[1] > 57) 
    {
        printf("Wrong Input!!! \n");
        return 1;
    }
    else
    {
        string text = get_string("Plaintext: ");
        //This converts the string into an int
        int key = atoi(argv[1]);
        //This runs through each of the char in the array and adds the key to each of the elements
        printf("Ciphertext: ");
        for (int i = 0; i < strlen(text); i++)
        {
            //If Lowercase
            if (text[i] >= 97 && text[i] <= 122)
            {   
                // The print statement takes the text[i] and subtracts it by 'a' which is 97, adds the key.  But we can't just leave it like that because then it once text[i] == 'z'  it will continue with the ascii until it gets to 123, the { key.  Instead we want to loop it back to 'a' so we have to %26 and add 'a' again to get it to loop.     
                printf("%c", ((text[i] - 'a' + key) % 26 + 'a'));
            }
            //If Uppercase
            else if (text[i] >= 65 && text[i] <= 90) 
            {
                // The print statement takes the text[i] and subtracts it by 'A' which is 65, adds the key.  But we can't just leave it like that because then it once text[i] == 'Z'  it will continue with the ascii until it gets to 91, the [ key.  Instead we want to loop it back to 'A' so we have to %26 and add 'A' again to get it to loop. 
                printf("%c", ((text[i] - 'A' + key) % 26 + 'A'));
            }
            else 
            {
                printf("%c", text[i]);
            }
        }
        printf("\n");
        return 0;
    }
}




