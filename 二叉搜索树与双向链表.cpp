//输入一棵二叉搜索树，将该二叉搜索树转换成一个排序的双向链表。要求不能创建任何新的结点，只能调整树中结点指针的指向。
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
    void convertHelper(TreeNode *cur, TreeNode *&pre)
    {
        if(cur == nullptr) return;

        convertHelper(cur->left, pre);

        cur->left = pre;
        if(pre) pre->right = cur;
        pre = cur;

        convertHelper(cur->right, pre);
    }

    TreeNode* Convert(TreeNode* pRootOfTree)
    {
        if(pRootOfTree == nullptr) return nullptr;
        TreeNode* pre = nullptr;
        
        convertHelper(pRootOfTree, pre);

        TreeNode* res = pRootOfTree;
        while(res->left)
            res = res->left;
        return res;
    }
};