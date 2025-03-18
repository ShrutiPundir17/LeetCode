class Solution {
public:
    bool isSymmetric(TreeNode* root) {
        if (!root) return true;

        queue<TreeNode*> q;
        q.push(root->left);
        q.push(root->right);

        while (!q.empty()) {
            TreeNode* p = q.front(); q.pop();
            TreeNode* qNode = q.front(); q.pop();

            if (!p && !qNode) continue;
            if (!p || !qNode || p->val != qNode->val) return false;

            q.push(p->left);
            q.push(qNode->right);
            q.push(p->right);
            q.push(qNode->left);
        }

        return true;
    }
};
