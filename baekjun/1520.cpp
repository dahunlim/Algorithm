#include <iostream>
#include <cstring>
using namespace std;
int N, M, map[500][500], dp[500][500];
int ax[4] = {0, 0, 1, -1};
int ay[4] = {1, -1, 0, 0};
int solve(int x, int y){
    if(x == N-1 && y == M-1) return 1;

    int &ans = dp[x][y];
    if(ans != -1) return ans;
    ans = 0;
    for(int i=0; i<4; i++){
        int a = x + ax[i];
        int b = y + ay[i];
        if(a < 0 || b < 0 || a >= N || b >= M || (map[x][y] <= map[a][b])) continue;
        ans += solve(a, b);
    }
    return ans;
}
int main(){
    cin >> N >> M;
    for(int i=0; i<N; i++) for(int j=0; j<M; j++) cin >> map[i][j];
    memset(dp, -1, sizeof(dp));
    cout << solve(0,0);
    return 0;
}