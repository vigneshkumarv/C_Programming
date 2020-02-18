#include <stdio.h>
#include <ctype.h>
int count(char *str);

int main(void)
{
    char str[30];
    printf("Enter a string: ");
    fgets(str,sizeof(str),stdin);
    printf("Count is: %d\n",count(str));
    
    return 0;
}

int count(char *str)
{
    int count=0;
    while(*str!='\0')
    {
        while(isspace(*str))
        str++;
        
        if(*str=='\0')
        return count;
        while(!isspace(*str) && *str!='\0')
        {
            putchar(*str);
            str++;
        }
        count++;
        printf("\n");
    }
    return count;
}
