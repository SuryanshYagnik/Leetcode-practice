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

    void rt(TreeNode* root, int level, vector <int> &ans){
        if(root == nullptr){
            return;
        }

        if(ans.size() == level){
            ans.push_back(root ->val);
        }

        rt(root-> right, level+1, ans);
        rt(root-> left, level +1, ans);
    }
    vector<int> rightSideView(TreeNode* root) {
        int level = 0;
        vector <int> ans;
        rt(root,level,ans);
        return ans;

        
        
    }
};