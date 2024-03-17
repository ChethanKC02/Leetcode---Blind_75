#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int,int> index;
        int n = nums.size();
        for(int i=0;i<n;i++){
            int complement = target - nums[i];
            if(index.count(complement)){
                return {index[complement],i};
            }
            index[nums[i]] = i;
        }
        return {-1,-1};
    }
};

int main() {
    vector<int> nums = {2, 7, 11, 15};
    int target = 9;
    
    Solution solution;
    vector<int> result = solution.twoSum(nums, target);
    
    for (int num : result) {
        cout<<num<<" ";
    }
    cout<<endl;

    return 0;
}
