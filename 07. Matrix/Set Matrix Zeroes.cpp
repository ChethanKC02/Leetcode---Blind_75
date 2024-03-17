#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    void setZeroes(vector<vector<int>>& m) {
        int r = m.size(), c = m[0].size(), col0 = 1;
        for(int i=0;i<r;i++){
            if(m[i][0] == 0){
                col0 = 0;
            }
            for(int j=1;j<c;j++){
                if(m[i][j] == 0){
                    m[i][0] = m[0][j] = 0;
                }
            } 
        }

        for(int i=r-1;i>-1;i--){
            for(int j=c-1;j>0;j--){
                if(m[i][0]==0 || m[0][j] == 0){
                    m[i][j] = 0;
                }
            }
            if(col0 == 0){
                m[i][0] = 0;
            }
        }
    }
    
    void print(vector<vector<int>> &v){
        cout<<endl;
        for(vector<int> i:v){
            for(int j:i){
                cout<<j<<" ";
            }
            cout<<endl;
        }
        cout<<endl;
    }
};

int main(){
    Solution s;
    vector<vector<int>> v1 = {{1,2},{2,3},{3,4},{1,3}};
    s.print(v1);
    s.setZeroes(v1);
    s.print(v1);
    // Input: matrix = [[1,1,1],[1,0,1],[1,1,1]]
    // Output: [[1,0,1],[0,0,0],[1,0,1]]   
    return 0;
}