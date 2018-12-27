#include <iostream>
using namespace std;
int N, a, x[2001], y[2001];
int dp[2001][2001];
int main(){
    cin >> N;
    for(int i=0; i<N; i++) cin >> x[i];
    for(int i=0; i<N; i++) cin >> y[i];
    dp[0][0] = (x[0]-y[0])*(x[0]-y[0]);
    for(int i=1; i<N; i++) dp[i][0] = dp[i-1][0] + (x[i]-y[0])*(x[i]-y[0]);
    for(int i=1; i<N; i++) dp[0][i] = dp[0][i-1] + (x[0]-y[i])*(x[0]-y[i]);
    for(int i=1; i<N; i++) for(int j=1; j<N; j++){
        dp[i][j] = min(dp[i-1][j-1] + (x[i]-y[j])*(x[i]-y[j]), 
                   min(dp[i][j-1]+(x[i]-y[j])*(x[i]-y[j]),
                       dp[i-1][j]+(x[i]-y[j])*(x[i]-y[j])));
    }
    cout << dp[N-1][N-1];
    return 0;
}