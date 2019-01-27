#include <iostream>
#include <cstdio>
#include <stdlib.h>
#include <algorithm>

using namespace std;

struct Node {
  int v, height;
  Node *lchild, *rchild;
} *root;

Node* newNode(int v) {
  Node* node = new Node;
  node->v = v;
  node->height = 1;
  node->lchild = node->rchild = NULL;
  return node;
}

int getHeight(Node* root) {
  if(root == NULL) return 0;
  return root->height;
}

void updateHeight(Node* root) {
  root->height = max(getHeight(root->lchild), getHeight(root->rchild)) + 1;
}

int getBalanceFactor(Node* root) {
  return getHeight(root->lchild) - getHeight(root->rchild);
}

void L(Node* &root) {
  Node* temp = root->rchild;
  root->rchild = temp->lchild;
  temp->lchild = root;
  updateHeight(root);
  updateHeight(temp);
  root = temp;
}

void R(Node* &root) { 
  Node* temp = root->lchild;
  root->lchild = temp->rchild;
  temp->lchild = root;
  updateHeight(root);
  updateHeight(temp);
  root = temp;
}

void insert(Node* &root, int v) {
  if(root == NULL) {
    root = newNode(v);
    return;
  }
  if(v < root->v) {
    insert(root->lchild, v);
    updateHeight(root);
    if(getBalanceFactor(root) == 2) {
      if(getBalanceFactor(root->lchild) == 1) {
        R(root);
      } else {
        L(root->lchild);
        R(root);
      }
    }
  } else {
    insert(root->rchild, v);
    updateHeight(root);
    if(getBalanceFactor(root) == -2) {
      if(getBalanceFactor(root->rchild) == -1) {
        L(root);
      } else if(getBalanceFactor(root->rchild) == 1) {
        R(root->rchild);
        L(root);
      }
    }
  }
}

Node* Create(int data[], int n) {
  Node* root = NULL;
  for(int i = 0; i < n; i++) {
    insert(root, data[i]);
  }
  return root;
}


int main() {
  int n, v;
  cin >> n;
  for(int i = 0; i < n; i++) {
    cin >> v;
    insert(root, v);
  }
  cout << root->v << endl;
  system("pause");
  return 0;
}