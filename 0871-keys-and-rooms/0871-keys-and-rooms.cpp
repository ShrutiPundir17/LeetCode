class Solution {
public:
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
    int n = rooms.size();
        vector<bool> vis(n, false);
        stack<int> st;
        int cnt = 0;

        st.push(0);
        vis[0] = true;
        ++cnt;

        while (!st.empty()) {
            int i = st.top();
            st.pop();

            for (int key : rooms[i]) {
                if (!vis[key]) {
                    vis[key] = true;
                    st.push(key);
                    ++cnt;
                }
            }
        }
        return cnt == n; 
    }
};