#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll dp[1000001];
ll mod = 1e9+7;
ll Fun(int n){
    if(n == 0)return 1;
    ll res = 0;
    for(int i = 1 ; i < 7 ; i++){
        if(i <= n){
            if(dp[n] != -1)return res + dp[n];
            else{
                res += Fun(n-i);
            }
        }
    }
    return dp[n] = res % mod;
    
}
int main(){
    ll n;
    cin >> n;
    memset(dp,-1,sizeof(dp));
    cout << Fun(n);
}