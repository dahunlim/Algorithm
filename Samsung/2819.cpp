#include <iostream>
using namespace std;

int ax[4] = {0, 0, 1, -1};
int ay[4] = {1, -1, 0, 0};
int result;
int map[4][4];
bool chk[10000000];

void dfs(int x, int y, int value, int depth){
    if(depth == 7) {
        if(!chk[value]) result++; chk[value] = true;
        return ;
    }
    value *= 10;
    value += map[x][y];
    
    for(int i=0; i<4; i++){
        int nx = x + ax[i];
        int ny = y + ay[i];

        if(nx < 0 || nx >= 4 || ny < 0 || ny >= 4) continue;
        dfs(nx, ny, value, depth+1);
    }
}

int main() {
    int T;
    cin >> T;
    //TC 반복
    for(int TC = 0; TC < T; TC++) {
        //초기조건
        for(int i=0; i<10000000; i++) chk[i] = 0;
        result = 0;
        //격자판 입력
        for(int i=0; i<4; i++) for(int j=0; j<4; j++) {
            cin >> map[i][j];
        }
        
        //격자판 탐색위치 지정
        for(int i=0; i<4; i++) for(int j=0; j<4; j++) {
            dfs(i, j, 0, 0);
        }
        cout << "#" << TC+1 << " " << result << endl;
    }
    return 0;
}