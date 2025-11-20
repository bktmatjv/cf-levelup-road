#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using vll = vector<long long>; 
using vi = vector<int>;
using mii = map<int,int>;

#define endl "\n"
#define sz(s) int(s.size())
#define fori(_, n) for(int i =_; i<n; i++)
#define forj(_, n) for(int j =_; j<n; j++)
#define fastio() ios::sync_with_stdio(false); cin.tie(nullptr);

#define inf 1e9

void floyd() { 
    int n,m; cin>>n>>m;
    vector<vector<int>> adj(n, vector<int>(n));

    // se realiza un dp iterativo dentro de la matriz de adyacencia para encontrar el camino minimo
    // NOTA: NO DEBEN HABER CICLOS NEGATIVOS 
    fori(0, n) {
        forj(0, n) {
            if(i == j) {
                adj[i][i] = 0;
                continue;
            }
            adj[i][j] = inf;
        }
    }

    fori(0, m) {
        int u, v, c; cin>>u>>v>>c;
        // dependiendo de si es dirigido o no dirigido 
        adj[u][v] =  c;
        // adj[v][u] = c;
    }

    for(int k = 0; k<n; k++) {
        fori(0,n) {
            forj(0, n) {
                adj[i][j] = min(adj[i][j], adj[i][k] + adj[k][j]);
            }
        }
    }

    //impresion de matriz de adyacencia
    for(auto e : adj) {
        for(auto f : e ) {

            cout<<f<<" ";
        }
        cout<<endl;
    }
}

int main() {
    fastio();
    floyd();
    return 0;
}