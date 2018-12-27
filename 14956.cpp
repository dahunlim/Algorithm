#include <iostream>
#include <vector>
#include <utility>
#include <math.h>
using namespace std;
int n, m;
pair<int, int> solve(int a, int b){
    pair<int,int> p;
    if(a == 0){
        p = make_pair(1, 1);
        return p;
    }
    int len = pow(2, a);
    int amount = len * len;
    int quarter = amount / 4;
    int count;
    int where, x, y;
    where = b / quarter;
    count = b - (quarter * where);
    p = solve(a-1, count);
    if(where == 0){
        x = p.second;
        y = (len / 2) - p.first + 1;
        y = ((len / 2) + 1) - y;
    }
    else if(where == 1){
        x = p.first;
        y = p.second + (len / 2);
    }
    else if(where == 2){
        x = p.first + (len / 2);
        y = p.second + (len / 2);
    }
    else{
        x = (len / 2) - p.second + 1 + (len / 2);
        y = p.first;
        y = ((len / 2) + 1) - y;
    }
    p = make_pair(x, y);
    return p;
}   
int main(){
    cin >> n >> m;
    pair<int, int> result;
    for(int i=0; i<=15; i++){
        if(pow(2,i) == n){
            result = solve(i, m-1);
            cout << result.first << " " << result.second;
            break;
        }
    }
    return 0;
}