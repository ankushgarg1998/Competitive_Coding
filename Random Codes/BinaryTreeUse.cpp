#include <iostream>
using namespace std;
#include "BinaryTreeNode.h"

int count(BinaryTreeNode* root){
  if(root = NULL){
    return 0;
  }
  int x = count(root->left);
  int y = count(root->right);
  return 1+x+y;

}

int main(){

}
