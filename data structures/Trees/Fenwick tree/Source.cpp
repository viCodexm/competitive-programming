
#include <iostream>
#include <map>
#include <unordered_map>
#include <chrono>

using namespace std;

typedef long long ll;
struct FenwickTree {
	// BItree - Binary Indexed Tree [1..N]
	vector<ll> BItree;
	FenwickTree(vector<int> arr) {
        int n = arr.size();
        BItree.resize(n + 1);
        for (int i = 0; i < n; ++i)
            updateBIT(n, i, arr[i]);
	}

    void updateBIT(int n, int index, int val) {
        index++; // arr[0..N-1] -> BITree[1..N]
        while (index <= n) {
            BItree[index] += val;
            index += index & -index; // black magic
            // extraction of the least significant single bit
        }
    }
    ll sum(int l, int r) {
        ll res = 0;
        while (l < r) {
            res += BItree[r];
            r -= r & -r;
        }
        return res;
    }
    void add(int pos, int x) {
        while (pos <= BItree.size()) {
            BItree[pos] += x;
            pos += pos & -pos;
        }
    }
    void printTree() {
        for (int i = 1; i < BItree.size(); ++i)
            cout << BItree[i] << " ";
        cout << endl;
    }
};


int main() {

    vector<int> arr = { 1, 3, 4, 8, 6, 1, 4, 2 };
    FenwickTree ft(arr);
    ft.printTree();
    cout << ft.sum(1, 7) << "\n"; // expected 27, got 27
    ft.add(3, 5);
    cout << ft.sum(1, 7) << "\n"; // expected 32, got 32

	return 0;
}
