#include <iostream>

using namespace std;
int s[301];
int dp[301] = {};
int T;

int main(){
    cin >> T;
    for(int i=1; i<=T; i++){
        cin >> s[i];
    }
    dp[1] = s[1];
    dp[2] = s[1] + s[2];
    
    for(int i=3; i<=T; i++){
        dp[i] = max(dp[i-3] + s[i-1] + s[i], dp[i-2] + s[i]);
    }

    cout << dp[T];
    return 0;
}