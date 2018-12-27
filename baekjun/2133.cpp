#include <iostream>
#include <cstring>
using namespace std;
int N, dp[901][1<<3];
int solve(int now, int state){
    if(now == 3*N && state == 0) return 1;
    if(now >= 3*N) return 0;
    int &ans = dp[now][state];
    if(ans != -1) return ans;
    ans = 0;

    if(state & 1){
        ans = solve(now + 1, state >> 1);
    }
    else{
        if(now < (N-1)*3){
            ans = solve(now + 1, (state >> 1) | (1<<2));
        }
        if((now%3 != 2) && (state & 2) == 0){ 
            ans += solve(now + 2, state >> 2);
        }
    }
    return ans;
}
int main(){
    memset(dp, -1, sizeof(dp));
    cin >> N;
    cout << solve(0,0);
    return 0;
}