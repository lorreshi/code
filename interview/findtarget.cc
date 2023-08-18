//
// 给定一个数组和一个target。1. 看他的子数组里面有没有和为target的，有返回true
//                        2. 有的话返回数组不能取重复的
#include "../dp/sly.h"

int back(vector<int>& vec, int target, int sum, int startsum){

}



int main(){
    //cin
    int n, target;
    cin >> n >> target;
    vector<int> vec(n);
    for(int i=0; i<n; ++i){
        cin >> vec[i];
    }

    auto res = back(vec, target, 0, 0);
    cout << res << endl;

    return 0;
}