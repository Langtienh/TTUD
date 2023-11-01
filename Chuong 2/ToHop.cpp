#include<bits/stdc++.h>
#define ll long long
#define xFOR(a, b) for(int i = (a); i < (b); i++)

ll mod = 1000000007;

using namespace std;

ll dx[1000][1000];

ll toHop(ll n, ll k){
    if (k == 0 || k == n) return 1;
    if (dx[n][k] != -1) return dx[n][k];
    dx[n][k] = (toHop(n - 1, k) % mod + toHop(n - 1, k - 1) % mod) % mod;
    return dx[n][k];
}

int main(){
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    memset(dx, -1, sizeof(dx));
    cin >> k >> n;
    cout << toHop(n, k) << endl;
    return 0;
}