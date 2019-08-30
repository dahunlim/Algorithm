// 17142 연구소3
#include <iostream>
#include <cstring>
#include <stdlib.h>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;

int map[51][51];
int visit[51][51];
int N, M, K, temp, minnum, result;
int ax[4] = {0, 0, 1, -1};
int ay[4] = {1, -1, 0, 0};
typedef struct {int r; int c;} cordi;
vector<cordi> virus;
vector<cordi> pick;
queue<cordi> q;
void bfs() {
    int infect = 0, times = 0;
    while(!q.empty()) {
        int x = q.front().r;
        int y = q.front().c;
        q.pop();

        for(int i=0; i<4; i++) {
            int nx = x + ax[i];
            int ny = y + ay[i];

            if(nx < 0 || nx >= N || ny < 0 || ny >= N) continue;
            if(map[nx][ny] != 1 && visit[nx][ny] == -1) {
                visit[nx][ny] = visit[x][y] + 1;
                if(map[nx][ny] == 0) {
                    infect += 1;
                    times = visit[nx][ny];
                }
                q.push({nx, ny});
            }
        }
    }
    if(infect == K && result > times) result = times;
}
void choose(int cnt) {
    if(cnt == virus.size()) {
        if(pick.size() == M) {
            memset(visit, -1, sizeof(visit));
            
            for(int i=0; i<pick.size(); i++) {
                q.push(pick.at(i));
                visit[pick.at(i).r][pick.at(i).c] = 0;
            }
            bfs();
        }
        return ;
    }

    pick.push_back(virus.at(cnt));
    choose(cnt+1);
    pick.pop_back();

    choose(cnt+1);
}
int main() {
    cin >> N >> M;
    K = 0;
    for(int i=0; i<N; i++) for(int j=0; j<N; j++) {
        cin >> map[i][j];
        if(map[i][j] == 2) virus.push_back({i, j});
        if(map[i][j] == 0) K++;
    }
    result = 987654321;
    choose(0);
    if(result == 987654321) result = -1;
    cout << result;
    return 0;
}