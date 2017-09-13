//输入两棵二叉树A，B，判断B是不是A的子结构。（ps：我们约定空树不是任意一个树的子结构）
/*
struct TreeNode {
	int val;
	struct TreeNode *left;
	struct TreeNode *right;
	TreeNode(int x) :
			val(x), left(NULL), right(NULL) {
	}
};*/
class Solution {
public:
    bool IsSubtree(TreeNode* p1, TreeNode* p2)
    {
        if(!p2) 
            return true;
        if(!p1)
            return false;
        
        if(p1->val != p2->val)
            return false;
        
        return IsSubtree(p1->left, p2->left) && IsSubtree(p1->right, p2->right);
    }

    bool HasSubtree(TreeNode* pRoot1, TreeNode* pRoot2)
    {
        if(pRoot2 == NULL)
            return false;
        if(pRoot1 == NULL)
            return false;
        
        bool result = IsSubtree(pRoot1, pRoot2);
        if(!result)
            result = HasSubtree(pRoot1->left, pRoot2);
        if(!result)
            result = HasSubtree(pRoot1->right, pRoot2);
        
        return result;
    }
};