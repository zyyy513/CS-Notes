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
	if(root == NULL)    //ֱ��Ҷ�ӽڵ㣬�ݹ����
        return NULL;
    swap(root->left,root->right);      //ֱ�ӽ������Һ���  
    //���ǹ⻻�Լ������꣬��Ҫ�ݹ齻�����������Һ���  ����swap
    mirrorTree(root->left);
    mirrorTree(root->right);  
        
    return root;    //����������root
    }
};
