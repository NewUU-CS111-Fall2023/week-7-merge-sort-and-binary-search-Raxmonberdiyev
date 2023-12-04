#include <iostream>
#include <vector>
#include <unordered_map>
#include <queue>

using namespace std;

vector<int> topKFrequent(vector<int>& nums, int k) {
    // Create a frequency map to count the occurrences of each element
    unordered_map<int, int> freqMap;
    for (int num : nums) {
        freqMap[num]++;
    }

    // Create a min-heap (priority queue) based on frequency, with a custom comparator
    auto compare = [](pair<int, int>& a, pair<int, int>& b) {
        return a.second > b.second; // Min-heap based on frequency count
    };
    priority_queue<pair<int, int>, vector<pair<int, int>>, decltype(compare)> minHeap(compare);

    // Push elements into the min-heap
    for (auto& entry : freqMap) {
        minHeap.push(entry);
        if (minHeap.size() > k) {
            minHeap.pop(); // Maintain heap size <= k
        }
    }

    // Extract top k frequent elements from the min-heap
    vector<int> result;
    while (!minHeap.empty()) {
        result.push_back(minHeap.top().first);
        minHeap.pop();
    }

    // Reverse the result to get elements in any order
    reverse(result.begin(), result.end());

    return result;
}

int main() {
    int n, k;
    cin >> n; // Size of the array
    vector<int> nums(n);

    // Input array elements
    for (int i = 0; i < n; ++i) {
        cin >> nums[i];
    }

    cin >> k; // Value of k for k most frequent elements

    // Find k most frequent elements
    vector<int> result = topKFrequent(nums, k);

    // Output the k most frequent elements
    for (int num : result) {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}
