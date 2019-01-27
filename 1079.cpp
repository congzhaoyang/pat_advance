// N: 节点
// P: 根节点给出的单价， r每一级的加价 

#include <iostream>
#include <cstdio>
#include <stdlib.h>
#include <vector>
#include <cmath>

using namespace std;

const int maxn = 10010;

struct Node {
  double data;
  vector<int> child;
} node[maxn];

int n;
double p, r, ans = 0;
void DFS(int index, int depth) {
  if(node[index].child.size() == 0) {
    ans += node[index].data * pow(1 + r, depth);
    return;
  }
  for(int i = 0; i < node[index].child.size(); i++) {
    DFS(node[index].child[i], depth + 1);
  }
}

int main() {
  int k, child;
  cin >> n >> p >> r;
  r /= 100;
  for(int i = 0; i < n; i++) {
    cin >> k;
    if(k == 0) cin >> node[i].data;
    else {
      for(int j = 0; j < k; j++) {
        cin >> child;
        node[i].child.push_back(child);
      }
    }
  }
  DFS(0, 0);
  printf("%.1f\n", p * ans);
  system("pause");
  return 0;
}