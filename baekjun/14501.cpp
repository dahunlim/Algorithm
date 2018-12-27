#include <iostream>

using namespace std;

int N;
int date;
int job[16];
int val[16];
int dp[16];

int main(){

    cin >> N;
    for(int i=0; i<N; i++){
        cin >> job[i] >> val[i];
    }
    dp[N] = 0;
    for(int i = N-1; i>=0; i--){
        date = i + job[i];

        if(date > N){
            dp[i] = dp[i+1];
        }
        else{
            dp[i] = max(dp[i+1], dp[date] + val[i]);
        }
    }

    cout << dp[0];
    return 0;
}