//
// Created by 石立宇 on 2023/8/9.
//
#include "sly.h"
int dp[100005];

int main(){

    int n, x;
    cin >> n;
    for(int i=1; i<=n; ++i){
        cin >> x;
        // dp[i] 前i个数中最大的数,要么不取i的值为dp[i-1]，要么取当前值
        // 但又不能相邻读取故而为dp[i-2] + x
        dp[i] = max(dp[i-1], dp[i-2]+x);
    }
    cout << dp[n] << endl;

}
