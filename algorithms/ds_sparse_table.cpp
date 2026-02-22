#include <bits/stdc++.h>
using namespace std;

/*
    SPARSE TABLE ALGORITHM
*/

using ll = long long;

#define endl "\n"
#define sz(s) int(s.size())
#define fori(_, n) for(int i =_; i<n; i++)
#define all(s) s.begin(), s.end()
#define fastio() ios::sync_with_stdio(false); cin.tie(nullptr);

#define maxn 1000000
#define log2 25

int sparse[maxn][log2+1];
int a[maxn];


// se precalculan todos los valores de las "ventanas" o "bloques"
void calc(int n) {
    fori(0, n) sparse[i][0] = a[i]; 
    for(int j = 1; (1<<j)<= n; j++) {
        // depende del operador -> min, max, ^, |, +, -, etc
        for(ll i =0; i + (1<<j) - 1  <= n-1; i++) {
            // operador (en este caso max)
            sparse[i][j] = max(sparse[i][j-1], sparse[i + (1<<(j-1))][j-1]);
        }
    }
}

int query(int l, int r){
    int len = r-l+1;
    // posicion donde sale el primer uno (en binario) 000010101 ->  0000 1 0101
    int t = 32 - (__builtin_clz(len)) -1;
    int ans = INT_MIN;

    // en este caso se usa el operador MAX para guardar las respuestas. 
    for(int j = t; j >= 0; j--) {
        if((1<<j <= len)) {
            ans = max(ans, sparse[l][j]);
            len -= (1<<j);
            l += (1<<j);
        }
    }

    return ans;
}



void solve() {
    int n, q; cin>>n>>q;
    fori(0, n) cin>>a[i];

    calc(n);
    int l, r;
    while(q--) {
        cin>>l>>r;
        l--, r--; 
        cout<<query(l, r)<<endl;
    }

}

int main() {
    fastio();
    int t=1; //cin>>t;

    while (t--) solve();
    return 0;
}