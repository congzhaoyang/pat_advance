#include <iostream>
#include <cstdio>
#include <stdlib.h>
#include <algorithm>

using namespace std;

const int N = 1010;

int father[N];
int isRoot[N] = {0};
int course[N] = {0};

int findFather(int x) {
  int a = x;
  while(x != father[x]) {
    x = father[x];
  }
  while(a != father[a]) {
    int z = a;
    a = father[a];
    father[z] = x;
  }
  return x;
}

void Union(int a, int b) {
  int faA = findFather(a);
  int faB = findFather(b);
  if(faA != faB) {
    father[faA] = faB;
  }
}

void init(int n) {
  for(int i = 1; i <= n; i++) {
    father[i] = i;
    isRoot[i] = false;
  }
}

bool cmp(int a, int b) {
  return a > b;
}

int main() {
  int n, k, h;
  cin >> n;
  init(n);
  for(int i = 0; i < n; i++) {
    cin >> k;
    for(int j = 0; j < k; j++) {
      cin >> h;
      if(course[h] == 0) {
        course[h] = i;
      }
      Union(i, findFather(course[h]));
    }
  }
  for(int i = 1; i <= n; i++) {
    isRoot[findFather(i)]++;
  }
  int ans = 0;
  for(int i = 1; i <= n; i++) {
    if(isRoot[i] != 0) {
      ans++;
    }
  }
  cout << ans << endl;
  sort(isRoot + 1, isRoot + n + 1, cmp);
  for(int i = 0; i <= ans; i++) {
    cout << isRoot[i];
    if(i < ans) cout << " ";
  }
  system("pause");
  return 0;
}