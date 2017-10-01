/**
 * 请实现一个函数用来找出字符流中第一个只出现一次的字符。例如，当从字符流中只读出前两个字符"go"时，
 * 第一个只出现一次的字符是"g"。当从该字符流中读出前六个字符“google"时，第一个只出现一次的字符是"l"。
*/
class Solution
{
public:
    unsigned cnt[128];
    queue<char> data;

    Solution()
    {
        memset(cnt, 0, sizeof(cnt));
    }
  //Insert one char from stringstream
    void Insert(char ch)
    {
        ++cnt[ch - '\0'];
        if(cnt[ch - '\0'] == 1)
            data.push(ch);    
    }
  //return the first appearence once char in current stringstream
    char FirstAppearingOnce()
    {
        while(!data.empty() && cnt[data.front()] >= 2) data.pop();
            if(data.empty()) return '#';
            return data.front();
    }
};