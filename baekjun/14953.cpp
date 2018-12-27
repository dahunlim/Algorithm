#include <iostream>
#include <vector>
#include <cstring>
using namespace std;
int n, m, mx;
vector<int> map[100000];
int count[100000] = {};
int check[100000];
int dp(int now){}
    int a = 0;
    int &ans = check[now];
    if(ans != -1) return ans;

    for(int i=0; i<map[now].size(); i++){
        if(count[now] < count[map[now].at(i)]){
            ans = max(ans, 1+dp(map[now].at(i)));
        a++;
        }
    }
    if(a == 0){
        return 1;
    }
    return ans;
}
int main(){
    memset(check, -1, sizeof(check));
    int temp = 0;
    mx = 0;
    cin >> n >> m;
    for(int i=0; i<m; i++){
        int a, b;
        cin >> a >> b;
        map[a].push_back(b);
        map[b].push_back(a);
        count[a]++;
        count[b]++;
    }
    for(int i=0; i<n; i++){
        temp = max(temp, dp(i));
    }
    cout << temp;    
    return 0;
}