#include <iostream>
#include <vector>
#include <climits>
using namespace std;
struct Node
{
    int data;
    Node *left;
    Node *right;
    Node(int val) : data(val), left(nullptr), right(nullptr) {}
};

Node *BSTBuildFromSort(vector<int> arr, int start, int end)
{
    if (start > end)
        return nullptr;
    int mid = start + (end - start) / 2;
    Node *root = new Node(arr[mid]);
    root->left = BSTBuildFromSort(arr, start, mid - 1);
    root->right = BSTBuildFromSort(arr, mid + 1, end);
    return root;
}
void preorderTraversal(Node *root)
{
    if (root == nullptr)
        return;
    cout << root->data << " ";
    preorderTraversal(root->left);
    preorderTraversal(root->right);
}

Node *deleteTree(Node *root)
{
    if (root == nullptr)
        return nullptr;
    root->left = deleteTree(root->left);
    root->right = deleteTree(root->right);
    delete root;
    return nullptr;
}

Node *BSTFromSortVec(vector<int> arr, int start, int end)
{
    if (start > end)
        return nullptr;
    int mid = start + (end - start) / 2;
    Node *root = new Node(arr[mid]);
    root->left = BSTFromSortVec(arr, start, mid - 1);
    root->right = BSTFromSortVec(arr, mid + 1, end);
    return root;
}

void getInorder(Node *root, vector<int> &nodes)
{
    if (root == NULL)
    {
        return;
    }

    getInorder(root->left, nodes);
    nodes.push_back(root->data);
    getInorder(root->right, nodes);
}
Node *balanceBST(Node *root)
{
    // Get Inorder sequence
    vector<int> nodes;
    getInorder(root, nodes);

    return BSTFromSortVec(nodes, 0, nodes.size() - 1);
}

class info
{
public:
    bool isBST;
    int min;
    int max;
    int sz;
    info(bool isBST, int min, int max, int sz)
    {
        this->isBST = isBST;
        this->min = min;
        this->max = max;
        this->sz = sz;
    }
};

static int maxSize = 0;

info *largestBST(Node *root)
{
    if (root == nullptr)
    {
        return new info(true, INT_MAX, INT_MIN, 0);
    }

    info *leftinfo = largestBST(root->left);
    info *rightinfo = largestBST(root->right);

    int currMin = min(root->data, min(leftinfo->min, rightinfo->min));
    int currMax = max(root->data, max(leftinfo->max, rightinfo->max));
    int currSz = leftinfo->sz + rightinfo->sz + 1;

    if (leftinfo->isBST && rightinfo->isBST 
        && leftinfo->max < root->data 
        && rightinfo->min > root->data)
    {
        maxSize = max(maxSize, currSz);
        return new info(true, currMin, currMax, currSz);
    }

    return new info(false, currMin, currMax, currSz);
}

Node* mergeBSTs(Node* root1, Node* root2) {
    if (!root1) return root2;
    if (!root2) return root1;

    vector<int> nodes1, nodes2;
    vector<int> mergedNodes;
    getInorder(root1, nodes1);
    getInorder(root2, nodes2);

    int i = 0, j = 0;
    while (i < nodes1.size() && j < nodes2.size()) {
        if (nodes1[i] < nodes2[j]) {
            mergedNodes.push_back(nodes1[i]);
            i++;
        } else {
            mergedNodes.push_back(nodes2[j]);
            j++;
        }
    }
    while (i < nodes1.size()) {
        mergedNodes.push_back(nodes1[i]);
        i++;
    }
    while (j < nodes2.size()) {
        mergedNodes.push_back(nodes2[j]);
        j++;
    }
    return BSTFromSortVec(mergedNodes, 0, mergedNodes.size() - 1);

}
    
int main()
{
    // vector<int> sortedArr = {1, 2, 3, 4, 5, 6, 7};
    // Node* root = BSTBuildFromSort(sortedArr, 0, sortedArr.size() - 1);
    // // The tree is now built. Further code can be added to test or display the tree.
    // preorderTraversal(root);
    // cout << endl;

    // Node* root = new Node(6);
    // root->left = new Node(5);
    // root->left->left = new Node(4);
    // root->left->left->left = new Node(3);

    // root->right = new Node(7);
    // root->right->right = new Node(8);
    // root->right->right->right = new Node(9);

    // root = balanceBST(root);
    // preorderTraversal(root);
    // cout << endl;




    // Node *root = new Node(50);
    // root->left = new Node(30);
    // root->left->left = new Node(5);
    // root->left->right = new Node(20);

    // root->right = new Node(60);
    // root->right->left = new Node(45);
    // root->right->right = new Node(70);
    // root->right->right->right = new Node(80);
    // root->right->right->left = new Node(65);

    // largestBST(root);
    // cout << "Size of largest BST is: " << maxSize << endl;


    Node* root1 = new Node(2);
    root1->left = new Node(1);
    root1->right = new Node(4);

    Node* root2 = new Node(9);
    root2->left = new Node(3);
    root2->right = new Node(12);

    Node* mergedRoot = mergeBSTs(root1, root2);
    preorderTraversal(mergedRoot);
    cout<<endl;
    return 0;
}