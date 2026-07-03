#include <iostream>
#include <vector>
#include <queue>
#include <map>
using namespace std;

class Node
{
public:
    int data;
    Node *left;
    Node *right;

    Node(int data)
    {
        this->data = data;
        left = right = NULL;
    }
};
static int idx = -1; // Reset index for each buildtree call
// Do NOT make idx static. Pass it by reference instead.
Node *buildTree(const vector<int> &Nodes)
{
    idx++;
    if (Nodes[idx] == -1)
    {
        return NULL;
    }

    Node *currNode = new Node(Nodes[idx]);
    currNode->left = buildTree(Nodes);
    currNode->right = buildTree(Nodes);

    return currNode;
}

void preOrder(Node *root)
{
    if (root == NULL)
    {
        return;
    }
    cout << root->data << " ";
    preOrder(root->left);
    preOrder(root->right);
}

void inOrder(Node *root)
{
    if (root == NULL)
    {
        return;
    }
    inOrder(root->left);
    cout << root->data << " ";
    inOrder(root->right);
}

void postOrder(Node *root)
{
    if (root == NULL)
    {
        return;
    }

    postOrder(root->left);
    postOrder(root->right);
    cout << root->data << " ";
}

void levelOrder(Node *root)
{
    if (root == NULL)
    {
        return;
    }
    queue<Node *> Q;
    Q.push(root);
    Q.push(NULL); // Marker for end of Level
    while (!Q.empty())
    {
        Node *currNode = Q.front();
        Q.pop();
        if (currNode == NULL)
        {
            cout << endl; // print a new line for the next level
            if (!Q.empty())
            {
                // break; // Break if we reach the end of the current levl
                Q.push(NULL); // add marker for next level
            }
        }
        else
        {
            cout << currNode->data << " ";

            if (currNode->left != NULL)
            {
                Q.push(currNode->left);
            }
            if (currNode->right != NULL)
            {
                Q.push(currNode->right);
            }
        }
    }
}

int Height(Node *root)
{
    if (root == NULL)
    {
        return 0;
    }

    int leftHt = Height(root->left);
    int rightHt = Height(root->right);
    return max(leftHt, rightHt) + 1;
}

int count(Node *root)
{
    if (root == NULL)
    {
        return 0;
    }

    int leftCount = count(root->left);
    int rightCount = count(root->right);
    return leftCount + rightCount + 1; // +1 for the current node
}

int sum(Node *root)
{
    if (root == NULL)
    {
        return 0;
    }

    int leftSum = sum(root->left);
    int rightSum = sum(root->right);
    // return leftSum + rightSum + root->data;  // + data of the current node
    int totalSum = leftSum + rightSum + root->data;
    cout << "Sum at node " << root->data << ": " << totalSum << endl;
    return totalSum;
}

int diam1(Node *root)
{
    if (root == NULL)
    {
        return 0;
    }
    int currdiam = Height(root->left) + Height(root->right) + 1;
    int leftdiam = diam1(root->left);
    int rightdiam = diam1(root->right);
    return max(currdiam, max(leftdiam, rightdiam)); // return the maximum diameter found
}

pair<int, int> diam2(Node *root)
{ // O(n) timt complexity, O(n)space complexity
    if (root == NULL)
    {
        return make_pair(0, 0); // diameter, height
    }

    pair<int, int> leftInfo = diam2(root->left);
    pair<int, int> rightInfo = diam2(root->right);

    int currdiam = leftInfo.second + rightInfo.second + 1; // +1 for the current node
    int finaldiam = max(currdiam, max(leftInfo.first, rightInfo.first));
    int currHt = max(leftInfo.second, rightInfo.second) + 1; // +1 for the current node
    return make_pair(finaldiam, currHt);
}
bool isIdentical(Node *root, Node *SubRoot)
{
    if (root == NULL && SubRoot == NULL)
    {
        return true;
    }
    if (root == NULL || SubRoot == NULL)
    {
        return false;
    }
    if (root->data != SubRoot->data)
    {
        return false;
    }
    return isIdentical(root->left, SubRoot->left) && isIdentical(root->right, SubRoot->right);
}
bool isSubtree(Node *root, Node *SubRoot)
{
    if (root == NULL && SubRoot == NULL)
    {
        return true;
    }
    else if (root == NULL || SubRoot == NULL)
    {
        return false;
    }
    if (root->data == SubRoot->data)
    {
        // Check for identical trees
        if (isIdentical(root, SubRoot))
        {
            return true;
        }
    }

    int isLeftSubtree = isSubtree(root->left, SubRoot);
    if (!isLeftSubtree)
    {
        return isSubtree(root->right, SubRoot);
    }
    return true;
}

