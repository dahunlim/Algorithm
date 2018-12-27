#include <iostream>
#include <cstring>

using namespace std;

int map[501][501];
int check[501][501];
int ax[4] = {0, 0, 1, -1};
int ay[4] = {1, -1, 0, 0};
int n;

int solve(int x, int y){
    if(check[x][y] != 0) return check[x][y];
    check[x][y] = 1;

    for(int i=0; i<4; i++){
        int a = x + ax[i];
        int b = y + ay[i];

        if(a >= 0 && a < n && b >= 0 && b < n){
            if(map[x][y] < map[a][b]){
                check[x][y] = max(check[x][y], solve(a,b)+1);
            }
        }
        else{continue;}
    }
    return check[x][y];
}

int main(){
    int ans = 0;
    memset(check, 0, sizeof(check));
    cin >> n;
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            cin >> map[i][j];
        }
    }

    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            ans = max(ans, solve(i, j));
        }
    }

    cout << ans;
    return 0;   
}