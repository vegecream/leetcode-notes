class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int n = nums.size();
        vector<int>pre(n+1,0);
        int sum = 0;
        int max = -100000;
        for(int i = 0; i < n; ++i){
            if(nums[i]>max) max = nums[i];
            sum += nums[i];
            pre[i+1]=sum;
        }
        for(int len = 2; len < n+1; ++len){
            for(int s = 0; s < n+1-len; ++s){
                if((pre[s+len]-pre[s])>max) max=pre[s+len]-pre[s];
            }
        }
        return max;
    }
};