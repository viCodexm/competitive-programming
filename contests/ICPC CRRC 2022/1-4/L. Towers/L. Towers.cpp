#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;


int lengthOfLIS(vector<int>& A) {
    int len = 0;
    for (auto cur : A)
        if (len == 0 || A[len - 1] < cur) A[len++] = cur;             // extend
        else *lower_bound(begin(A), begin(A) + len, cur) = cur;    // replace
    return len;
}

int main() {
    int n; cin >> n;
    vector<int> input(n);
    for (int i = 0; i < n; ++i) {
        cin >> input[i];
    }
    cout << lengthOfLIS(input);
}