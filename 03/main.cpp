#include <iostream>
#include<sstream>
#include <vector>
#include <algorithm>
#include <map>
#include <tuple>
#include <queue>

using namespace std;
queue<string> arr;
int max_idx = 0;

class Node{
public:
  Node *left;
  Node *right;
  string val;

  Node(string v){
    left = nullptr;
    right = nullptr;
	  val = v;
  }
};

string serialize(Node *n){
  if(n!= nullptr)
  return n->val +" " +serialize(n->left) +" " +serialize(n->right);
  else
  return "#";
}

Node* deserialize(){
  string val = arr.front();
  arr.pop();
  if(val == "#"){
    return nullptr;
  }
  else{
    Node *ret = new Node(val);
    ret->left = deserialize();
    ret->right = deserialize();
    return ret;
  }
}

int main(void){
  Node *root = new Node("root");
  root->left = new Node("left");
  root->right = new Node("right");
  root->left->left = new Node("left.left");
  string serialized_str = serialize(root);
  cout<<serialized_str<<endl;

  istringstream ss(serialized_str);
  string del;

  
  while(getline(ss, del, ' ')){
    arr.push(del);
  }
  max_idx = arr.size();
  Node *dec = deserialize();
  cout<<serialize(dec)<<endl;
  return 0;
}
