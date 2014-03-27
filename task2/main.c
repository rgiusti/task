//
//  main.c
//  task2
//
//  Created by rafael giusti on 3/27/14.
//  Copyright (c) 2014 rafael giusti. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>

int main(int argc, const char * argv[])
{
    printf("x^y mod z: \n");
    
    int x = atoi(argv[1]);
    int y = atoi(argv[2]);
    int z = atoi(argv[3]);
    
    printf("x= %d, y=%d, z=%d \n", x, y, z);
    
    double xy_test = pow(x,y);
    printf("x^y = %f\n", xy_test);
    int remainder_test = (int)(xy_test)%z;
    printf("test remainder (x^y) mod z)= %d\n\n", remainder_test);
    
    
    int remainder = x;
    int x_Pow_y;
    
    for (int i=0; i<y; i++) {
        x_Pow_y *= x_Pow_y;
    }
    
    
    int xy_by_z = x_Pow_y/z;
    printf("xy/z = %d\n", xy_by_z);
    int xy_by_z_times_z = xy_by_z*z;
    printf("xy_by_z_times_z= %d\n",xy_by_z_times_z);
    
    
    printf("remainder (x^y) mod z)= %d\n", remainder);
    
    return 0;
}

