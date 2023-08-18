//
// Created by 石立宇 on 2023/8/12.
//
#include <iostream>
#include <vector>
#include <string>
using namespace std;


int solution(string &s){
    int n = s.length();
    vector<vector<int> > dp(n, vector<int>(n, 0));

    for(int l=2; l<=n; ++l){
        for(int i=0; i<=n-l; ++i){
            int j = i + l - 1;
            if(s[i] == s[j]){
                dp[i][j] = dp[i+1][j-1];
            }else{
                dp[i][j] = min(dp[i+1][j], dp[i][j-1]);
            }
        }
    }
    return dp[0][n-1];

}

int main() {
    int n;
    string s;
    cin >> n >> s;

    int result = solution(s);
    cout << result << endl;


    return 0;
}


// 64 位输出请用 printf("%lld")