#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int T;
    cin >> T; // Number of test cases

    while (T--) {
        int N, M;
        cin >> N >> M; // Sizes of the two arrays

        vector<int> A(N), B(M);
        for (int i = 0; i < N; ++i) {
            cin >> A[i]; // Input for the first array
        }
        for (int i = 0; i < M; ++i) {
            cin >> B[i]; // Input for the second array
        }

        vector<int> merged;
        int i = 0, j = 0;

        while (i < N && j < M) {
            if (A[i] >= B[j]) {
                merged.push_back(A[i]);
                ++i;
            } else {
                merged.push_back(B[j]);
                ++j;
            }
        }

        while (i < N) {
            merged.push_back(A[i]);
            ++i;
        }

        while (j < M) {
            merged.push_back(B[j]);
            ++j;
        }

        // Sort the merged array in non-increasing order
        sort(merged.begin(), merged.end(), greater<int>());

        // Output the merged array
        for (int k = 0; k < merged.size(); ++k) {
            cout << merged[k] << " ";
        }
        cout << endl;
    }

    return 0;
}
