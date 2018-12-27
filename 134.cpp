#include <string>
#include <vector>
#include <algorithm>
#include <utility>
#include <functional>
using namespace std;
bool desc(pair<float, float>& a, pair<float, float>& b){
    if(a.first == b.first) return a.second > b.second;
    return a.first > b.first;
}
int main() {
    int N;
    vector<int> stages;
    vector<int> answer;
    vector<pair<float, float>> sol;
    cin >> N;
    for(int i=0; i<N; i++) cin >> 
    int ranking = 0;
    float count[501] = {};
    float suc[501] = {};
    for(int i=0; i<N; i++){
        ranking = stages[i];
        for(int j=1; j<ranking; j++){
            count[j]++;
        }
        suc[ranking]++;
    }
    for(int i=0; i<N; i++){
        sol.push_back(make_pair(suc[i]/count[i], i+1));
    }
    sort(sol.begin(), sol.end());
    for(int i=sol.size()-1; i>=0; i--) answer.push_back(sol[i].second);
    return 0;
}