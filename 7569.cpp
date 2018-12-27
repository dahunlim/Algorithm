#include <iostream>
#include <utility>
#include <queue>
#include <tuple>

using namespace std;

int map[101][101][101];
int check[101][101][101];
int ax[6] = {1, -1, 0, 0, 0, 0};
int ay[6] = {0, 0, -1, 1, 0, 0};
int az[6] = {0, 0, 0, 0, 1, -1};

int main(void){

    queue<tuple<int,int,int>> q;

    int a, b, c;

    cin >> a >> b >> c;

    for(int i=0; i<c; i++){
        for(int j=0; j<b; j++){
            for(int k=0; k<a; k++){
                int m;

                cin >> m;
                map[k][j][i] = m;
                check[k][j][i] = -1;
                if(m == 1){
                    check[k][j][i] = 0;
                    q.push(make_tuple(k,j,i));
                }
            }
        }
    }

    while(!q.empty()){
        int x = get<0>(q.front());
        int y = get<1>(q.front());
        int z = get<2>(q.front());
        q.pop();

        for(int i=0; i<6; i++){
            int nx =  x + ax[i];
            int ny =  y + ay[i];
            int nz =  z + az[i];

            if(nx >= 0 && nx < a && ny >= 0 && ny < b && nz >= 0 && nz < c && map[nx][ny][nz] == 0 && check[nx][ny][nz] == -1){
                check[nx][ny][nz] = check[x][y][z] + 1;
                q.push(make_tuple(nx,ny,nz));
            }
        }
    }

    int max = 0;
    for(int i=0; i<c; i++){
        for(int j=0; j<b; j++){
            for(int k=0; k<a; k++){
                if(check[k][j][i] > max){
                    max = check[k][j][i];
                }
                
                if(check[k][j][i] == -1 && map[k][j][i] == 0){
                    max = -1;
                    cout << max;
                    return 0;
                }
            }
        }
    }

    cout << max;

    return 0;
}