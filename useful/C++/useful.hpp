#pragma once
#include "includes.h"

struct persone {
    int age;
    int weight;
};

struct compare_persone {
    bool operator()(persone persone1, persone persone2) {
        return persone1.age > persone2.age;
    }
};

bool operator> (const persone& persone1, const persone& persone2) {
    return persone1.age > persone2.age;
}
bool operator< (const persone& persone1, const persone& persone2) {
    return persone1.age < persone2.age;
}
void StructSortAndOperatorOverloading() {
    priority_queue<persone, vector<persone>, greater<persone>> pq;
    pq.push(persone(19, 184));
    pq.push(persone(9, 36));
    pq.push(persone(13, 54));
    while (!pq.empty()) {
        cout << pq.top().age << "  " << pq.top().weight << "\n";
        pq.pop();
    }
    cout << "\n\n";
    vector<persone> a;
    a.push_back(persone(44, 84));
    a.push_back(persone(13, 41));
    a.push_back(persone(57, 103));
    sort(a.begin(), a.end(), [](persone& left, persone& right) {
        return left.age < right.age;
    });
    cout << "done..";
}

void FuncThroughLambda() {
    auto turtle = [](int x, int y, int z) {
        cout << "do smf... " << x + y + z;
    };
    turtle(1, 2, 3);
}

void AssertFileIsOpen() {
    fstream file;
    file.open("C:\\Users\\PC\\Downloads\\24.txt");
    assert(file.is_open());
}

void chrono_TimeTakenByFunc() {
    auto start = chrono::high_resolution_clock::now();
    // do smf...
    auto stop = chrono::high_resolution_clock::now();
    auto duration = duration_cast<chrono::seconds>(stop - start);

    cout << "Time taken by function: "
        << duration.count() << " seconds" << endl;
}

void defineDebugTests() {
#define pro_deb(x, expected) printf("Got: %d Expected: %d Test %s", x, expected, (x == expected) ? "Passed V\n" : "Failed X\n");
#define deb(x, expected) cout << #x << " expected: " << #expected << " Test " << ((#x == #expected) ? "Passed V\n" : "Failed X\n");
    deb(1, 1); deb(2, 0); deb(3, 1);
    pro_deb(1, 1); pro_deb(2, 0); pro_deb(3, 1);
}

// читает и выводит через запятую
template<typename... T>
void readEverythingWithTemplate(T&... args) {
    ((cin >> args), ...);
}
template<typename... T>
void writeEverythingWithTemplate(T&&... args) {
    ((cout << args << " "), ...);
}
void readWrite_Example() {
    int x, y, z, h; float a, b;
    readEverythingWithTemplate(x, y, z, h, a, b);
    writeEverythingWithTemplate(x, y, z, h, a, b, "That's amazing! :)");
}

void betterLoop() {
#define fo(i, n) for (int i = 0; i < n; ++i)
    int n = 4;
    vector<int> a = { 1, 2 , 3, 4 };
    int i;
    fo(i, n)
        cout << a[i] << " ";
}

// Custom hash for unordered_map
struct Ceil {
    pair<int, int> down, up, left, right;
};

struct pair_hash
{
    template <class T1, class T2>
    std::size_t operator() (const std::pair<T1, T2> &pair) const {
        return std::hash<T1>()(pair.first) ^ std::hash<T2>()(pair.second);
    }
};
void umap() {
    unordered_map<pair<int, int>, Ceil, pair_hash> memory;
}

//----------------------------
// hide debug for ONLINE_JUDGE
// int main() {
    #if !ONLINE_JUDGE
        #define _CRT_SECURE_NO_WARNINGS
        #include <cstdio>
        freopen("input.txt", "r", stdin);
    #endif

    #if !ONLINE_JUDGE
        // cout debug here
    #endif
    // actual code
// }

