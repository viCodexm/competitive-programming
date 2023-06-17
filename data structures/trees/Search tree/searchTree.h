#pragma once
#include <vector>

namespace dsData {
	class SearchTree {
		struct node;
		node* root;
	public:
		SearchTree();
		int getMin();
		int getMax();
		node* nfind(int _data);
		bool find(int _data);
		void push(int _data);
		void pop(int _data);
	};

	struct SearchTree::node {
		node* left, * right, * parent;
		int data;
		node() {
			left = right = parent = NULL; data = NULL;
		};
		node(node* _parent, int _data) {
			left = right = NULL;
			parent = _parent;
			data = _data;
		}
	};

	SearchTree::SearchTree() {
		root = NULL;
	}
	int SearchTree::getMin() {
		if (root == NULL) return NULL;
		node* cur = root;
		while (cur->left != NULL)
			cur = cur->left;
		return cur->data;
	}
	int SearchTree::getMax() {
		if (root == NULL) return NULL;
		node* cur = root;
		while (cur->right != NULL)
			cur = cur->right;
		return cur->data;
	}
	SearchTree::node* SearchTree::nfind(int _data) {
		node* cur = root;
		while (cur != NULL) {
			if (cur->data == _data) return cur;
			if (cur->data > _data && cur->left) cur = cur->left;
			else if (cur->right) cur = cur->right;
			else return NULL;
		}
		return NULL;
	}
	bool SearchTree::find(int _data) {
		return nfind(_data) != NULL;
	}

	void SearchTree::push(int _data) {
		if (root == NULL) {
			root = new node(NULL, _data);
			return;
		}
		node* cur = root;
		while (cur->data != _data) {
			if (cur->data < _data) {
				if (!cur->right)
					cur->right = new node(cur, _data);
				cur = cur->right;
			}
			else {
				if (!cur->left)
					cur->left = new node(cur, _data);
				cur = cur->left;
			}
		}
	}
	
	void SearchTree::pop(int _data) {
		node* cur = nfind(_data);
		if (cur == NULL) return;

		if (cur->left == NULL && cur->right == NULL) {
			node* tmp = cur->parent;
			if (tmp->left && tmp->left->data == cur->data)
				tmp->left = NULL;
			else tmp->right = NULL;
			delete cur;
			return;
		}
		if (cur->parent != NULL && cur->left == NULL && cur->right) {
			node* tmp = cur->parent;
			if (tmp->left && tmp->left->data == cur->data)
				tmp->left = cur->right;
			else tmp->right = cur->right;
			delete cur;
			return;
		}
		if (cur->parent != NULL && cur->right == NULL && cur->left) {
			node* tmp = cur->parent;
			if (tmp->left && tmp->left->data == cur->data)
				tmp->left = cur->left;
			else tmp->right = cur->left;
			delete cur;
			return;
		}
		
		node* submin = cur->right;
		while (submin->left != NULL)
			submin = submin->left;
		
		cur->data = submin->data;
		
		node* tmp = submin->parent;
		if (tmp->right && tmp->right->data == submin->data)
			tmp->right = NULL;
		else tmp->left = NULL;

		delete submin;
		return;
	}
}
