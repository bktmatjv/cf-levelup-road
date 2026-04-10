#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using vll = vector<long long>; 
using vi = vector<int>;
using mii = map<int,int>;
using pll = pair<long long, long long>; // pair de long long 's

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

// bases con numeros primos
const ll base = 131; 
const ll base2 = 137;
const ll mod = 1e9 + 7;
const ll mod2 = 1e9 + 9;

// struct para el unordered_set (+ eficiencia que un set normal x consultas O(1))
struct hash_pair {
    size_t operator()(const pll& p) const {
        return hash<ll>()(p.first) ^ (hash<ll>()(p.second) << 1);
    }
};

// vectores potencias (en este caso hash doble pero con el mismo concepto) y vector para el hashing
vll pot(1502), pot2(1502), h(1502), h2(1502); 

// construccion de hash (en este caso es doble hash, pero el concepto es el mismo)
// h[k] = (h[k-1] * base + letra) % mod
void build(const string &s){
    int n = sz(s);
    pot[0] = 1;
    pot2[0] = 1;
    fori(1, n+1){
        pot[i] = (pot[i-1] * base) % mod;
        pot2[i] = (pot2[i-1] * base2) % mod2;
    }
    h[0] = s[0] - 'a' + 1;
    h2[0] = s[0] - 'a' + 1;
    fori(1, n){
        h[i] = (h[i-1] * base + (s[i]-'a'+1)) % mod;
        h2[i] = (h2[i-1] * base2 + (s[i]-'a'+1)) % mod2;
    }
}

// obtener hash (l a r)
// proceso de normalizacion
// x = h[r] -> si es 0
// x = (h[r] - h[l-1]*pot[r-l+1] % mod + mod) % mod
// -> + mod) % mod -> por si sale negativo
pll getHash(int l,int r){
    ll x1 = h[r];
    if(l>0) x1 = (x1 - h[l-1]*pot[r-l+1]%mod + mod)%mod;
    ll x2 = h2[r];
    if(l>0) x2 = (x2 - h2[l-1]*pot2[r-l+1]%mod2 + mod2)%mod2;
    return {x1,x2};
}

void solve() {
    string s, abc; cin>>s>>abc;
    build(s);
    int k; cin>>k;
    int n = sz(s);

    unordered_set<pll, hash_pair> cont;

    int l = 0, c = 0;

    // caso problema -> Good Substrings
    fori(0, n) {
        c = 0;
        forj(i, n){
            c += (abc[s[j] - 'a'] == '0');
            if(c > k) break;
            cont.insert(getHash(i, j));
        }
    }

    cout<<sz(cont)<<endl;
}

int main() {
    fastio();
    solve();
    return 0;
}