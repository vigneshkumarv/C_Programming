#include <stdio.h>
#include <string.h>

void reverse_letters(char str[], int start, int end);
void reverse_position(char str[], int start_pos, int end_pos); //helper function


int main(void)
{
    char str[30];
    printf("Enter a string: ");
    fgets(str,sizeof(str),stdin);
    int size = strlen(str)-1;
    reverse_letters(str,0,size);
    printf("Reversed string is: %s\n",str);
    
    return 0;
}

void reverse_letters(char str[], int start, int end)
{
    int write_start, write_end;
    for(write_start=write_end=start;write_end<end;write_end++)
    {
        if(str[write_end] == ' ')
        continue;
        
        write_start=write_end;
        while(str[write_end]!=' ' && write_end<end)
        {
            write_end++;
        }
        write_end--;
        reverse_position(str,write_start,write_end);
    }
}

void reverse_position(char str[], int start_pos, int end_pos)
{
    int i,j;
    char temp;
    for(i=start_pos,j=end_pos;i<j;i++,j--)
    {
        temp = str[i];
        str[i] = str[j];
        str[j] = temp;
    }
}
