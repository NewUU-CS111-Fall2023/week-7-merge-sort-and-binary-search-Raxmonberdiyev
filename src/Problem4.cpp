#include <iostream>
#include <vector>
#include <queue>

using namespace std;

struct Element {
    int value;
    int row;
    int col;

    Element(int v, int r, int c) : value(v), row(r), col(c) {}
};

struct CompareElements {
    bool operator()(const Element& e1, const Element& e2) {
        return e1.value > e2.value;
    }
};

int kthSmallest(vector<vector<int>>& matrix, int k) {
    int n = matrix.size();
    priority_queue<Element, vector<Element>, CompareElements> minHeap;

    // Push the first element of each row into the min heap
    for (int i = 0; i < n; ++i) {
        minHeap.push(Element(matrix[i][0], i, 0));
    }

    int kthSmallest = 0;
    for (int i = 0; i < k; ++i) {
        Element current = minHeap.top();
        minHeap.pop();

        kthSmallest = current.value;

        // If the element has a valid column index, push the next element from the same row
        if (current.col < n - 1) {
            minHeap.push(Element(matrix[current.row][current.col + 1], current.row, current.col + 1));
        }
    }

    return kthSmallest;
}

int main() {
    int n, k;
    cin >> n >> k; // Input n and k
    vector<vector<int>> matrix(n, vector<int>(n));

    // Input matrix elements
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            cin >> matrix[i][j];
        }
    }

    int result = kthSmallest(matrix, k);
    cout << result << endl;

    return 0;
}
