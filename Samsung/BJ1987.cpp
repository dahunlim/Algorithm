// BJ1987 알파벳
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <cstring>
using namespace std;
int R, C, result, map[21][21], chk[27];
int ax[4] = {0, 0, 1, -1};
int ay[4] = {1, -1, 0, 0};
void search(int x, int y, int cnt) {
    if(cnt > result) result = cnt;
    for(int i=0; i<4; i++) {
        int nx = x + ax[i];
        int ny = y + ay[i];

        if(nx < 0 || nx >= R || ny < 0 || ny >= C) continue;
        if(chk[map[nx][ny]]) continue;
        chk[map[nx][ny]] = 1;
        search(nx, ny, cnt+1);
        chk[map[nx][ny]] = 0;
    }
}
int main() {
    result = 0;
    memset(map, 0, sizeof(map));
    memset(chk, 0, sizeof(chk));
    cin >> R >> C;
    for(int i=0; i<R; i++) for(int j=0; j<C; j++) {
        char input;
        cin >> input;
        map[i][j] = input - 65;
    }
    chk[map[0][0]] = 1;
    search(0, 0, 1);
    cout << result;
    return 0;
}