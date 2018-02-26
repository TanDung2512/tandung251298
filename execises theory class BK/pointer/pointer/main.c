//  main.c
//  pointer
//
//  Created by nguyen tan dung on 7/6/17.
//  Copyright © 2017 nguyen tan dung. All rights reserved.

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(int argc, const char * argv[]) {
    static int s1[2][2],s2[2][2];
    int  **p;
    p=((int **)calloc(2, sizeof(int)));
    for (int i=0; i<2; i++) {
        *(p+i)=(int *)calloc(2, sizeof(int));
    }
    
    for (int i=0;i<2; i++) {
        for (int k=0; k<2; k++) {
            scanf("%d ",&s1[i][k]);
        }
    }
    
    for (int i=0;i<2; i++) {
        for (int k=0; k<2; k++) {
            scanf("%d ",&s2[i][k]);
        }
    }
    for (int i=0; i<2; i++) {
        for(int k=0;k<2;k++){
            *(k+*(p+i))=s1[i][k]+s2[i][k];
        }
    }
    for (int i=0; i<2; i++) {
        for (int j=0;j<2; j++) {
            printf("%d ",*(j+*(p+i)));
        }
    }
    free(p);
        return 0;
}
