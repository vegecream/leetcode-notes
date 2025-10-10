class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_set<char>window;
        int winsize = 0;
        int start = 0;
        for(int i = 0; i < s.size(); ++i){
            if(window.find(s[i])== window.end()){
                window.insert(s[i]);
                winsize = max(winsize,int(window.size()));
            }
            else{
                //检查哪里出的问题，移除之前的项
                int j = i -int( window.size()); 
                while(s[j]!= s[i]){
                    window.erase(s[j]);
                    ++j;
                }
            }
        }
        return winsize;
    }
};