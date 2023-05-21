
#include <iostream>
#include <map>
#include <unordered_map>
#include <chrono>

using namespace std;


template<typename Tkey, typename Tval>
struct HashTable {
	// basically our hash table is something like this:
	// index |  <key, value>
	// `[0]` -> () 
	// `[1]` -> ()
	// `[2]` -> ()
	// `[3]` -> ()
	// `[4]` -> () -> () -> () // this is worst case scenario then search becomes O(k), k-length of this list
	// `[5]` -> ()
	// `[6]` -> ()
	// note: we get our index through hash(key)
	int a, b, k, hv;
	list<pair<Tkey, Tval>>* table; // array of pointers to lists

	// on `Windows 7` max size of a `rand()` is 15 bits => 32768
	HashTable(int size) {
		//a = rand() % 9 + 1; // just a random numbers
		//b = rand() % 100 + 10; // it's better without it. Maybe Im wrong
		
		// works well with initial size [1; 1'100'000]
		// after this it starts to have collisions
		// so there should be like 50% of empty space to have 0 collisions
		// best solution with maximum density should have like 90% of filled space
		// with the size of 4'000'000 it's still works really well and has only ~1.9mil collisions
		// with 2.2s of inserting and 1.3s for searching when unordered_map has 4.7s and 1.2s respectively
		size = 2237561; // prime number & Einstein integer
		// or use Mersenne prime number
		k = size;
		table = new list<pair<Tkey, Tval>>[size];
	}
	int hash(string key) {
		// the STUPIDEST & easiest realisation of string hashing
		int sum = 0; for (char& c : key) sum += c;
		// let's assume that sum will not overflow
		return hash(sum);
	}
	int hash(int& key) {
		return key % k;
		// maybe Im doing smf wrong, but key % k behaves way better than (a*key+b) % k and can handle bigger input sizes
		//return (a * key + b) % k; // gives no benefits. Maybe `a` & `b` generates wrong
	}

	bool insert(Tkey key, Tval value) {
		hv = hash(key);
		table[hv].push_back({ key, value });
		return table[hv].size() == 1; // if was no collisions
	}

	Tval search(Tkey& key) {
		hv = hash(key);
		for (pair<Tkey, Tval>& e : table[hv])
			if (e.first == key)
				return e.second;
		return NULL;
	}
};

#define time_mark(val) val = chrono::high_resolution_clock::now();
#define time_duration(text) cout << text << duration_cast<chrono::milliseconds>(stop - start).count() << " milliseconds\n";

int main() {
	std::srand(std::time(NULL));

	chrono::steady_clock::time_point start, stop;

	const int insert_size = 1'000'000;
	const int insert_maxValue = insert_size * 10;
	vector<int> iKeys(insert_size);
	int used = 0;
	for (int i = 0; i < INT_MAX && used < insert_size; i += 100) {
		if (rand() % 2)
			iKeys[used++] = i;
	}
	cout << "Hash function: key % 2237561\n";
	cout << "Hash table size: 2237561\n";
	cout << "Total keys: " << used << "\n";
	cout << "Range of keys: " << iKeys[0] << "..." << iKeys[used - 1] << "\n";
	cout << "Next key is equal to last plus 100";
	cout << "\ninserting elements:\n";
	
	unordered_map<int, int> uDict;
	time_mark(start);
	for (int& key : iKeys)
		uDict[key] = 1;
	time_mark(stop);
	time_duration("\nunordered_map: ");
	
	int COLLISIONS_COUNT = 0;
	HashTable<int, int> ht(insert_size);
	time_mark(start)
	for (int& key : iKeys)
		if (!ht.insert(key, 1)) COLLISIONS_COUNT++;
	time_mark(stop)
	time_duration("Modular hash table: ");


	cout << "\nsearching elements:\n";
	time_mark(start)
	for (int& key : iKeys)
		if (!uDict[key]) exit(-1);
	time_mark(stop)
	time_duration("\nunordered_map: ");

	time_mark(start)
	for (int& key : iKeys)
		if (!ht.search(key)) exit(-1);
	time_mark(stop)
	time_duration("Modular hash table: ");

	cout << "\nTOTAL COLLISIONS: " << COLLISIONS_COUNT << "\n";
	return 0;
}