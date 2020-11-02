#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include "log2.h"

int main()
{
    int error = 0;
    for (int i = 0; i < 600; i++)
    {
        float x = ((float)rand() / (float)(RAND_MAX)) * 512;
        float y_gold = log2(x);
        float y;
        mylog2(x, &y);

        if (abs(y - y_gold) > 0.001)
        {
            error = 1;
            printf("Error with x = %f, %f != %f\n", x, y, y_gold);
        }
    }

    printf("Test bench completed\n");
    if (error)
        return 1;
    else
        return 0;
}
