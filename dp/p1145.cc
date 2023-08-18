////
//// Created by 石立宇 on 2023/8/9.
////
#include "sly.h"

int n, m, g;
int map[1005][1005];
int dp[1005][1005];
int ans = INT_MAX;

void solution(){
    if(dp[1][1]>=g){
        ans = 0;
        return;
    }

    for(int i=1; i<=n; ++i){
        for(int j=1; j<=m; ++j){
            dp[i][j] = max(dp[i-1][j], dp[i][j-1]) + map[i][j];
            if(dp[i][j] >= g){
                ans = min(ans, (i-1)+(j-1));
            }
        }
    }

    if(ans == INT_MAX){
        ans = -1;
        return;
    }
    return ;
}

int main(int argc, char** argv){

    cin >> n >> m >> g;
    int x;
    for(int i=1; i<=n; ++i){
        for(int j=1; j<=m; ++j){
            cin >> x;
            map[i][j] = x;
        }
    }
    solution();
    cout << ans << endl;

    return 0;
}


