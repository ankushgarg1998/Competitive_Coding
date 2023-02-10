#include <iostream>
using namespace std;
#include "BinaryTreeNode.h"

int count(BinaryTreeNode* root){
  if(root == NULL)
    return 0;
  int x = count(root->left);
  int y = count(root->right);
  if((root->data)>x)
    return 1+x+y;
  else
    return x+y;
}

int sum(BinaryTreeNode* root){
  if(root == NULL)
    return 0;

  return root->data + sum(root->left) + sum(root->right);
}

int main(){

}
