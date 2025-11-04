/*
 * ICPC Template
 * Author: Matías Del Castillo Mendoza
 * University: UPC
 * Language: C++17
 * ---------------------------------------------------------
 * Description:
 *  Base template for competitive programming
 * ---------------------------------------------------------
 */

#include <bits/stdc++.h>
using namespace std;

/*----------------------------------------------------------*/
/*                         MACROS                           */
/*----------------------------------------------------------*/
using ll = long long;
using pii = pair<int,int>;
using pll = pair<ll,ll>;
using vi = vector<int>;
using vll = vector<ll>;
using vii = vector<pii>;

#define forn(i, n) for (int i = 0; i < int(n); i++)
#define for1(i, n) for (int i = 1; i <= int(n); i++)
#define fore(i, a, b) for (int i = (a); i <= (b); i++)
#define rof(i, n) for (int i = int(n)-1; i >= 0; i--)
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define pb push_back
#define eb emplace_back
#define fi first
#define se second
#define mp make_pair
#define endl '\n'

const int INF = 1e9;
const ll LINF = 1e18;
const int MOD = 1e9+7;
const double EPS = 1e-9;

#ifdef LOCAL
    #define dbg(x) cerr << #x << " = " << (x) << endl
    #define dbgv(v) cerr << #v << " = ["; for (auto _ : v) cerr << _ << " "; cerr << "]" << endl;
    #define dbgp(v) cerr << #v << " = ["; for (auto [_f, _s] : v) cerr << "(" << _f << "," << _s << ") "; cerr << "]" << endl;
    #define fastio() 
    freopen("input.txt", "r", stdin); freopen("output.txt", "w", stdout);
#else
    #define dbg(x)
    #define dbgv(v)
    #define dbgp(v)
    #define fastio() ios::sync_with_stdio(false); cin.tie(nullptr);
#endif


ll gcdll(ll a, ll b) { return b ? gcdll(b, a % b) : a; }
ll lcmll(ll a, ll b) { return a / gcdll(a, b) * b; }

ll mod_pow(ll a, ll b, ll m = MOD) {
    ll res = 1;
    while (b) {
        if (b & 1) res = res * a % m;
        a = a * a % m;
        b >>= 1;
    }
    return res;
}

ll mod_inv(ll a, ll m = MOD) { return mod_pow(a, m - 2, m); }


void solve() {
    // solve here    


}

int main() {
    fastio();
    int t=1; // cin >> t;
    while (t--) solve();
    return 0;
}
