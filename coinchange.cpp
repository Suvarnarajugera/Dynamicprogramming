#include<bits/stdc++.h>
using namespace std;
#define ll long long
int dp[1000001];
ll Fun(ll k , ll arr[] ,ll n){
    if(k < 0)return -1;
    if(k == 0){
        return 0;
    }
    if(dp[k] != -1)return dp[k];
    ll ans = INT_MAX;
    ll p = INT_MAX;
    for(int i = 0 ; i < n ; i++){
        if(arr[i] <= k){
            p = 1 + Fun(k-arr[i] , arr , n);
            ans = min(ans , p);
        }
    }
    return dp[k] = ans;
}
int main(){
    ll n , k;
    cin >> n >> k;
    ll arr[n];
    for(ll i = 0 ; i < n ; i++){
        cin >> arr[i];
    }
    memset(dp,-1,sizeof(dp));
    if(Fun(k,arr,n) >= INT_MAX)cout << -1;
    else cout << Fun(k,arr,n);
}