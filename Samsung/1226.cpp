#include <iostream>
#include <stdio.h>
#include <cstring>

using namespace std;
int map[16][16];
int visit[16][16];
int ax[4] = {0, 0, 1, -1};
int ay[4] = {1, -1, 0, 0};
typedef struct {
    int x;
    int y;
} cordi;
cordi startP, endP;
int ans;
        
void dfs(int x, int y) {
    if(x == endP.x && y == endP.y) {
        ans = 1;   
        return ;
    }
    for(int i=0; i<4; i++){
        int nx = x + ax[i];
        int ny = y + ay[i];

        if(nx >= 0 && nx < 16 && ny >= 0 && ny <16){
            if(!visit[nx][ny] && map[nx][ny] != 1){
                visit[nx][ny] = 1;
                dfs(nx, ny);
            }
        }
    }
    return ;
}

int main(){
    for(int tc=1; tc<=10; tc++) {
        int T;
        cin >> T;
        ans = 0;
        memset(map, 0, sizeof(map));
        memset(visit, 0, sizeof(visit));
        for(int i=0; i<16; i++) for(int j=0; j<16; j++) {
            scanf("%1d", &map[i][j]);
            if(map[i][j] == 2) {
                startP.x = i;
                startP.y = j;
            } else if(map[i][j] == 3) {
                endP.x = i;
                endP.y = j;
            }
        }
        visit[startP.x][startP.y] = 1;
        dfs(startP.x, startP.y);
        printf("#%d %d\n", tc, ans);
    }
    return 0;
}