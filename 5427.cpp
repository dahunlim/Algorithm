#include <iostream>
#include <queue>
#include <cstring>
#include <utility>
#include <vector>
using namespace std;
int T, w, h, result, sx, sy;
int dx[4] = {0, 0, 1, -1};
int dy[4] = {1, -1, 0, 0};
char map[1000][1000];
bool check[1000][1000];
vector<pair<int, int>> v;
vector<int> v1;
typedef struct cord{
    int x;
    int y;
    int time;
    bool type;
} cordi;

int bfs(){
    queue<cordi> q;

    for(int i=0; i<v.size(); i++) q.push(cordi{v[i].first, v[i].second, 0, 0});
    q.push(cordi{sx, sy, 0, 1});
    check[sx][sy] = 1;
    while(!q.empty()){
        int nx = q.front().x;
        int ny = q.front().y;
        int nt = q.front().time;
        int ntp = q.front().type;
        q.pop();
        for(int i=0; i<4; i++){
            int ax = nx + dx[i];
            int ay = ny + dy[i];

            if(ntp){
                if(map[ax][ay] == '#' || map[ax][ay] == '*' || check[ax][ay] != 0) continue;

                if(ax < 0 || ax >= h || ay < 0 || ay >= w) return nt + 1;
                
                q.push(cordi{ax, ay, nt+1, ntp});
                check[ax][ay] = 1;
            }
            else{
                if(ax < 0 || ax >= h || ay < 0 || ay >= w) continue;
                if(map[ax][ay] == '#' || map[ax][ay] == '*') continue;

                q.push(cordi{ax, ay, nt, ntp});
                map[ax][ay] = '*';
            }
        }
    }
    return 0;
}
int main(){
    //freopen("F.in", "r", stdin);
    cin >> T;
    while(T--){
        cin >> w >> h;
        v.clear();
        memset(check, 0, sizeof(check));
        memset(map, 0, sizeof(map));
        for(int i=0; i<h; i++) for(int j=0; j<w; j++){
            cin >> map[i][j];
            if(map[i][j] == '@'){
                sx = i;
                sy = j;
            }
            if(map[i][j] == '*'){
                v.push_back(make_pair(i, j));
            }            
        }
        result = bfs();
        if(result) cout << result << endl;
        else cout << "IMPOSSIBLE\n";
    }
    return 0;
}