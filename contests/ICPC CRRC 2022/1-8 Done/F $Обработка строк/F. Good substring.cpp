#include <unordered_map>
#include <functional>
#include <algorithm>
#include <iterator>
#include <iostream>
#include <fstream>
#include <sstream>
#include <numeric>
#include <vector>
#include <string>
#include <ranges>
#include <queue>
#include <deque>
#include <stack>
#include <list>
#include <map>
#include <set>
 
using namespace std;
 
 
 
set<char> vowels = { 'a', 'e', 'i', 'o', 'u', 'A', 'E', 'I', 'O', 'U'};
 
bool v(char c) {
    return vowels.contains(c);
}
 
int main() {
    string s; cin >> s;
    int k; cin >> k;
    
    int ans = 0, vowels = 0, consonant = 0, count = 0;
    for (char& c : s) {
            
        if (v(c)) {
            vowels++;
            consonant = 0;
        }
        else {
            consonant++;
            vowels = 0;
        }
        if (vowels >= k || consonant >= k) {
            ans = max(ans, count);
            count = k - 1;
        }
        else count++;
    }
 
    cout << max(ans, count);
}