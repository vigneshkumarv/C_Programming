#include <stdio.h>

int count(char str[], char search_char);
void replace(char *str, char search_char, char replace_char);
int main(void)
{
    char str[30], search_c, replace_c;
    int res=0;
    printf("Enter a string: ");
    fgets(str,sizeof(str),stdin);
    printf("Enter character to be searched: ");
    search_c = getchar();
    printf("Enter character to be replaced: ");
    replace_c = getchar();
    printf("No. of occurences of \'%c\' is %i\n",search_c,count(str,search_c));
    replace(str,search_c,replace_c);
    puts(str);
    return 0;
}
int count(char str[], char search_char)
{
    int i=0, count=0;
    while(str[i]!='\0')
    {
        if(str[i]==search_char)
        {
            count++;
        }
        i++;
    }
    return count;
}

void replace(char *str, char search_char, char replace_char)
{
    while(*str++ !='\0')
    {
        if(*str == search_char)
        {
            *str = replace_char;
        }
    }
}