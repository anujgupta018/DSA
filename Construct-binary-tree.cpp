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
//Construct Binary tree from inorder and preoder traversal
class Solution {
public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        map<int,int>mpp;
        for(int i=0;i<inorder.size();i++){
            mpp[inorder[i]]=i;
        }
        TreeNode *root=build(preorder,0,preorder.size()-1,inorder,0,inorder.size()-1,mpp);
        return root;
    }
    TreeNode *build(vector<int>&preorder,int preStart,int preEnd,vector<int>&inorder,int inStart,int inEnd,map<int,int>&mpp){
        if(preStart>preEnd || inStart>inEnd){
            return nullptr;
        }
        TreeNode *node=new TreeNode(preorder[preStart]);
        int inRoot=mpp[node->val];
        int left=inRoot-inStart;
        node->left=build(preorder,preStart+1,preStart+left,inorder,inStart,inRoot-1,mpp);
        node->right=build(preorder,preStart+left+1,preEnd,inorder,inRoot+1,inEnd,mpp);
        return node;
    }
};
//Construct Binary tree from inorder and postorder traversal
class Solution {
public:
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        if(inorder.size()!=postorder.size()){
            return nullptr;
        }
        map<int,int>mpp;
        for(int i=0;i<inorder.size();i++){
            mpp[inorder[i]]=i;
        }
        return build(inorder,0,inorder.size()-1,postorder,0,postorder.size()-1,mpp);
    }
    TreeNode *build(vector<int>&inorder,int is,int ie,vector<int>&postorder,int ps,int pe,map<int,int>&mpp){
        if(ps>pe || is>ie){
            return nullptr;
        }
        TreeNode *node=new TreeNode(postorder[pe]);
        int inRoot=mpp[postorder[pe]];
        int left=inRoot-is;
        node->left=build(inorder,is,inRoot-1,postorder,ps,ps+left-1,mpp);
        node->right=build(inorder,inRoot+1,ie,postorder,ps+left,pe-1,mpp);
        return node;
    }
};
