class Solution {
public:
    int maxArea(vector<int>& height) {
        int i = 0;
        int j = height.size()-1;
        int res = min(height[i],height[j])*(j-i);
        while(i!=j){
            res=max(res,min(height[i],height[j])*(j-i));
            if(min(height[i],height[j])==height[i]) ++i;
            else --j;
        }
        return res;
    }
};