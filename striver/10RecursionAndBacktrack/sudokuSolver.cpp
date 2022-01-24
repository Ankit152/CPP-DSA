#include<bits/stdc++.h>
using namespace std;
void printGrid(vector<vector<int>> &grid, int n){
    for(int i=0;i<9;i++){
        for(int j=0;j<9;j++){
            cout<<grid[i][j]<<' ';
        }
        cout<<'\n';
    }
    return;
}
bool isSafe(vector<vector<int>> &grid,int x,int y,int num){
    for(int k=0;k<9;k++){
        if(grid[x][k] == num or grid[k][y] == num) return false;
    }
    int sx = (x/3)*3, sy = (y/3)*3;
    for(int i=sx;i<sx+3;i++){
        for(int j=sy;j<sy+3;j++){
            if(grid[i][j]==num) return false;
        }
    }
    return true;
}
bool solveSudoku(vector<vector<int>> &grid,int i,int j, int n){
    if(i==n){
        printGrid(grid,n);
        return true;
    }
    if(j==n) return solveSudoku(grid,i+1,0,n);
    if(grid[i][j]!=0) return true;
    for(int num=1;num<=9;num++){
        if(isSafe(grid,i,j,num)){
            grid[i][j] = num;
            bool success = solveSudoku(grid,i,j+1,n);
            if(success) return true;
        }
    }
    grid[i][j]=0;
    return false;
}

int main(){
    vector<vector<int>> grid(9,vector<int>(9));
    grid = { { 3, 1, 6, 5, 7, 8, 4, 9, 2 },
         { 5, 2, 9, 1, 3, 4, 7, 6, 8 },
         { 4, 8, 7, 6, 2, 9, 5, 3, 1 },
         { 2, 6, 3, 0, 1, 5, 9, 8, 7 },
         { 9, 7, 4, 8, 6, 0, 1, 2, 5 },
         { 8, 5, 1, 7, 9, 2, 6, 4, 3 },
         { 1, 3, 8, 0, 4, 7, 2, 0, 6 },
         { 6, 9, 2, 3, 5, 1, 8, 7, 4 },
         { 7, 4, 5, 0, 8, 6, 3, 1, 0 } };
    solveSudoku(grid,0,0,n);
    return 0;
}