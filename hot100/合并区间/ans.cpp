class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        if (intervals.empty()) return {};
        
        // 按区间起点排序
        sort(intervals.begin(), intervals.end());
        
        vector<vector<int>> merged;
        merged.push_back(intervals[0]);
        
        for (int i = 1; i < intervals.size(); i++) {
            vector<int>& last = merged.back();
            vector<int>& current = intervals[i];
            
            // 如果当前区间与最后一个合并区间有重叠
            if (current[0] <= last[1]) {
                // 合并区间，取较大的结束点
                last[1] = max(last[1], current[1]);
            } else {
                // 没有重叠，直接添加
                merged.push_back(current);
            }
        }
        
        return merged;
    }
};