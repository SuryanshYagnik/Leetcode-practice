class Solution {
public:
    void inorder(TreeNode* root, vector<int>& vals) {
        if (!root) return;
        inorder(root->left, vals);
        vals.push_back(root->val);
        inorder(root->right, vals);
    }

    bool findTarget(TreeNode* root, int k) {
        vector<int> vals;
        inorder(root, vals);

        int left = 0, right = vals.size() - 1;
        while (left < right) {
            int sum = vals[left] + vals[right];
            if (sum == k) return true;
            else if (sum < k) left++;
            else right--;
        }

        return false;
    }
};
