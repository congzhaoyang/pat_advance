#include <iostream>
#include <algorithm>
#include <cstdio>
#include <vector>
#include <cmath>
#include <stdlib.h>

using namespace std;

int n, k, p;
vector<int> fac, ans, temp;
int maxfacsum = -1;

int power(int x) {
  int ans = 1;
  for(int i = 0; i < p; i++) ans *= x;
  return ans;
}

void init(int n, int k, int p) {
  int i = 0, temp = 0;
  while(temp <= n){
    fac.push_back(temp);
    temp = power(++i);
  }
}

void DFS(int index, int nowk, int sum, int facsum) {
  if(nowk == k && sum == n) {
    if(facsum > maxfacsum) {
      ans = temp;
      maxfacsum = facsum;
    }
    return;
  }
  if(sum > n || nowk > k) return;
  if(index - 1 >= 0) {
    temp.push_back(index);
    DFS(index, nowk + 1, sum + fac[index], facsum + index);
    temp.pop_back();
    DFS(index - 1, nowk, sum, facsum);
  }
}

int main() {
  cin >> n >> k >> p;
  init(n, k, p);
  // for(int i = 0; i < fac.size(); i++) cout << fac[i] << endl;
  DFS(fac.size() - 1, 0, 0, 0);
  if(maxfacsum == -1) cout << "Impossible" << endl;
  else {
    cout << n << " = ";
    for(int i = 0; i < ans.size(); i++) {
      cout << ans[i] << "^" << p;
      if(i != ans.size() - 1) {
        cout << " + ";
      }
    }
  }
  system("pause");
  return 0;
}