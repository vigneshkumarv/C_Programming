#include <stdio.h>
#include <string.h>

void reverse(char str[], int start, int end);
void reverse_str(char str[], int start, int end);
void reverse_position(char str[], int start, int end);

int main(void)
{
    char str[30];
    printf("Enter a string (less than 30 characters): ");
    fgets(str,sizeof(str),stdin);
    int size = strlen(str)-1;
    reverse(str,0,size);
    printf("%s\n", str);
    return 0;
}

void reverse(char str[], int start, int end)
{
    reverse_position(str,start,end);
    reverse_str(str,start,end);
}

void reverse_str(char str[], int start, int end)
{
    int i,j;
    char temp;
    for(i=start,j=end;i<j;i++,j--)
    {
        temp = str[i];
        str[i] = str[j];
        str[j] = temp;
    }
}

void reverse_position(char str[], int start, int end)
{
    int write_start, write_end;
    for(write_start=write_end=start;write_end<end;write_end++)
    {
        if(str[write_end]==' ')
        continue;
        
        write_start=write_end;
        while(str[write_end]!= ' ' && write_end<end)
        {
            write_end++;
        }
        write_end--;
        reverse_str(str,write_start,write_end);
    }
}