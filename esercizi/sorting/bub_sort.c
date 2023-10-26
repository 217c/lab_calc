/* This program implements the bubble sorting algorithm */

#include <stdio.h> 
#include <math.h> 
#include <stdlib.h> 

#define len 10

int main()
{
    int vec_raw[len], vec[len];
    int i, ii, temp, max = 0;

    // printf("Sanity check\n");
    srand(122123);
    // define vector elements
    for (i=0; i<len; i++) 
    {
        vec_raw[i] = rand() % (10 - 100) + 10; // in range 10-100
        vec[i] = vec_raw[i];
    }
    

    // print vector
    for (i=0;i<len;i++) 
    {
        printf("%d\n", vec_raw[i]);
    }
    printf("Start sorting\n\n");

    // sort vector decreasing
    printf("Decreasing:\n");
    for (i=len-1; i>=0; i--) // for each element
    {
        for (ii=i-1; ii>=0; ii--) // against all others
        {
            
            //printf("i is: %d | ii is: %d\n", i, ii);
            //OK.

            if (vec[i] > vec[ii]) // triggera lo scambio
            {
                temp = vec[i];
                vec[i] = vec[ii];
                vec[ii] = temp;
            }

        }
    }
    
    // print vector
    for (i=0;i<len;i++) 
    {
        printf("%d\n", vec[i]);
    }


    // sort vector increasing
    printf("Increasing:\n");
    for (i=len-1; i>=0; i--) // for each element
    {
        for (ii=i-1; ii>=0; ii--) // against all others
        {
            
            // printf("i is: %d | ii is: %d\n", i, ii);
            //OK.

            if (vec[i] < vec[ii]) // triggera lo scambio
            {
                temp = vec[i];
                vec[i] = vec[ii];
                vec[ii] = temp;
            }

        }
    }

    // print vector
    for (i=0;i<len;i++) 
    {
        printf("%d\n", vec[i]);
    }

    // find max value
    for (i=0; i<len; i++) // for each element
    {

        if (vec[i] > max) // triggera lo scambio
        {
            max = vec[i];
        }

    }
    printf("max value is %d\n", max);

}