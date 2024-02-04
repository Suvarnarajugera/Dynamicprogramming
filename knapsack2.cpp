#include<bits/stdc++.h>
using namespace std;
int dp[101][100001];
long long Fun(int *wei ,int *val , int mx ,int n ,int ind){
    if(ind >= n) {
        if(mx == 0) return 0;
        return INT_MAX;
    }
    if(dp[ind][mx] != -1) return dp[ind][mx];
    long long p = INT_MAX;
    long long np = INT_MAX;
    if(val[ind] <= mx) {
        p = Fun(wei, val, mx - val[ind],n, ind + 1) + wei[ind];
    }
    np = Fun(wei,val,mx,n,ind+1);
    dp[ind][mx] = min(p, np);
    return dp[ind][mx];
}
int main(){
    int n , k;
    cin >> n >> k;
    int wei[n],val[n];
    for(int i = 0 ; i < n ; i++){
        cin >> wei[i];
        cin >> val[i];
    }
    int mx = 0;
    for(int i = 0 ; i < n ; i++){
        mx += val[i];
    }
    memset(dp,-1,sizeof(dp));
    for(int i = mx ; i >= 0 ; i--){
        long long ans = Fun(wei,val,i,n,0);
        if(ans <= k){
            cout << i ;
            break;
        }
    }
}