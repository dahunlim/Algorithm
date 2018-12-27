#include <iostream>
#include <cstring>
using namespace std;
int n, result, map[100001], dp[100001];
int main(){
    cin >> n;
    for(int i=1; i<=n; i++) cin >> map[i];
    for(int i=1; i<=n; i++){
        if(dp[i-1] + map[i] > map[i]) dp[i] = dp[i-1] + map[i];
        else dp[i] = map[i];
    }
    result = dp[1];
    for(int i=1; i<=n; i++) if(dp[i] > result) result = dp[i];
    cout << result;
    return 0;
}