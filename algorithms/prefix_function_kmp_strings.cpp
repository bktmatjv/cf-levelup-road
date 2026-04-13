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


// construccion de la prefix_function
vll prefix(string s) {
    int n = sz(s);
    vll fail(n, 0);
    int j = 0;
    fori(1, n) {
        while(j > 0 && s[i] != s[j]) j = fail[j-1];
        if(s[i] == s[j]) j++;
        fail[i] = j;
    }

    return fail;
}

void solve() {
    string s; cin>>s;
    int n = sz(s);
    vll p = prefix(s);

    int x = p[n-1];

    vector<pair<int,int>> xd; 
    xd.pb({n, 1}); 


    // prefix_function -> numero de ocurrencias de cada substring del failure

    vll ans(n+1, 0);

    fori(0, n) ans[p[i]]++;
    for(int i = n-1; i>= 0; i--) ans[p[i-1]] += ans[i];
    fori(0, n+1) ans[i]++;


    // literalmente es pre computo

    while(x > 0) {
        int f = ans[x];
        xd.pb({x, f});
        x = p[x-1];
    }


    sort(all(xd));
    cout<<sz(xd)<<endl;
    for(auto e : xd) {
        cout<<e.fi<<" "<<e.se<<endl;
    }


}

int main() {
    fastio();
    solve();
    return 0;
}