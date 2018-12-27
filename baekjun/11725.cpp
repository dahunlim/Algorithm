#include <iostream>
#include <cstring>
using namespace std;
int n, dp[2000][1<<2];
int solve(int num, int state){
    if(num == n*2 && state == 0) return 1;
    if(num >= n*2) return 0;
    if(dp[num][state] >= 0) return dp[num][state];

    int &ret = dp[num][state];
    ret = 0;

    if(state & 1) ret = solve(num+1, (state >> 1)); //현재위치에 놓여있음 
    else{
        ret = solve(num+1, (state >> 1) | (1 << 1)); //세로
        if((num % 2) != 1 && (state & 2) == 0){ //가로
            ret += solve(num+2, (state >> 2)); //새로운길이므로 +=
        }
    }
    ret %= 10007;
    return ret;
}

int main(){
    cin >> n;
    memset(dp, -1, sizeof(dp));
    cout << solve(0, 0);
    return 0;
}