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
    bool isSameNode(TreeNode* p, TreeNode* q) {
        if (p->val == q->val) return true;
        else return false;
    }

    bool isSameTree(TreeNode* p, TreeNode* q) {
        if (p && q) {
            if (isSameNode(p, q)) {
                if (isSameTree(p->left, q->left)) {
                    return isSameTree(p->right, q->right);
                }
                return false;
            } 
            return false;
        }
        else if (p || q) {
            return false;
        }
        else {
            return true;
        }
    }
};