/**
 * 将一个字符串转换成一个整数，要求不能使用字符串转换整数的库函数。 数值为0或者字符串不是一个合法的数值则返回0
*/
class Solution {
public:
    int StrToInt(string str) {
        int res = 0, n = str.size(), symbol = 1;
        if(!n) return 0;
        int start;
        for(start = 0; start < n; start++){
            if(str[start] == '-' || str[start] == '+' || ('0' <= str[start] && str[start] <= '9'))
            break;
        }

        if(str[start] == '-') symbol = -1;

        for (int i = (str[start] == '-' || str[start] == '+')? start+1 : start; i < n; ++i)
        {
            if (!('0' <= str[i] && str[i] <= '9'))
                return 0;
            
            res = (res << 1) + (res << 3) + (str[i] & 0xf);//字符'0'到'9'的ascii值的低4个二进制位刚好就是0到9所以str[i]&0xf等于str[i]-'0'
        }
        return res * symbol;
    }
};