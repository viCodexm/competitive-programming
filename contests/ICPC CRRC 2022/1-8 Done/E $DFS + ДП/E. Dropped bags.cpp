#include <unordered_map>
#include <functional>
#include <algorithm>
#include <iterator>
#include <iostream>
#include <fstream>
#include <sstream>
#include <numeric>
#include <bitset>
#include <vector>
#include <string>
#include <queue>
#include <deque>
#include <stack>
#include <list>
#include <map>
#include <set>

using namespace std;


#define print(v)    for (auto& e : v) cout << e << " "; cout << "\n";
#define all(v)      v.begin(), v.end()
#define ll long long
#define range(i, a, b) for (int i = a; i < b; ++i)
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<vvi> vvvi;

typedef vector<char> vc;
typedef vector<vc> vvc;
typedef pair<int, int> pi;
typedef vector<pi> vpi;
typedef vector<vpi> vvpi;
typedef vector<vvpi> vvvpi;



int ans = 0;
unordered_map<int, vi> connects;
map<pi, vpi> adj;
vvi dp;
map<pair<pi, int>, bool> used;

int dfs(int cur, int k, int sum) {
    if (k <= 0)
        return sum;
    
    if (sum < dp[cur][k])
        return dp[cur][k];
    
    for (int& to : connects[cur]) {
        
        for (auto& [price, nIdx] : adj[{cur, to}]) {
            if (used[{ {cur, to}, nIdx} ]) //Чтобы не ходить два раза в одну и ту же сторону
                continue;
            
            int weight = price;
            int& back_price = adj[{to, cur}][nIdx].first;
            back_price = price = 0;
        
            used[{{cur, to}, nIdx}] = true;
            dp[cur][k] = max(dp[cur][k], dfs(to, k - 1, sum + weight));
            ans = max(ans, dp[cur][k]);
            used[{{cur, to}, nIdx}] = false;
        
            back_price = price = weight;
        }
    }
    return dp[cur][k] = sum;
}

int main() {
    std::cin.tie(0);
    ios_base::sync_with_stdio(false);
    int cities, roads, k; cin >> cities >> roads >> k;

    while (roads--) {
        int a, b, c; cin >> a >> b >> c;
        connects[a].push_back(b);
        connects[b].push_back(a);
        adj[{a, b}].push_back({ c, adj[{a, b}].size() });
        adj[{b, a}].push_back({ c, adj[{b, a}].size() });
    }
    dp.resize(cities + 1, vi(k + 1, -1));
    dfs(1, k, 0);
    cout << ans;
    return 0;
}