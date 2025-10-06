## 2025.10.6 异位词分组的解法
1. 熟悉了unordered_map<类型，类型>实现哈希表的写法

2. 使用sort(begin,end,cmp)排序,对string s,sort(s.begin(),s.end())即可
3. emplace_back()向vector中添加元素
4. auto it = mp.begin(); it != mp.end(); ++it，这样得到的是迭代器，可以使用it->second访问value,auto &[k,v]: hash得到的是结构化绑定对象，for(auto it:um)中，it的类型是std::pair<const Key,Value>,要使用it.second

