// BJ17144 미세먼지 안녕!
#include <iostream>
#include <stdlib.h>
#include <cstring>
#include <vector>
#include <queue>
#include <math.h>
using namespace std;
int R, C, T;
int map[51][51];
int ax[4] = {0, 0, 1, -1};
int ay[4] = {1, -1, 0, 0};
typedef struct {int r; int c;} cordi;
typedef struct {int r; int c; int cnt;} infor;
vector<cordi> cleaner;
queue<cordi> dust;
void cleaning() {
    for(int i=0; i<2; i++) {
        int x = cleaner.at(i).r;
        int y = cleaner.at(i).c;
        int pre = 0;
        int temp;
        //오른쪽
        for(int j=1; j<C; j++) {
            temp = map[x][y+j];
            map[x][y+j] = pre;
            pre = temp; 
        }

        //위 or 아래
        if(i == 0) {
            for(int j=x-1; j>=0; j--) {
                temp = map[j][C-1];
                map[j][C-1] = pre;
                pre = temp;
            }
        } else {
            for(int j=x+1; j<R; j++) {
                temp = map[j][C-1];
                map[j][C-1] = pre;
                pre = temp;
            }
        }

        //왼쪽
        for(int j=C-2; j>=0; j--) {
            if(i == 0) {
                temp = map[0][j];
                map[0][j] = pre;
                pre = temp;
            } else {
                temp = map[R-1][j];
                map[R-1][j] = pre;
                pre = temp;
            }
        }

        //아래 or 위
        if(i == 0) {
            for(int j=1; j<x; j++) {
                temp = map[j][0];
                map[j][0] = pre;
                pre = temp;
            }
        } else {
            for(int j=R-2; j>x; j--) {
                temp = map[j][0];
                map[j][0] = pre;
                pre = temp;
            }
        }
    }
}
void spread() {
    int new_map[51][51] = {0, };
    int dustNum = dust.size();
    while(dustNum--) {
        int x = dust.front().r;
        int y = dust.front().c;
        dust.pop();
        int amount = map[x][y] / 5;
        for(int i=0; i<4; i++) {
            int nx = x + ax[i];
            int ny = y + ay[i];

            if(nx < 0 || nx >= R || ny < 0 || ny >= C) continue;
            if(map[nx][ny] == -1) continue;

            new_map[nx][ny] += amount;
            dust.push({nx, ny});
            map[x][y] -= amount;
            dust.push({x, y});
        }
    }
    for(int i=0; i<R; i++) for(int j=0; j<C; j++) map[i][j] += new_map[i][j];
}
int main() {
    int result = 0;
    cin >> R >> C >> T;
    for(int i=0; i<R; i++) for(int j=0; j<C; j++) {
        cin >> map[i][j];
        if(map[i][j] == -1) cleaner.push_back({i, j});
        else if(map[i][j] != 0) dust.push({i, j});
    }

    while(T--) {
        spread();
        cleaning();
        for(int i=0; i<R; i++) {
            for(int j=0; j<C; j++) {
                cout << map[i][j] << " ";
            }
            cout << endl;
        }
        cout << endl;
    }
    for(int i=0; i<R; i++) {
        for(int j=0; j<C; j++) {
            // cout << map[i][j] << " ";
            if(map[i][j] != 0 && map[i][j] != -1) {
                result += map[i][j];
            }
        }
        // cout << endl;
    }
    cout << result;
    return 0;
}