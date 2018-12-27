#include <iostream>
#include <cstring>
#define INF 987654321
using namespace std;
int N, map[16][16], dp[16][1<<16];
int solve(int now, int state){
    if(state == (1<<N)-1){
        if(map[now][0] != 0) return map[now][0];
        else return INF;
    } 
    
    int &ans = dp[now][state];
    if(ans != -1) return ans;
    ans = INF;
    
    for(int i=0; i<N; i++){
        if(state & (1<<i)) continue;
        if(map[now][i] == 0) continue;
        ans = min(ans, map[now][i] + solve(i, state | (1<<i)));
    }
    return ans;
}
int main(){
    cin >> N;
    for(int i=0; i<N; i++) for(int j=0; j<N; j++) cin >> map[i][j];
    memset(dp, -1, sizeof(dp));
    cout << solve(0, 1);
    return 0;
}