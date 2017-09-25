/**
在一个字符串(1<=字符串长度<=10000，全部由字母组成)中找到第一个只出现一次的字符,并返回它的位置
*/
class Solution {
public:
    int FirstNotRepeatingChar(string str) {
        map<char, int> mp;
        for(int i = 0; i < str.size(); i++){
            mp[str[i]]++;
        }
        for(int i = 0; i < str.size(); i++){
            if(mp[str[i]]++)
                return i;
        }
        return -1;
    }
};