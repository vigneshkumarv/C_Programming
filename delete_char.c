#include <stdio.h>
#include <string.h>

void delete(char *str, char delete_char);

int main(void)
{
    char str[30], del_char;
    printf("Enter a string (Max. of 30 characters): ");
    fgets(str,sizeof(str),stdin);
    printf("Enter the character to be deleted: ");
    del_char = getchar();
    delete(str,del_char);
    puts(str);
    return 0;
}

void delete(char *str, char delete_char)
{
    int i,j;
    for(i=0,j=0;i<=strlen(str)-1;i++)
    if(str[i]!=delete_char)
    str[j++]=str[i];
    
    str[j]='\0';
}