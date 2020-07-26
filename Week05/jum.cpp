#include <vector>
#include <iostream>

using std::vector;

class Solution {
public:
    void dfs(vector<int>& nums, int pos, vector<int>& path, int &count, vector<vector<int> >& paths) {
        if (pos >= nums.size() - 1 || count > nums.size()) {
            return;
        }

        if (count == nums.size()) {
            paths.push_back(path);
        }
        
        path.push_back(nums[pos]);
        count = count + nums[pos + 1];
        dfs(nums, pos + 1, path, count, paths);
    }
    
    int jump(vector<int>& nums) {
        vector<int> path;
        int count = nums[0];
        vector<vector<int> > paths;
        dfs(nums, 0, path, count, paths);
        std::cout << "count:" << paths.size() << std::endl;
        for (size_t j = 0; j < paths.size(); j++) {
            vector<int> temp = paths[j];
            for (size_t i = 0; i < temp.size(); i++) {
                std::cout << "i:" << temp[i] << std::endl;
            }   
        }

        return count;
    }
};




int main(int argc, char const *argv[])
{
    vector<int> nums;
    nums.push_back(2);
    nums.push_back(3);
    nums.push_back(1);
    nums.push_back(1);
    nums.push_back(4);

    Solution s;
    s.jump(nums);
    return 0;
}
