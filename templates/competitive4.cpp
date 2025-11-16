#include <bits/stdc++.h>
using namespace std;

/*
         Æ          Æ Æ           
     ÆÆÆÆ            Æ ÆÆ         
    ÆÆ ÆÆ            ÆÆ ÆÆ        
   ÆÆ ÆÆ              ÆÆÆÆ        
   ÆÆÆÆÆ              ÆÆ ÆÆ       
  ÆÆÆÆÆÆÆÆÆÆÆÆÆÆÆÆÆÆÆÆÆÆÆÆÆÆ      
  ÆÆÆÆÆÆÆÆÆÆÆÆÆÆÆÆÆÆÆÆÆÆÆÆÆÆ      
   ÆÆÆ ÆÆÆÆÆÆÆÆÆÆÆÆÆÆÆ  ÆÆÆ       
     ÆÆÆÆÆÆÆÆÆÆÆÆÆÆÆÆÆÆÆÆ         
   ÆÆÆ   ÆÆ ÆÆÆÆÆÆ ÆÆ   ÆÆÆ       
 ÆÆÆ    ÆÆÆ ÆÆÆÆÆ  ÆÆ     ÆÆÆ     
 ÆÆ     ÆÆÆ  ÆÆÆÆ  ÆÆ     ÆÆÆ     
 ÆÆÆ     ÆÆ  ÆÆÆ   ÆÆ     ÆÆÆ     
 ÆÆÆ     ÆÆ        ÆÆ     ÆÆ      
  ÆÆ     ÆÆ        ÆÆ     ÆÆ      
   Æ     ÆÆ       ÆÆÆ    ÆÆ       
   ÆÆ     ÆÆ      ÆÆ     Æ        
    ÆÆ    ÆÆ      Æ     Æ         
           ÆÆ    ÆÆ               
            Æ    Æ                

    spiterman :v
    by yo :v (ascii art xd)
*/

using ll = long long;
using vll = vector<long long>; 
using vi = vector<int>;
using mii = map<int,int>;

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

/*
// for math
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
*/


void solve() {  


}


int main() {
    fastio();
    int t=1;  cin >> t;
    while (t--) solve();
    return 0;
}