#include<bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin>>n;
    vector<int>ans[n];
    for(int i=0;i<n;i++){
        ans[i].push_back(i+1);
        ans[i].push_back(i+2);
        
    }
    
    cout<<ans[1].size()<<endl;;
    cout<<ans[1][0]<<endl;
    cout<<ans[1][1]<<endl;
    
}