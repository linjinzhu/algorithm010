#include <vector>
using namespace std;

void merge_sort(vector<int> &v, int left, int right) {
    if (right < left) return;
    int mid = (right + left) / 2;
    merge_sort(v, left, mid);
    merge_sort(v, mid + 1, right);
    merge(v, left, mid, right);
}

void merge(vector<int> &v, int left, int mid, int right) {
    // 合并
}