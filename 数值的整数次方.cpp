/**
 * 给定一个double类型的浮点数base和int类型的整数exponent。求base的exponent次方。
 * 1.全面考察指数的正负、底数是否为零等情况。
 * 2.写出指数的二进制表达，例如13表达为二进制1101。
 * 3.举例:10^1101 = 10^0001*10^0100*10^1000。
 * 4.通过&1和>>1来逐位读取1101，为1时将该位代表的乘数累乘到最终结果。
 */
class Solution {
public:
    double Power(double base, int exponent) {
     return pow(base,exponent);
    }
};