#include <unordered_map>
#include <vector>
#include <iostream>

using std::vector;
using std::unordered_map;

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> ans;
        unordered_map<int, int> nummap;
        for (int i = 0; i < nums.size(); i++) {
            nummap[nums[i]] = i;
        }

        for (int i = 0; i < nums.size(); i++) {
            int temp = target - nums[i];
            if (nummap.count(temp) && nummap[temp] != i) {
                ans.push_back(i);
                ans.push_back(nummap[temp]);
                return ans;
            }
        }

        return ans;
    }
};

int main(int argc, char const *argv[])
{
    Solution s;
    static const int arr[] = {7, 3, 1, 3, 0, 2, 0, 0};
    vector<int> nums (arr, arr + sizeof(arr) / sizeof(arr[0]));
    vector<int> ans = s.twoSum(nums, 9);
    for (size_t i = 0; i < ans.size(); i++) {
        std::cout << i << ":" << ans[i] << std::endl;
    }

    return 0;
}
