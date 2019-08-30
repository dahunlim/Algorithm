// 1849. 영준이의 무게측정
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <cstring>
using namespace std;
int T, N, M;
int map[10001][10001];
int result[10001];
int main() {
    cin >> T;
    for (int tc=1; tc<=T; tc++) {
        int a, b, w;
        char flag;
        memset(result, 0, sizeof(result));
        memset(map, 1000001, sizeof(map));
        int cnt = 0;
        cin >> N >> M;

        for(int i=0; i<M; i++) {
            cin >> flag >> a >> b >> w;
            if(flag == '!') {
                map[a][b] = -w;
                map[a][b] = w;
            } else if(flag == '?') {
                result[cnt] = map[a][b];
                cnt += 1;
            } 
        }
        cout << "#" << tc;
        for(int i=0; i<cnt; i++) {
            if(result[i] < 1000001) {
                cout << " " << result[i];
            } else {
                cout << " UNKNOWN";
            }
        }
        cout << endl;
    }
    return 0;
}