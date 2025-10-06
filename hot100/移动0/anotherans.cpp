void moveZeroes(vector<int>& nums) {
        auto it = remove(nums.begin(), nums.end(), 0);
        int zeroCount = nums.end() - it;
        nums.erase(it, nums.end());
        nums.insert(nums.end(), zeroCount, 0);
    }