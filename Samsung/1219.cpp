//1219. [S/W 문제해결 기본] 4일차 - 길찾기
#include <iostream>
#include <stdio.h>
#include <cstring>
#include <vector>
using namespace std;
vector<int> v1[101];
int visit[101];
int ans;
void search(int node){
    if(node == 99) {
        ans = 1;
        return ;
    }
    for(int i=0; i<v1[node].size(); i++) {
        if(!visit[v1[node].at(i)]) {
            visit[v1[node].at(i)] = 1;
            search(v1[node].at(i));
        }
    }
    return ;
}
int main() {
    int T, count, now, next;
    for(int tc=1; tc<=10; tc++) {
        memset(visit, 0, sizeof(visit));
        for(int i=0; i<101; i++) v1[i].clear();
        ans = 0;

        cin >> T >> count;
        
        for(int i=0; i<count; i++) {
            cin >> now >> next;
            v1[now].push_back(next);
        }
        search(0);

        printf("#%d %d\n", T, ans);
    }
    return 0;
}