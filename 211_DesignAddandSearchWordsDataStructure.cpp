#include <vector>
#include <string>
#include <stack>
#include <unordered_map>
#include <queue>

class WordDictionary {
private:
    bool stop;
    int level;
    WordDictionary *_word[26];

public:
    WordDictionary() {
        for (int i = 0; i < 26; ++i) {
            _word[i] = nullptr;
        }
        level = 0;
        stop = false;
    }
    
    void addWord(std::string word) {
        int num = word.size();
        WordDictionary *p = this;
        for (int i = 0; i < num; ++i) {
            int x = word[i] - 'a';
            if (p->_word[x] == nullptr) {
                p->_word[x] = new WordDictionary;
                p->_word[x]->level = p->level + 1;
            }
            p = p->_word[x];
        }
        p->stop = true;
    }
    
    bool search(std::string word) {
        int num = word.size();
        std::stack<WordDictionary*> st;
        st.push(this);
        WordDictionary *p;
        while (!st.empty()) {
            p = st.top();
            st.pop();
            if (p->level == num) {
                if (p->stop) {
                    return true;
                } else {
                    continue;
                }
            }
            if (word[p->level] == '.') {
                for (int i = 0; i < 26; ++i) {
                    if (p->_word[i] != nullptr) {
                        st.push(p->_word[i]);
                    }
                }
            } else {
                int x = word[p->level] - 'a';
                if (p->_word[x] != nullptr) {
                    st.push(p->_word[x]);
                }
            }
        }
        return false;
    }
};
int main () {
    WordDictionary word;
    word.addWord("bad");
    word.addWord("dad");
    word.addWord("mad");
    bool flag;
    flag =word.search("pad");
    flag= word.search("bad");
    flag =word.search(".ad");
    flag =word.search("b..");
    return 0;
}
