// 1258. [S/W 문제해결 응용] 7일차 - 행렬찾기
#include <iostream>
#include <stdio.h>
#include <cstring>
#include <vector>
#include <algorithm>
using namespace std;
int n;
int map[101][101];
int visit[101][101];
typedef struct {
    int size;
    int x;
    int y;
} result;
vector<result> v;

bool cmp(const result &r1, const result &r2) {
    if(r1.size < r2.size) {
        return true;
    } else if(r1.size == r2.size) {
        return r1.x < r2.x;
    } else {
        return false;
    }
}
void search() {

    for(int i=0; i<n; i++) for(int j=0; j<n; j++) {
        // cout << i << " " << j << endl;
        result val;
        if(map[i][j] != 0 && visit[i][j] == 0) {
            for(int k=0; k < n-j; k++) {
                if(map[i][j+k] == 0) break;
                visit[i][j+k] = 1;
                val.y = k + 1;
            }
            for(int k=0; k < n-i; k++) {
                if(map[i+k][j] == 0) break;
                visit[i+k][j] = 1;
                val.x = k + 1;
            }
            for(int vx=i; vx<i+val.x; vx++) for(int vy=j; vy<j+val.y; vy++) {
                // cout << vx << " " << vy << " ";
               visit[vx][vy] = 1;
            }
            // cout << i << j << " " << val.x << val.y << endl;
            val.size = val.x * val.y;
            v.push_back(val);
            // for(int ab=0; ab<n; ab++) {
            //     for(int cd=0; cd<n; cd++) {
            //         cout << visit[ab][cd]; 
            //     }
            //     cout << endl;
            // }
            // cout << endl;
        }
    }

    return ;
}
int main() {
    int T;
    cin >> T;
    for(int tc = 1; tc <= T; tc++) {
        memset(map, 0, sizeof(map));
        memset(visit, 0, sizeof(visit));
        v.clear();
        cin >> n;
        for(int i=0; i<n; i++) for(int j=0; j<n; j++) {
            cin >> map[i][j];
        }
        search();
        sort(v.begin(), v.end(), cmp);
        cout << "#" << tc << " " << v.size();
        for(int i=0; i<v.size(); i++) {
            cout << " " << v.at(i).x << " " << v.at(i).y;
        }
        cout << endl;
    }
    return 0;
}