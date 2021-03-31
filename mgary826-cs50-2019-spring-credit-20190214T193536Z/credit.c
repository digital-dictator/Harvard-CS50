#include <stdio.h>
#include <cs50.h>
#include <math.h>

int main(void)
{
    //Promts user to add credit card number
    long originalnum = get_long("Number:  ");
    long num = originalnum;
    int digit = 0;
    int sum = 0;
    int product = 0;
    //get to second to last digit
    num = num / 10;
    while (num > 0)
    {   
        //get the mod for digit  
        digit = num % 10;
        //add product
        product = (digit) * 2; 
        //If the product is more than one digit, then the two digits must be added together 
        if (product > 9)
        {
            //take the last digit and add it to sum
            sum = sum + (product % 10);
            //take the product and divide by 10 and then mod 10 to get the first digit
            product = (product / 10);
            //add the first digit to the sum 
            sum = sum + (product % 10);    
        }
        else
        {
            //if the product is just one digit add it to the sum without mod.
            sum = sum + product;
        }
        //to get to everyother digit, divide num by 100
        num = num / 100;
    }
    //reset num to original card number
    num = originalnum;
    while (num > 0)
    {      
        //get mod for last digit
        digit = num % 10;
        //add sum of digits
        sum = sum + digit;
        //get third to last digit
        num = num / 100; 
    }
    if (sum % 10 == 0)
    {
        // Prints out the credit card information out based on number data
        if (originalnum > 4000000000000000 && originalnum < 5000000000000000) 
        {
            printf("VISA\n");    
        }
        else if ((originalnum > 340000000000000 && originalnum < 350000000000000) || (originalnum > 370000000000000
                 && originalnum < 380000000000000))
        {
            printf("AMEX\n");
        }
        else if (originalnum > 5100000000000000 && originalnum < 5600000000000000)
        {
            printf("MASTERCARD\n");
        }
        else 
        {
            printf("INVALID\n");
        }       
    }  
    else 
    {
        printf("INVALID\n");
    }
}
                               
    
        
          
    
    
