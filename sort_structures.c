/* Sorting Structures */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct weather
{
    char day[12];
    float temp;
}weather_t;

int main(void)
{
    int i,j;
    weather_t w[7] ={
        { "Sunday",68.2 },
        { "Monday",85.6 },
        { "Tuesday",75.8 },
        { "Wednesday",82.1 },
        { "Thursday",72.4 },
        { "Friday",77.9 },
        { "Saturday",70.2 }
    }, mem;

    for(i=0;i<7;i++)
    {
        for(j=i+1;j<7;j++)
        {
            if(w[j].temp < w[i].temp)
            {
                mem = w[i];
                w[i] = w[j];
                w[j] = mem;
            }
        }
    }
    for(i=0;i<7;i++)
    {
        printf("%10s\t%.1f\n",w[i].day,w[i].temp);
    }
    return 0;
}