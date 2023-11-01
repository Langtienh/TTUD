#include <bits/stdc++.h>

#define llong long long

using namespace std;

void turnOff(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
}

void openIO(){
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
}

void scanArr(int a[], int n){
    for (int i = 0; i < n; i++) cin >> a[i];
}

void printArr(int a[], int n){
    for (int i = 0; i < n; i++) cout << a[i] << endl;
    cout << endl;
}

int main(){
    turnOff();
    // openIO();
    int n; cin >> n;
    llong x;
    set<llong> s;
    for (int i = 0; i < n; i++){
        cin >> x;
        cout << s.count(x) << endl;
        s.insert(x);
    }

}
