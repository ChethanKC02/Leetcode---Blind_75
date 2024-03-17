#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        vector<vector<int>> ans;
        vector<int> merged = newInterval;
        int i = 0, n = intervals.size();
        while(i<n && newInterval[0]>intervals[i][1]){
            ans.push_back(intervals[i++]);
        }
        
        while(i<n && intervals[i][0]<=newInterval[1]){
            merged[0] = min(intervals[i][0] , merged[0]);
            merged[1] = max(intervals[i++][1] , merged[1]);
        }
        ans.push_back(merged);
        
        while(i<n){
            ans.push_back(intervals[i++]);
        }
        return ans;
    }

    void print(vector<vector<int>> &v){
        int n = v.size();
        cout<<endl<<"[";
        for(int i=0; i<n; i++){
            cout<<'['<<v[i][0]<<','<<v[i][1]<<"]";
            if(i!=n-1) cout<<',';
        }
        cout<<"]"<<endl;
    }
};

int main(){
    Solution s;
    vector<vector<int>> v1 = {{1,2},{3,5},{6,7},{8,10},{12,16}};
    vector<int> i1 = {4,8};
    vector<vector<int>> ans1 = s.insert(v1, i1);
    s.print(ans1);
    // [[1,2],[3,10],[12,16]]
    vector<vector<int>> v2 = {{1,3},{6,9}};
    vector<int> i2 = {2,5};
    vector<vector<int>> ans2 = s.insert(v2, i2);
    s.print(ans2);
    // [[1,5],[6,9]]
    return 0;
}