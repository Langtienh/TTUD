#include<bits/stdc++.h>
#define ll long long
#define FOR(a, b) for(int i = (a); i < (b); i++)

using namespace std;

int n;

void inChuoi(string s){
    for(int i = 0; i < s.size(); i++) cout << s[i] << " ";
    cout << endl;
}

void hoanVi(string s, bool b[]){
    if (s.size() == n){
        inChuoi(s);
        return;
    }
    for (int i = 1; i <= n; i++){
        if(!b[i]){
            b[i] = true;
            hoanVi(s + char(i + '0'), b);
            b[i] = false;
        }
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    cin >> n;
    bool b[10];
    hoanVi("", b);
    return 0;
}