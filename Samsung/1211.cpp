//1211. [S/W 문제해결 기본] 2일차 - Ladder2
#include <stdio.h>
#include <iostream>
#include <cstring>
using namespace std;
int map[101][101];
int ax[3] = {1, 0, 0};
int ay[3] = {0, -1, 1};
int now;

void search(int x, int y, int dir, int depth){
    //dir 0, 1, 2 : 아래 왼쪽 오른쪽
    if(x == 99) {
        // printf("%d %d %d %d\n", x, y, dir, depth);
        now = depth + 1;
        return ;
    }

    if(!dir) {
        int flag = 0; 
        for(int i=1; i<=2; i++){
            int nx = x + ax[i];
            int ny = y + ay[i];
            if(nx >= 0 && nx < 100 && ny >= 0 && ny < 100){
                if(map[nx][ny]){
                  search(nx, ny, i, depth + 1);
                  flag = 1;
                }
            }
        }
        if(!flag) {
            search(x + 1, y, dir, depth + 1);
        }        
    } else {
        int nx = x + ax[0];
        int ny = y + ay[0];
        if(nx >= 0 && nx < 100 && ny >= 0 && ny < 100) {
            if(map[nx][ny]) {
                search(nx, ny, 0, depth + 1);
            }
            else {
                search(x + ax[dir], y + ay[dir], dir, depth + 1);
            }
        }
    }
    return ;
}

int main() {
    for(int tc=1; tc<=10; tc++) {
        int T, ansY, ans;
        cin >> T;

        ans = 10001;
        memset(map, 0, sizeof(map));

        for(int i=0; i<100; i++) for(int j=0; j<100; j++) {
            cin >> map[i][j];
        }

        for(int j=0; j<100; j++) {
            if(map[0][j]) {
                search(0, j, 0, 1);
                if(ans > now) {  
                    ans = now;
                    ansY = j;
                }
            }
        }
        printf("#%d %d\n", tc, ansY); 
    }
    return 0;
}