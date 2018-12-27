#include <iostream>
#include <vector>
#include <utility>
#include <math.h>
using namespace std;
int N, M;
int result = 987654321;
int map[50][50];
int list[14];
vector<pair<int, int>> house;
vector<pair<int, int>> chicken;
int dfs(int now, int cnt){
    if(now > chicken.size()) return 0;
    if(cnt == M){ // 다골랐다!
        int sum = 0;
        for(int i=0; i<house.size(); i++){ //집 설정
            int dist = 987654321;
            for(int j=0; j<chicken.size(); j++){ //집과 고른 치킨집들과의 거리중 최소를 구하자
                if(list[j] == 1){
                    int hx = house[i].first;
                    int hy = house[i].second;
                    int cx = chicken[j].first;
                    int cy = chicken[j].second;
                    dist = min(dist, (abs(hx-cx)+abs(hy-cy)));                    
                    cout << dist << endl;
                }
            }
            cout << "@@" << endl;
            sum += dist;
        }
        result = min(result, sum);
        return 0;
    }
    list[now] = 1;
    dfs(now+1, cnt+1);
    list[now] = 0;
    dfs(now+1, cnt);
    return 0;
}
int main(){
    cin >> N >> M;
    for(int i=0; i<N; i++){
        for(int j=0; j<N; j++){
            cin >> map[i][j];
            if(map[i][j] == 1) house.push_back(make_pair(i, j));
            else if(map[i][j] == 2) chicken.push_back(make_pair(i, j));
        }
    }
    dfs(0, 0);
    cout << result;
    return 0;
}