/*
 * 给你一个无重复元素的升序整数数组candidates(1 <=candidates.length <= 10,1 <= candidates门 <=20)和一个
目标整数target(1 <= target <=20)，计算candidates中可以使数宇和为目标数target的所有不同组合。candidates中的
同一个数字可以无限制重复被选取。如果至少一个数字的被选数量不同，则两种组合是不同的。对于给定的输入，保证和为target的
不同组合数少于50个。
输入为一行，,以空格分隔。输入第一个数n为target， 第二个数n2为candidates长度，剩余n2个数为candidates数组的值 7 4 2 3 6 7
输出：组合的个数 2
 */
#include <iostream>
#include <vector>

using namespace std;

//1. backtrack
void backtrack(vector<vector<int> >& result, vector<int> candidates,
               int target, int start, vector<int> m_v){
    if(target == 0){
        result.push_back(m_v);
        return;
    }
    for(int i=start; i<candidates.size(); ++i){
        if (target - candidates[i] >= 0) {
            m_v.push_back(candidates[i]);
            backtrack(result, candidates, target - candidates[i], i, m_v);
            m_v.pop_back();
        }
    }

}

int solution(vector<int>& candidates, int target){
    vector<vector<int> > result;
    vector<int> m_v;
    backtrack(result, candidates, target, 0, m_v);
    return result.size();

}

//2. dp dp[i][x] 遍历x中满足等于i的个数

int solution01(vector<int> candidates, int target){
    int dp[target+1];
    dp[0] = 1;
    for(int i=1; i<=target; ++i){
        for(auto &x: candidates){
            if(i-x >= 0){
                dp[i] = dp[i] +dp[i-x];
            }
        }
    }
    return dp[target];
}


int main(){
    int target, n;
    cin >> target >> n;
    vector<int> candidates(n);
    for(int i=0; i<candidates.size(); ++i){
        cin >> candidates[i];
    }
    cout << solution(candidates, target) << endl;
    solution01(candidates, target);
    cout << solution(candidates, target) << endl;
}