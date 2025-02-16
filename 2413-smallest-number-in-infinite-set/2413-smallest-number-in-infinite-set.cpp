#include <queue>
#include <unordered_set>

class SmallestInfiniteSet {
public:
    SmallestInfiniteSet() : currentMin(1) {}

    int popSmallest() {
        if (!minHeap.empty()) {
            int smallest = minHeap.top();
            minHeap.pop();
            addedNumbers.erase(smallest);
            return smallest;
        }
        return currentMin++;
    }

    void addBack(int num) {
        if (num < currentMin && addedNumbers.insert(num).second) {
            minHeap.push(num);
        }
    }

private:
    int currentMin;
    std::priority_queue<int, std::vector<int>, std::greater<int>> minHeap;
    std::unordered_set<int> addedNumbers;
};
