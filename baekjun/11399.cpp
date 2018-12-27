#include <iostream>
#include <cstring>
using namespace std;
int N, P[1000], dp[1000], check[1000];
int main(){
    memset(check, -1, sizeof(check));
    cin >> N;
    int mini = 10000;
    int loc = -1;
    int ans = 0;
    for(int i=0; i<N; i++) cin >> P[i];
    
    for(int i=0; i<N; i++){
        if(P[i] < mini) {
            mini = P[i];
            loc = i;
        }
        dp[i] = 10000000;
    }
    dp[0] = mini;
    check[loc] = 1;
    
    for(int i=1; i<N; i++){
        for(int j=0; j<N; j++){
            if(check[j]!=-1) continue;
            
            if(dp[i] > (P[j] + dp[i-1])){
                dp[i] = P[j] + dp[i-1];
                loc = j;
            }
        }
        check[loc] = 1;
    }
    for(int i=0; i<N; i++) ans += dp[i];
    cout << ans;
    return 0;
}