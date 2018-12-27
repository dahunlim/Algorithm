#include <iostream>
using namespace std;
int N, H[1001][3], dp[1001][3];
int main(){
    cin >> N;
    for(int i=1; i<=N; i++) cin >> H[i][0] >> H[i][1] >> H[i][2];
    for(int i=0; i<3; i++) H[0][i] = 0, dp[0][i] = 0;
    
    for(int i=1; i<=N; i++){
        dp[i][0] = H[i][0] + min(dp[i-1][1], dp[i-1][2]);
        dp[i][1] = H[i][1] + min(dp[i-1][0], dp[i-1][2]);
        dp[i][2] = H[i][2] + min(dp[i-1][0], dp[i-1][1]);
    }
    cout << min(dp[N][0], min(dp[N][1], dp[N][2]));
    return 0;
}