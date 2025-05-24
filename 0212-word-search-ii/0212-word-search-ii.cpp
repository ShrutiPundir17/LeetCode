class Solution {
public:
    struct TrieNode {
        TrieNode* children[26] = {};
        string word = "";
    };
    
    void insert(TrieNode* root, const string& word) {
        TrieNode* node = root;
        for (char c : word) {
            if (!node->children[c - 'a']) node->children[c - 'a'] = new TrieNode();
            node = node->children[c - 'a'];
        }
        node->word = word;
    }
    
    void dfs(vector<vector<char>>& board, int i, int j, TrieNode* node, vector<string>& result) {
        char c = board[i][j];
        if (c == '#' || !node->children[c - 'a']) return;
        node = node->children[c - 'a'];
        if (!node->word.empty()) {
            result.push_back(node->word);
            node->word.clear();  // avoid duplicates
        }
        
        board[i][j] = '#';
        int dirs[4][2] = {{0,1},{1,0},{0,-1},{-1,0}};
        for (auto& d : dirs) {
            int ni = i + d[0], nj = j + d[1];
            if (ni >= 0 && nj >= 0 && ni < board.size() && nj < board[0].size())
                dfs(board, ni, nj, node, result);
        }
        board[i][j] = c;
    }
    
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        TrieNode* root = new TrieNode();
        for (const string& word : words)
            insert(root, word);
        
        vector<string> result;
        for (int i = 0; i < board.size(); ++i)
            for (int j = 0; j < board[0].size(); ++j)
                dfs(board, i, j, root, result);
        
        return result;
    }
};
