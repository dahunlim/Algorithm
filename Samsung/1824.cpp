#include <iostream>
#include <cstring>
using namespace std;

int ax[4] = {0, 0, -1, 1};
int ay[4] = {-1, 1, 0, 0};
//왼, 오, 위, 아
char map[20][20];
int visit[20][20][4][15];
int memory;
int R, C;

bool dfs(int x, int y, int dir){
    cout << x << " " << y << " " << dir << " " << memory << endl;
    bool ret = false;
    char now = map[x][y];
    if('0' <= now && now <= '9') memory = map[x][y] - '0';
    else if (now == '>' || (now == '_' && memory == 0)) dir = 1;
    else if (now == 'v' || (now == '|' && memory == 0)) dir = 3;
    else if (now == '<' || (now == '_')) dir = 0;
    else if (now == '^' || (now == '|')) dir = 2;
    else if (now == '+') memory = (memory + 1) % 16;
    else if (now == '-' && memory == 0) memory = 15;
    else if (now == '-') memory -= 1;
    else if (now == '@') return true;

    if(visit[x][y][dir][memory] == 1) return false;
    else visit[x][y][dir][memory] = 1;

    int nx = x + ax[dir];
    int ny = y + ay[dir];

    if(nx == R) nx = 0;
    else if(nx < 0) nx = R - 1;
    if(ny == C) ny = 0;
    else if(ny < 0) ny = C - 1;
    
    if(map[x][y] == '?'){
        for(int i=0; i<4; i++){
            nx = x + ax[i];
            ny = y + ay[i];
            if(nx == R) nx = 0;
            else if(nx < 0) nx = R - 1;
            if(ny == C) ny = 0;
            else if(ny < 0) ny = C - 1;
            ret = max(dfs(nx, ny, i), ret);
        }
        return ret;
    } else return max(dfs(nx, ny, dir), ret);
}

int main() {
    int T;
    cin >> T;
    for(int tc = 1; tc <= T; tc++) {
        cin >> R >> C;
        memory = 0;
        memset(map, -1, sizeof(map));
        memset(visit, -1, sizeof(visit));

        for(int i=0; i<R; i++) for(int j=0; j<C; j++){
            cin >> map[i][j];
        }

        cout << "#" << tc << " " << (dfs(0, 0, 1)? "YES": "NO") << endl;
    }
    return 0;
}