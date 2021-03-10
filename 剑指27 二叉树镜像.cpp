/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    TreeNode* mirrorTree(TreeNode* root) {
	if(root == NULL)    //直到叶子节点，递归结束
        return NULL;
    swap(root->left,root->right);      //直接交换左右孩子  
    //但是光换自己不算完，还要递归交换它结点的左右孩子  继续swap
    mirrorTree(root->left);
    mirrorTree(root->right);  
        
    return root;    //结束，返回root
    }
};
