//
// Created by 石立宇 on 2023/8/11.
//

#include "../dp/sly.h"
int n, m;
string str[1005];
bool grip01[1005][1005], grip02[1005][1005];




int main(){
    // n行 m列
    cin >> n >> m;
    for(int i=0; i<n; ++i){
        cin >> str[i];
    }

    // B G 当成一种颜色
    for(int i=0; i<n; ++i){
        for(int j=0; j<m; ++j){
            if(str[i][j] == 'B') str[i][j] = 'G';
        }
    }
    cout << str[0] << str[1];
    return 0;
}