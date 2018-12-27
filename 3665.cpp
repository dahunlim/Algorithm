#include <iostream>
#include <cstdio>
#include <queue>
#include <utility>

using namespace std;

int main(void){

    int num;
    scanf("%d", &num);
    
    for(int i=0; i<num; i++){
        int a, b;
        int error = 0;
        int in[501] = {};
        int past[501] = {};
        int graph[501][501] = {};
        int result[501] = {};
        queue<int> q;

        scanf("%d", &a);

        for(int j=0; j<a; j++){
            scanf("%d", &past[j]);
        }
        for(int j=0; j<a; j++){
            for(int k=0; k<j; k++){
                graph[past[k]][past[j]] = 1;
                in[past[j]]++;
            }
        }

        for(int i=0; i<=a; i++){
            for(int j=0; j<=a; j++){
                cout << graph[i][j];
            }
            cout << "\n";
        }
    
        scanf("%d", &b);
        while(b--){
            int m, n;
            scanf("%d%d", &m, &n);
            if(graph[m][n]) {
                in[m]++;
                in[n]--;
            }
            else {
                in[m]--;
                in[n]++;
            }
            swap(graph[m][n], graph[n][m]);
        }

        for(int i=1; i<=a; i++){
            if(!in[i]){
                q.push(i);
            }
        }        

        for(int i=0; i<a; i++){
            if(q.empty()){
                error = 1;
                break;
            }
            else if(q.size() > 1){
                error = 2;
                break;
            }

            int now = q.front();
            result[i] = now;
            q.pop();
            for(int j=0; j<=a; j++){
                if(graph[now][j]){
                    in[j]--;

                    if(!in[j]){
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
            for(int i=0; i<a; i++){
                printf("%d ", result[i]);
            }
            printf("\n");
        }
    }
    return 0;
}