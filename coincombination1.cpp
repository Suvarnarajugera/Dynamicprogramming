#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll dp[1000001];
ll mod = 1e9+7;
int Fun(ll k,ll arr[],ll n){
    if(k < 0)return 0;
    if(k == 0)return 1;
    if(dp[k] != -1)return dp[k];
    ll ans = 0;
    for(int i = 0 ; i < n ; i++){
        ans += Fun(k-arr[i],arr,n);
    }
    return dp[k] = ans % mod;
}
int main(){
    ll n,k;
    cin >> n >> k;
    ll arr[n];
    for(int i = 0 ; i < n ; i++){
        cin >> arr[i];
    }
    memset(dp,-1,sizeof(dp));
    cout << Fun(k,arr,n);
}