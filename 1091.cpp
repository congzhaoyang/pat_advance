#include <iostream>
#include <stdlib.h>
#include <cstdio>
#include <queue>

using namespace std;

struct Node {
  int x, y, z;
} node;

int n, m, slice, t;

int pixel[1290][130][61];
bool inq[1290][130][61] = {false};

int X[6] = {1, -1, 0, 0, 0, 0};
int Y[6] = {0, 0, 1, -1, 0, 0};
int Z[6] = {0, 0, 0, 0, 1, -1};

bool judge(int x, int y, int z) {
  if(x >= n || x < 0 || y >= m || y < 0 || z >= slice || z < 0) return false;
  if(pixel[x][y][z] == 0 || inq[x][y][z] == true) return false;
  else return true;
}

int BFS(int x, int y, int z) {
  int total = 0;
  queue<Node> q;
  node.x = x, node.y = y, node.z = z;
  q.push(node);
  inq[x][y][z] = true;
  while(!q.empty()){
    Node top = q.front();
    q.pop();
    total++;
    for(int i = 0; i < 6; i++) {
      int newx = top.x + X[i];
      int newy = top.y + Y[i];
      int newz = top.z + Z[i];
      if(judge(newx, newy, newz)) {
        node.x = newx, node.y = newy, node.z = newz;
        q.push(node);
        inq[newx][newy][newz] = true;
      }
    }
  }
  if(total >= t) return total;
  else return 0;
}

int main() {
  cin >> n >> m >> slice >> t;
  for(int z = 0; z < slice; z++) {
    for(int x = 0; x < n; x++) {
      for(int y = 0; y < m; y++) {
        cin >> pixel[x][y][z];
      }
    }
  }
  int ans = 0;
  for(int z = 0; z < slice; z++) {
    for(int x = 0; x < n; x++) {
      for(int y = 0; y < m; y++) {
        if(pixel[x][y][z] == 1 && inq[x][y][z] == false) {
          ans += BFS(x, y, z);
        }
      }
    }
  }
  cout << ans << endl;
  system("pause");
  return 0;
}