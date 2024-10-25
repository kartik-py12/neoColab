#include<bits/stdc++.h>
using namespace std;

struct Node{
    Node* left;
    Node* right;
    int data;
    Node(int value):data(value),left(nullptr),right(nullptr) {}
};


Node* insertLevelOrder(Node* root,int data){
    if(root==nullptr){
        return new Node(data);
    }
    queue<Node*>q;
    q.push(root);

    while(!q.empty()){
        Node* temp=q.front();
        q.pop();

        if(temp->left==nullptr){
            temp->left=new Node(data);
            break;
        }else{
            q.push(temp->left);
        }
        if(temp->right==nullptr){
            temp->right=new Node(data);
            break;
        }else{
            q.push(temp->right);
        }
    }

    return root;
}


void preorder(Node* root){
    if(root==nullptr){
        return;
    }

    cout<<root->data<<" ";

    preorder(root->left);
    preorder(root->right);

};

void inorder(Node* root){
    if(root==nullptr){
        return;
    }
    inorder(root->left);
    cout<<root->data<<" ";
    inorder(root->right);
}

void postorder(Node* root){
    if(root==nullptr){
        return;
    }
    postorder(root->left);
    postorder(root->right);
    cout<<root->data<<" ";
}

int main(){
    int n;
    cin>>n;
    Node *root=nullptr;
    for(int i=0;i<n;i++){
        int ele;
        cin>>ele;
        root=insertLevelOrder(root,ele);
    }
    cout<<"PreOrder traversal is: ";
    preorder(root);
    cout<<endl;

    cout<<"InOrder traversal is: ";
    inorder(root);
    cout<<endl;

    cout<<"PostOrder traversal is: ";
    postorder(root);
    cout<<endl;
}