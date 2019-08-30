// 1248. [S/W 문제해결 응용] 3일차 - 공통조상 D5
#include <iostream>
#include <stdio.h>
#include <cstring>
using namespace std;
int V, E, n1, n2;
int tree[10001][2];
int degree[10001], parent[10001];
void init() {
    for(int i=0; i<10001; i++) degree[i] = 0;
    parent[1] = 0;
    return ;
}
int search() {
    int flag = -1;
    for(int i=n1; i!=0; i=parent[i]) {
        for(int j=n2; j!=0; j=parent[j]){
            if(i == j) {
                flag = i;
                break;
            }
        }
        if(flag != -1) {
            break;
        }
    }
    return flag;
}
int subtree(int num) {
    int size = 0;
    size += 1;

    for(int i=0; i<degree[num]; i++) {
        size += subtree(tree[num][i]);
    }
    return size;
}
int main() {
    int T;
    cin >> T;
    for(int tc=1; tc<=T; tc++) {
        int ansNode, ans;
        init();
        cin >> V >> E >> n1 >> n2;
        for(int i=0; i<E; i++) {
            int p, c;
            cin >> p >> c;
            tree[p][degree[p]++] = c;
            parent[c] = p;
        }
        ansNode = search();
        ans = subtree(ansNode);
        cout << "#" << tc << " " << ansNode << " " << ans << endl;
    }
    return 0;
}
 
