#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using vll = vector<long long>; 
using vi = vector<int>;
using mii = map<int,int>;
using pll = pair<long long, long long>;

#define endl "\n"
#define sz(s) int(s.size())
#define fori(_, n) for(int i =_; i<n; i++)
#define forj(_, n) for(int j =_; j<n; j++)
#define all(s) s.begin(), s.end()
#define rall(s) s.rbegin(), s.rend()
#define pb push_back
#define fi first
#define se second
#define eb emplace_back

#define dbg(x) cerr << #x << " = " << (x) << endl
#define dbgv(v) cerr << #v << " = ["; for (auto _ : v) cerr << _ << " "; cerr << "]" << endl;
#define dbgvp(v) cerr << #v << " = ["; for (auto [_f, _s] : v) cerr << "(" << _f << ", " << _s << ") "; cerr << "]" << endl;
#define fastio() ios::sync_with_stdio(false); cin.tie(nullptr);

// zobrist HASHING (XOR + RANDOM NUMBERS)

#define maxn 50001
const ll base = 131;
const ll base2 = 137;
const ll mod = 1e9 + 7;
const ll mod2 = 1e9 + 9;

/*
ejemplo test case: 
5
1 2 3 4 5 -> arreglo 1
1 2 2 4 3 -> arreglo 2
7
1 1
2 2
2 3
3 3
4 4
4 5
5 5
*/

// declaracion de map de randoms -> aca se guardan los randoms de cada numero del arreglo
// se usa esta forma de random porque guara con 64 bits lo que hace menos probable que colisionen los numeros
unordered_map<ll,ll> hass;
mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count()); // random 64 bits

ll random(ll x) {
    if (!hass.count(x)) {
        hass[x] = rng();
    }
    return hass[x];
}

// en este apartado se construye el hashing de la siguiente forma: 
// h[i] = (h[i-1]) ^ random(a[i]) <- el random de la key del map que guarda los aleatorios por valor 

pair<vll,vll> build(vll& a) {
    int n = sz(a);
    vll h(n), h2(n);

    h[0] = random(a[0]);
    h2[0] = random(a[0]);

    set<ll> setsito; 

    setsito.insert(a[0]);

    // hashing 
    fori(1, n) {
        if(!setsito.count(a[i])) {
            h[i] = ((h[i-1])^ random(a[i]));
            h2[i] = ((h2[i-1])^ random(a[i]));
            setsito.insert(a[i]);
        }
        else {
            h[i] = h[i-1];
            h2[i] = h2[i-1];
        }
    }

    return {h, h2};
}


void solve() {
    // srand(time(0));
    int n; cin>>n;
    vll a(n), b(n);
    fori(0, n) cin>>a[i];
    fori(0, n) cin>>b[i];
    pair<vll, vll> f1 = build(a), f2 = build(b);


    // entrada de datos y resolución del problema -> prefix equality atcoder
    int q; cin>>q;
    while(q--) {
        int x,y; cin>>x>>y;
        cout<<((f1.fi[x-1] == f2.fi[y-1] && f1.se[x-1] == f2.se[y-1])? "Yes" :"No")<<endl;
    }
}

int main() {
    fastio();
    solve();
    return 0;
}