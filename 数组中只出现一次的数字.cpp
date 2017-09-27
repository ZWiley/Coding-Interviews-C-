//一个整型数组里除了两个数字之外，其他的数字都出现了两次。请写程序找出这两个只出现一次的数字。
class Solution {
public:
    void FindNumsAppearOnce(vector<int> data, int *num1, int *num2){
        if(data.size() < 2) return 0;
        int size = data.size();
        int temp = data[0];

        for(int i = 1; i < size; i++)
            temp = temp^data[i];
        if(temp == 0) return ;

        int index = 0;
        while((temp & 1) == 0){
            temp = temp>>1;
            ++index;
        }
        *num1 = *num2 = 0;
        for(int i = 0; i < size;i++)
        {
            if(IsBit(data[i], index)) *num1^=data[i];
            else *num2^= data[i];
        }
    }
    bool IsBit(int num, int index){
        num = num>>index;
        return (num & 1);
    }
};    