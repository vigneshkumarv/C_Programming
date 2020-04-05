#include <stdio.h>
#include <stdlib.h>

int deci_to_bin(int num);

int main(void)
{
    int n,res;
    int (*bin_ptr)(int);
    bin_ptr = deci_to_bin;
    printf("Enter an integer: ");
    scanf("%d",&n);
    if(n < 0)
    {
        printf("Enter positive integer!");
        exit(1);
    }
    res = (*bin_ptr)(n);
    printf("Binary of %d is %d\n",n,res);

    return 0;
}

int deci_to_bin(int num)
{
    int res = 0, mul = 1, rem;
    while(num>0)
    {
        rem = num%2;
        res = res + (rem*mul);
        mul*=10;
        num/=2;
    }
    return res;
}
