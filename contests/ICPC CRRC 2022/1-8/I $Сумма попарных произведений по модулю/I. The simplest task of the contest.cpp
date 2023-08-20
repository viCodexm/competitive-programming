#include <iostream>
using namespace std;
 
int main() {
    
    int n, module, nums[30001];
    cin >> n >> module;
    for (int i = 0; i < n; ++i)
        cin >> nums[i];
 
    long long total = 0, psum = 0;
    for (int i = 0; i < n; ++i) {
        long long x = 0;
        for (int j = i; j < n; ++j) {
            x += nums[j];
            total += (psum * x);
            psum += x;
        }
        total %= module;
        psum %= module;
    }
    cout << total % module;
   
 
    return 0;
}