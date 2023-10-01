struct TrieNode {
    bool isEnd;
    unordered_map<char, TrieNode*> children;
};
class Trie {
    TrieNode root;
public:
    Trie() {}

    void insert(string word) {
        TrieNode* tmp = &root;
        for (char& c : word) {
            if (!tmp->children[c])
                tmp->children[c] = new TrieNode();
            tmp = tmp->children[c];
        }
        tmp->isEnd = true;
    }

    bool search(string word) {
        TrieNode* tmp = &root;
        for (char& c : word) {
            if (tmp->children.find(c) == tmp->children.end())
                return false;
            tmp = tmp->children[c];
        }
        return tmp->isEnd;
    }

    bool startsWith(string prefix) {
        TrieNode* tmp = &root;
        for (char& c : prefix) {
            if (tmp->children.find(c) == tmp->children.end())
                return false;
            tmp = tmp->children[c];
        }
        return true;
    }
};
