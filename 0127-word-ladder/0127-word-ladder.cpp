class Solution {
public:
    // The main function that starts the bidirectional BFS
    int ladderLength(std::string beginWord, std::string endWord, std::vector<std::string>& wordList) {
        // Initialize a set with the words for fast lookup
        std::unordered_set<std::string> words(wordList.begin(), wordList.end());
        // If the end word is not in the set, no transformation sequence exists
        if (!words.count(endWord)) return 0;

        // Two queues for the bidirectional BFS
        std::queue<std::string> queueBegin{{beginWord}};
        std::queue<std::string> queueEnd{{endWord}};

        // Mapping from word to its number of steps from the begin word or end word
        std::unordered_map<std::string, int> stepsFromBegin;
        std::unordered_map<std::string, int> stepsFromEnd;

        // Initial steps counts for beginWord and endWord
        stepsFromBegin[beginWord] = 1;
        stepsFromEnd[endWord] = 1;

        // Bidirectional BFS
        while (!queueBegin.empty() && !queueEnd.empty()) {
            // Choose the direction with the smaller frontier for extension
            int result = queueBegin.size() <= queueEnd.size()
                ? extendQueue(stepsFromBegin, stepsFromEnd, queueBegin, words)
                : extendQueue(stepsFromEnd, stepsFromBegin, queueEnd, words);

            if (result != -1) return result; // If paths meet, return the result
        }
        return 0; // If no path is found, return 0
    }

    // Extend one level of BFS, updating the queue and steps count
    int extendQueue(std::unordered_map<std::string, int>& currentSteps, 
                    std::unordered_map<std::string, int>& oppositeSteps, 
                    std::queue<std::string>& currentQueue, 
                    std::unordered_set<std::string>& words) {
      
        for (int i = currentQueue.size(); i > 0; --i) {
            std::string word = currentQueue.front();
            int step = currentSteps[word];
            currentQueue.pop();

            // Try to transform each position in the word
            for (int j = 0; j < word.size(); ++j) {
                char originalChar = word[j];

                // Replace the current character with all possible characters
                for (char c = 'a'; c <= 'z'; ++c) {
                    word[j] = c;
                    // Continue if the transformed word is the same or not in the word set
                    if (!words.count(word) || currentSteps.count(word)) continue;
                    // If the transformed word is in the opposite steps, a connection is found
                    if (oppositeSteps.count(word)) return step + oppositeSteps[word];

                    // Otherwise, add the transformed word into the current steps and queue
                    currentSteps[word] = step + 1;
                    currentQueue.push(word);
                }

                // Change back to the original character before trying the next position
                word[j] = originalChar;
            }
        }
        return -1;
    }
};