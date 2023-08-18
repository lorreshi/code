//
// Created by 石立宇 on 2023/8/9.
//
#include "sly.h"
int dp[101];

int main(){
    int n;
    cin >> n;
    dp[1] = 1; dp[2] = 2; dp[3] = 3;
    for(int i=3; i<=n; ++i){
        dp[i] = dp[i-1] + dp[i-2];
    }
    cout << dp[n] << endl;

}