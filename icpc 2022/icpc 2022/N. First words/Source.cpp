#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main()
{
    cin.tie(0);
    ios_base::sync_with_stdio(false);
    int n; cin >> n;
    vector<string> words(n);
    for (auto &e : words)
        cin >> e;
    
    string s; cin >> s;
    vector<bool> couldbe(s.size() + 1, false);
    couldbe[0] = true;

    for (int i = 0; i < s.size(); ++i) {
        if (!couldbe[i])
            continue;
        for (auto& word : words)
            if (s.size() - word.size() >= i && s.substr(i, word.size()) == word)
                couldbe[i + word.size()] = true;
    }

    if (couldbe[s.size()]) cout << "YES";
    else cout << "NO";

    return 0;
}