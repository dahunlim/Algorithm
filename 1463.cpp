#include <iostream>

using namespace std;
int dp[1000001];

int solve(int n){
    if(n==1) return 0;
    if(dp[n] != 2222222) return dp[n];
    
    int &ans = dp[n];
    if(n % 3 == 0) ans = min(ans, solve(n/3)+1);
    if(n % 2 == 0) ans = min(ans, solve(n/2)+1);
    ans = min(ans, solve(n-1)+1);

    return ans;
}

int main(){
    int X;

    cin >> X;
    for(int i=1; i<=X; i++) dp[i] = 2222222;
    cout << solve(X);
    return 0;
}