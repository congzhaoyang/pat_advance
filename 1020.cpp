#include <iostream>
#include <stdlib.h>
#include <cstdio>
#include <queue>

using namespace std;

const int maxn = 30;

struct Node {
  int data;
  Node * lchild;
  Node * rchild;
};

int pre[maxn], in[maxn], post[maxn];
int n;

Node* create(int postl, int postr, int inl, int inr) {
  if(postl > postr) return NULL;
  Node* root = new Node;
  root->data = post[postr];
  int k;
  for(k = inl; k <= inr; k++) {
    if(in[k] == post[postr]) break;
  }
  int numleft = k - inl;
  root->lchild = create(postl, postl + numleft - 1, inl, k - 1);
  root->rchild = create(postl + numleft, postr - 1, k + 1, inr);
  return root;
}

int num = 0;
void BFS(Node* root) {
  queue<Node*> q;
  q.push(root);
  while(!q.empty()){
    Node* now = q.front();
    q.pop();
    cout << now->data;
    num++;
    if(num < n) cout << " ";
    if(now->lchild != NULL) q.push(now->lchild);
    if(now->rchild != NULL) q.push(now->rchild);
  }
}

int main() {
  cin >> n;
  for(int i = 0; i < n; i++) {
    cin >> post[i];
  }
  for(int i = 0; i < n; i++) {
    cin >> in[i];
  }
  Node* root = create(0, n - 1, 0, n - 1);
  BFS(root);
  system("pause");
  return 0;
}