/**
求出1~13的整数中1出现的次数,并算出100~1300的整数中1出现的次数？
为此他特别数了一下1~13中包含1的数字有1、10、11、12、13因此共出现6次,
但是对于后面问题他就没辙了。ACMer希望你们帮帮他,并把问题更加普遍化,可以很快的求出任意非负整数区间中1出现的次数。
*/

class Solution {
public:
    // 计算从0到n中1的总数
    int NumberOf1Between1AndN_Solution(int n)
    {
        int count = 0;
        for(int i=0;i<=n;i++) {
            count += NumberOf1(i);
        }
        return count;
    }
    // 计算数字n中1的个数
    int NumberOf1(int n)
    {
        int count = 0;
        while(n) {
            if(n%10 == 1) count++;
            n /= 10;
        }
        return count;
    }
};