#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int hammingWeight(uint32_t n) {
        int ans = 0, t = 0;
        uint32_t num = n;
        while(t<32){
            if((num>>t & 1 )== 1){
                ans++;
            }
            t++;
        }
        return ans;
    }
};

int main() {
    uint32_t n = 11;
    Solution solution;
    int result = solution.hammingWeight(n);
    cout << "Number of set bits: " << result << endl;

    return 0;
}
