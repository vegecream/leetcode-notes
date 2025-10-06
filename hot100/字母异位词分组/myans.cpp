class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string,vector<string>>hash;
        for(auto it: strs){
            auto save = it;
            sort(it.begin(),it.end());
            auto tmp = hash.find(it);
            if(tmp == hash.end()){
                vector<string> vt;
                vt.push_back(save);
                hash[it]=vt;
            }
            else{
                hash[it].push_back(save);
            }
        }
        vector<vector<string>> ans;
        for(auto &[k,v]: hash){
            ans.push_back(v);
        }
        return ans;
    }
};