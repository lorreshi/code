//
// Created by 石立宇 on 2023/8/9.
//
#include "sly.h"
char map[1001][1001];
int dp[1001][1001];

int main(){

    int m, n;
    cin >> m >> n;

    for(int i=0; i<m; ++i){
        for(int j=0; j<n; ++j){
            cin >> map[i][j];
            if(map[i][j] > 'A' && map[i][j] < 'Z');
            dp[i][j] = 1;
        }
    }
    //初始化
    for(int i=1;i<m;i++){
        if(map[i][0]>='A'&&map[i][0]<='Z'){
            dp[i][0]=dp[i-1][0]+1;
        }else{
            dp[i][0]=dp[i-1][0];
        }
    }

    for(int i=1;i<n;i++){
        if(map[0][i]>='A'&&map[0][i]<='Z'){
            dp[0][i]=dp[0][i-1]+1;
        }else{
            dp[0][i]=dp[0][i-1];
        }
    }

    //dp dp[i][j] -> 前i行j列的最大字母数量
    for(int i=1;i<m;i++)
    {
        for(int j=1;j<n;j++)
        {
            if(map[i][j]>='A'&&map[i][j]<='Z')
                dp[i][j] = max(dp[i-1][j], dp[i][j-1]) + 1;
            else   dp[i][j]=max(dp[i-1][j],dp[i][j-1]);

        }
    }

    std::cout<<dp[m-1][n-1];


    return 0;
}