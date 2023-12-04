    /*
 * Author:
 * Date:
 * Name: Raximberdi
 */

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n;
    cin >> n; // Number of elements

    vector<int> permutation(n);
    for (int i = 0; i < n; ++i) {
        cin >> permutation[i]; // Input permutation
    }

    vector<pair<int, int>> diff(n);
    for (int i = 0; i < n; ++i) {
        diff[i] = make_pair(permutation[i] - i, i + 1);
    }

    sort(diff.begin(), diff.end());

    long long int beautifulness = 0;
    for (int i = 0; i < n; ++i) {
        beautifulness += abs(diff[i].first);
    }

    if (diff[0].first < 0) {
        beautifulness += 2 * abs(diff[0].first); // Maximize the beautifulness by swapping two elements
    }

    cout << beautifulness << endl;

    return 0;
}
