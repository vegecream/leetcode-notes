class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> ans;
        vector<int> first(1,1);
        ans.push_back(first);
        for(int i = 1; i<numRows;++i){
            vector<int> tmp(i+1,0);
            tmp[0]=1; 
            tmp[i]=1;
            for(int j = 1; j < i; ++j){
                tmp[j]=ans[i-1][j-1]+ans[i-1][j];
            }
            ans.push_back(tmp);
        }
        return ans;
    }
};