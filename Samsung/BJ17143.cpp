// 17143 낚시왕
#include <iostream>
#include <stdlib.h>
#include <cstring>
using namespace std;
typedef struct {
    int check;
    int speed;
    int dir;
    int power;
} shark;
shark map[101][101];
shark new_map[101][101];
int R, C, M, r, c, s, d, z, result;
int ax[4] = {-1, 1, 0, 0};
int ay[4] = {0, 0, 1, -1};
void move() {
    memset(new_map, 0, sizeof(new_map));
    for(int i=0; i<R; i++) for(int j=0; j<C; j++) {
        if(map[i][j].check == 1) {
            int Nspeed;
            int Ndir = map[i][j].dir;
            int Npower = map[i][j].power;
            int nx = i;
            int ny = j;
            if(Ndir < 2) Nspeed = map[i][j].speed % ((R-1)*2);
            else Nspeed = map[i][j].speed % ((C-1)*2);
            
            for(int keep=Nspeed; keep>0; keep--) {
                nx += ax[Ndir];
                ny += ay[Ndir];

                if(nx < 0 || nx >= R || ny < 0 || ny >= C) {
                    if(Ndir == 0) Ndir = 1;
                    else if(Ndir == 1) Ndir = 0;
                    else if(Ndir == 2) Ndir = 3;
                    else if(Ndir == 3) Ndir = 2;
                    nx += ax[Ndir] * 2;
                    ny += ay[Ndir] * 2; 
                }
            }

            if(new_map[nx][ny].check == 1) {
                if(new_map[nx][ny].power < Npower) {
                    new_map[nx][ny] = {1, Nspeed, Ndir, Npower};
                }
            } else {
                new_map[nx][ny] = {1, Nspeed, Ndir, Npower};
            }
        } else {
            continue;
        }
    }
    for(int i=0; i<R; i++) for(int j=0; j<C; j++) {
        map[i][j] = new_map[i][j];
    }
}
void fishing() {
    for(int man=0; man<C; man++) {
        for(int i=0; i<R; i++) {
            if(map[i][man].check == 0) continue;
            else {
                // cout << i << man << endl;
                result += map[i][man].power;
                map[i][man] = {0, 0, 0, 0};
                break;
            }
        }
        move();
    }
}
int main() {
    result = 0;
    memset(map, 0, sizeof(map));
    cin >> R >> C >> M;
    for(int i=0; i<M; i++) {
        cin >> r >> c >> s >> d >> z;
        map[r-1][c-1] = {1, s, d-1, z};
    }

    fishing();
    cout << result;
    return 0;
}