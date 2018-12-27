#include <iostream>
#include <cstring>
using namespace std;
int n, map[10000], dp[10000];
int solve(int num){
    if(num >= n) return 0;
    int &ans = dp[num];
    if(ans != -1) return ans;
    ans = 0;
    
    ans = max(solve(num-1), max(map[num] + solve(num -2), map[num]+map[num-1]+solve(num-3)));
    return ans;
}
int main(){
    cin >> n;
    memset(dp, -1, sizeof(dp));
    for(int i=0; i<n; i++) cin >> map[i];
    solve(n-1);
    cout << dp[n-1];
    return 0;
}