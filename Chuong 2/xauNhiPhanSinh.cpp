#include<bits/stdc++.h>
#define ll long long
#define FOR(a, b) for(int i = (a); i < (b); i++)

using namespace std;

int n;

void inChuoi(string s){
    for (int i = 0; i < s.size(); i++) cout << s[i] << " ";
    cout << endl;
}

void quayLui(string s){
    if (s.size() == n){
        inChuoi(s); return;
    }
    quayLui(s + '0');
    quayLui(s + '1');
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