#include<bits/stdc++.h>
using namespace std;
int dp[100001][3];
int Fun(int i,int j, vector<vector<int>> &arr,int n){
    if(i >= n)return 0;
    int x = INT_MIN, y = INT_MIN, z = INT_MIN;
    if(dp[i][j] != -1) return dp[i][j];
    if(j == 0) x = max(Fun(i + 1, j + 1, arr, n), Fun(i + 1, j + 2, arr, n));
    if(j == 1) y = max(Fun(i + 1, j - 1, arr, n), Fun(i + 1, j + 1, arr, n));
    if(j == 2) z = max(Fun(i + 1, j - 1, arr, n), Fun(i + 1, j - 2, arr, n));
    int ans = max(x, y);
    return dp[i][j] = arr[i][j] + max(ans, z);    
}
int main(){
    int n;
    cin >> n;
    vector<vector<int>>arr;
    for(int i = 0 ; i < n ;i++){
        int A ,B , C ;
        cin >> A >> B >> C;
        arr.push_back({A,B,C});
    }
    memset(dp,-1,sizeof(dp));
    int ans = INT_MIN;
    for(int i = 0; i < 3; i++){
        ans = max(Fun(0, i, arr, n), ans);
    }
    cout << ans;
}