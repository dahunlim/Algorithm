#include <iostream>

using namespace std;

int main(){

    long dp[101][11];
    long sum=0;
    int N;
    cin >> N;
    
    dp[1][0] = 0;
    dp[1][9] = 1;
    for(int i=1; i<9; i++){
        dp[1][i] = 1;
    }

    for(int i=2; i<=N; i++){
        dp[i][0] = dp[i-1][1]%1000000000;
        dp[i][9] = dp[i-1][8]%1000000000;
        for(int j=1; j<9; j++){
            dp[i][j] = (dp[i-1][j-1] + dp[i-1][j+1])%1000000000;
        }
    }

    for(int i=0; i<=9; i++){
        sum += (dp[N][i]%1000000000);
    }
    cout << (sum%1000000000);
    return 0;
}