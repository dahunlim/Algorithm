#include <iostream>
using namespace std;
int T, result;
bool visited[10000000];
int dx[4] = {0, 0, 1, -1};
int dy[4] = {1, -1, 0, 0};
int map[4][4] = {};
void dfs(int x, int y, int count, int val){
    if(count == 7) {
        if(visited[val] == 0) {visited[val] = 1; result++;}
        return;
    }
    val = val * 10 + map[x][y];
    for(int i=0; i<4; i++){
        int ax = x + dx[i];
        int ay = y + dy[i];

        if(ax < 0 || ax >= 4 || ay < 0 || ay >= 4) continue;
        dfs(ax, ay, count+1, val);
    }
}   
int main(){
    cin >> T;
    for(int TC = 1; TC <= T; TC++){
        result = 0;
        for(int i=0; i<4; i++) for(int j=0; j<4; j++) cin >> map[i][j];
        for(int i=0; i<10000000; i++) visited[i] = 0;
        for(int i=0; i<4; i++) for(int j=0; j<4; j++){
            dfs(i, j, 0, 0);                    
        }
        cout << "#" << TC << " " << result << "\n";
    }
    return 0;
}