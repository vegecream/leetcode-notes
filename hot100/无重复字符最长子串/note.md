### 无重复字符最长子串

1. unordered_set<char>的.size()是unsigned long, 和int做max的时候会报错，建议强制转换
2. 熟悉unordered_set的erase，insert操作
3. 要注意的是，int j = i -int( window.size());中，换成winsize是行不通的，可以试着构造一下反例。