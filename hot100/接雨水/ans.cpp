class Solution {
public:
    int trap(vector<int>& height) {
        if(height.size()==1) return 0;
        int ans = 0;
        vector<int>leftmax(height.size());
        vector<int>rightmax(height.size());
        int lm = -1;
        int rm = -1;
        for(int l = 0; l < height.size(); ++l){
            leftmax[l]=lm;
            if(height[l]>lm) lm=height[l];
        }
        for(int r = height.size()-1;  r > 0; --r){
            rightmax[r]=rm;
            if(height[r]>rm) rm=height[r];}

        for(int i = 0; i< height.size()-1;++i){
            int hgi = height[i];
            if(min(leftmax[i],rightmax[i])>hgi) ans+=(min(leftmax[i],rightmax[i])-hgi);
        }
        return ans;
    }
};