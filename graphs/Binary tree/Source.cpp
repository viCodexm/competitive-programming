#include <iostream>
#include <vector>

using namespace std;

struct node {
private:
	int data;
	node* left;
	node* right;

public:
	node* createnode(int data) {
		node* newnode = new node();
		newnode->data = data;
		return newnode;
	}

	bool insert(node** root, int key) {
		if (*root == NULL) {
			*root = createnode(key);
			return true;
		}
		node* tmp = *root;
		while (true) {
			if (tmp == NULL) tmp = createnode(key);
			if (key < tmp->data) {
				if (tmp->left == NULL) {
					tmp->left = createnode(key);
					return true;
				}
				else tmp = tmp->left;
			}
			else
			if (key > tmp->data) {
				if (tmp->right == NULL) {
					tmp->right = createnode(key);
					return true;
				}
				else tmp = tmp->right;
			}
			else
			if (key == tmp->data) return false;
		}
	}
	bool find(node* root, int key) {
		node* tmp = root;
		while (true) {
			if (tmp == NULL) return false;
			if (key == tmp->data)
				return true;
			if (key > tmp->data)
				tmp = tmp->right;
			else tmp = tmp->left;
		}
	}
	void print(node* root) {
		if (root != NULL) {
			if (root->left != NULL)
				print(root->left);
			cout << root->data << " ";
			if (root->right != NULL)
				print(root->right);
		}
	}
};

void Solution(node* root, vector<int> a) {
	for (auto& e : a)
		root->insert(&root, e);
	cout << "Print tree: "; root->print(root); cout << endl;
	cout << "Find 3: " << root->find(root, 3) << endl;
	cout << "Find 2: " << root->find(root, 2) << endl;
	cout << "Find 1: " << root->find(root, 1) << endl;

	cout << endl << endl;
}

int main() {
	Solution(NULL, { 1, 2, 3, 4, 5, 6, 7 });
	Solution(NULL, { 9, 13, 0, 2, 324, 47, 29, 34, 2, 1, 59, 7, 3 });
	Solution(NULL, { 9, 3, 8, 7 });
}
