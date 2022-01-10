#include<bits/stdc++.h>

using namespace std;

class Node{
  public:
  Node* left;
  Node* right;
  int val=0;
  Node(int v){
    val = v;
    left = nullptr;
    right = nullptr;
  }
};

int ret =0;

bool eval(Node* n){
  if(n==nullptr){
    return false;
  }
  Node* r = n->right;
  Node* l = n->left;
  // leaf is unival tree.
  if(l == nullptr && r == nullptr){
    ret++;
    return true;
  }
  else{
    bool l_bool = eval(l);
    bool r_bool = eval(r);

    //if left and right is unival and same value as this node then unival tree.
    if(l_bool && r_bool && l->val==r->val && l->val==n->val){ 
      ret++;
      return true;
    }
    else{
      return false;
    }
  }
}

int main(void){
  Node* node = new Node(0);
  node->left = new Node(1);
  node->right = new Node(0);
  node->right->left = new Node(1);
  node->right->left->right = new Node(1);
  node->right->left->left = new Node(1);
  node->right->right = new Node(0);

  eval(node);
  cout<<ret<<endl;
  return 0;
}
