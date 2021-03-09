/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    //要定义一个子函数_buildTree
    TreeNode* _buildTree(vector<int>& preorder, vector<int>& inorder,int & prei,int inbegin,int inend) 
    {
        if(inbegin>inend)
        {
            return NULL;                                //怎么理解？？?
        }

        //由前序确定根节点
        TreeNode* root = new TreeNode(preorder[prei]);  
        //在中序中找到根节点
        int rooti=inbegin;   //先初始化为inbegin处
        while(rooti!=inend)
        {
            if(preorder[prei]==inorder[rooti])
            	break;
            else
                ++rooti;
        }
        
        //所以就把inorder分成了三部分：左子树中序  根   右子树中序
        //[inbegin,rooti-1] rooti [rooti+1,inend]
        //然后对左右子树进行同样操作   递归构建左右子树  (左子树建完了才建右子树)
        if(inbegin<=rooti-1)
        	root->left=_buildTree(preorder, inorder, ++prei,inbegin,rooti-1); 
        else
            root->left=NULL;
        if(inend>=rooti+1)
            root->right=_buildTree(preorder, inorder, ++prei,rooti+1,inend);
        else
            root->right=NULL;   

        return root; 
    }
    
    
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {    //给出前序和中序 最终返回二叉树的根
        int prei=0;
        int inbegin=0,inend=inorder.size()-1;    //从零位置开头，以最后一个位置为末尾 看图
        return _buildTree(preorder,inorder,prei,inbegin,inend);   //这几个参数传回_buildTree
    }
};
