#include <iostream>
#include <cstdio>
#include <algorithm>
#include <stdlib.h>
#include <vector>

using namespace std;

const int maxn = 110;

struct node {
  int weight;
  vector<int> child;
} Node[maxn];

bool cmp(int a, int b) {
  return Node[a].weight > Node[b].weight;
}

int n, m, s;
int path[maxn];

void DFS(int index, int numNode, int sum) {
  if(sum > s) return;
  if(sum == s) {
    if(Node[index].child.size() != 0) return;
    for(int i = 0; i < numNode; i++) {
      cout << Node[path[i]].weight;
      if(i < numNode - 1) cout << " ";
      else cout << endl;
    }
    return;
  }
  for(int i = 0; i < Node[index].child.size(); i++) {
    int child = Node[index].child[i];
    path[numNode] = child;
    DFS(child, numNode + 1, sum + Node[child].weight);
  }
}

int main() {
  cin >> n >> m >> s;
  for(int i = 0; i < n; i++) {
    cin >> Node[i].weight;
  }
  int id, k, child;
  for(int i = 0; i < m; i++) {
    cin >> id >> k;
    for(int i = 0; i < k; i++) {
      cin >> child;
      Node[id].child.push_back(child);
    }
    sort(Node[id].child.begin(), Node[id].child.end(), cmp);
  }
  path[0] = 0;
  DFS(0, 1, Node[0].weight);
  system("pause");
  return 0;
}