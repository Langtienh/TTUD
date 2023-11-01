#include<bits/stdc++.h>
#define ll long long
#define FOR(a, b) for(int i = (a); i < (b); i++)

using namespace std;

int n;

void quayLui(string s){
    if (s.size() == n){
        cout << s << endl;
        return;
    }
    quayLui(s + '0');
    if (s.empty() || s[s.size() - 1] != '1')    quayLui(s + '1');
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    cin >> n;
    quayLui("");
    return 0;
}