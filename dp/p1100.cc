//
// Created by 石立宇 on 2023/8/9.
//
#include "sly.h"

using namespace std;

struct compare{
    bool operator()(const pair<int, int>& p1, const pair<int, int>& p2){
        return p1.second < p2.second;
    }
};


int main(int argc, char** argv){
    int a, x;
    cin >> a;
    vector<pair<int,int>> v1, v2;
    for(int i=0; i<a; ++i){
        cin >> x;
        v1.push_back(make_pair(i, x));
    }
    for(int i=0; i<a; ++i){
        cin >> x;
        v2.push_back(make_pair(i, x));
    }
    sort(v1.begin(), v1.end(), compare());
    sort(v2.begin(), v2.end(), compare());

    for(int i=0; i<a; ++i){
        v1[i].first = v2[i].first;
    }
    sort(v1.begin(), v1.end());
    for(auto &x : v1)
        cout << x.second << endl;

    return 0;
}