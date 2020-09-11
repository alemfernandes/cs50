\\get the users name and print it with Hello
#include <cs50.h>
#include <stdio.h>

int main(void)
{
    string name = get_string("what's your name?\n");
    printf("hello, %s\n", name);
}