#include <iostream>
#include <vector>
#include <utility>

using namespace std;
int count;
int dfs(int start, vector<int> tree[1001], int check[1001]){
    check[start] = 1;
    
    int next = tree[start].front();
    int index = next - 1;
    
    if(check[index] == 0){
        dfs(index, tree, check);
    }
    else{
        count++;
    }
}

int main(void){

    int a, b, c;
    
    cin >> a;

    for(int i=0;i<a;i++){
        int start = 0;
        count = 0;
        vector<int> tree[1001];
        int check[1001] = {};
        cin >> b;
        for(int j=0;j<b;j++){
            cin >> c;
            tree[j].push_back(c);
        }
        for(int k=0;k<b;k++){
            if(check[k] == 0){
                dfs(k, tree, check);
            }
        }
        cout << count << "\n";
    }
    
    return 0;
}