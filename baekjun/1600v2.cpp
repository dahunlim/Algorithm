#include <iostream>
#include <queue>
#include <tuple>
#include <utility>
using namespace std;
int K, W, H, x, y, jc, ac, ax, ay;
int map[201][201];
bool check[201][201][31] = {false};
int dx[4] = {0, 0, 1, -1};
int dy[4] = {1, -1, 0, 0};
int hx[8] = {-2, -2, -1, -1, 1, 1, 2, 2};
int hy[8] = {-1, 1, -2, 2, -2, 2, -1, 1};
queue<tuple<int, int, int, int>> q;
int main(){
    cin >> K >> W >> H;
    for(int i=0; i<H; i++) for(int j=0; j<W; j++){
        cin >> map[i][j];
    }
    q.push(make_tuple(0, 0, K, 0));
    
    while(!q.empty()){
        x = get<0>(q.front());
        y = get<1>(q.front());
        jc = get<2>(q.front());
        ac = get<3>(q.front());
        q.pop();
        if(x < 0 || x >= W || y < 0 || y >= H) continue;
        if(map[y][x]) continue;
        
        if(x == W-1 && y == H-1){
            cout << ac;
            return 0;
        }

        if(check[y][x][jc]) continue;
        check[y][x][jc] = true;
    
        for(int i=0; i<4; i++){
            ax = x + dx[i];
            ay = y + dy[i];  
            q.push(make_tuple(ax, ay, jc, ac+1));
        }
        if(jc == 0) continue;
        for(int i=0; i<8; i++){
            ax = x + hx[i];
            ay = y + hy[i];
            q.push(make_tuple(ax, ay, jc-1, ac+1));   
        }
    }
    cout << "-1";
    return 0;
}