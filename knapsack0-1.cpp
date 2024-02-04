#include<bits/stdc++.h>
using namespace std;
int Fun(int ind , int *val , int *wei ,int n , int k,vector<vector<int>>&dp){
    if(ind >= n){
        return 0;
    }
    int p = 0;
    int np = 0;
    if(dp[ind][k] != -1)return dp[ind][k];
    if(wei[ind] < k){
        // cout << wei[ind] <<" ";
        // cout << val[ind] <<"-->" << wei[ind] <<endl;
        p = val[ind] + Fun(ind+1,val,wei,n,k-wei[ind],dp);
    }
    np = Fun(ind+1,val,wei,n,k,dp);
    return dp[ind][k] = max(p,np);

}
int main(){
    int n , k;
    cin >> n >> k;
    int val[n], wei[n];
    for(int i = 0 ; i < n ; i++){
        cin >> val[i];
    }
    for(int i = 0 ; i < n ; i++){
        cin >> wei[i];
    }
    vector<vector<int>>dp(n+1,vector<int>(k+1,-1));
    for(auto it : dp){
        for(auto i : it){
            cout << i <<" ";
        }
        cout <<endl;
    }
    cout << Fun(0,val,wei,n,k,dp);
}