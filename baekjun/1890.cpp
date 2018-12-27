#include <iostream>
#include <queue>
#include <utility>

using namespace std;

int map[101][101];
long dp[101][101];

int main(void){

    int n;
    int count = 0;
    cin >> n;

    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            int m;
            cin >> m;
            map[i][j] = m;
        }
    }
    dp[0][0] = 1;

    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(map[i][j] == 0 || (i == n-1 && j == n-1)){
                continue;
            }

            int right = i + map[i][j];
            int down = j + map[i][j];

            if(right < n){
                dp[right][j] += dp[i][j];
            }

            if(down < n){
                dp[i][down] += dp[i][j];
            }
        }
    }

    cout << dp[n-1][n-1];
    return 0;
}