#include <iostream>
#include <queue>

using namespace std;

int main(){

    int t;
    cin >> t;
    while(t--){
        int n, m;
        int error = 0;
        int origin[501];
        int graph[501][501]={};
        int len[501]={};
        int result[501];
        queue<int> q;

        cin >> n;
        for(int i=0; i<n; i++){
            cin >> origin[i];
        }

        for(int i=0; i<n; i++){
            for(int j=i+1; j<n; j++){
                graph[origin[i]][origin[j]] = 1;
                len[origin[j]]++;
            }
        }
        
        cin >> m;
        for(int i=0; i<m; i++){
            int a, b;
            cin >> a >> b;

            if(graph[a][b]){
                len[b]--;
                len[a]++;
            }
            else{
                len[b]++;
                len[a]--;
            }
            swap(graph[b][a], graph[a][b]);
        }

        for(int i=1; i<=n; i++){
            if(len[i]==0) q.push(i);
        }        

        for(int i=0; i<n; i++){
            if(q.empty()) {error = 1; break;}
            if(q.size()>1) {error = 2;; break;}

            int now = q.front();
            result[i] = now;
            q.pop();
            for(int j=0; j<=n; j++){
                if(graph[now][j]){
                    len[j]--;
                    if(len[j]==0) {
                        q.push(j);
                    }
                }
            }
        }

        if(error == 1){
            printf("IMPOSSIBLE\n");
        }
        else if(error == 2){
            printf("?\n");
        }
        else{
            for(int i=0; i<n; i++){
                printf("%d ", result[i]);
            }
            printf("\n");
        }
    }    

    return 0;
}