#include <iostream>
#include <vector>
#include <memory>
class Skiplist {
private:
    struct Node {
        int val;
        std::vector<std::shared_ptr<Node>> next;
        Node(int v, int level):val(v), next(level){}
    };
    std::shared_ptr<Node> head;
    int maxlevel = 32;
    double p = 0.25;

    int RandomLevel() {
        int level = 1;
        while (rand() % 4 == 0 && level < maxlevel) {
            ++level;
        }
        return level;
    }
public:
    Skiplist() {
        head = std::make_shared<Node>(-1,1);
        srand(time(0));
    }
    
    bool search(int target) {
        std::shared_ptr<Node> cur = head;
        int level = head->next.size() - 1;
        while (level >= 0) {
            while (cur->next[level] && cur->next[level]->val < target) {
                cur = cur->next[level];
            }
            if (cur->next[level] && cur->next[level]->val == target) {
                return true;
            }
            --level;
        }
        return false;
    }
    
    void add(int num) {
        int newlevel = RandomLevel();
        if (newlevel > head->next.size()) {
            head->next.resize(newlevel);
        }
        std::shared_ptr<Node> cur = head;
        int level = head->next.size() - 1;
        std::vector<std::shared_ptr<Node>> update(level+1, nullptr);
        while (level >= 0) {
            while (cur->next[level] && cur->next[level]->val < num) {
                cur = cur->next[level];
            }   
            if (cur->val == num) {
                return;
            }
            update[level] = cur;
            --level;
        }
        std::shared_ptr<Node> newNode = std::make_shared<Node>(num, newlevel);
        for (int i = 0; i < newlevel; ++i) {
            newNode->next[i] = update[i]->next[i];
            update[i]->next[i] = newNode;
        }
    }

    bool erase(int num) {
        std::shared_ptr<Node> cur = head;
        int level = head->next.size() - 1;
        std::vector<std::shared_ptr<Node>> update(level+1,nullptr);
        while (level >= 0) {
            while (cur->next[level] && cur->next[level]->val < num) {
                cur = cur->next[level];
            }
            update[level] = cur;
            --level;
        }
        cur = cur->next[0];
        if (cur == nullptr || cur->val != num) {
            return false;
        }
        for (int i = 0; i < cur->next.size(); ++i) {
            update[i]->next[i] = cur->next[i];
        }
        int i = head->next.size() - 1;
        while (i >= 0 && head->next[i] == nullptr) {
            --i;
        }
        head->next.resize(i+1);
        return true;
    }
};

/**
 * Your Skiplist object will be instantiated and called as such:
 * Skiplist* obj = new Skiplist();
 * bool param_1 = obj->search(target);
 * obj->add(num);
 * bool param_3 = obj->erase(num);
 */

int main() {
    Skiplist* list = new Skiplist();
    for (int i = 0; i < 10; ++i) {
        list->add(i);
    }
    list->add(5);
    bool b = list->erase(3);
    return 0;
}