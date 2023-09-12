
#include <iostream>
#include <string>

using namespace std;

int main() {
    string res; getline(cin, res);
    string s;
    while (getline(cin, s)) {
        int diff = s.size() - res.size();
        if (diff > 0)
            res.append(diff, (char)NULL);

        for (int j = 0; j < s.size(); ++j)
            res[j] ^= s[j];
    }
    cout << res;
}
