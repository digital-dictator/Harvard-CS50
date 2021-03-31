#include <cs50.h>
#include <stdio.h>

int main(void)
{
    int height = 0;
   
    printf("\n");
    //get value within a range of 0 to 23.        
    while (height < 1 || height > 8)
    {
        //Request a height for the pyramid within while loop so that any other request not within parameters is excluded
        height = get_int("Please enter a number between 1 and 8:  \n");
    }    
    //set i to 0
    for (int i = 0; i < height; i++)
    {
        //this sets spaces in row by adding a                   nested for loop   
        for (int j = 0; j < height - i; j++)
        {
            printf(" ");
        }
        //this sets the pound symbols down to make               the pyramids as a second nested for loop
                
        for (int k = 0; k < i + 1; k++)
        {
            printf("#");
        }
            
        //this prints new row
        printf("\n");
    }
    //stops while loop
    return 0;
}
