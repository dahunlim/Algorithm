#include <iostream>
#include <math.h>
using namespace std;
int N, r, c, idx;
int map[2][2];
int solve(int x, int y, int now){
    int range = pow(2, now) / 2;
    if(now == 1){
        return map[x][y];
    }
    if(x < range && y < range){
        return solve(x, y, now-1);
    }
    else if(x < range && y >= range){
        return solve(x, y-range, now-1) + range*range;
    }
    else if(x >= range && y < range){
        return solve(x-range, y, now-1) + range*range*2;
    }
    else{
        return solve(x-range, y-range, now-1) + range*range*3;
    }
}
int main(){
    cin >> N >> r >> c;
    map[0][0] = 0;
    map[0][1] = 1;
    map[1][0] = 2;
    map[1][1] = 3;
    cout << solve(r, c, N);
    
    return 0;
}