#include <iostream>
using namespace std;
int ax[4] = {0, 0, 1, -1};
int ay[4] = {1, -1, 0, 0};
int map[4][4];
bool chk[10000000];
int result;

void dfs(int x, int y, int value, int depth){
    if(depth == 7) {
        if(!chk[value]) {
            chk[value] = true; 
            result++;
        }
        return ;
    }
    value *= 10;
    value += map[x][y];
    for(int i=0; i<4; i++){
        int nx = x + ax[i];
        int ny = y + ay[i];
        //if(nx >= 0 && nx < 4 && ny >= 0 && ny < 4) dfs(nx, ny, value, depth+1);
        if(nx < 0 || nx >= 4 || ny < 0 || ny >= 4) continue;
        dfs(nx, ny, value, depth+1);
    }
}
int main() {
    int T;
    cin >> T;
    for(int tc = 0; tc < T; tc++){
        //조건 초기화
        result = 0;
        for(int i=0; i<10000000; i++) chk[i] = false;
        
        //입력부
        for(int i=0; i<4; i++) for(int j=0; j<4; j++) cin >> map[i][j];
        
        //실행
        for(int i=0; i<4; i++) for(int j=0; j<4; j++) dfs(i, j, 0, 0);

        cout << "#" << tc + 1 << " " << result << endl;
    }
    return 0;
}