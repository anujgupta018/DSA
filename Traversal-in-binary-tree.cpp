//Preorder Traversal of a Binary Tree
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
    void traversal(TreeNode *root,vector<int>&nums){
        if(root==nullptr){
            return ;
        }
        nums.push_back(root->val);
        traversal(root->left,nums);
        traversal(root->right,nums);
    }
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int>nums;
        traversal(root,nums);
        return nums;
    }
};
//Inorder Traversal of Binary Tree
class Solution {
public:
    void traversal(TreeNode *root,vector<int>&nums){
        if(root==nullptr){
            return ;
        }
        traversal(root->left,nums);
        nums.push_back(root->val);
        traversal(root->right,nums);
    }
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int>nums;
        traversal(root,nums);
        return nums;
    }
};
//Postorder Traversal of a Binary Tree
class Solution {
public:
    void postorder(TreeNode *root,vector<int>&nums){
        if(root==nullptr){
            return ;
        }
        postorder(root->left,nums);
        postorder(root->right,nums);
        nums.push_back(root->val);
    }
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int>ans;
        postorder(root,ans);
        return ans;
    }
};
