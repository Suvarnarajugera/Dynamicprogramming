#include<bits/stdc++.h>
using namespace std;
#define ll long long
long long dp[101][100001];
long long Fun(int ind,int w,int *val , int *wei , int n){
    if(ind > n)return 0;
    ll p = 0;
    ll np = 0;
    if(dp[ind][w] != -1)return dp[ind][w];
    np = Fun(ind+1,w,val,wei,n);
    if(val[ind] <= w){
        w = w - val[ind];
        p = wei[ind] + Fun(ind+1,w,val,wei,n);
        w = w + val[ind];
    }
    dp[ind][w] = max(p,np);
    return dp[ind][w];
}
int main(){
    int n  , w;
    cin >> n >> w;
    int val[n],wei[n];
    for(int i = 0 ; i < n ; i ++){
        cin >> val[i];
        cin >> wei[i];
    }
    memset(dp,-1,sizeof(dp));
    cout << Fun(0,w,val,wei,n);
}