#include<bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin>>n;
    vector<int> arr(n);
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    int mn=arr[0],mx=arr[0];
    for(int i=1;i<n;i++){
        mn=min(arr[i],mn);
        mx=max(arr[i],mn);
    }
    cout<<mn<<" "<<mx;
    return 0;
}
