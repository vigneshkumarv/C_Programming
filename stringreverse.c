#include <stdio.h>
#include <string.h>

void reverseStr(char str[], int size);
void reverse(char str[], int start, int end);

int main(void)
{
    char str[20];
    int start, end;
    printf("Enter a string: ");
    fgets(str,sizeof(str),stdin);
    printf("Enter start and end position of the string: ");
    scanf("%i%i",&start,&end);
    int size = strlen(str);
    //reverseStr(str,size);
    reverse(str,start,end);
    return 0;
}

/* Reverse a String */
void reverseStr(char str[], int size)
{
    int i,j;
    char temp;
    j=size-1;
    for(i=0;i<((size)/2);i++,j--)
    {
        temp = str[i];
        str[i]=str[j];
        str[j]= temp;
    }
    printf("Reversed String: %s\n",str);
}

/* Reverse a portion of a string */
void reverse(char str[], int start, int end)
{
    int i,j;
    char temp;
    for(i=start-1,j=end-1;i<j;i++,j--)
    {
        temp=str[i];
        str[i]=str[j];
        str[j]=temp;
    }
    printf("Reversed portion of string: %s\n",str);
}