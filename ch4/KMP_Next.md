参考：https://www.bilibili.com/video/av94967070/
## Next 数组的定义
Next[i]:表示匹配模式串i位置失配，模式串向后滑动对齐匹配指针的位置

* 如何定义模式串内部的可以利用的重复性？
pm数组：partial match
p[i]：表示字符串长度为i+1的前缀里（除本身外）最长相等后缀的长度


构造方式：
eg：
inx: 0 1 2 3 4 5
str: b b b b a b
pm:  0 1 2 3 0 1
nxt:-1 0 1 2 3 0 

* 手动（考试）如何计算next数组？
那么next[i] = k + 1，就是找到一个最大的前缀str[1...k]，是以i为结尾的后缀str[...i-1]
比如：
a b a b a a a b a b a a
0 1 1 2 3 4 2 2 3 4 5 6


[失配，模式串跳next]

* 计算机如何快速计算next数组？
- 动态规划：将计算next数组化为匹配模式串的子问题（匹配前缀）
