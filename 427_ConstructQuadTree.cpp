#include <vector>
#include <string>
#include <stack>
#include <unordered_map>
#include <queue>
#include <algorithm>

class Node {
public:
    bool val;
    bool isLeaf;
    Node* topLeft;
    Node* topRight;
    Node* bottomLeft;
    Node* bottomRight;
    
    Node() {
        val = false;
        isLeaf = false;
        topLeft = nullptr;
        topRight = nullptr;
        bottomLeft = nullptr;
        bottomRight = nullptr;
    }
    
    Node(bool _val, bool _isLeaf) {
        val = _val;
        isLeaf = _isLeaf;
        topLeft = nullptr;
        topRight = nullptr;
        bottomLeft = nullptr;
        bottomRight = nullptr;
    }
    
    Node(bool _val, bool _isLeaf, Node* _topLeft, Node* _topRight, Node* _bottomLeft, Node* _bottomRight) {
        val = _val;
        isLeaf = _isLeaf;
        topLeft = _topLeft;
        topRight = _topRight;
        bottomLeft = _bottomLeft;
        bottomRight = _bottomRight;
    }
};

class Solution {
private:
    // std::vector<std::vector<int>> _grid;
    Node *consLeaf(int i, int j, int n,std::vector<std::vector<int>>& grid) {
        Node *_cons = new Node();
        if (n == 1) {
            _cons->isLeaf = true;
            _cons->val = grid[i][j];
        } else {
            _cons->topLeft = consLeaf(i,j,n/2,grid);
            _cons->topRight = consLeaf(i,j+n/2,n/2,grid);
            _cons->bottomLeft = consLeaf(i+n/2,j,n/2,grid);
            _cons->bottomRight = consLeaf(i+n/2,j+n/2,n/2,grid);
            if (_cons->topLeft->isLeaf && _cons->topRight->isLeaf && _cons->bottomLeft->isLeaf && _cons->bottomRight->isLeaf && _cons->topLeft->val == _cons->topRight->val && _cons->bottomLeft->val == _cons->topLeft->val && _cons->bottomRight->val == _cons->topLeft->val) {
                _cons->isLeaf = true;
                _cons->val = _cons->topLeft->val;
                // delete _cons->topLeft;
                // delete _cons->topRight;
                // delete _cons->bottomLeft;
                // delete _cons->bottomRight;
                _cons->bottomLeft = nullptr;
                _cons->bottomRight = nullptr;
                _cons->topLeft = nullptr;
                _cons->topRight = nullptr;
            }
        }
        return _cons;
    }
public:
    Node* construct(std::vector<std::vector<int>>& grid) {
        // _grid = grid;
        Node *cons = new Node();
        int num = grid.size();
        cons = consLeaf(0,0,num,grid);
        return cons;
    }
};

int main() {
    
    return 0;
}