#include <iostream>
#include <queue>
#include <tuple>
#include <cstring>
#include <utility>
using namespace std;
int M, N, sx, sy, sd, ex, ey, ed, map[100][100], check[100][100][4];
int dx[4] = {0, 0, 1, -1};
int dy[4] = {1, -1, 0, 0};
int main(){
    //input
    cin >> M >> N;
    for(int i=0; i<M; i++) for(int j=0; j<N; j++){
        cin >> map[i][j];
    }
    cin >> sx >> sy >> sd;
    cin >> ex >> ey >> ed;
    //search bfs
    queue<tuple<int, int, int, int>> q; //x y dir ord
    q.push(make_tuple(sx-1, sy-1, sd-1, 0));
    check[sx-1][sy-1][sd-1] = 1;
    while(!q.empty()){
        int x = get<0>(q.front());
        int y = get<1>(q.front());
        int dir = get<2>(q.front());
        int ord = get<3>(q.front());
        q.pop();
        if(x == ex-1 && y == ey-1 && dir == ed-1){
            cout << ord;
            return 0;
        }
        //order 1
        for(int i=1; i<4; i++){
            int ax = x + dx[dir]*i;
            int ay = y + dy[dir]*i;

            if(ax < 0 || ax >= M || ay < 0 || ay >= N || check[ax][ay][dir] == 1) continue;
            if(map[ax][ay] == 1) break;

            q.push(make_tuple(ax, ay, dir, ord+1));
            check[ax][ay][dir] = 1;
        }
        //order 2
        for(int i=0; i<2; i++){
            int idx;
            if(dir / 2 == 0) idx = 2;
            if(dir / 2 == 1) idx = 0;

            if(map[x][y] == 1 || check[x][y][idx+i] == 1) continue;

            q.push(make_tuple(x, y, idx+i, ord+1));
            check[x][y][idx+i] = 1;
       }
    }
    return 0;
}