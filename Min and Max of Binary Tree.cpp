#include <iostream>
#include <queue>

template <typename T>
class BinaryTreeNode {
    public : 
    T data;
    BinaryTreeNode<T> *left;
    BinaryTreeNode<T> *right;

    BinaryTreeNode(T data) {
        this -> data = data;
        left = NULL;
        right = NULL;
    }
};

class PairAns {
    public :
    int min;
    int max;
};

using namespace std;

#include<climits>

PairAns minMax(BinaryTreeNode<int> *root) {
    PairAns p;
    
    if(root==NULL){
        p.min=INT_MAX;
        p.max=INT_MIN;
        
        return p;
    }

    PairAns leftch=minMax(root->left); 
    PairAns rightch=minMax(root->right); 
    
    p.min=min(root->data,min(leftch.min,rightch.min));
    p.max=max(root->data,max(leftch.max,rightch.max));
    
    return p;

}


BinaryTreeNode<int>* takeInput() {
    int rootData;
    cin >> rootData;
    if(rootData == -1) {
        return NULL;
    }
    BinaryTreeNode<int> *root = new BinaryTreeNode<int>(rootData);
    queue<BinaryTreeNode<int>*> q;
    q.push(root);
    while(!q.empty()) {
        BinaryTreeNode<int> *currentNode = q.front();
	q.pop();
        int leftChild, rightChild;
        //cout << "Enter left child of " << currentNode -> data << " : ";
        cin >> leftChild;
        if(leftChild != -1) {
            BinaryTreeNode<int>* leftNode = new BinaryTreeNode<int>(leftChild);
            currentNode -> left =leftNode;
            q.push(leftNode);
        }
        //cout << "Enter right child of " << currentNode -> data << " : ";
        cin >> rightChild;
        if(rightChild != -1) {
            BinaryTreeNode<int>* rightNode = new BinaryTreeNode<int>(rightChild);
            currentNode -> right =rightNode;
            q.push(rightNode);
        }
    }
    return root;
}

int main() {
    BinaryTreeNode<int>* root = takeInput();
    PairAns ans = minMax(root);
    cout << ans.max << " " << ans.min << endl;
}
