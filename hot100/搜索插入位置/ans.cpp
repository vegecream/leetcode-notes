class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        return find(nums,0,nums.size(),target);
    }
    int find(vector<int>& nums,int begin, int end, int target){
        if((end-begin)==1){
            if(nums[begin]<target) return begin+1;
            else return begin;
        }

        int mid = (begin + end)/2;
        if(nums[mid]<target) return find(nums,mid,end,target);
        else return find(nums,begin,mid,target);
    }
};