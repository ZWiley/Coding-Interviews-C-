//从上往下打印出二叉树的每个节点，同层节点从左至右打印。
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
    vector<int> PrintFromTopToBottom(TreeNode* root) {
        queue<TreeNode*> q;
        q.push(root);
        vector<int> r;
        while(!q.empty()){
            root = q.front(); q.pop();
            if(!root) continue;
            r.push_back(root->val);
            q.push(root->left);
            q.push(root->right);
        }
        return r;
    }
};