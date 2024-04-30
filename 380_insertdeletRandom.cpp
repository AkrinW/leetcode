#include <iostream>
#include <vector>
#include <map>
#include <unordered_map>
//O(1)HashTable
class RandomizedSet {
public:
    RandomizedSet() {
        srand(unsigned(time(nullptr)));
    }
    
    bool insert(int val) {
        if (hash.count(val)) {
            return false;
        } else {
            int index = array.size();
            array.push_back(val);
            hash[val] = index;
        }
        return true;
    }
    
    bool remove(int val) {
        if (hash.count(val)) {
            int index = array.size();
            array[hash[val]] = array.back();
            hash[array.back()] = hash[val];
            array.pop_back();
            hash.erase(val);
        } else {
            return false;
        }
        return true;
    }
    
    int getRandom() {
        int ran = rand()%array.size();
        return array[ran];
    }
private:
    std::vector<int> array;
    std::unordered_map<int, int> hash;

};

int main() {


    return 0;
}


/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */