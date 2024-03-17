#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int row = matrix.size()-1, col = matrix[0].size()-1;
        int srow = 0, scol = 0;
        vector<int> v;
        while(srow<=row && scol<=col){
            for(int i=scol;i<=col;i++){
                v.push_back(matrix[srow][i]);
            }
            srow++;
            for(int i=srow;i<=row;i++){
                v.push_back(matrix[i][col]);
            }
            col--;
            if(srow<=row){
                for(int i=col;i>=scol;i--){
                    v.push_back(matrix[row][i]);
                }
                row--;
            }
            if(scol<=col){
                for(int i=row;i>=srow;i--){
                    v.push_back(matrix[i][scol]);
                }
                scol++;
            }
        } 
        return v;
    }
    
    void print(vector<int> &v){
        cout<<endl;
        for(int i:v){
            cout<<i<<" ";
        }
        cout<<endl;
    }
};

int main(){
    Solution s;
    vector<vector<int>> v1 = {{1,2,3,4},{5,6,7,8},{9,10,11,12}};
    vector<int> ans1 = s.spiralOrder(v1);
    s.print(ans1);
    return 0;
}