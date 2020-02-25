#include <stdio.h>
#include <math.h>

void printprime(int start, int end);
int isprime(int num);

int main(void)
{
    int n1, n2;
    printf("Enter start and end to print prime numbers: ");
    scanf("%i%i",&n1,&n2);
    if(n1<2)
    {
        n1=2;
        if(n2>2 && n1<n2)
        {
          printprime(n1,n2);
        }
    }
    return 0;
}

void printprime(int start, int end)
{
    int i;
    for(i=start;i<end;i++)
    {
        if(isprime(i))
        {
            printf("%i\t",i);
        }
    }
}

int isprime(int num)
{
    int i, count = sqrt(num);
    for(i=2;i<=count;i++)
    {
        if(num%i==0)
        {
            return 0;
        }
    }
    if(i>count)
    {
        return 1;
    }
}