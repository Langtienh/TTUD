#include<bits/stdc++.h>
#define ll long long
#define FOR(a, b) for(int i = (a); i < (b); i++)

using namespace std;

int a[21], b = 1;
int n;

void inArr(int a[]){
    for (int i = 1; i <= n; i++) cout << a[i];
    cout << endl;
}

void sinh(){
    int i = n;
    while(i && a[i] == 1){
        a[i] = 0; i--;
    }
    if (i == 0){
        b = 0; return;
    }
    a[i] = 1;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    cin >> n;
    while(b) {
        inArr(a);
        sinh();
    }

    return 0;
}