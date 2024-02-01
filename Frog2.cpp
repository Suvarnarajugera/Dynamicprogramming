#include<bits/stdc++.h>
using namespace std;
int dp[100000];
int Fun(int ind , int n ,int *arr , int k){
    if(ind == n-1)return 0;
    int res = INT_MAX;
    if(dp[ind] != -1)return dp[ind];
    for(int i = 1 ; i <= k ; i++){
        if(ind + i <= n-1){
            int p = abs(arr[ind]-arr[ind+i])+Fun(ind+i,n,arr,k);
            res  = min(p,res);
            dp[ind] = res;
        }
    }
    return dp[ind];

}
int main(){
    int n , k;
    cin >> n >> k;
    int arr[n];
    for(int i = 0 ; i < n ; i++){
        cin >> arr[i];
    }
    memset(dp,-1,sizeof(dp));
    cout << Fun(0,n,arr,k);
}