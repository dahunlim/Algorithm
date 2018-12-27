#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int N, w, result;
vector<int> v1;
int main(){
    cin >> N;
    for(int i=0; i<N; i++) {
        cin >> w;
        v1.push_back(w);
    }
    sort(v1.begin(), v1.end(), greater<int>());
    for(int i=0; i<N; i++){
        w = v1[i]*(i+1);
        if(w > result) result = w;
    }
    cout << result;
    return 0;
}
