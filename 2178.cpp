#include <iostream>
#include <cstdio>
#include <queue>
#include <utility>

using namespace std;

int main(void){
    int m, n, k;
    int ax[4] = {0, 0, 1, -1};
    int ay[4] = {1 , -1 , 0, 0};
    cin >> m >> n;
    
    long map[101][101] = {};
    long check[101][101] = {};
    long result[101][101] = {};
    queue<pair<int, int>> q;

    for(int i=0; i<m; i++){
        //cin >> k;
        for(int j=0;j<n;j++){
            int a;
            scanf("%1d",&a);
            map[i][j] = a;
        }            
    }

    q.push(make_pair(0,0));
    result[0][0] = 1;
    check[0][0] = 1;

    while(!q.empty()){
        int x = q.front().first;
        int y = q.front().second;
        
        q.pop();
        if(x == (m-1) && y == (n-1)){
            break;
        }

        for(int i=0; i<4; i++){
            int nx = x + ax[i];
            int ny = y + ay[i];

            if(nx >= 0 && nx < m && ny >= 0 && ny < n){
                if(map[nx][ny] == 1 && check[nx][ny] == 0){
                    q.push(make_pair(nx, ny));
                    check[nx][ny] = 1;
                    result[nx][ny] = result[x][y] + 1;
                }
            }
        }
    }
    
    cout << result[m-1][n-1];
    return 0;
}