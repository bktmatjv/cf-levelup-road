#include <bits/stdc++.h>
#define ll long long
using namespace std;

ll n;

ll sd (ll num) {
    int sum = 0;
    while (num > 0) {
        sum += (num % 10);
        num /= 10;
    }
    return sum;
}

ll f(ll x, ll sx) {
    return x * x + sx * x;
}

int main() {
    cin >> n;
    ll res = 1000000000;
    for (int sx = 1; sx <= 81; ++sx) {
        // x^2 + sx * x = n
        ll lo = 1, hi = 1000000000, ans = -1;
        while (lo <= hi) {
            ll mi = lo + (hi - lo) / 2;
            if (f(mi, sx) == n) {
                ans = mi;
                break;
            }
            if (f(mi, sx) < n) lo = mi + 1;
            else hi = mi - 1;
        }
        if (ans != -1 && sd(ans) == sx) res = min(res, ans);
    }
    if (res == 1000000000) cout << "-1";
    else cout << res;
}