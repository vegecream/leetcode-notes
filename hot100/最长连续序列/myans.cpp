class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if(nums.size()==0) return 0;
        if(nums.size()==0) return 1;
        sort(nums.begin(),nums.end());
        int flag = nums[0];

        int now = 1;
        int max = 1;

        for(int i = 1; i < nums.size(); ++i){
            if(nums[i]==flag) continue;
            else if(nums[i]==(flag+1)){
                ++now;
                flag = nums[i];
                if(max<now) max=now;
            }
            else{
                now=1;
                flag=nums[i];
            }
        }
        return max;
    }
};