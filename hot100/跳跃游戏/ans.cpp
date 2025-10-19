class Solution {
public:
    bool canJump(vector<int>& nums) {
        int reach = 0;
        int n = nums.size();
        for (int i = 0; (i < reach + 1) && (i < n - 1); ++i) {
            if ((i + nums[i]) > reach)
                reach = i + nums[i];
        }
        return reach >= (n - 1);
    }
};