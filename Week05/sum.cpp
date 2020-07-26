#include <vector>
#include <algorithm>
#include <iostream>

using std::vector;


vector<vector<int> > sum(vector<int> &nums, int target) {
    vector<vector<int> > ans;

    int size = nums.size();
    if (size < 4) {
        return ans;
    }

    std::sort(nums.begin(), nums.end());

    for (size_t i = 0; i < size; i++) {
        if (i > 0 && nums[i] == nums[i - 1]) {
            continue;
        }

        for (size_t j = i + 1; j < size; j++) {
            if (j > i + 1 && nums[j] == nums[j - 1]) {
                continue;
            }

            int l = j + 1;
            int r = size - 1;

            while (l < r) {
                int sum = nums[i] + nums[j] + nums[l] + nums[r];
                if (sum == target) {
                    vector<int> item;
                    item.push_back(nums[i]);
                    item.push_back(nums[j]);
                    item.push_back(nums[l]);
                    item.push_back(nums[r]);
                    ans.push_back(item);
                    while (nums[l] == nums[l + 1]) l++;
                    while (nums[r] == nums[r - 1]) r--;
                    l++;
                    r--;
                } else if (sum < target) {
                    l++;
                } else if (sum > target) {
                    r--;
                }
            }
        }
    }

    return ans;
}

int main(int argc, char const *argv[]) {
    vector<int> nums;
    nums.push_back(1);
    nums.push_back(0);
    nums.push_back(-1);
    nums.push_back(0);
    nums.push_back(2);
    nums.push_back(-2);
    int target = 0;

    vector<vector<int> > ans = sum(nums, target);
    std::cout << "size:" << ans.size() << std::endl;
    for (size_t i = 0; i < ans.size(); i++)
    {
        vector<int> item = ans[i];
        for (size_t j = 0; j < 4; j++)
        {
            std::cout << "" << item[j] << ",";
        }
        std::cout << std::endl;
        
    }
    
    return 0;
}
