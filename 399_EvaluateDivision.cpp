#include <iostream>
#include <vector>
#include <unordered_map>
#include <stack>
//糟糕至极的代码，需要重写。
class Solution {
private:
    struct point {
        int parent;
        long double val;
        point() {
            val = 1;
            parent = -1;
        }
    };

public:
    std::vector<double> calcEquation(std::vector<std::vector<std::string>>& equations, std::vector<double>& values, std::vector<std::vector<std::string>>& queries) {
        // std::unordered_map<std::string, int> unionmap;
        std::unordered_map<std::string, int> list;
        std::unordered_map<int, point*> unionmap;
        std::stack<int> st;
        int count = 1;
        int num = equations.size();
        for (int i = 0; i < num; ++i) {
            std::string a = equations[i][0];
            std::string b = equations[i][1];
            if (!list.count(a) && !list.count(b)) {
                list[a] = count;
                point *p = new point();
                unionmap[count] = p;
                ++count;
                list[b] = count;
                point *p2 = new point();
                unionmap[count] = p2;
                ++count;
                point *pa = unionmap[list[a]];
                point *pb = unionmap[list[b]];
                pa->parent = list[b];
                pa->val = values[i];
            } else if (!list.count(a)) {
                list[a] = count;
                point *p = new point();
                unionmap[count] = p;
                ++count;
                //缩短b
                point *pa = unionmap[list[a]];
                point *pb = unionmap[list[b]];
                int la = list[b];
                int la_p = unionmap[la]->parent;
                if (la_p == -1) {
                    pa->parent = list[b];
                    pa->val = values[i];
                } else {
                    while (la_p != -1) {
                        st.push(la);
                        la = la_p;
                        la_p = unionmap[la]->parent;
                    }
                    la = st.top();
                    st.pop();
                    la_p = unionmap[la]->parent;
                    long double tmpv = unionmap[la]->val;
                    while (!st.empty()) {
                        int lb = st.top();
                        st.pop();
                        unionmap[lb]->parent = la_p;
                        tmpv *= unionmap[lb]->val;
                        unionmap[lb]->val = tmpv;
                    }
                    if (list[a] != la_p) {
                        pa->parent = la_p;
                        pa->val = values[i] * tmpv;
                    }
                }
            } else if (!list.count(b)) {
                list[b] = count;
                point *p = new point();
                unionmap[count] = p;
                ++count;
                // 缩短a
                point *pa = unionmap[list[a]];
                point *pb = unionmap[list[b]];
                int la = list[a];
                int la_p = unionmap[la]->parent;
                if (la_p == -1) {
                    pb->parent = list[a];
                    pb->val = 1 / values[i];
                } else {
                    while (la_p != -1) {
                        st.push(la);
                        la = la_p;
                        la_p = unionmap[la]->parent;
                    }
                    la = st.top();
                    st.pop();
                    la_p = unionmap[la]->parent;
                    long double tmpv = unionmap[la]->val;
                    while (!st.empty()) {
                        int lb = st.top();
                        st.pop();
                        unionmap[lb]->parent = la_p;
                        tmpv *= unionmap[lb]->val;
                        unionmap[lb]->val = tmpv;
                    }
                    if (list[b] != la_p) {
                        pb->parent = la_p;
                        pb->val =  tmpv / values[i];
                    }
                }
            } else {
                point *pa = unionmap[list[a]];
                point *pb = unionmap[list[b]];
                //缩短ab
                int la = list[a];
                int la_p = unionmap[la]->parent;
                if (la_p != -1){
                    while (la_p != -1) {
                        st.push(la);
                        la = la_p;
                        la_p = unionmap[la]->parent;
                    }
                    la = st.top();
                    st.pop();
                    la_p = unionmap[la]->parent;
                    long double tmpv = unionmap[la]->val;
                    while (!st.empty()) {
                        int lb = st.top();
                        st.pop();
                        unionmap[lb]->parent = la_p;
                        tmpv *= unionmap[lb]->val;
                        unionmap[lb]->val = tmpv;
                    }
                    if (unionmap[list[b]]->parent != la_p) {
                        unionmap[la_p]->parent = list[b];
                        unionmap[la_p]->val = values[i] / tmpv;
                    }
                } else {
                    if (unionmap[list[b]]->parent != la) {
                        unionmap[la]->parent = list[b];
                        unionmap[la]->val = values[i];
                    }
                }
                la = list[b];
                la_p = unionmap[la]->parent;
                if (la_p != -1) {
                    while (la_p != -1) {
                        st.push(la);
                        la = la_p;
                        la_p = unionmap[la]->parent;
                    }
                    la = st.top();
                    st.pop();
                    la_p = unionmap[la]->parent;
                    long double tmpv = unionmap[la]->val;
                    while (!st.empty()) {
                        int lb = st.top();
                        st.pop();
                        unionmap[lb]->parent = la_p;
                        tmpv *= unionmap[lb]->val;
                        unionmap[lb]->val = tmpv;
                    }
                }
            }
        }
        std::vector<double> cal;
        int num2 = queries.size();
        for (int i = 0; i < num2; ++i) {
            std::string a = queries[i][0];
            std::string b = queries[i][1];
            if (!list.count(a) || !list.count(b)) {
                cal.push_back(-1);
                continue;
            }
            long double diva, divb;
            int a_p, b_p;
            if (unionmap[list[a]]->parent == -1) {
                diva = 1;
                a_p = list[a];
            } else {
                int la = list[a];
                int la_p = unionmap[la]->parent;
                while (la_p != -1) {
                    st.push(la);
                    la = la_p;
                    la_p = unionmap[la]->parent;
                }
                la = st.top();
                st.pop();
                la_p = unionmap[la]->parent;
                long double tmpv = unionmap[la]->val;
                while (!st.empty()) {
                    int lb = st.top();
                    st.pop();
                    unionmap[lb]->parent = la_p;
                    tmpv *= unionmap[lb]->val;
                    unionmap[lb]->val = tmpv;
                }
                diva = unionmap[list[a]]->val;
                a_p = unionmap[list[a]]->parent;
            }
            if (unionmap[list[b]]->parent == -1) {
                divb = 1;
                b_p = list[b];
            } else {
                int la = list[b];
                int la_p = unionmap[la]->parent;
                while (la_p != -1) {
                    st.push(la);
                    la = la_p;
                    la_p = unionmap[la]->parent;
                }
                la = st.top();
                st.pop();
                la_p = unionmap[la]->parent;
                long double tmpv = unionmap[la]->val;
                while (!st.empty()) {
                    int lb = st.top();
                    st.pop();
                    unionmap[lb]->parent = la_p;
                    tmpv *= unionmap[lb]->val;
                    unionmap[lb]->val = tmpv;
                }
                divb = unionmap[list[b]]->val;
                b_p = unionmap[list[b]]->parent;
            }
            if (a_p != b_p) {
                cal.push_back(-1);
            } else {
                cal.push_back(diva/divb);
            }
        }
        return cal;
    }
};

int main() {
    std::vector<std::vector<std::string>> _equ = {{"a","b"},{"c","b"},{"d","b"},{"w","x"},{"y","x"},{"z","x"},{"w","d"}};
    std::vector<double> _val = {2.0,3.0,4.0,5.0,6.0,7.0,8.0};
    std::vector<std::vector<std::string>> _que = {{"a","c"},{"b","c"},{"a","e"},{"a","a"},{"x","x"},{"a","z"}};
    Solution sol;
    std::vector<double> ans;
    ans = sol.calcEquation(_equ,_val,_que);
    return 0;
}