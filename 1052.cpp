#include <iostream>
#include <stdlib.h>
#include <algorithm>
#include <cstdio>

using namespace std;

const int maxn = 100010;

struct Node {
    int adress, data, next;
    bool flag;
} node[maxn];

bool cmp(Node a, Node b) {
    if(a.flag == false || b.flag == false) {
        return a.flag > b.flag;
    } else {
        return a.data < b.data;
    }
}

int main() {
    int n, start;
    cin >> n >> start;
    for(int i = 0; i < maxn; i++) {
        node[i].flag = false;
    }
    for(int i = 0; i < n; i++) {
        int adress, data, next;
        cin >> adress >> data >> next;
        node[adress].adress = adress;
        node[adress].data = data;
        node[adress].next = next;
    }
    int count = 0, p = start;
    while(p != -1){
        count++;
        node[p].flag = true;
        p = node[p].next;
    }
    if(count == 0) {
        cout << 0 << " " << -1;
    } else {
        sort(node, node + maxn, cmp);
        printf("%d %05d\n", count, node[0].adress);
        for(int i = 0; i < count; i++) {
            if(i != count - 1) {
                printf("%05d %d %05d\n", node[i].adress, node[i].data, node[i + 1].adress);
            } else {
                printf("%05d %d -1\n", node[i].adress, node[i].data);
            }
        }
    }
    system("pause");
    return 0;
}