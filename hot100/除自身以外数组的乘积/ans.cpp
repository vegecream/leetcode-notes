class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        vector<int> pre(n, 0);
        vector<int> lat(n, 0);
        int p = 1;
        int l = 1;
        for (int i = 0; i < n; ++i) {
            p *= nums[i];
            l *= nums[n - 1 - i];
            pre[i] = p;
            lat[n - 1 - i] = l;
        }
        vector<int> ans(n, 0);
        ans[0] = lat[1];
        ans[n - 1] = pre[n - 2];
        for (int i = 1; i < n - 1; ++i) {
            ans[i] = pre[i - 1] * lat[i + 1];
        }
        return ans;
    }
};