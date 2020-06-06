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
    TreeNode* invertTree(TreeNode* root) {
        if(root!=NULL){
            queue<TreeNode *>q;
            q.push(root);
            while(!q.empty()){
                swap(q.front()->right,q.front()->left);
                if(q.front()->right)
                    q.push(q.front()->right);
                if(q.front()->left)
                    q.push(q.front()->left);
                 q.pop();
            }
        }
        return root;
    }
};


