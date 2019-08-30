//BJ2580 스도쿠
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
using namespace std;
int map[10][10];
int chk[9][10];
int chkX[9][10];
int chkY[9][10];
int flag;
void solve(){
    int r = -1; int c = -1;
    for(int i=0; i<9; i++) {
        for(int j=0; j<9; j++) {
            if(map[i][j] == 0) {
                r = i;
                c = j;
                break;
            }
        }
        if(r != -1) break;
    }
    if(r == -1) {
        for(int i=0; i<9; i++) {
            for(int j=0; j<9; j++) {
                cout << map[i][j] << " ";
            }
            cout << endl;
        }
        exit(0);
    }
    for(int i=1; i<=9; i++) {
        if(chk[(r/3)*2+(r/3)+(c/3)][i] || chkX[r][i] || chkY[c][i]) continue;
        chk[(r/3)*2+(r/3)+(c/3)][i] = 1;
        chkX[r][i] = 1;
        chkY[c][i] = 1;
        map[r][c] = i;
        solve();
        chk[(r/3)*2+(r/3)+(c/3)][i] = 0;
        chkX[r][i] = 0;
        chkY[c][i] = 0;
        map[r][c] = 0;
    }
}
int main() {
    for(int i=0; i<9; i++) for(int j=0; j<9; j++) {
        cin >> map[i][j];
        chkX[i][map[i][j]] = 1;
        chkY[j][map[i][j]] = 1;
        chk[(i/3)*2+(i/3)+(j/3)][map[i][j]] = 1;
    }
    solve();

    return 0;
}