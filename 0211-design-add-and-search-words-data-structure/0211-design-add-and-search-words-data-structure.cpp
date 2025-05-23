class TrieNode {
public:
    vector<TrieNode*> children; // Children nodes for each character
    bool isWordEnd; // Flag to check if a node represents the end of a word

    TrieNode() : children(26, nullptr), isWordEnd(false) {
        // Constructor initializes children pointers to nullptrs and isWordEnd to false
    }

    void insert(const string& word) {
        TrieNode* current = this;
        for (char ch : word) {
            int index = ch - 'a'; // Calculate the index of the character 'a' to 'z'
            if (current->children[index] == nullptr) {
                // If there is no TrieNode at index, create a new one
                current->children[index] = new TrieNode;
            }
            current = current->children[index]; // Move to the next node
        }
        current->isWordEnd = true; // Mark the end of the word
    }
};

class WordDictionary {
private:
    TrieNode* root; // Root node of the Trie

public:
    WordDictionary() : root(new TrieNode()) {
        // Constructor initializes the root node
    }

    void addWord(string word) {
        // Public method to add a word to the Trie
        root->insert(word);
    }

    bool search(string word) {
        // Public method to search for a word in the Trie
        return dfsSearch(word, 0, root);
    }

private:
    bool dfsSearch(const string& word, int index, TrieNode* node) {
        if (index == word.size()) {
            // If end of word is reached, return true if current node isWordEnd
            return node->isWordEnd;
        }

        char ch = word[index]; // Get the character at the current index
        if (ch != '.') {
            // If the character is not a wildcard
            TrieNode* child = node->children[ch - 'a']; // Get the corresponding child node
            if (child && dfsSearch(word, index + 1, child)) {
                // Recurse for the next index if child is not null
                return true;
            }
        } else {
            // If the character is a wildcard, check all possible nodes
            for (TrieNode* child : node->children) {
                if (child && dfsSearch(word, index + 1, child)) {
                    // Recurse with each existing child node and move to the next index
                    return true;
                }
            }
        }
        return false; // Return false if the word does not match or is not found
    }
};
