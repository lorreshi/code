//
// 岛屿数量
//
#include "../dp/sly.h"

int main(){
    vector<vector<char> > vec = {
            {'1','1','1','1','0'},
            {'1','1','0','1','0'},
            {'1','1','0','0','0'},
            {'0','0','0','0','0'}
    };



    std::function<void(vector<vector<char>>&, int, int)>
            dfs = [&](vector<vector<char>>& vec, int i, int j){
                if(i<0 || i>=vec.size() || j<0 || j>=vec[0].size() ||
                vec[i][j] == '0') return 0;
                vec[i][j] = '0';
                dfs(vec, i+1, j);
                dfs(vec, i-1, j);
                dfs(vec, i, j+1);
                dfs(vec, i, j-1);
    };
    int num = 0;
    for(int i=0; i<vec.size(); ++i){
        for(int j=0; j<vec[0].size(); ++j){
            if(vec[i][j] == '1'){
                dfs(vec, i, j);
                num++;
            }
        }
    }
    cout << num << endl;

    return 0;
}