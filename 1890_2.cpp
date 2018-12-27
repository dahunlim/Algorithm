#include <iostream>

using namespace std;

int N;
int map[100][100];
long dp[100][100];
long solve(int a, int b){
    if(a == N-1 && b == N-1) return 1;
    long &ans = dp[a][b];
    if(ans != -1) return ans;
    ans = 0;

    if(a + map[a][b] < N) ans += solve(a+map[a][b], b);
    if(b + map[a][b] < N) ans += solve(a, b+map[a][b]);
    
    return ans;
}

int main(){
    cin >> N;
    for(int i=0; i<N; i++) {
        for(int j=0; j<N; j++) {
            cin >> map[i][j];
            dp[i][j] = -1;
        }
    }
    cout << solve(0, 0);

    return 0;
}