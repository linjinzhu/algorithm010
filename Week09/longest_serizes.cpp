#include <iostream>
#include <vector>
#include <algorithm>

std::vector<int> find(std::vector<int> &n);
void dfs(std::vector<int> &v, std::vector<std::vector<int> > &result, std::vector<int> &nums, int level);

using namespace std;
int main() {
    // 序列
    std::vector<int> v;
    v.push_back(10);
    v.push_back(9);
    v.push_back(122);
    v.push_back(3);
    v.push_back(2);
    v.push_back(1);
    v.push_back(0);
    v.push_back(6);
    v.push_back(7);
    v.push_back(8);
    v.push_back(11);
    v.push_back(12);
    std::vector<int> ans = find(v);
    for (auto num : ans) {
        std::cout << num << "\t";
    }
}

std::vector<int> find(std::vector<int> &v) {
    // 排序
    std::sort(v.begin(), v.end());
    
    // 找所有子序列
    std::vector<std::vector<int> > result;
    std::vector<int> nums;
    dfs(v, result, nums, 0);
    
    // 返回最长子序列
    std::vector<int> ans;
    int size_nums = 0;
    std::cout << "result size:" << result.size() << std::endl;
    for (int i=0; i < result.size(); i++) {
        std::vector<int> nums = result[i];
        std::cout << "nums size:" << nums.size() << std::endl;
        if (size_nums < nums.size()) {
            size_nums = nums.size();
            ans = nums;
        }
    }
    
    return ans;
}

void dfs(std::vector<int> &v, std::vector<std::vector<int> > &result, std::vector<int> &nums, int level) {
    // 退出条件
    if (level >= v.size() - 1) {
        result.push_back(nums);
        return;
    }
    
    // 处理逻辑
    int num_left = v[level];
    int num_right = v[level + 1];
    std::cout << num_left << "\t" << num_right << std::endl;
    if (num_right - num_left == 1) {
        nums.push_back(num_left);
    } else {
        nums.push_back(num_left);
        result.push_back(nums);
        nums.clear();
    }
    
    // 下钻到下一层
    dfs(v, result, nums, ++level);
}