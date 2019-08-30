// BJ17144 미세먼지 안녕!
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <cstring>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;
int R, C, T;
int map[51][51];
typedef struct {int r;int c;} cordi;
vector<cordi> air;
queue<cordi> dust;
int ax[4] = {0, 0, 1, -1};
int ay[4] = {1, -1, 0, 0};
void spread() {
    // cout << "#" << dust.size() << endl;
    int qsize = dust.size();
    int memory[51][51] = {0, };
    for(int i=0; i<qsize; i++) {
        int x = dust.front().r;
        int y = dust.front().c;
        dust.pop();
        if(map[x][y] == 0) continue;
        int spreadDust = map[x][y] / 5;
        
        for(int k=0; k<4; k++) {
            int nx = x + ax[k];
            int ny = y + ay[k];
            if(nx < 0 || nx >= R || ny < 0 || ny >= C) continue;
            if(air.at(0).r == nx && air.at(0).c == ny) continue;
            if(air.at(1).r == nx && air.at(1).c == ny) continue;

            memory[nx][ny] += spreadDust;
            map[x][y] -= spreadDust;   
            // dust.push({nx, ny});    
        }
    }
    for(int i=0; i<R; i++) for(int j=0; j<C; j++) {
        map[i][j] += memory[i][j];
        if(map[i][j] != 0) dust.push({i, j});
    }
}

void cleaning() {
    for(int i=0; i<2; i++) {
        int airx = air.at(i).r;
        int airy = air.at(i).c;
        int temp = 0;
        int tempn = 0; 
        for(int j=1; j<C; j++) {
            tempn = map[airx][j];
            map[airx][j] = temp;
            temp = tempn;
        }
        if(i==0) {
            for(int j=airx-1; j>=0; j--) {
                tempn = map[j][C-1];
                map[j][C-1] = temp;
                temp = tempn;
            }
        } else {
            for(int j=airx+1; j<R; j++) {
                tempn = map[j][C-1];
                map[j][C-1] = temp;
                temp = tempn;
            }
        }
        if(i==0) {
            for(int j=C-2; j>=0; j--) {
                tempn = map[0][j];
                map[0][j] = temp;
                temp = tempn;
            }
        } else {
            for(int j=C-2; j>=0; j--) {
                tempn = map[R-1][j];
                map[R-1][j] = temp;
                temp = tempn;
            }
        }
        if(i==0) {
            for(int j=1; j<airx; j++) {
                tempn = map[j][0];
                map[j][0] = temp;
                temp = tempn;
            }
        } else {
            for(int j=R-2; j>airx; j--) {
                tempn = map[j][0];
                map[j][0] = temp;
                temp = tempn;
            }
        }
    }
}
int main() {
    cin >> R >> C >> T;
    for(int i=0; i<R; i++) for(int j=0; j<C; j++) {
        cin >> map[i][j];
        if(map[i][j] == -1) {
            air.push_back({i, j});
            map[i][j] = 0;
        } else if (map[i][j] != 0) {
            dust.push({i, j});
        }
    }

    while(T--) {
        spread();
        cleaning();
        // for(int i=0; i<R; i++) {
        // for(int j=0; j<C; j++) {
        //     // if(map[i][j]) result += map[i][j];
        //     printf("%2d ", map[i][j]);
        // }
        // cout << endl;
        // }
    }
    int result = 0;
    for(int i=0; i<R; i++) {
        for(int j=0; j<C; j++) {
            if(map[i][j]) result += map[i][j];
            printf("%2d ", map[i][j]);
        }
        cout << endl;
    }
    cout << result;
    return 0;
}