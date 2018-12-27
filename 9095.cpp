#include <iostream>

using namespace std;

int dp[12];

int main(){

    int T, N;
    cin >> T;
    dp[1] = 1;
    dp[2] = 2;
    dp[3] = 4;
    for(int i=4; i<=11; i++){
        if((i-1)>0) dp[i] += dp[i-1];
        if((i-2)>0) dp[i] += dp[i-2];
        if((i-3)>0) dp[i] += dp[i-3];
    }
    while(T--){
        cin >> N;
        cout << dp[N] << "\n";
    }
    return 0;
}