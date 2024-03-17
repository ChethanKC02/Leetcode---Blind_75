#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        vector<vector<int>> ans;
        sort(intervals.begin(),intervals.end());
        int count = 0;
        for(vector<int> i:intervals){
            if(ans.size() == 0){
                ans.push_back(i);
            }
            else if(ans[ans.size()-1][1]< i[0]){
                ans.push_back(i);
            }
            else{
                ans[ans.size()-1][0] = min(ans[ans.size()-1][0],i[0]);
                ans[ans.size()-1][1] = max(ans[ans.size()-1][1],i[1]);
            }
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
    vector<vector<int>> v1 = {{1,3},{2,6},{8,10},{15,18}};
    vector<vector<int>> ans1 = s.merge(v1);
    s.print(ans1);
    // [[1,6],[8,10],[15,18]]
    vector<vector<int>> v2 = {{1,4},{4,9}};
    vector<vector<int>> ans2 = s.merge(v2);
    s.print(ans2);
    // [[1,9]]
    return 0;
}