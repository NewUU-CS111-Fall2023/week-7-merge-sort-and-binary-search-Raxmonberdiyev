    /*
 * Author:
 * Date:
 * Name:
 */

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int T;
    cin >> T; // Number of test cases

    while (T--) {
        int N;
        cin >> N; // Number of elements in the array

        vector<int> arr(N);
        for (int i = 0; i < N; ++i) {
            cin >> arr[i]; // Input array elements
        }

        for (int i = 0; i < N - 2; ++i) {
            vector<int> medians;
            for (int j = 0; j < N - i - 2; ++j) {
                vector<int> subarray(arr.begin() + j, arr.begin() + j + i + 3);
                if (subarray.size() % 2 != 0) {
                    sort(subarray.begin(), subarray.end());
                    medians.push_back(subarray[subarray.size() / 2]);
                }
            }
            int min_median = *min_element(medians.begin(), medians.end());
            auto it = find(arr.begin(), arr.end(), min_median);
            if (it != arr.end()) {
                arr.erase(it);
            }
        }

        int remaining_sum = 0;
        for (int i = 0; i < arr.size(); ++i) {
            remaining_sum += arr[i];
        }

        cout << remaining_sum << endl;
    }

    return 0;
}
