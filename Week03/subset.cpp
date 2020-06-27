#include <iostream>
#include <vector>
#include <set>

using std::vector;

void debug(vector<vector<int> > &ans) {
    for (size_t i = 0; i < ans.size(); i++)
    {
        for (size_t j = 0; j < ans[i].size(); j++)
        {
            int num = ans[i][j];
            std::cout << num << "\t";
        }
        std::cout << std::endl;
    }
}

class Solution {
public:
    vector<vector<int> > subsets(vector<int>& nums) {
        vector<vector<int> > ans;
        if (nums.size() == 0) {
            return ans;
        }

        vector<int> list;
        dfs(ans, nums, list, 0);

        return ans;
    }

    void dfs(vector<vector<int> > &ans, vector<int>& nums, vector<int>& list, int level) {
        // terminator
        if (level == nums.size()) {
            ans.push_back(list);
            return;
        }

        std::cout << "level:" << level << std::endl;

        // process cur level logic
        dfs(ans, nums, list, level + 1); // not pick the num
        list.push_back(nums[level]);
        dfs(ans, nums, list, level + 1); // pick the num

        // debug(ans);
        // reverse state
        list.pop_back();
    }
};

int main(int argc, char const *argv[]) {
    Solution s;
    vector<int> nums;
    nums.push_back(1);
    nums.push_back(2);
    nums.push_back(3);
    std::cout << "nums size:" << nums.size() << std::endl;
    vector<vector<int> > ans = s.subsets(nums);
    debug(ans);
    return 0;
}
