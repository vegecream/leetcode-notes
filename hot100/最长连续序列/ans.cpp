class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int>numset;
        for(int i: nums) numset.insert(i);
        int maxlen = 0;
        for(int num:numset){
            //查找n-1
            if(!numset.count(num-1)){
                int now = num;
                int nowlen = 1;

                while(numset.count(now+1)){
                    ++now;
                    ++nowlen;
                }
                maxlen=max(maxlen,nowlen);
            }
        }
        return maxlen;
    }
};