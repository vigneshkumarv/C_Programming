#include <stdio.h>

int sum_of_digits(int num);

int main(void)
{
    int n;
    printf("Enter a number: ");
    scanf("%i",&n);
    if(n>0)
    {
        printf("Sum of digits of %i is %i\n",n,sum_of_digits(n));   
    }
    return 0;
}

int sum_of_digits(int num)
{
    int sum = 0;
    while(num%10!=0)
    {
        sum += num%10;
        num=num/10;
    }
    return sum;
}