// 17140 이차원 배열과 연산
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <cstring>
#include <vector>
#include <algorithm>
using namespace std;
int map[101][101];
int new_map[101][101];
int r, c, k, nowR, nowC, newR, newC;
typedef struct {
    int num;
    int count;
} calc;
bool comp(const calc &v1, const calc &v2) {
    return v1.count < v2.count || ((v1.count == v2.count) && (v1.num < v2.num));
}
void calR() {
    int temp = 0;
    memset(new_map, 0, sizeof(new_map));
    for(int i=0; i<nowR; i++) {
        vector<calc> list;
        int count[101] = {0, };
        for(int j=0; j<nowC; j++) {
            int number = map[i][j];
            count[number] += 1;
        }

        for(int j=1; j<=100; j++) {
            if(count[j] != 0) {
                list.push_back({j, count[j]});
            }
        }

        sort(list.begin(), list.end(), comp);

        int length = list.size();
        
        for(int j=0; j<length; j++) {
            new_map[i][j*2] = list.at(j).num;
            new_map[i][j*2 + 1] = list.at(j).count;
        }

        temp = max(temp, length);
    }
    newC = temp * 2;
    newR = nowR;
}
void calC() {
    int temp = 0;
    memset(new_map, 0, sizeof(new_map));
    for(int i=0; i<nowC; i++) {
        vector<calc> list;
        int count[100] = {0, };
        for(int j=0; j<nowR; j++) {
            int number = map[j][i];
            count[number] += 1;
        }

        for(int j=1; j<100; j++) {
            if(count[j] != 0) {
                list.push_back({j, count[j]});
            }
        }

        sort(list.begin(), list.end(), comp);

        int length = list.size();
        
        for(int j=0; j<length; j++) {
            new_map[j*2][i] = list.at(j).num;
            new_map[j*2 + 1][i] = list.at(j).count;
        }

        temp = max(temp, length);        
    }
    newR = temp * 2;
    newC = nowC;
}
int main() {
    newR = 3;
    newC = 3;
    int time = -1;
    cin >> r >> c >> k;
    for(int i=0; i<3; i++) for(int j=0; j<3; j++) cin >> map[i][j];
    for(int i=0; i<100; i++) {
        nowR = newR;
        nowC = newC;
        if(map[r-1][c-1] == k) {
            time = i;
            break;
        }
        if(nowR >= nowC) calR();  
        else calC();
    
        for(int i=0; i<newR; i++) {
            for(int j=0; j<newC; j++) {
                map[i][j] = new_map[i][j];
            }
        }
    }
    cout << time;
    return 0;
}