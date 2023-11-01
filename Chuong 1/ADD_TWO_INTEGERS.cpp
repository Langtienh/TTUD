#include<bits/stdc++.h>
#define ll long long
#define FOR(a, b) for(int i = (a); i < (b); i++)

using namespace std;

string sum(string a, string b){
    while (a.size() < b.size()) a = '0' + a;
    while (a.size() > b.size()) b = '0' + b;
    a = '0' + a; b = '0' + b;
    // cout << a << " + " << b << " = ";
    int n = a.size(); 
    string s(n, ' '); 
    char du = '0', temp;
    for (int i = n - 1; i >= 0; i--){
        temp = a[i] - '0' + b[i] - '0' + du;
        if (temp > '9'){
            du = '1'; temp = temp - '9' + 2 * '0' - '1';
        }
        else du = '0';
        s[i] = temp;
    }
    while(s[0] == '0') s = s.erase(0, 1);
    return s;
}

int main(){
    string a, b;
    while (cin >> a >> b)
        cout << sum(a, b) << endl;

    return 0;
}
