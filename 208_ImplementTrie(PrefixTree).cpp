#include <vector>
#include <string>
#include <stack>
#include <unordered_map>
#include <queue>

class Trie {
private:
    struct Node {
        bool stop;
        std::vector<Node*> _word;
        Node() {
            for (int i = 0; i < 26; ++i) {
                _word.push_back(nullptr);
            }
            stop = false;
        }
    };
    Node *root;

public:
    Trie() {
        root = new Node;
    }
    
    void insert(std::string word) {
        int num = word.size();
        Node *p = root;
        for (int i = 0; i < num; ++i) {
            int x = word[i] - 'a';
            if (p->_word[x] == nullptr) {
                p->_word[x] = new Node;
            }
            p = p->_word[x];
        }
        p->stop = true;
    }
    
    bool search(std::string word) {
        int num = word.size();
        Node *p = root;
        for (int i = 0; i < num; ++i) {
            int x = word[i] - 'a';
            if (p->_word[x] == nullptr) {
                return false;
            }
            p = p->_word[x];
        }
        return p->stop;
    }
    
    bool startsWith(std::string prefix) {
        int num = prefix.size();
        Node *p = root;
        for (int i = 0; i < num; ++i) {
            int x = prefix[i] - 'a';
            if (p->_word[x] == nullptr) {
                return false;
            }
            p = p->_word[x];
        }
        return true;
    }
    
};
