#include <iostream>
#include <cstdio>

using namespace std;

const int maxn = 100010;

struct Node {
    char data;
    int next;
    bool flag;
};

int main() {
    int start1, start2, n;
    cin >> start1 >> start2 >> n;
    Node node[maxn];
    for(int i = 0; i < maxn; i++) {
        node[i].flag = false;
    }
    for(int i = 0; i < n; i++) {
        int adress, next;
        char data;
        cin >> adress >> data >> next;
        node[adress].data = data;
        node[adress].next = next;
    }
    int p;
    for(p = start1; p != -1; p = node[p].next) {
        node[p].flag = true;
    }
    int q;
    for(q = start2; q != -1; q = node[q].next) {
        if(node[q].flag == true) {
            break;
        }
    }
    if(q != -1) {
        printf("%05d", q);
    } else {
         cout << -1;
    }
    cout << endl;
    return 0;
}
