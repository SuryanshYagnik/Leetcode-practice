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
    vector<int> inorderTraversal(TreeNode* root) {
      stack<TreeNode*>s;
      TreeNode *temp=root;
      vector<int>ans;
      if(root==NULL){
        return ans;
      }
      while(true){
        if(temp!=NULL){
            s.push(temp);
            temp=temp->left;

        }
        else{
            if(s.empty()){break;}
            ans.push_back(s.top()->val);
            temp=s.top();
            s.pop();
            temp=temp->right;
        }
      }
      return ans;
        
    }
};