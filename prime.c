#include <stdio.h>
#include <math.h>

int isprime(int num);

int main(void)
{
    int n;
    printf("Enter a number: ");
    scanf("%i",&n);
    if(n>1)
    {
          if(isprime(n))
          {
              printf("Prime\n");
          }
          else
          {
              printf("Not prime\n");
          }
    }
    return 0;
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