#include <iostream>
#include <cstring>

using namespace std;
int T, N;
int map[4001][1<<4];

int solve(int num, int state){
    if(num == 4*N && state == 0) return 1;
    if(num >= 4*N) return 0;
    if(map[num][state] >= 0) return map[num][state];

    int &ans = map[num][state];
    ans = 0;

    if(state & 1) ans = solve(num+1, state >> 1);
    else{
        if(num < (N-1)*4){
            ans = solve(num+1, (state >> 1) | (1 << 3));
        }
        if(num%4 != 3 && (state & 2) == 0){
            ans += solve(num+2, state >> 2);
        }
    }
    return ans;
}
int main(){
    cin >> T;
    while(T--){
        memset(map, -1, sizeof(map));
        cin >> N;
        cout << solve(0,0) << "\n";
    }
    return 0;
}