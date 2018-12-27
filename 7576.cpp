#include <iostream>
#include <utility>
#include <queue>

using namespace std;

int map[1001][1001];
int check[1001][1001];
int ax[4] = {-1, 0, 0, 1};
int ay[4] = {0, 1, -1, 0};

int main(void){

    queue<pair<int,int>> q; 
    int m, n;
    cin >> n >> m;

    for(int i=0; i<m; i++){
        for(int j=0; j<n; j++){
            int k;
            cin >> k;
            map[i][j] = k;
            check[i][j] = -1;
            if(k==1){
                check[i][j] = 0;
                q.push(make_pair(i,j));
            }
        }
    }

    while(!q.empty()){
        int x = q.front().first;
        int y = q.front().second;
        q.pop();
        for(int i = 0; i<4; i++){
            int nx = x + ax[i];
            int ny = y + ay[i];

            if(0 <= nx && nx <= m && 0 <= ny && ny <= n && map[nx][ny] == 0 && check[nx][ny] == -1){
                check[nx][ny] = check[x][y] + 1;
                q.push(make_pair(nx,ny));
            }
        }        
    }
for(int i = 0; i<m;i++){
    for(int j=0; j<n;j++){
        cout << check[i][j] << " ";
    }
    cout << "\n";
}
    int max = 0;
    for(int i = 0; i<m; i++){
        for(int j = 0; j<n; j++){
            if(max < check[i][j]){
                max = check[i][j];
            }
        }
    }

    for(int i = 0; i<m; i++){
        for(int j = 0; j<n; j++){
            if(map[i][j] == 0 && check[i][j] == -1){
                max = -1;
            }
        }
    }

    cout << max;
    return 0;
}