void topView(Node *root)
{
    queue<pair<Node *, int>> Q; // Node, Horizontal Distance
    map<int, int> m;            // HD, Node->data
    Q.push(make_pair(root, 0));
    while (!Q.empty())
    {
        pair<Node *, int> curr = Q.front();
        Q.pop();
        Node *currNode = curr.first;
        int currHD = curr.second;

        if (m.count(currHD) == 0) // if horizontal distance is not present in the map
        {
            m[currHD] = currNode->data;
        }
        if (currNode->left != NULL)
        {
            pair<Node *, int> left = make_pair(currNode->left, currHD - 1);
            Q.push(left);
        }
        if (currNode->right != NULL)
        {
            pair<Node *, int> right = make_pair(currNode->right, currHD + 1);
            Q.push(right);
        }
    }
    for (auto i : m)
    {
        cout << i.second << " ";
    }
}
void KthHelper(Node *root, int k, int currlevel)
{
    if (root == NULL)
    {
        return;
    }
    if (currlevel == k)
    {
        cout << root->data << " ";
        return;
    }
    KthHelper(root->left, k, currlevel + 1);
    KthHelper(root->right, k, currlevel + 1);
}
void KthLevel(Node *root, int k)
{
    KthHelper(root, k, 1);

    cout << endl;
}

bool rootToNodePath(Node *root, int n, vector<int> &path)
{
    if (root == NULL)
    {
        return false;
    }

    path.push_back(root->data);
    if (root->data == n)
    {
        return true;
    }
    int isleft = rootToNodePath(root->left, n, path);
    int isright = rootToNodePath(root->right, n, path);

    if (isleft || isright)
    {
        return true;
    }

    path.pop_back();
    return false;
}
int LCA(Node *root, int n1, int n2)
{
    vector<int> path1;
    vector<int> path2;

    rootToNodePath(root, n1, path1);
    rootToNodePath(root, n2, path2);

    int lca = -1;
    for (int i = 0, j = 0; i < path1.size() && j < path2.size(); i++, j++)
    {
        if (path1[i] != path2[j])
        {
            return lca;
        }
        lca = path1[i];
    }
    return lca;
}

Node *LCA2(Node *root, int n1, int n2)
{
    if (root == NULL)
    {
        return NULL;
    }

    if (root->data == n1 || root->data == n2)
    {
        return root;
    }

    Node *leftLCA = LCA2(root->left, n1, n2);
    Node *rightLCA = LCA2(root->right, n1, n2);

    if (leftLCA != NULL && rightLCA != NULL)
    {
        return root;
    }

    return leftLCA == NULL ? rightLCA : leftLCA;
}

int Dist(Node *root, int n)
{
    if (root == NULL) return -1;
    
    
    if (root->data == n)  return 0;
    

    int leftroot = Dist(root->left, n);
    if (leftroot != -1)
    {
        return leftroot + 1;
    }
    int rightroot = Dist(root->right, n);
    if (rightroot != -1)
    {
        return rightroot + 1;
    }

    return -1;
}
int minDist(Node *root, int n1, int n2)
{
    Node *lca = LCA2(root, n1, n2);

    int Dist1 = Dist(lca, n1);
    int Dist2 = Dist(lca, n2);

    return Dist1 + Dist2;
}

int KthAncestor(Node* root, int node, int k){
    if (root == NULL)
    {
        return -1;
    }
    if (root->data == node)
    {
        return 0;
    }
    
    int leftDist =KthAncestor(root->left, node, k);
    int rightDist =KthAncestor(root->right, node, k);

    if (leftDist == -1 && rightDist == -1)
    {
        return -1;
    }
    
    int vailidVal = leftDist == -1 ? rightDist : leftDist;
    if (vailidVal+1 == k){
        cout<<"KthAncestor value : "<<root->data<<endl;
    }
    
    return vailidVal+1;
    
}

