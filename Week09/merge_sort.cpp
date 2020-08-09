#include <vector>
#include <iostream>

void merge(std::vector<int> &nums, int left, int right, int mid) {
    // 临时容器
    std::cout << left << ":" << right << std::endl;
    std::vector<int> tmp(right - left + 1);
    int i = left, j = mid + 1, k = 0;

    while (i <= mid && j <= right) {
        tmp[k++] = nums[i] <= nums[j] ? nums[i++] : nums[j++];
    }

    while (i <= mid) tmp[k++] = nums[i++];
    while (j <= right) tmp[k++] = nums[j++];

    for (i = left, k = 0; i <= right;) nums[i++] = tmp[k++];
}

void merge_sort(std::vector<int> &nums, int left, int right) {
    if (left >= right) {
        return;
    }
    std::cout << left << "\t" << right << std::endl;

    int mid = left + (right - left) / 2;
    merge_sort(nums, left, mid);
    merge_sort(nums, mid + 1, right);
    merge(nums, left, right, mid);
}

int main(int argc, char const *argv[])
{
    std::vector<int> v;
    v.push_back(0);
    v.push_back(10);
    v.push_back(9);
    v.push_back(6);
    v.push_back(20);
    v.push_back(80);
    v.push_back(0);
    v.push_back(1000);
    merge_sort(v, 0, v.size() - 1);
    for (auto num : v) {
        std::cout << num << "\t";
    }
    return 0;
}