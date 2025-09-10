#include<bits/stdc++.h>
#define ll long long
using namespace std;

// with Divide and Conquer technique

ll fast_pow_MOD(int a, int b, int c) {
    if (b == 0) return 1 % c;
    ll x = fast_pow(a, b/2, c);
    x = (x * x) % c;
    if (b % 2 == 1) x = (x * (a % c)) % c;    
    return x;
}

ll fast_pow(int a, int b) {
    if (b == 0) return 1;
    ll x = fast_pow(a, b/2);
    x = (x * x) % c;
    if (b % 2 == 1) x = x * a;    
    return x;
}


int main() {
    int b, p, n; 
    while (cin>>b){
         cin >> p >> n;
         cout << fast_pow(b,p,n) << endl;
    }   
    return 0;
}