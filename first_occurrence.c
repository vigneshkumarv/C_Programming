#include <stdio.h>
#include <string.h>

int first_occurence(char *str, int size);

int main(void)
{
    char str[30];
    int res=0;
    printf("Enter a string (< 30 characters): ");
    fgets(str,sizeof(str),stdin);
    int len = strlen(str)-1;
    res=first_occurence(str,len);
    if(res>0)
    {
        printf("first occurrence of non-repeated character in \"%s\" at index: %i\n",str,res);
    }
    else
    {
        printf("none\n");
    }
    return 0;
}

int first_occurence(char *str, int size)
{
    int i,j;
    char ch;
    for(i=0;i<size;i++)
    {
        ch=str[i];
        for(j=0;j<=size;j++)
        {
            if(str[j]==ch && i!=j)
            {
                break;
            }
        }
        if(j>size)
        {
            return i;
        }
    }
    return -1;
}
