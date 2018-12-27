#include <iostream>
#include <queue>
#include <utility>

using namespace std;

int main(){

    int t=0;
    int ax[4] = {1, -1, 0, 0};
    int ay[4] = {0, 0, 1, -1};

    while(true){
        t++;
        int n;
        int map[125][125];
        int check[125][125]={};
    
        queue<pair<int, int>> q1;

        cin >> n;
        if(n == 0) break;

        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                cin >> map[i][j];
                check[i][j] = 3000;
            }
        }

        int x=0, y=0;
        q1.push(make_pair(x,y));
        check[0][0] = map[0][0];

        while(!q1.empty()){
            x = q1.front().first;
            y = q1.front().second;
            q1.pop();
            
            for(int i=0; i<4; i++){
                int nx = x + ax[i];
                int ny = y + ay[i];

                if (0 <= nx && nx < n && 0 <= ny && ny < n){
                    if(check[x][y] + map[nx][ny] < check[nx][ny]){
                        check[nx][ny] = check[x][y] + map[nx][ny];
                        q1.push(make_pair(nx, ny));
                    }
                }
            }
        }
        cout << "Problem " << t << ": " << check[n-1][n-1] << "\n";
    }
    return 0;
}