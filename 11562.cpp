#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;


int main(){
    int n, m;
    int map[250][250];
    int no = 350000;
    scanf("%d %d", &n, &m);
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            map[i][j] = no;
        }
        map[i][i] = 0;
    }

    for(int i=0; i<m;i++){
        int u, v, b;
        scanf("%d %d %d", &u, &v, &b);
        u--; 
        v--;
        if(b){
            map[u][v] = 0;
            map[v][u] = 0;
        }
        else{
            map[u][v] = 0;
            map[v][u] = 1;
        }
    }

    for(int i=0; i<n; i++)
        for(int j=0; j<n; j++)
            for(int k=0; k<n; k++)
                map[j][k] = min(map[j][k], map[j][i] + map[i][k]);

    int tt;
    scanf("%d", &tt);
    for(int i=0; i<tt; i++){
        int s, e;
        scanf("%d %d", &s, &e);        
        printf("%d\n", map[s-1][e-1]);
    }
    return 0;
}