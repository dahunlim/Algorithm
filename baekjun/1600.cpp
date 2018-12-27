#include <iostream>
#include <utility>
#include <queue>
#include <tuple>
#include <cstring>
using namespace std;
int K, W, H, ans, nx, ny;
int map[200][200];
int check[200][200][31];
int dx[4] = {0, 0, 1, -1};
int dy[4] = {1, -1, 0, 0};
int hx[8]= {-2, -2, -1, -1, 1, 1, 2, 2};
int hy[8] = {-1, 1, -2, 2, -2, 2, -1, 1};
int solve(int x, int y){
    queue<tuple<int, int, int>> q;
    q.push(make_tuple(x, y, 0));
    while(!q.empty()){
        nx = get<0>(q.front());
        ny = get<1>(q.front());
        int njc = get<2>(q.front());
        int ax, ay;
        if(nx == W-1 && ny == H-1){
            return check[ny][nx][njc];
        }
        q.pop();
        if(njc != K){
            for(int i=0; i<8; i++){
                ax = nx + hx[i];
                ay = ny + hy[i];
                if(ax < 0 || ax >= W || ay < 0 || ay >= H) continue;
                if(map[ay][ax] == 1 || check[ay][ax][njc+1] != 0) continue;
                q.push(make_tuple(ax, ay, njc+1));
                check[ay][ax][njc+1] = check[ny][nx][njc] + 1;
            }
        }
        for(int i=0; i<4; i++){
            ax = nx + dx[i];
            ay = ny + dy[i];
            if(ax < 0 || ax >= W || ay < 0 || ay >= H) continue;
            if(map[ay][ax] == 1 || check[ay][ax][njc] != 0) continue;
            q.push(make_tuple(ax, ay, njc));
            check[ay][ax][njc] = check[ny][nx][njc] + 1;
        }
    }
}
int main(){
    memset(check, 0, sizeof(check));
    cin >> K;
    cin >> W >> H;
    for(int i=0; i<H; i++) for(int j=0; j<W; j++){
        cin >> map[i][j];
    }
    ans = solve(0,0);
    if(nx != H-1 && nx != W-1) cout << "-1";
    else cout << ans;
    return 0;
}