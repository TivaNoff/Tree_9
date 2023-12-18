#include <iostream>
#include <vector>
#include <sstream>
#include <stack>

using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

TreeNode* recoverFromTraversal(string traversal) {
    if (traversal.empty()) {
        return nullptr;
    }

    vector<TreeNode*> nodes;
    int depth = 0;
    for (int i = 0; i < traversal.size(); ) {
        int val = 0;
        while (i < traversal.size() && traversal[i] == '-') {
            ++depth;
            ++i;
        }
        while (i < traversal.size() && isdigit(traversal[i])) {
            val = val * 10 + (traversal[i] - '0');
            ++i;
        }
        TreeNode* node = new TreeNode(val);
        while (nodes.size() > depth) {
            nodes.pop_back();
        }
        if (!nodes.empty()) {
            if (!nodes.back()->left) {
                nodes.back()->left = node;
            }
            else {
                nodes.back()->right = node;
            }
        }
        nodes.push_back(node);
        depth = 0;
    }
    return nodes[0];
}

void inorderTraversal(TreeNode* root) {
    if (!root) {
        return;
    }
    inorderTraversal(root->left);
    cout << root->val << " ";
    inorderTraversal(root->right);
}

int main() {
    string traversal1 = "1-2--3--4-5--6--7";
    TreeNode* root1 = recoverFromTraversal(traversal1);
    cout << "Input 1: " << traversal1 << endl;
    cout << "Output 1: ";
    inorderTraversal(root1);
    cout << endl;

    string traversal2 = "1-2--3---4-5--6---7";
    TreeNode* root2 = recoverFromTraversal(traversal2);
    cout << "Input 2: " << traversal2 << endl;
    cout << "Output 2: ";
    inorderTraversal(root2);
    cout << endl;

    string traversal3 = "1-401--349---90--88";
    TreeNode* root3 = recoverFromTraversal(traversal3);
    cout << "Input 3: " << traversal3 << endl;
    cout << "Output 3: ";
    inorderTraversal(root3);
    cout << endl;

    return 0;
}
