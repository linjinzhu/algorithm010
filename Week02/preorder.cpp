#include <vector>
#include <stack>
#include <iostream>

using std::vector;
using std::stack;

// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};

class Solution {
public:
    vector<int> preorder(Node* root) {
        vector<int> ans;
        if (root == NULL) {
            return ans;
        }

        stack<Node*> _stack;
        _stack.push(root);
        while (!_stack.empty()) {
            Node *n = _stack.top();
            _stack.pop();

            ans.push_back(n->val);
            vector<Node*> children = n->children;
            std::reverse(children.begin(),children.end());
            for (auto child : children) {
                if (child == NULL) {
                    continue;
                }
                _stack.push(child);
            }
        }

        return ans;
    }
};

int main(int argc, char const *argv[])
{
    Node *root = new Node(10);

    Node *c1 = new Node(1);
    Node *c2 = new Node(2);
    Node *c3 = new Node(3);
    root->children.push_back(c1);
    root->children.push_back(c2);
    root->children.push_back(c3);

    Node *c4 = new Node(4);
    Node *c5 = new Node(5);
    c3->children.push_back(c4);
    c1->children.push_back(c5);

    Solution s;
    vector<int> ans = s.preorder(root);
    for (auto s : ans) {
        std::cout << s << std::endl;
    }
    return 0;
}
