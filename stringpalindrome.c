#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void)
{
    char str[10];
    int i;
    printf("Enter a string: ");
    fgets(str,sizeof(str),stdin);
    int len = strlen(str);
    len-=2;
    for(i=0;i<(len/2);i++,len--)
    {
        if(str[i]!=str[len])
        {
            printf("Not a palindrome\n");
            exit(1);
        }
    }
    printf("Palindrome");
    return 0;
}