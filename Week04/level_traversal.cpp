/**
 * Definition for a binary tree node.
 
 */

#include <vector>
#include <queue>
#include <iostream>
using std::vector;
using std::queue;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    vector<vector<int> > levelOrder(TreeNode* root) {
        vector<vector<int> > ans;
        bfs(root, ans);
        return ans;
    }

    void bfs(TreeNode* root, vector<vector<int> > &ans) {
        if (root == NULL) {
            return;
        }

        queue<TreeNode*> nodes;
        nodes.push(root);
        while (!nodes.empty()) {
            vector<int> values;

            int len = nodes.size();
            for (int i = 0; i < len; i++) {
                TreeNode* node = nodes.front();
                values.push_back(node->val);
                nodes.pop();

                if (node->left != NULL) {
                    nodes.push(node->left);
                }
                
                if (node->right != NULL) {
                    nodes.push(node->right);
                }
            }
            

            ans.push_back(values);
        }
    }
};

int main(int argc, char const *argv[]) {
    TreeNode node1(3);
    TreeNode node2(9);
    TreeNode node3(20);
    TreeNode node4(15);
    TreeNode node5(7);
    node1.left = &node2;
    node1.right = &node3;
    node3.left = &node4;
    node3.right = &node5;
    Solution s;
    vector<vector<int> > ans = s.levelOrder(&node1);
    for (size_t i = 0; i < ans.size(); i++)
    {
        for (size_t j = 0; j < ans[i].size(); j++)
        {
            std::cout << ans[i][j] << "\t";
        }
         std::cout << std::endl;
        
    }
    

    return 0;
}
