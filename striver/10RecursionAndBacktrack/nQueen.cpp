#include<bits/stdc++.h>
using namespace std;
void printGrid(vector<vector<int>> &grid,int n){
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cout<<grid[i][j]<<' ';
        }
        cout<<'\n';
    }
    return;
}

bool isSafe(vector<vector<int>> &grid,int x,int y,int n){
    for(int i=0;i<x;i++){
        if(grid[i][y]==1) return false;
    }
    int i=x,j=y;
    while(i>=0 and j>=0){
        if(grid[i][j]==1) return false;
        i--;
        j--;
    }
    i=x,j=y;
    while(i>=0 and j<n){
        if(grid[i][j]==1) return false;
        i--;
        j++;
    }
    return true;
}

bool solveNQueen(vector<vector<int>> &grid, int i, int n){
    if(i==n){
        printGrid(grid,n);
        return true;
    }
    for(int j=0;j<n;j++){
        if(isSafe(grid,i,j,n)){
            grid[i][j] = 1;
            bool success = solveNQueen(grid,i+1,n);
            if(success) return true;
            grid[i][j] = 0;
        }
    }
    return false;
}

int countNQueen(vector<vector<int>> &grid,int i,int n){
    if(i==n){
        printGrid(grid,n);
        return 1;
    }
    int ways = 0;
    for(int j=0;j<n;j++){
        if(isSafe(grid,i,j,n)){
            grid[i][j] = 1;
            ways+=countNQueen(grid,i+1,n);
            grid[i][j] = 0;
        }
    }
    return ways;
}
int main(){
    int n;
    cin>>n;
    vector<vector<int>> grid(n,vector<int>(n));
    solveNQueen(grid,0,n);
    cout<<"Total ways: "<<countNQueen(grid,0,n);
    return 0;
}