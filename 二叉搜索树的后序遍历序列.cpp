//输入一个整数数组，判断该数组是不是某二叉搜索树的后序遍历的结果。如果是则输出Yes,否则输出No。假设输入的数组的任意两个数字都互不相同。
class Solution {
public:
    bool VerifySquenceOfBST(vector<int> sequence) {
       int size = sequence.size();
       if( 0 == size) return false;

       int i = 0;
       while(--size)
       {
           while(sequence[i] < sequence[size])
           {
               i++;
           }
           while(sequence[i] > sequence[size])
           {
               i++;
           }
           if(i < size) return false;
           i = 0;
       }
       return true;
    }
};