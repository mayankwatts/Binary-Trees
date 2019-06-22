#include<iostream>
#include<queue>
using namespace std;


template<typename T>
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

void printSpecificPattern(BinaryTreeNode<int> * root)
{
     /* Write your code here
      * Print the required pattern
      * Taking input is handled automatically
      */
    queue<BinaryTreeNode<int>*> q;
    vector<int> v;
    
    cout<<root->data<<" ";
    q.push(root->left);
    q.push(root->right);
    
    
    
    while(q.size()!=0){
        
        int size=q.size();
        int mid=q.size()/2;
        
        for(int i=0;i<size;i++){
            BinaryTreeNode<int> *front=q.front();
            q.pop();
            
            if(front->left!=NULL)
                q.push(front->left);
            
            if(front->right!=NULL)
                q.push(front->right);
            
            v.push_back(front->data);
        }
         
        for(int i=0;i<mid;i++){
            cout<<v[i]<<" ";
            cout<<v[size-i-1]<<" ";
        }
        
        for(int i=0;i<size;i++){
            v.pop_back();
        }
    }
    
}


BinaryTreeNode<int> * takeinputlevelwise()
     {

    queue<BinaryTreeNode<int>*> pendingnodes;
    int rootdata;
    cin>>rootdata;
    if(rootdata == -1)
        return NULL;

    BinaryTreeNode<int> * root = new BinaryTreeNode<int>(rootdata);

    pendingnodes.push(root);


    while(!pendingnodes.empty())
    {

        BinaryTreeNode<int> * frontnode = pendingnodes.front();
        BinaryTreeNode<int> * currentnode = frontnode;
        pendingnodes.pop();

        int lchild;
        cin>>lchild;

        if(lchild!=-1)
        {
            BinaryTreeNode<int> * leftchild = new BinaryTreeNode<int>(lchild);
            pendingnodes.push(leftchild);
            currentnode->left = leftchild;

        }

        int rchild;
        cin>>rchild;

        if(rchild!=-1)
        {
            BinaryTreeNode<int> * rightchild = new BinaryTreeNode<int>(rchild);
            pendingnodes.push(rightchild);
            currentnode->right = rightchild;
        }


    }
    return root;
}

int main()
{
    BinaryTreeNode<int> * root = NULL;
    root = takeinputlevelwise();
    printSpecificPattern(root);
    
    return 0;
}
