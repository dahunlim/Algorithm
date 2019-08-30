// 16236. 아기상어
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <cstring>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;
int N, x, y, age, result;
int map[21][21];
int visit[21][21];
int ax[4] = {0, 0, 1, -1};
int ay[4] = {1, -1, 0, 0};
typedef struct {
    int a;
    int b;
    int cost;
} cordi;
bool comp(const cordi& c1, const cordi& c2) {
    // if(c1.cost < c2.cost) {
    //     return true;
    // } else if(c1.cost == c2.cost) {
    //     if(c1.a < c2.a) {
    //         return true;
    //     } else if(c1.a == c2.a) {
    //         if(c1.b < c2.b) {
    //             return true;
    //         } else {
    //             return false;
    //         }
    //     } else {
    //         return false;
    //     }
    // } else {
    //     return false;
    // }
    return c1.cost < c2.cost || (c1.cost == c2.cost && c1.a < c2.a) || (c1.cost == c2.cost && c1.a == c2.a && c1.b < c2.b);
}

void search() {
    
    int count = age;
    int flag = 1;
    while(flag) {
        queue<cordi> q1;
        vector<cordi> v1;
        memset(visit, 0, sizeof(visit));
        visit[x][y] = 1;
        q1.push({x, y, 0});
        // cout << x << " " << y << " " << age << " " << count << endl;
        while(!q1.empty()) {
            int nx = q1.front().a;
            int ny = q1.front().b;
            int cost = q1.front().cost;
            q1.pop();
            for(int i=0; i<4; i++) {
                int sx = nx + ax[i];
                int sy = ny + ay[i];
                if(sx >= 0 && sx < N && sy >= 0 && sy < N && visit[sx][sy] == 0) {
                    if(map[sx][sy] == 0 || map[sx][sy] == age) {
                        q1.push({sx, sy, cost + 1});
                        visit[sx][sy] = 1;
                    } else if (map[sx][sy] < age) {
                        q1.push({sx, sy, cost + 1});   
                        v1.push_back({sx, sy, cost + 1});
                        // cout << sx << " " << sy << endl;
                        visit[sx][sy] = 1;     
                    }
                }
            }
        }
        // for(int i=0; i<N; i++) {
        //     for(int j=0; j<N; j++) {
        //         cout << visit[i][j] << " ";
        //     }
        //     cout << endl;
        // }
        // cout << endl;
        
        if(v1.empty()) {
            flag = 0;
        } else {
            sort(v1.begin(), v1.end(), comp);
            result += v1.front().cost;
            x = v1.front().a;
            y = v1.front().b;
            count -= 1;
            map[x][y] = 0;
        }
        if(count == 0) {
            age += 1;
            count = age;
        }
    }    
}
int main () {
    cin >> N;
    for(int i=0; i<N; i++) for(int j=0; j<N; j++) {
        cin >> map[i][j];
        if(map[i][j] == 9) {
            x = i;
            y = j;
            map[i][j] = 0;
        }
        
    }
    age = 2;
    result = 0;
    search();
    cout << result;

    return 0;
}