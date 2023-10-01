
#include <iostream>

using namespace std;


#define print(v)    for (auto& e : v) cout << e << " "; cout << "\n";
#define read(v)		for (auto& e : v) cin >> e;
typedef long long ll;
typedef vector<int> vi;


struct segtree {
	vector<ll> tree;
	int size;

	segtree(int n) {
		size = 1;
		while (size < n) size *= 2;
		tree.assign(2 * size - 1, 0);
	}
	
	void set(int i, int v, int x, int lx, int rx) {
		if (rx - lx == 1) {
			tree[x] = v;
			return;
		}
		int m = (lx + rx) / 2;
		if (i < m)
			set(i, v, 2 * x + 1, lx, m);
		else set(i, v, 2 * x + 2, m, rx);
		tree[x] = tree[2 * x + 1] + tree[2 * x + 2];
	}
	void set(int i, int v) {
		set(i, v, 0, 0, size);
	}

	
	ll sum(int l, int r, int x, int lx, int rx) {
		if (l >= rx || lx >= r)
			return 0;
		if (lx >= l && rx <= r)
			return tree[x];

		int m = (lx + rx) / 2;
		return sum(l, r, 2 * x + 1, lx, m) + sum(l, r, 2 * x + 2, m, rx);
	}
	ll sum(int l, int r) {
		return sum(l, r, 0, 0, size);
	}
};

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int n, q; cin >> n >> q;
	
	segtree seg(n);
	for (int i = 0; i < n; ++i) {
		int x; cin >> x;
		seg.set(i, x);
	}
	
	while (q--) {
		int c; cin >> c;
		if (c == 1) {
            // set query
			int i, v; cin >> i >> v;
			seg.set(i, v);
		}
		else {
            // sum query on [l, r]
			int l, r; cin >> l >> r;
			cout << seg.sum(l, r) << "\n";
		}
	}
	return 0;
}