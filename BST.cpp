#include<iostream>
using namespace std;
template<typename T>
T maxim(T a,T b){
    return (a >= b)? a:b; 
}

class bst{
 class Node{
     public:
     int  value;
     Node* left;
     Node* right;
     Node():value(0),left(nullptr), right(nullptr){}
     Node(int val):value(val),left(nullptr), right(nullptr){}
 };
         Node* root;
    void insertp(Node* treeNode,int data){
       if (!treeNode)
        {
                treeNode = new Node(data);           
                root = treeNode;           
        }
        else
        {
                if (data < treeNode->value)
                {
                        if (!treeNode->left)
                        {
                                Node *treeTemp = new Node(data);
                                treeNode->left = treeTemp;
                        }
                        else
                                insertp(treeNode->left, data);
                }
                else
                {
                        if (!treeNode->right)
                        {
                                Node *treeTemp = new Node(data);                         
                                treeNode->right = treeTemp;
                        }
                        else
                                insertp(treeNode->right, data);
                }
        }
    }
    bool balance(Node* rot){
            if((height(rot->right)-height(rot->left) == 1)||(height(rot->right)-height(rot->left) == -1)) return true;
            else return false;
    }
    int height(Node* temp){
        if(!temp)return 0;
        return 1 +maxim(height(temp->left),height(temp->right));
    }
    void delete_tree(Node* temp){
        
        if(!temp)
        {
            return;
        }
        delete_tree(temp->left);
        delete_tree(temp->right);
        delete temp;
        temp = nullptr;
    }
    void inorder(Node* temp){
        if(!temp) return;
        inorder(temp->left);
        cout<<temp->value<<endl;
        inorder(temp->right);
    }
        
    void preorder(Node* temp) {
        if(!temp) return;
        cout<<temp->value<<endl; 
        preorder(temp->left);
        preorder(temp->right);
    } 
    void postorder(Node* temp){
                if(!temp) return;
                postorder(temp->left);
                postorder(temp->right);
                cout<<temp->value<<endl; 
            }











public:



    bst():root(nullptr){}
    void insert(int curv){
        insertp(root, curv);
    }
    bool isbalanced(){
        balance(root);
    }  
    int getheight(){
        return height(root);
    }
    void del_tree()
    {
        delete_tree(root);
        root = nullptr;
    }
    bool isempty(){
        if(!root) return true;
        else return false;
    }
    void Inord(){
        inorder(root);
    }
    void Preord(){
        preorder(root);
    }
    void postord(){
        postorder(root);
    }
};

int main(){
    bst mytree;
    mytree.insert(15);
    mytree.insert(8);
    mytree.insert(12);
    mytree.insert(1);
    mytree.insert(5); 
    mytree.insert(21);   
    mytree.insert(18);   
    mytree.insert(31);   
  
    int b = mytree.getheight();
    bool bl =  mytree.isbalanced();
    bool frst =  mytree.isempty();
    int b1 = mytree.getheight();
    bool sec =  mytree.isempty();
    mytree.Inord();
    cout<<endl<<"########################### pre"<<endl;
    mytree.Preord();
    cout<<endl<<"########################### post"<<endl;
    mytree.postord();
    cout<<endl<<"########################### post after delete"<<endl;
    mytree.del_tree();
    mytree.postord();

    return 0;
}