#include <iostream>
using namespace std;

int N;
long long dp[91][2];
int main(){
    cin >> N;
    dp[2][0] = 1;
    dp[2][1] = 0;
    
    for(int i=3; i<=N; i++){
        dp[i][0] = dp[i-1][0] + dp[i-1][1];
        dp[i][1] = dp[i-1][0];
    }
    if(N == 1) cout << "1";
    else if(N == 2) cout << "1";
    else cout << dp[N][0] + dp[N][1];
    return 0;
}