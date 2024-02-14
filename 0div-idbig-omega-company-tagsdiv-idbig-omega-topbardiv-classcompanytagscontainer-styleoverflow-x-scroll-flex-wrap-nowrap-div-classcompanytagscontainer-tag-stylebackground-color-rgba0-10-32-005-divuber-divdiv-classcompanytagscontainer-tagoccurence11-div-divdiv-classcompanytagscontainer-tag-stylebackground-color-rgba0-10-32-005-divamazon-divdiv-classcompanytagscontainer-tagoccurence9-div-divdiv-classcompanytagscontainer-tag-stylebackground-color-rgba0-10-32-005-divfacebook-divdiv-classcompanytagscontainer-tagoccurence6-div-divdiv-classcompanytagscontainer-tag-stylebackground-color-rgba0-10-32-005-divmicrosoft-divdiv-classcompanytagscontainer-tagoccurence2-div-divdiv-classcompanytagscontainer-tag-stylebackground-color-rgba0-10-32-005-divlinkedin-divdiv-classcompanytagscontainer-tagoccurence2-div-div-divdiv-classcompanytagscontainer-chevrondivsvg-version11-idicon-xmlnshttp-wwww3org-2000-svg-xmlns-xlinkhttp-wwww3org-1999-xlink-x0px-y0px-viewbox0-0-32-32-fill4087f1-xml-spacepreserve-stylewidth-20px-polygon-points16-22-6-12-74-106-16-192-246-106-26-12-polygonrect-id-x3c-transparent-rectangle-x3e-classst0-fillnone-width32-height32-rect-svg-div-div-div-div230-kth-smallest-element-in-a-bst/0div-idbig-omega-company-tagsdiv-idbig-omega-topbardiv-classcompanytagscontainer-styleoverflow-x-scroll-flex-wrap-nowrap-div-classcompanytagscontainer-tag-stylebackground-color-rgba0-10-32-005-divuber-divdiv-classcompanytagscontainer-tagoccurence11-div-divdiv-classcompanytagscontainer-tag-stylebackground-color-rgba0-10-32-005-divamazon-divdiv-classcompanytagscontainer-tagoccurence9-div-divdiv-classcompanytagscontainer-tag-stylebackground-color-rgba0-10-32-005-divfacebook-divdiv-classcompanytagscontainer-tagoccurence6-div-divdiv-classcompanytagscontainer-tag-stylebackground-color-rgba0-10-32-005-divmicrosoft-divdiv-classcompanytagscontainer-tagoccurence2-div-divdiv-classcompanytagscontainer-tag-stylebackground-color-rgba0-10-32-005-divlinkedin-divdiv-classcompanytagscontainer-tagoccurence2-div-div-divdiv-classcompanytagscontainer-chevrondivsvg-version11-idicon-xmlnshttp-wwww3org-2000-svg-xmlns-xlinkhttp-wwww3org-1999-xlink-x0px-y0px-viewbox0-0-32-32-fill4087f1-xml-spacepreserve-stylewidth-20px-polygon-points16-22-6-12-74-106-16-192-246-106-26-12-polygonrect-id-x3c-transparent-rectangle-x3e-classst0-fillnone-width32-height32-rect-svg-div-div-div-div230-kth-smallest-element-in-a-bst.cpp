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
 // we know that the inorder traversal of the bst is alwasys in the sorted (increasing order)
class Solution {
public:
    void sortedBst(TreeNode* root,vector<int>& ansArray )
    {
        if (root == NULL ) return;
        sortedBst(root->left,ansArray);
        ansArray.push_back(root->val);
        sortedBst(root->right,ansArray);
    }
    int kthSmallest(TreeNode* root, int k) {        
        vector<int> ansArray;
        sortedBst(root,ansArray);
        for(int i =0; i< ansArray.size(); i++)
        {
            cout<< ansArray[i]<<endl;
        }
        return ansArray[k-1];
    }
};