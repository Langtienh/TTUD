#include<bits/stdc++.h>
#define ll long long
#define FOR(a, b) for(int i = (a); i < (b); i++)

using namespace std;
int n, s;

vector<int> a;

void inArr(){
    for (int i = 0; i < n; i++)
        cout << a[i] << " ";
    cout << endl;
}

void quyHoach(int s, int n){
    int max = s - n + 1;
    if (n == 1){
        a.push_back(s);
        inArr();
        a.pop_back();
        return;
    }
    for (int i = 1; i <= max; i++){
        a.push_back(i);
        quyHoach(s - i, n - 1);
        a.pop_back();
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    cin >> n >> s;
    quyHoach(s, n);

    return 0;
}