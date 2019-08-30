#include <iostream>
#include <cstring>
#include <stdio.h>
#include <queue>
using namespace std;

int ax[4] = {0, 0, 1, -1};
int ay[4] = {1, -1, 0, 0};
int map[101][101];
int chk[101][101];
int T, N;
typedef struct {
    int x;
    int y;
} cordi;


int main() {
    cin >> T;
    for(int tc = 1; tc <= T; tc++){
        int ans = 0;
        queue<cordi> q;
        memset(map, 0, sizeof(map));
        for(int i=0; i<101; i++) for(int j=0; j<101; j++) chk[i][j] = 99999;

        cin >> N;
        for(int i=0; i<N; i++) for(int j=0; j<N; j++) scanf("%1d", &map[i][j]);
        chk[0][0] = 0;
        q.push({0, 0});
        while(!q.empty()){
            int x = q.front().x;
            int y = q.front().y;
            q.pop();

            for(int i=0; i<4; i++){
                int nx = x + ax[i];
                int ny = y + ay[i];

                if(nx >= 0 && nx < N && ny >= 0 && ny < N) {
                    int next = map[nx][ny];
                    if(chk[x][y] + next < chk[nx][ny]){
                        chk[nx][ny] = chk[x][y] + next;
                        q.push({nx, ny});
                    }
                }
            }
        }
        cout << "#" << tc << " " << chk[N-1][N-1] << endl;
    }
    return 0;
}