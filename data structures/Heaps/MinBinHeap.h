#pragma once
#include <vector>
#include <map>

namespace dsData {
	// 1..n indexation
	class binHeap {
		std::vector<int> data;
		std::map<int, int> dict;
		int count;

		void go_down(int Id, int size);
		void go_up(int Id);
		void magic_swap(int Id, int parentId);
	public:
		binHeap();
		void push(int x);
		int pop();
		int getMin();
		bool find(int key);
	};
	void binHeap::magic_swap(int Id, int parentId) {
		std::swap(data[parentId], data[Id]);
		std::swap(dict[parentId], dict[Id]);
	}

	binHeap::binHeap() {
		data.push_back(0);
		count = 0;
	}
	void binHeap::go_up(int Id) {
		int parentId = Id / 2;
		while (parentId > 0) {	
			if (data[parentId] > data[Id]) {
				magic_swap(parentId, Id);
				Id = parentId;
			}
			else return;
			parentId = Id / 2;
		}
	}
	void binHeap::go_down(int Id, int size) {
		int left = 2 * Id;
		while (left <= size) {
			int minId = (data[Id] <= data[left]) ? Id : left;
			int right = left + 1;
			if (right <= size && data[right] < data[minId])
				minId = right;
			if (minId == Id)
				return;
			magic_swap(minId, Id);
		}
	}

	void binHeap::push(int x) {
		data.push_back(x);
		dict[x]++;
		count++;
		go_up(data.size() - 1);
	}
	int binHeap::pop() {
		int temp = data[1];
		dict[temp]--;
		data[1] = data[count];
		count--;
		go_down(1, count);
		return temp;
	}
	int binHeap::getMin() {
		return data[1];
	}
	bool binHeap::find(int key) {
		return dict[key];
	}
}
