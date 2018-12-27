#include <iostream>
#include <cstring>
using namespace std;
int N, result, A[1000], dp[1000];

int solve(int num){
    if(num == N-1) return 0;
    if(num >= N) return 987654321;
    int &ans = dp[num];
    if(ans != 987654321) return dp[num];
    ans = 987654321;
    for(int i=1; i<=A[num]; i++){
        if(num+i < N) ans = min(ans, solve(num+i)+1);
    }
    return ans;
}

int main(){
    cin >> N;
    for(int i=0; i<N; i++){
        cin >> A[i];
        dp[i] = 987654321;
    }
    result = solve(0);
    if(result == 987654321) cout << "-1";
    else cout << result;
    return 0;
}