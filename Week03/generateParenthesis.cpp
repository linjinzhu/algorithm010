#include <vector>
#include <string>
#include <iostream>

using std::vector;
using std::string;

class Solution {
public:
    vector<string> generate(int n) {
        vector<string> ans;
        dfs(ans, n, 0, 0, "");
        return ans;
    }

    void dfs(vector<string> &ans, int n, int left, int right, string str) {
        // terminator
        if (left == n && right == n) {
            ans.push_back(str);
            return;
        }

        // process
        if (left < n) {
            dfs(ans, n, left + 1, right, str + "(");
        } 
        if (right < left) {
            dfs(ans, n, left, right + 1, str + ")");
        }

        // reverse state
    }
};

int main(int argc, char const *argv[]) {
    Solution s;
    vector<string> ans = s.generate(6);
    for (string s : ans) {
        std::cout << s << std::endl;
    }
    return 0;
}
