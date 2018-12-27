#include <iostream>
#include <vector>
#include <stdio.h>
using namespace std;
int N;
int map[64][64];
vector<char> v1;
void solve(int x, int y, int idx, int idy){
    int flag = 0;
    for(int i=x; i<x+idx; i++) for(int j=y; j<y+idy; j++){
        if(map[x][y] != map[i][j]){
            flag = 1;
            break;
        }
    }
    if(flag){
        v1.push_back('(');
        solve(x, y, idx/2, idy/2);
        solve(x, y+idy/2, idx/2, idy/2);
        solve(x+idx/2, y, idx/2, idy/2);
        solve(x+idx/2, y+idy/2, idx/2, idy/2);
        v1.push_back(')');
    }
    else{
        v1.push_back(map[x][y]+48);
    }
    
    return;
}
int main(){
    cin >> N;
    for(int i=0; i<N; i++) for(int j=0; j<N; j++) scanf("%1d", &map[i][j]);
    solve(0, 0, N, N);
    for(int i=0; i<v1.size(); i++) cout << v1[i];
    return 0;
}