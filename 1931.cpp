#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>
using namespace std;
int N, st, et, ct;
vector<pair<int, int>> v;
int main(){
    cin >> N;
    for(int i=0; i<N; i++){
        cin >> st >> et;
        v.push_back(make_pair(et, st));
    }
    sort(v.begin(), v.end());
    int pre = 0;
    ct = 0;
    for(int i=0; i<N; i++){
        if(v[i].second >= pre){
            pre = v[i].first;
            ct++;
        }
    }
    cout << ct;
    return 0;
}