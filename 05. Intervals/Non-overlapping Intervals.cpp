#include<bits/stdc++.h>
using namespace std;

class Solution {
private:
    static bool comp(vector<int> &n1, vector<int> &n2){
        return n1[1]<n2[1];
    }
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        int ans = -1;
        if(intervals.size() == 0){
            return 0;
        }
        sort(intervals.begin(),intervals.end(),comp);
        vector<int> prev_interval = intervals[0];
        for(vector<int> i:intervals){
            if(prev_interval[1]>i[0]) ans++;
            else prev_interval = i;
        }
        return ans;
    }
};

int main(){
    Solution s;
    vector<vector<int>> v1 = {{1,2},{2,3},{3,4},{1,3}};
    cout<<s.eraseOverlapIntervals(v1)<<endl;
    // 1
    
    vector<vector<int>> v2 = {{1,2},{1,2},{1,2}};
    cout<< s.eraseOverlapIntervals(v2)<<endl;
    // 2
    
    vector<vector<int>> v3 = {{1,2},{2,3}};
    cout<<s.eraseOverlapIntervals(v3)<<endl;
    // 0
    return 0;
}