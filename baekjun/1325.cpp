#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int main(void){

    int m, n;   // n : 컴퓨터개수 m : 신뢰관계라인수
    int max = 0;
    int answer[10001];
    int num = 0;
    vector<int> tree[10001];
    queue<int> q;
    cin >> n >> m;

    for(int i=0; i<m;i++){
        int a, b;
        cin >> a >> b;
        tree[b].push_back(a);
    }

    for(int i=0; i<=n;i++){
        int count = 0;
        int visit[10001] = {};

        q.push(i);
        visit[i] = 1;
        count++;

        while(!q.empty()){
            int now = q.front();

            q.pop();

            for(int j=0; j<tree[now].size();j++){
                int input = tree[now][j];

                if(visit[input] == 0){
                    visit[input] = 1;
                    q.push(input);
                    count++;
                }
            }
        }

        if(count > max){
            num = 0;
            max = count;
            answer[num] = i;
            num++;
        }
        else if(count == max){
            answer[num] = i;
            num++;
        }
    }

    for(int i=0;i<num;i++){
        cout << answer[i] << " ";
    }
    return 0;
}