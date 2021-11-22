#include<bits/stdc++.h>
using namespace std;
int main(){
    int n,k;
    cin>>n>>k;
    vector<int> arr(n);
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    priority_queue<int> mx;
    priority_queue<int,vector<int>,greater<int>> mn;
    for(int i=0;i<n;i++){
        mx.push(arr[i]);
        mn.push(arr[i]);
    }
    while(k>1){
        mx.pop();
        mn.pop();
        k--;
    }
    cout<<mx.top()<<" "<<mn.top();
    return 0;
}
