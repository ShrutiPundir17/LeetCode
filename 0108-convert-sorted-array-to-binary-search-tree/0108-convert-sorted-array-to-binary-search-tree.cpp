class Solution {
public:
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        if (nums.empty()) return nullptr;

        stack<tuple<TreeNode**, int, int>> st;
        TreeNode* root = nullptr;
        st.emplace(&root, 0, nums.size() - 1);

        while (!st.empty()) {
            auto [node, left, right] = st.top();
            st.pop();

            if (left > right) continue;

            int mid = left + (right - left) / 2;
            *node = new TreeNode(nums[mid]);

            st.emplace(&((*node)->right), mid + 1, right);
            st.emplace(&((*node)->left), left, mid - 1);
        }

        return root;
    }
};
