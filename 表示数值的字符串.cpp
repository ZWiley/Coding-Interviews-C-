/**
 * 请实现一个函数用来判断字符串是否表示数值（包括整数和小数）。
 * 例如，字符串"+100","5e2","-123","3.1416"和"-1E-16"都表示数值。
 *  但是"12e","1a3.14","1.2.3","+-5"和"12e+4.3"都不是。
*/
class Solution {
public:
    bool isNumeric(char* str)
    {
        bool sign = false, decimal = false, hasE = false;
        for(int i = 0; i < strlen(str); i++){
            if(str[i] == 'e' || str[i] == 'E'){
                if(i == strlen(str)-1) return false;
                if(hasE) return false;
                hasE = true;
            }else if (str[i] == '+' || str[i] == '-')
            {
                if(sign && str[i-1] != 'e' && str[i-1] != 'E') return false;
                if(!sign && i > 0 && str[i-1] != 'e' && str[i-1] != 'E') return false;
                sign = true;   
            }else if (str[i] == '.')
            {
                if(hasE || decimal) return false;
                decimal = true;   
            }else if (str[i] < '0' || str[i] > '9')
            {
                return false;   
            }
        }
        return true;
    }
};