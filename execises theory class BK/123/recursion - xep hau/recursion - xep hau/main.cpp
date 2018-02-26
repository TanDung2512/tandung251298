//
//  main.cpp
//  recursion - xep hau
//
//  Created by nguyen tan dung on 9/14/17.
//  Copyright © 2017 nguyen tan dung. All rights reserved.
//

#include <iostream>
using namespace std;

void OutputBoard(int ** board,int size);
void Set_true_checkqueen(bool **checkqueen,int i,int j,int size);
void Check_SetTrue_checkqueen(bool **checkqueen,int **board,int size);
void xephau(bool **checkqueen,int **board,int j,int size,int &num_fail);



int main(int argc, const char * argv[]) {
    int num_fail=0;
    bool **checkqueen;
    int **board;
    int size;
    cin>>size;
    checkqueen =new bool*[size];
    board=new int*[size];
    for (int i=0; i<size; i++) {
        checkqueen[i]=new bool [size];
        board[i]=new int[size];
    }
    for (int i=0; i<size; i++) {
        for (int j=0; j<size; j++) {
            board[i][j]=0;
            checkqueen  [i][j]=false;
        }
    }
    xephau(checkqueen , board, 0, size,num_fail);
    cout<<num_fail<<endl;
    return 0;
}



void xephau(bool **checkqueen,int **board,int j,int size,int &num_fail){
    int i;
    for ( i=0; i<size; i++) {
        if((checkqueen[i][j]==false) && j<size-1){
            board[i][j]=1;
            Set_true_checkqueen(checkqueen, i, j, size);
            xephau(checkqueen,board,j+1,size,num_fail);
            board[i][j]=0;
            Check_SetTrue_checkqueen(checkqueen, board, size);
        }
        else if((checkqueen[i][j]==false )&& j==size-1){
            board[i][j]=1;
            OutputBoard(board, size);
            board[i][j]=0;
        }
    }
    i--;
    if(i==size-1 && j==size-1 &&( checkqueen[i][j]==true)){
        num_fail++;
    }
}
void OutputBoard(int ** board,int size){
    for (int i=0; i<size; i++) {
        for (int j=0; j<size; j++) {
            cout<<board[i][j]<<" ";
        }
        cout<<endl;
    }
    cout<<endl;
}
void Set_true_checkqueen(bool **checkqueen,int i,int j,int size){
    int a=i;
    int b=0;
    while(b<size){
        checkqueen[a][b]=true;
        b++;
    }
    a=0;
    b=j;
    while(a<size){
        checkqueen[a][b]=true;
        a++;
    }
    a=i;
    b=j;
    while(a<size & b<size){
        checkqueen[a][b]=true;
        a++;b++;
    }
    a=i;
    b=j;
    while(a>=0 & b>=0){
        checkqueen[a][b]=true;
        a--;b--;
    }
    a=i;
    b=j;
    while (a>=0 & a<size & b>=0 & b<size) {
        checkqueen[a][b]=true;
        a--;b++;
    }
    a=i;
    b=j;
    while (a>=0 & a<size & b>=0 & b<size) {
        checkqueen[a][b]=true;
        a++;b--;
    }
}
void Check_SetTrue_checkqueen(bool **checkqueen,int **board,int size){
    for (int i=0; i<size; i++) {
        for (int j=0; j<size; j++) {
            checkqueen[i][j]=false;
        }
    }
    for (int i=0; i<size; i++) {
        for (int j =0 ; j<size; j++) {
            if(board[i][j]==1){
                Set_true_checkqueen(checkqueen, i, j, size);
            }
        }
    }
}

