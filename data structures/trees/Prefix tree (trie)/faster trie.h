struct TrieNode {
    bool isEnd;
    TrieNode* children[26];
    TrieNode() {
        for (int i = 0; i < 26; ++i)
            children[i] = NULL;
        isEnd = false;
    }
};
class Trie {
    TrieNode* root;
public:
    Trie() { root = new TrieNode(); }

    void insert(string word) {
        TrieNode* tmp = root;
        for (char& c : word) {
            if (!tmp->children[c - 'a'])
                tmp->children[c - 'a'] = new TrieNode();
            tmp = tmp->children[c - 'a'];
        }
        tmp->isEnd = true;
    }

    bool search(string word) {
        TrieNode* tmp = root;
        for (char& c : word) {
            if (!tmp->children[c - 'a'])
                return false;
            tmp = tmp->children[c - 'a'];
        }
        return tmp->isEnd;
    }

    bool startsWith(string prefix) {
        TrieNode* tmp = root;
        for (char& c : prefix) {
            if (!tmp->children[c - 'a'])
                return false;
            tmp = tmp->children[c - 'a'];
        }
        return true;
    }
};