int transfrom(Node* root){
    if (root == NULL) return 0;

    int leftOld = transfrom(root->left);
    int rightOld = transfrom(root->right);
    int currOld = root->data;

    root->data = leftOld + rightOld;

    if (root->left != NULL)
    {
        root->data += root->left->data;
    }
    
     if (root->right!= NULL)
    {
        root->data += root->right->data;
    }
    
    return currOld ;
}

// Assinment question 1
int isUnivalTree(Node* root){
    if (root == NULL)
    {
        return true;
    }

    if (!isUnivalTree(root->left) || !isUnivalTree(root->right))
    {
        return false;
    }

    if (root->left != NULL)
    {
        if (root->data != root->left->data)
        {
            return false;
        }
    
        
    }
    if (root->right != NULL)
    {
        if (root->data != root->right->data)
        {
            return false;
        }
    }
    
    return true;
    
}

// Assinment question 2

Node* invertedTree(Node* root){
    if (root == NULL)
    {
        return root;
    }

    Node* left = invertedTree(root->left);
    Node* right = invertedTree(root->right);


    root->left = right;
    root->right = left;

    return root;
    
}
// Assinmet question3

Node* removeLeafNode(Node* root, int Target){
    if (root == NULL)
    {
        return NULL;
    }

    Node* left = removeLeafNode(root->left , Target);
    Node* right = removeLeafNode(root->right , Target);

    if (left==NULL && right == NULL &&  root->data == Target )
    {
        return NULL;
    }

    root->left = left;
    root->right = right;
    return root;
}



int main()
{
    // vector<int> Nodes = {1, 2, 4, -1, -1, 3, -1, -1, 5, -1, -1, 6, -1, -1};
    // vector<int> Nodes = {1, 2, 4, -1, -1, 5, -1, -1, 3, 6, -1, -1, -1};
    vector<int> Nodes = {1, 2, 4, -1, -1, 5, -1, -1, 3, -1, 6, -1, -1};
    // vector<int> Nodes = {1, 1, 1, -1, -1, 1, -1, -1, 5, -1, 1, -1, -1};   // Assinment Question

    //   static int idx = -1;  // Reset index
    Node *root = buildTree(Nodes);

    cout << "Binary tree built successfully" << endl;
    // cout << "Preorder traversal: ";
    // preorder(root);  // 1 2 4 5 3 6

    // levelOrder(root);  // 1 2 3 4 5 6
    // cout << endl;

    // cout<<"Height of the tree:"<<Height(root)<<endl;

    // cout<<"Count of nodes in the tree: "<<count(root)<<endl;

    // cout<<"Sum of all nodes in the tree: "<<sum(root)<<endl;

    // cout<< "Diameter of the tree: " << diam1(root) << endl;

    // cout<< "Diameter of the tree: " << diam2(root).first << endl;
    // cout<< "Height of the tree: " << diam2(root).second << endl;

    /* Node *SubRoot = new Node(2);
     SubRoot->left = new Node(4);
     SubRoot->right = new Node(5);

     cout << isSubtree(root, SubRoot) << endl;  // 1(true)*/

    // topView(root);  // 1 2 4 5 3 6

    // KthLevel(root, 3); // 4 5 6

    // int n1 = 4, n2 = 5; // 2
    // cout<<"lca :"<<LCA(root, n1, n2)<<endl;
    // int n1 = 4, n2 = 6;                                   // 1
    // cout << "lca2 :" << LCA2(root, n1, n2)->data << endl; // Node Pointer of the data

    // int n1 = 4, n2 = 5; // 2
    // cout << "MinDist n1 & n2 Nodes: " << minDist(root, n1, n2) << endl;

    // int node = 5 , k = 2;
    // KthAncestor(root, node, k);

    // transfrom(root);
    // levelOrder(root);

    // cout<< isUnivalTree(root)<<endl;

    // invertedTree(root);
    // levelOrder(root);

    removeLeafNode(root  , 6);
    levelOrder(root);

    return 0;
}
