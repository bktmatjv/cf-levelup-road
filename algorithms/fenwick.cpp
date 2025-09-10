#include <bits/stdc++.h>

typedef long long ll;

#define MAXN 500000
using namespace std;

ll tree[MAXN + 1];

ll query(int i) {
    ll sum = 0;
    while (i > 0) {
        sum += tree[i];
        i -= (i & -i);
    }
    return sum;
}

void update(int i, int d) {
    while (i <= MAXN) {
        tree[i] += d;
        i += (i & -i);
    }   
}

int main() {
    int t, n, q, x, a, b;
    cin >> n >> q;
    for (int i = 0; i < n; ++i) {
        cin >> x;
        update(i + 1, x);
    }
    for (int i = 0; i < q; ++i) {
        cin >> t >> a >> b;
        if (t == 0) {
            a++;
            update(a, b);
        } else {
            a++, b++;
            cout << query(b - 1) - query(a - 1) << "\n";
        }
    }
}