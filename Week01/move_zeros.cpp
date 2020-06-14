#include <vector>
#include <string>
#include <iostream>

using std::vector;

class Solution {
public:

    void moveZeroes(vector<int>& nums) {
        int j = 0;// 记录非0下标
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] != 0) {
                nums[j] = nums[i];
                j++;
            }
        }

        // 填充0的位置
        for (int i = j; i < nums.size(); i++) {
            nums[i] = 0;
        }
    }
};

void print(vector<int>& nums) {
    for (int num : nums)
    {
        std::cout << num << ",";
    }
    std::cout << std::endl;
    
}

int main(int argc, char const *argv[])
{
    static const int arr[] = {1, 2, 0, 3, 0, 3, 0, 0};
    vector<int> nums (arr, arr + sizeof(arr) / sizeof(arr[0]));
    print(nums);
    Solution s;
    s.moveZeroes(nums);
    print(nums);
    return 0;
}
