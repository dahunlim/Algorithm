#include <iostream>
#include <vector>
#include <deque>
#include <utility>
#include <algorithm>
using namespace std;
int T, N, L, k;
int main(){
    cin >> T;
    while(T--){
        int pos, id;
        vector<pair<int, int>> ant; // pos , id
        deque<int> idList; //pos, id
        vector<pair<int, int>> result; // id , pos
        cin >> N >> L >> k;
        for(int i=0; i<N; i++){
            cin >> pos >> id;
            if(id > 0) {pos = L - pos;}
            ant.push_back(make_pair(pos, id));
            idList.push_back(id);
        }
        sort(ant.begin(), ant.end());
        for(int i=0; i<N; i++){
            id = ant[i].second;
            if(id > 0){
                result.push_back(make_pair(ant[i].first, idList.back()));
                idList.pop_back();
            }
            else{
                result.push_back(make_pair(ant[i].first, idList.front()));
                idList.pop_front();
            }
        }
        sort(result.begin(), result.end());
        cout << result[k-1].second << "\n";
    }
    return 0;
}