#include <iostream>

using namespace std;
int n, m;
int rps[100001]; // 80 P 82 R 83 S
int my[100000];
int check[100000] = {};
int main(){
    cin >> n >> m;
    rps[n] = -1;  
    for(int i=0; i<n; i++) cin >> rps[i];
    for(int i=0; i<m; i++) cin >> my[i];
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            if(rps[i+j] == -1) break;
            if((rps[i] == 80) && (my[i] != 83)) break;
            if((rps[i] == 82) && (my[i] != 80)) break;
            if((rps[i] == 83) && (my[i] != 82)) break;

            check[i]++;
        }
    } 
    return 0;
}