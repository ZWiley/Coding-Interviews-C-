//输入一棵二叉树，判断该二叉树是否是平衡二叉树。
class Solution {
public:
    bool IsBalanced(TreeNode *root, int &dep){
        if(root == NULL) return true;
        
        int left = 0;
        int right = 0;
        if(IsBalanced(root->left, left) && IsBalanced(root->right, right)){
            int dif = left - right;
            if(dif<-1 || dif >1) return false;
            dep = (left > right ? left : right) + 1;
            return true;
        }
        return false;
    }
    bool IsBalanced_Solution(TreeNode* pRoot) {
        int dep = 0;
        return IsBalanced(pRoot,dep);
    }
};