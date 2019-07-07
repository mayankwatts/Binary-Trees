#include <bits/stdc++.h>
using namespace std;
/* A binary tree node has data, pointer to left child
   and a pointer to right child */
struct Node
{
    int data;
    struct Node* left;
    struct Node* right;
    
    Node(int x){
        data = x;
        left = right = NULL;
    }
};

void leftView(Node *root){
   queue<Node*> q;
   int count=1;
   q.push(root);
   while(!q.empty()){
       Node* front=q.front();
       cout<<front->data<<" ";
       int a=0;
       int b=0;
       while(count>0){
           Node* front=q.front();
           q.pop();
           if(front->left!=NULL){
              q.push(front->left);
              a+=1;
           }
           if(front->right!=NULL){
               q.push(front->right);
               b+=1;
           }
           
           count--;
       }
       
       count=a+b;
   }
}

int main()
{
  int t;
  struct Node *child;
  scanf("%d", &t);
  while (t--)
  {
     map<int, Node*> m;
     int n;
     scanf("%d",&n);
     struct Node *root = NULL;
     while (n--)
     {
        Node *parent;
        char lr;
        int n1, n2;
        scanf("%d %d %c", &n1, &n2, &lr);
        if (m.find(n1) == m.end())
        {
           parent = new Node(n1);
           m[n1] = parent;
           if (root == NULL)
             root = parent;
        }
        else
           parent = m[n1];
        child = new Node(n2);
        if (lr == 'L')
          parent->left = child;
        else
          parent->right = child;
        m[n2]  = child;
     }
     leftView(root);
     cout << endl;
  }
  return 0;
}
