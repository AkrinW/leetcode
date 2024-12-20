#include <vector>
#include <iostream>
#include <map>
using namespace std;

void mergexy(vector<int>& X, vector<int>& Y, vector<int>& tempX, vector<int>& tempY, int left, int right) {
    if (left < right) {
        int mid = (left + right) / 2;
        mergexy(X, Y, tempX, tempY, left, mid);
        mergexy(X, Y, tempX, tempY, mid + 1, right);

        int i = left, j = mid+1, k = left;
        while (i <= mid && j <= right) {
            if (X[i] <= X[j]) {
                tempX[k] = X[i];
                tempY[k] = Y[i];
                ++i;
            } else {
                tempX[k] = X[j];
                tempY[k] = Y[j];
                ++j;
            }
            ++k;
        }
        while (i <= mid) {
            tempX[k] = X[i];
            tempY[k] = Y[i];
            ++k;
            ++i;
        }
        while (j <= right) {
            tempX[k] = X[j];
            tempY[k] = Y[j];
            ++k;
            ++j;
        }
        for (i = left; i <= right; i++) {
            X[i] = tempX[i];
            Y[i] = tempY[i];
        }
    }
}

void mergey(vector<int>& Y, vector<int>& tempY, int left, int right, map<int,int>& count) {
    if (left < right) {
        int mid = (left+right)/2;
        mergey(Y,tempY,left, mid,count);
        mergey(Y,tempY,mid+1, right, count);

        int i = left, j = mid+1, k = left;
        int smaller = 0;
        while (i <= mid && j <= right) {
            if (Y[i] <= Y[j]) {
                ++smaller;
                tempY[k] = Y[i];
                ++i;
            } else {
                count[Y[j]] += smaller;
                tempY[k] = Y[j];
                ++j;
            }
            ++k;
        }
        while (i <= mid) {
            tempY[k] = Y[i];
            ++k;
            ++i;
        }
        while (j <= right) {
            count[Y[j]] += smaller;
            tempY[k] = Y[j];
            ++k;
            ++j;
        }
        for (i = left; i <= right; i++) {
            Y[i] = tempY[i];
        }
    }
}

// 执行两次归并排序, O(nlogn)
int main() {   
    int n;
    cin >> n;
    vector<int> X(n), Y(n);
    vector<int> tempX(n), tempY(n);
    for (int i = 0; i < n; ++i) {
        cin >> X[i] >> Y[i];
    }
    // 先让x从小到大排列
    mergexy(X,Y,tempX,tempY,0,n-1);

    // 接下来只要统计每个y，前面有多少比它小的y即可
    map<int,int> count;
    mergey(Y,tempY,0,n-1,count);
    int all = n * (n-1) /2 ;
    int consist = 0;
    for (auto u: count) {
        consist += u.second;
    }
    // double tao = double(2*consist-all)/double(all);

    // cout << tao;
    cout << (2*consist-all);
    return 0;
}