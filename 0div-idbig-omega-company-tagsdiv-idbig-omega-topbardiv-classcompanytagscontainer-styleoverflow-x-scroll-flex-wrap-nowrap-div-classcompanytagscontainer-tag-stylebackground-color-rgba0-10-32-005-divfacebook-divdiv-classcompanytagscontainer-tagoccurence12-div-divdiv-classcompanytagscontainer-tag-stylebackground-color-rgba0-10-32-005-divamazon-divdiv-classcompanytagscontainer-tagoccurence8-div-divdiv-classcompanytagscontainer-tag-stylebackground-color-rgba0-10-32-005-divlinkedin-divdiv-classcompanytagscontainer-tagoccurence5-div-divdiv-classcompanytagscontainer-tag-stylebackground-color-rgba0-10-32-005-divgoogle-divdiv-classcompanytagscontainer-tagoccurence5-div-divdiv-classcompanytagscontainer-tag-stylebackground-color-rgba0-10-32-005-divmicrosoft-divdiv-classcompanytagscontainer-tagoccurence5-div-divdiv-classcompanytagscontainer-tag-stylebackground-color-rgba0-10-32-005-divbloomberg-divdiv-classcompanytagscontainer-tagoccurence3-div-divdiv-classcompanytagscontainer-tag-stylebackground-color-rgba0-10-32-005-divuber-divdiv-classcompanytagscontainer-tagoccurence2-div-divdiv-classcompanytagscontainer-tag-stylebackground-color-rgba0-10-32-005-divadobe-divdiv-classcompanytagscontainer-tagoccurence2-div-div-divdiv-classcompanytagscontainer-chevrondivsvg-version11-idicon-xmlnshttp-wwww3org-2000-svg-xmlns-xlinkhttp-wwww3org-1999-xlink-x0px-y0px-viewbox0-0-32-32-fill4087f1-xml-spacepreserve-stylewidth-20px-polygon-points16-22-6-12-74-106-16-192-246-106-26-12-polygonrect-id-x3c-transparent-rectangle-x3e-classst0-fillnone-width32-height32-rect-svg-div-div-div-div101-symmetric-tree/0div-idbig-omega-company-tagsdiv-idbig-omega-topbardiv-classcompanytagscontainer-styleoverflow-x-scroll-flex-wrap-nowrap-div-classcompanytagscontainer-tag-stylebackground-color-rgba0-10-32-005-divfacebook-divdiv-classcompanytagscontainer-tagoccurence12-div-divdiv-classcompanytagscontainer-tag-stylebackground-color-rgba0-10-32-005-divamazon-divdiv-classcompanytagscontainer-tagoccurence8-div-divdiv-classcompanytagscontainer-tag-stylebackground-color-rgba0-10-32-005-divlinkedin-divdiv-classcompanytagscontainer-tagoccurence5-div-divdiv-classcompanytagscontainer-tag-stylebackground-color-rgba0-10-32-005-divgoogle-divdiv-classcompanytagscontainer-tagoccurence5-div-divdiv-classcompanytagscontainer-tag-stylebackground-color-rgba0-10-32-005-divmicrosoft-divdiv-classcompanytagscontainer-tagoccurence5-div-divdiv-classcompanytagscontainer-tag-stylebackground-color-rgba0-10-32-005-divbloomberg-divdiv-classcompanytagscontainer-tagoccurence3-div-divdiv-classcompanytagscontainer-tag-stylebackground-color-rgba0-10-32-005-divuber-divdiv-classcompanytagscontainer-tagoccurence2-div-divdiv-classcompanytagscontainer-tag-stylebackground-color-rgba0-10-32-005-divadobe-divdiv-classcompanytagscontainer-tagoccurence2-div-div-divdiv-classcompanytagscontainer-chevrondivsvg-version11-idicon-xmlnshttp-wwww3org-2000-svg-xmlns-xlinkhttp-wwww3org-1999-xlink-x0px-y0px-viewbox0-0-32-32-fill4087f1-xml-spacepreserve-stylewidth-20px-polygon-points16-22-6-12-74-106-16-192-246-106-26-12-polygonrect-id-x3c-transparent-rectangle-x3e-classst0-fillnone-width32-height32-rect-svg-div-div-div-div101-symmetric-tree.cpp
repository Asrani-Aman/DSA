
class Solution {
public:
    bool isPalindrome(vector<int>& level) {
        int n = level.size();
        for (int i = 0; i < n / 2; i++) {
            if (level[i] != level[n - i - 1]) return false;
        }
        return true;
    }

    bool isSymmetric(TreeNode* root) {
        if (root == NULL) return true;
        queue<TreeNode*> q;
        q.push(root);

        while (!q.empty()) {
            int size = q.size();
            vector<int> level;

            for (int i = 0; i < size; i++) {
                TreeNode* node = q.front();
                q.pop();

                if (node->left) {
                    q.push(node->left);
                    level.push_back(node->left->val); // Fix here
                } else {
                    level.push_back(1e9); // Fix here
                }

                if (node->right) {
                    q.push(node->right);
                    level.push_back(node->right->val); // Fix here
                } else {
                    level.push_back(1e9); // Fix here
                }
            }

            if (!isPalindrome(level)) return false;
        }
        return true;
    }
};

