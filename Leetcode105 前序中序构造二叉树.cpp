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
    //Ҫ����һ���Ӻ���_buildTree
    TreeNode* _buildTree(vector<int>& preorder, vector<int>& inorder,int & prei,int inbegin,int inend) 
    {
        if(inbegin>inend)
        {
            return NULL;                                //��ô��⣿��?
        }

        //��ǰ��ȷ�����ڵ�
        TreeNode* root = new TreeNode(preorder[prei]);  
        //���������ҵ����ڵ�
        int rooti=inbegin;   //�ȳ�ʼ��Ϊinbegin��
        while(rooti!=inend)
        {
            if(preorder[prei]==inorder[rooti])
            	break;
            else
                ++rooti;
        }
        
        //���ԾͰ�inorder�ֳ��������֣�����������  ��   ����������
        //[inbegin,rooti-1] rooti [rooti+1,inend]
        //Ȼ���������������ͬ������   �ݹ鹹����������  (�����������˲Ž�������)
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
    
    
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {    //����ǰ������� ���շ��ض������ĸ�
        int prei=0;
        int inbegin=0,inend=inorder.size()-1;    //����λ�ÿ�ͷ�������һ��λ��Ϊĩβ ��ͼ
        return _buildTree(preorder,inorder,prei,inbegin,inend);   //�⼸����������_buildTree
    }
};
