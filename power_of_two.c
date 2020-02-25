#include <stdio.h>

void poweroftwo(int num);

int main(void)
{
    int n;
    printf("Enter a number: ");
    scanf("%i",&n);
    if(n>0)
    {
      poweroftwo(n);   
    }
    return 0;
}

void poweroftwo(int num)
{
    int i, count=0;
    for(i=0;i<32;i++){
        if((num>>i)&0x01)
        {
            count++;
        }
    }
    if(count==1){
        printf("Power of two!\n");
    }
    else
    {
        printf("Not a power of two!\n");
    }
}