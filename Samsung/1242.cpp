// 1242. [S/W 문제해결 응용] 1일차 - 암호코드 스캔
#include <iostream>
#include <stdio.h>
#include <cstring>
#include <vector>
using namespace std;
typedef struct {
    int x;
    int y;
} cordi;
int N, answer;
cordi home;
cordi office;        
vector<cordi> v1;

int dist(cordi c1, cordi c2) {
    cordi cal;
    cal.x = abs(c1.x - c2.x);
    cal.y = abs(c1.y - c2.y);
    return cal.x + cal.y;
}
void search(int visit[10], int cnt, int sum, cordi pre) {
    if(cnt == N) {// 집까지 거리 구하고 정답이랑 비교
        sum += dist(pre, home);
        answer = min(answer, sum);
        return ;
    }
    for(int i=0; i<N; i++) {
        if(!visit[i]) {
            visit[i] = 1;
            search(visit, cnt+1, sum + dist(pre, v1.at(i)), v1.at(i));
            visit[i] = 0;
        }
    }
    return ;
}
int main() {
    int T;
    cin >> T;
    for(int tc=1; tc<=T; tc++) {
        cin >> N;
        
        v1.clear();
        int visit[10];
        answer = 987654321;
        memset(visit, 0, sizeof(visit));

        for(int i=0; i<N+2; i++) {
            cordi c1;
            cin >> c1.x >> c1.y;
            if(i==0) office = c1;
            else if(i==1) home = c1;
            else {
                v1.push_back(c1);
            }
        }

        search(visit, 0, 0, office);
        printf("#%d %d\n", tc, answer);
    }
    return 0;
}