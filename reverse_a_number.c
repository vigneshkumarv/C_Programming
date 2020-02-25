#include <stdio.h>

int reverse(int num);

int main(void)
{
    int n;
    printf("Enter a number: ");
    scanf("%i",&n);
    if(n>0)
    {
        printf("Reverse of %i is %i\n",n,reverse(n));   
    }
    return 0;
}

int reverse(int num)
{
    int rev = 0, mul = 10;
    while(num%10!=0)
    {
        rev = (rev*mul)+(num%10);
        num=num/10;
    }
    return rev;
}