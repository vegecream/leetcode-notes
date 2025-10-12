### 和为k的子数组（我没招了）

我们定义 pre[i] 为 [0..i] 里所有数的和，则 pre[i] 可以由 pre[i−1] 递推而来，即：

pre[i]=pre[i−1]+nums[i]
那么「[j..i] 这个子数组和为 k 」这个条件我们可以转化为

pre[i]−pre[j−1]==k
简单移项可得符合条件的下标 j 需要满足

pre[j−1]==pre[i]−k
所以我们考虑以 i 结尾的和为 k 的连续子数组个数时只要统计有多少个前缀和为 pre[i]−k 的 pre[j] 即可。我们建立哈希表 mp，以和为键，出现次数为对应的值，记录 pre[i] 出现的次数，从左往右边更新 mp 边计算答案，那么以 i 结尾的答案 mp[pre[i]−k] 即可在 O(1) 时间内得到。最后的答案即为所有下标结尾的和为 k 的子数组个数之和。

需要注意的是，从左往右边更新边计算的时候已经保证了mp[pre[i]−k] 里记录的 pre[j] 的下标范围是 0≤j≤i 。同时，由于pre[i] 的计算只与前一项的答案有关，因此我们可以不用建立 pre 数组，直接用 pre 变量来记录 pre[i−1] 的答案即可。

作者：力扣官方题解
链接：https://leetcode.cn/problems/subarray-sum-equals-k/solutions/238572/he-wei-kde-zi-shu-zu-by-leetcode-solution/
来源：力扣（LeetCode）
著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。