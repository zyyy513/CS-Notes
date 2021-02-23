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
    int maxDepth(TreeNode* root) {
        if (root == NULL)            //如果是空树，深度为零，递归结束
            return 0;
        else
        {
            int m = maxDepth(root->left);         //递归计算左子树的深度为m
            int n = maxDepth(root->right);         //递归计算右子树的深度为n

            return m > n ? (m + 1) : (n + 1);        //如果m>n 返回m+1,否则是n+1   用三目运算符
        }
    }
};

//思想：递归