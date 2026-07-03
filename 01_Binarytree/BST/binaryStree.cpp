#include<iostream>
#include<vector>
using namespace std;
class Node{
    public:
    int data;
    Node* left;
    Node* right;

    Node(int val){
        this->data=val;
        this->left=NULL;
        this->right=NULL;
    }
};
Node* insertIntoBST(Node* root,int val){
    //base case
    if(root==NULL){
        root=new Node(val);
        return root;
    }
    if(val>root->data){
        //insert in right part
        root->right=insertIntoBST(root->right,val);

    }
    else{
        //insert in left part
        root->left=insertIntoBST(root->left,val);
    }
    return root;
}
Node* buildBST(  int arr[], int n){
    Node* root=NULL;
    for(int i=0;i<n;i++){
        root=insertIntoBST(root,arr[i]);
    }
    return root;
}
void inorder(Node* root){
    //base case
    if(root==NULL){
        return;
    }
    inorder(root->left);
    cout<<root->data<<" ";
    inorder(root->right);
}

Node* searchenv(Node* root , int key){
    //base case
    if(root==NULL){
        return NULL;
    }
    if(root->data==key){
        return root;
    }
    if(root->data>key){
        return searchenv(root->left,key);
    }
    else{
        return searchenv(root->right,key);
    }
}

Node*deleteInBST(Node* root,int key){
    //base case
    if(root==NULL){
        return NULL;
    }
    if(root->data>key){
        root->left = deleteInBST(root->left,key);
    }
    else if(root->data<key){
        root->right = deleteInBST(root->right,key);
    }
    else{
        //key found
        //0 child
        if(root->left==NULL && root->right==NULL){
            delete root;
            return NULL;
        }
        //1 child
        //left child
        if(root->left!=NULL && root->right==NULL){
            Node* temp=root->left;
            delete root;
            return temp;
        }
        //right child
        if(root->left==NULL && root->right!=NULL){
            Node* temp=root->right;
            delete root;
            return temp;
        }
        //2 child
        if(root->left!=NULL && root->right!=NULL){
            //find inorder successor
            Node* temp=root->right;
            while (temp->left!=NULL)
            {
                temp=temp->left;
            }
            root->data=temp->data;
            root->right=deleteInBST(root->right,temp->data);
            return root;

        }
    }
    return root;
}
//    //OR deletion in BST
// Node*deleteInBST(Node* root,int key){
//     //base case
//     if(root==NULL){
//         return NULL;
//     }
//     if(root->data==key){
//         //0 child
//         if(root->left==NULL && root->right==NULL){
//             delete root;
//             return NULL;
//         }
//         //1 child
//         //left child
//         if(root->left!=NULL && root->right==NULL){
//             Node* temp=root->left;
//             delete root;
//             return temp;
//         }
//         //right child
//         if(root->left==NULL && root->right!=NULL){
//             Node* temp=root->right;
//             delete root;
//             return temp;
//         }
//         //2 child
//         if(root->left!=NULL && root->right!=NULL){
//             //find inorder successor
//             Node* temp=root->right;
//             while (temp->left!=NULL)
//             {
//                 temp=temp->left;
//             }
//             root->data=temp->data;
//             root->right=deleteInBST(root->right,temp->data);
//             return root;

//         }

//     }
//     else if(root->data>key){
//         root->left=deleteInBST(root->left,key);
//         return root;
//     }
//     else{
//         root->right=deleteInBST(root->right,key);
//         return root;
//     }
// }



void printInRange(Node* root,int start,int end){
    //base case
    if(root==NULL){
        return;
    }
    //left part
    if(root->data>=start && root->data<=end){
        cout<<root->data<<" ";
        printInRange(root->left,start,end);
        printInRange(root->right,start,end);
    }
    else if(root->data<start){
        printInRange(root->right,start,end);
    }
    else{
        printInRange(root->left,start,end);
    }
}
void printPath(vector<int> path){
    cout<<"path :";
    for(int i=0;i<path.size();i++){
        cout<<path[i]<<" ";
    }
    cout<<endl;
}

void pathHelper(Node* root,vector<int> &path){
    //base case
    if(root==NULL){
        return;
    }
    path.push_back(root->data);
    //leaf node
    if(root->left==NULL && root->right==NULL){
        //print the path
        printPath(path);
        path.pop_back();
        return;
    }
    //recursive call

    pathHelper(root->left,path);
    pathHelper(root->right,path);
    
    path.pop_back();
}
void rootPath(Node* root){
    vector<int> path;
    pathHelper(root,path);
}


bool validateHelper(Node* root, Node* minNode, Node* maxNode){
    //base case
    if(root==NULL){
        return true;
    }
    if(minNode!=NULL && root->data<=minNode->data){
        return false;
    }
    if(maxNode!=NULL && root->data>=maxNode->data){
        return false;
    }
    bool leftValid=validateHelper(root->left,minNode,root);
    bool rightValid=validateHelper(root->right,root,maxNode);
    return leftValid && rightValid;
}
bool validateBST(Node* root){
    return validateHelper(root,NULL,NULL);
}
int main(){
    // int arr[]={5,1,3,4,2,7};

    int arr[]={8,5,3,1,4,6,10,11,14};
    int n= sizeof(arr)/sizeof(arr[0]);
    Node* root=buildBST(arr,n);
    // inorder(root);
    int key;
    cin>>key;
    // if(searchenv(root,key)==NULL){
    //     cout<<"key does not exist"<<endl;
    // }
    // else{
    //     cout<<"key exist"<<endl;
    // }

    // root=deleteInBST(root,key);
    // inorder(root);

    // int start = 5,end =12;
    // cin>>start>>end;
    // printInRange(root,5,12);

    // rootPath(root);

    if(validateBST(root)){
        cout<<"valid BST"<<endl;
    }
    else{
        cout<<"not a valid BST"<<endl;
    }
    

    return 0;
}