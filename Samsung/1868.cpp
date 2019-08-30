#include <stdio.h>
#include <iostream>
#include <cstring>
#include <queue>

using namespace std;

char base[302][302];
int map[302][302];
bool visit[302][302];
int ax8[8] = {-1, -1, -1, 0, 1, 1, 1, 0};
int ay8[8] = {-1, 0, 1, 1, 1, 0, -1, -1};
int ax4[4] = {0, 0, 1, -1};
int ay4[4] = {1, -1, 0, 0};

typedef struct {
    int x;
    int y;
} cordi;

int main() {
    int T, N;
    scanf("%d", &T);
    for(int tc = 1; tc <= T; tc++){
        memset(base, 0, sizeof(base));
        memset(map, 0, sizeof(map));
        memset(visit, 0, sizeof(visit));
        scanf("%d", &N);
        int result = 0;
        for(int i=0; i<N; i++) {
            scanf("%s", &base[i]);
            for(int j=0; j<N; j++) {
                if(base[i][j] == '*') {
                    map[i][j]++;
                    for(int k=0; k<8; k++){
                        int nx = i + ax8[k];
                        int ny = j + ay8[k];
                        if(nx >= 0 && nx < N && ny >= 0 && ny < N){
                            map[nx][ny]++;
                        }
                    }
                }
            }
        }
        for(int i=0; i<N; i++) for(int j=0; j<N; j++) {
            if(base[i][j] == '*') { 
                visit[i][j] = true;
                continue;
            } else {
                if(map[i][j] == 0 && visit[i][j] == false) {
                    queue<cordi> q;
                    visit[i][j] = true;
                    q.push({i, j});
                    result += 1;
                    while(!q.empty()){
                        int x = q.front().x;
                        int y = q.front().y;
                        q.pop();
                        for(int k=0; k<8; k++) {
                            int nx = x + ax8[k];
                            int ny = y + ay8[k];

                            if(nx >= 0 && nx < N && ny >= 0 && ny < N && visit[nx][ny] == false) {
                                if(map[nx][ny] == 0) {
                                    q.push({nx, ny});
                                }
                                visit[nx][ny] = true;
                            }
                        }
                    }
                }
            }
        }

        for(int i=0; i<N; i++) {
            for(int j=0; j<N; j++) {
                if(!visit[i][j]) result += 1;
            }
        }
        printf("#%d %d\n", tc, result);
    }
    return 0;
}