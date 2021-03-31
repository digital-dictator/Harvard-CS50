#include <stdio.h>
#include <cs50.h>
//This program asks for a name and prints it out.
int main(void)
{
    string name = get_string("What is your name?\n");
    printf("hello, %s\n", name);
}
