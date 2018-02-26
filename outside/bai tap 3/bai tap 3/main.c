//
//  main.c
//  bai tap 3
//
//  Created by nguyen tan dung on 6/28/17.
//  Copyright © 2017 nguyen tan dung. All rights reserved.
//

#include <stdio.h>

int main(int argc, const char * argv[]) {
    // insert code here...
    int a,b,hieu1,hieu2;
    printf("Hello, World!\n");
    printf("please input a,b \n");
    scanf("%d",&a);
    scanf("%d",&b);
    if ((a%b )== 0 )
    {
        printf("a la boi so cua b \n");
    }
    else    printf("a khong phai la boi so cua b \n");
    
    if ((a*b)>1000) {
        printf("2 so a,b lon hon 1000");
    }
    else    printf("2 so a,b khong lon hon 1000 \n");
    hieu1=a-b;
    hieu2=b-a;
    if (hieu1==a) {
        printf("hieu cua a - b = a ");
    }
    else    printf("hieu cua a-b khong bang b \n");
    if (hieu2==b) {
        printf("hieu cua b - a = b ");
    }
    else    printf("hieu cua b-a khong bang b \n");
    
    
    return 0;
}
