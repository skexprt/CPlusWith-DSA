#include <bits/stdc++.h>
using namespace std;

// Binary Tree Node definition
struct Node {
    int val;
    Node *left, *right;
    Node(int x) : val(x), left(NULL), right(NULL) {}
};

// Helper function: serialize subtree + detect duplicates
string duplicate(Node* root, unordered_map<string, int> &mp, vector<Node*> &v) {
    if (root == NULL) return "#";   // null marker

    string left = duplicate(root->left, mp, v);
    string right = duplicate(root->right, mp, v);

    string serial = to_string(root->val) + "," + left + "," + right;

    mp[serial]++;
    if (mp[serial] == 2) {
        v.push_back(root);
    }

    return serial;
}

// Main function: find duplicate subtrees
vector<Node*> findDuplicateSubtrees(Node* root) {
    unordered_map<string, int> mp;
    vector<Node*> v;
    duplicate(root, mp, v);
    return v;
}

// Utility: print a subtree in preorder
void printPreorder(Node* root) {
    if (!root) return;
    cout << root->val << " ";
    printPreorder(root->left);
    printPreorder(root->right);
}
int height(Node* root, int &maxi){
    if (root == NULL)
    {
        return 0;
    }
    
    int leftH = max(0,height(root->left, maxi));
    int rightH = max(0,height(root->right, maxi));

    maxi = max(maxi, leftH+rightH+root->val);

    return root->val+max(leftH ,rightH);
}
int maxPathSum(Node* root){
    int res = INT_MIN;

    height(root , res);

    return res;
}
int main() {
    /*
        Example tree:
                 1
                / \
               2   3
              /   / \
             4   2   4
                /
               4

        Duplicate subtrees are:
        - Subtree "4"
        - Subtree "2 -> 4"
    */

    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);

    root->left->left = new Node(4);

    root->right->left = new Node(2);
    root->right->right = new Node(4);

    root->right->left->left = new Node(4);

    // // Find duplicates
    // vector<Node*> ans = findDuplicateSubtrees(root);

    // cout << "Duplicate Subtrees (Preorder Traversal):\n";
    // for (auto node : ans) {
    //     printPreorder(node);
    //     cout << endl;
    // }


    // max path sum
    cout<<"\nMaximum Path Sum : "<<maxPathSum(root)<<endl;
    return 0;
}
