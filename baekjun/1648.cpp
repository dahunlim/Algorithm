#include <iostream>
#include <cstring>

using namespace std;
int n, m;
int dp[196][1<<14];

int solve(int num, int state){
    if(num == n*m && state == 0) return 1;
    if(num >= n*m) return 0;
    if(dp[num][state] >= 0) return dp[num][state];

    int &ret = dp[num][state];
    ret = 0;

    if(state & 1) ret = solve(num+1, (state >> 1)); //현재위치에 놓여있음 
    else{
        ret = solve(num+1, (state >> 1) | (1 << (m-1))); //세로
        if((num % m) != (m-1) && (state & 2) == 0){ //가로
            ret += solve(num+2, (state >> 2)); //새로운길이므로 +=
        }
    }
    ret %= 9901;
    return ret;
}

int main(){
    cin >> n >> m;
    memset(dp, -1, sizeof(dp));

    cout << solve(0, 0) << "\n";
    return 0;
}