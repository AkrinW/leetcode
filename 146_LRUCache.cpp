#include <iostream>
#include <unordered_map>

class LRUCache {
private:
    struct ListNode {
        int key;
        int val;
        ListNode *next;
        ListNode *last;
        ListNode() : key(0), val(0), next(nullptr), last(nullptr) {}
        ListNode(int k, int v, ListNode *l = nullptr, ListNode *n = nullptr) : key(k), val(v), last(l), next(n) {}
    };
    std::unordered_map<int, ListNode*> map;
    ListNode *start;
    ListNode *end;
    int curn;
    int capc;
public:
    LRUCache(int capacity) {
        capc = capacity;
        start = new ListNode;
        end = new ListNode;
        start->next = end;
        end->last = start;
        curn = 0;
    }
    
    int get(int key) {
        if (map[key] == nullptr) {
            return -1;
        } else {
            int v = map[key]->val;
            ListNode *p = map[key];
            p->last->next = p->next;
            p->next->last = p->last;
            p->next = end;
            p->last = end->last;
            p->last->next = p;
            end->last = p;
            return v;
        }
    }
    
    void put(int key, int value) {
        if (map[key] == nullptr) {
            ++curn;
            ListNode *p = new ListNode(key, value, end->last, end);
            end->last->next = p;
            end->last = p;
            map[key] = p;
            if (curn > capc) {
                ListNode *q = start->next;
                start->next = q->next;
                q->next->last = start;
                map[q->key] = nullptr;
                delete q;
                --curn;
            }
        } else {
            map[key]->val = value;
            ListNode *p = map[key];
            p->last->next = p->next;
            p->next->last = p->last;
            p->next = end;
            p->last = end->last;
            p->last->next = p;
            end->last = p;
        }
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */