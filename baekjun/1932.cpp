#include <iostream>
#include <cstring>
using namespace std;
int n, map[500][500], dp[500][500];

int main(){
    memset(dp, 0, sizeof(dp));
    cin >> n;
    for(int i=0; i<n; i++) for(int j=0; j<=i; j++) cin >> map[i][j];
    for(int i=0; i<n; i++) dp[n-1][i] = map[n-1][i];
    
    for(int i=n-2; i>=0; i--){
        for(int j=0; j<=i; j++){
            dp[i][j] = max(map[i][j] + dp[i+1][j], map[i][j] + dp[i+1][j+1]);
        }
    }
    
    cout << dp[0][0];
    return 0;
}