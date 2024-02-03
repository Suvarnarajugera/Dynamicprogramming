#include<bits/stdc++.h>
using namespace std;
// Top down approach
int dp[10001][10001];
int Fun(int i , int j , int arr[] , int n){
    // Base case
    // present year -> (n-(j-i))
    if(i == j){
        return (n-(j-i))*arr[i];
    }
    if(dp[i][j] != -1)return dp[i][j];
    // left call
    int left = (n-(j-i))*arr[i] + Fun(i+1,j,arr,n);
    // right call
    int right = (n-(j-i))*arr[j] + Fun(i,j-1,arr,n);
    return dp[i][j] = max(left,right);
}
int main(){
    int n;
    cin >> n;
    int arr[n];
    for(int i = 0 ; i < n ; i++){
        cin >> arr[i];
    }
    memset(dp,-1,sizeof(dp));
    cout << Fun(0,n-1,arr,n);
}