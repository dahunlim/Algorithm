#include <iostream>
#include <stack>
#include <utility>
#include <vector>
using namespace std;
int N, x, y, d, g, last;
int ax[4] = {1, 0, -1, 0};
int ay[4] = {0, -1, 0, 1};
int map[101][101] = {};
int way(int d){
    if(d == 0) d = 1;
    else if(d == 1) d = 2;
    else if(d == 2) d = 3;
    else d = 0;
    return  d;
}
int main(){
    int result = 0;
    cin >> N;
    for(int i=0; i<N; i++){
        vector<int> v1;
        cin >> x >> y >> d >> g;
        v1.push_back(d);
        while(g--){
            last = v1.size();
            for(int j=last-1; j>=0; j--){
                v1.push_back(way(v1[j]));
            }
        }
        map[x][y] = 1;
        last = v1.size();
        for(int j = 0; j < last; j++){
            x += ax[v1[j]];
            y += ay[v1[j]];
            if(x > 100 || x < 0 || y < 0 || y > 100) break;
            map[x][y] = 1;
        }
 
    }
    for(int i=0; i<=100; i++){
        for(int j=0; j<=100; j++){
            if(map[i][j] && map[i+1][j] && map[i][j+1] && map[i+1][j+1]) result++;
        }
    }

    cout << result;
    return 0;
}
