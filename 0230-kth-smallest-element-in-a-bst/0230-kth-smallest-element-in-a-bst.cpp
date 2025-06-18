class Solution {
public:
    int cnt = 0;
    int ans = -1;

    int kthSmallest(TreeNode* root, int k) {
        inorder(root, k);
        return ans;
    }

    void inorder(TreeNode* node, int k) {
        if (!node || cnt >= k) return;

        inorder(node->left, k);

        cnt++;
        if (cnt == k) {
            ans = node->val;
            return;
        }

        inorder(node->right, k);
    }
};
