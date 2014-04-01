//
//  main.c
//  task2
//
//  Created by rafael giusti on 3/27/14.
//  Copyright (c) 2014 rafael giusti. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <stdbool.h>

int binary_search(int A[], int A_length, int X);

int main(int argc, const char * argv[])
{
    
    printf("\n Hello Github \nx^y mod z: \n");
    
    int x = atoi(argv[1]);
    int y = atoi(argv[2]);
    int z = atoi(argv[3]);
    
    printf("x= %d, y=%d, z=%d \n\n", x, y, z);
    
    long double xy_test = powl(x,y);
    printf("x^y = %.2Lf\n", xy_test);
    long double remainder_test = fmodl(xy_test,z);
    printf("test remainder (x^y) mod z)= %.2Lf\n\n", remainder_test);
    
    int remainder2 = 1;
    int xmodz = x%z;
    
    for (int j=0; j<y; j++) {
        remainder2 =  (remainder2*xmodz)%z;
        //remainder2 %= z;
    }
    //    remainder2 %= z;
    
    printf("remainder2 (x^y) mod z)= %d\n\n", remainder2);

    
    
    int remainder3 = 1;
    int a = x%z;
    int y3 = y;
    
    while (y3 > 0) {
        if (y3 & 1) {
            remainder3 = (remainder3*a) %z;
        }
        y3 >>= 1;
        a = (a*a)%z;
    }
    printf("remainder3 (x^y) mod z)= %d\n\n", remainder3);

    
    int remainder;
    int x_Pow_y = x; //x^y
    
    for (int i=1; i<y; i++) {
        x_Pow_y *= x;
    }
    printf("x^y = %d\n", x_Pow_y);
    
    int xy_by_z = x_Pow_y/z; // integer part of x^y/z
    //printf("xy/z = %d\n", xy_by_z);
    //int xy_by_z_times_z = xy_by_z*z;
    //printf("xy_by_z_times_z= %d\n",xy_by_z_times_z);
   
    remainder = x_Pow_y - (xy_by_z*z);
    
    /*
    long double remainder;
    long double x_Pow_y = x; //x^y
    
    remainder=x_Pow_y;
    while (remainder > z) {
        remainder = remainder - z;
    }
    */
    
    printf("remainder (x^y) mod z)= %d\n\n", remainder);
    
    
    int A[] = {3,3,3,3,3,4,7,90,123,133,244,500};
    int searchResult = binary_search(A, 12, 90);
    printf("binary search count= %d\n", searchResult);
    
    return 0;
}

int binary_search(int A[], int A_length, int X){

    // A[] sorted ascending
    
    bool x_found = false;
   
    int search_step = A_length/2;
    int search_index = search_step;
    int search_tail = 0;
    int search_head = A_length-1;
    
    int x_count = 0;
    
    while (!x_found && (search_step != 0)) {
        
        if (A[search_index] == X)
            x_found = true;
        else if (A[search_tail] <= X &&  X <= A[search_head] ) {
            //continue searching by moving search window either back or forward
            search_step /= 2;
            
            if (A[search_index] > X)
                search_index -= search_step; // keep searching backwards from current position
            else
                search_index += search_step; // keep seaeching forward from current position
            
            search_tail = search_index - search_step;
            search_head = search_index + search_step;
            
        }else
            search_step = 0; // X not found
        
    }
    
    //count X's scanning from found index
    if (x_found) {
        
        bool end_count_head = false;
        bool end_count_tail = false;
        int count_step = 1;
        x_count = 1;
        
        while (!end_count_head || !end_count_tail) {
            
            if (search_index+count_step < A_length)
                x_count+= (int)(A[search_index+count_step]==X);
            else
                end_count_head=true;
            
            if (search_index-count_step >= 0)
                x_count+= (int)(A[search_index-count_step]==X);
            else
                end_count_tail = true;
            
            count_step++;
        }
    }
    
    return x_count;

}

