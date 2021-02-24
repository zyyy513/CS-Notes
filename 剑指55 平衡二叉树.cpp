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
    //要调用求二叉树深度的函数maxdepth
    int maxDepth(TreeNode* root) {
        if (root == NULL)           
            return 0;
        else
        {
            int m = maxDepth(root->left);        
            int n = maxDepth(root->right);        

            return m > n ? (m + 1) : (n + 1);        
        }
    }


    bool isBalanced(TreeNode* root) {
        if (root == NULL)
            return true;        //空树满足条件
        else
        {
            int m = maxDepth(root->left);         //递归计算左子树的深度为m
            int n = maxDepth(root->right);         //递归计算右子树的深度为n
            int diff = m - n;
            if (diff > 1 || diff < -1)
            {
                return false;
            }

            return isBalanced(root->left) && isBalanced(root->right);     //再递归判断左右子树
        }
    }
};



//为什么平衡二叉树的要求是某节点的所有左右子树的高度差不超过1，而不是相等呢？ 
//因为在一些情况下做不到左右相等，所以退而求其次，不超过1即可。   
//平衡二叉树AVL树   改进版为：近似平衡搜索树  也叫红黑树

//思路：分三步：
//1、求出当前树的左右子树的高度，判断是否满足高度差<=1，满足继续下一步
//2、按照1的方法，递归检查判断左子树，满足继续下一步
//3、按照1的方法，递归检查判断右子树，满足则是AVL

//但这种方法要重复遍历多个节点，时间复杂度高  可用后序遍历的方法，每个节点只遍历一次