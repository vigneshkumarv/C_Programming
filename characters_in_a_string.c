#include <stdio.h>
#include <string.h>

void count (char *str, int size);
int main(void)
{
    char str[30];
    printf("Enter a string (<30 characters): ");
    fgets(str,sizeof(str),stdin);
    int len = strlen(str)-1;
    count(str,len);
    return 0;
}

void count(char *str, int size)
{
    int i,j,count=0;
    char ch;
    for(i=0;i<size;i++)
    {
        count=0;
        if(str[i]!=0)
        {
            ch = str[i];
            for(j=0;j<size;j++)
            {
                if(str[j]==ch)
                {
                    count++;
                    str[j]=0;
                }
            }
            printf("%c has occurred %i no. of times\n",ch,count);
        }
    }
}