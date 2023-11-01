#include<bits/stdc++.h>
#define ll long long
#define FOR(a, b) for(int i = (a); i < (b); i++)

using namespace std;

int m, n, k, s, tmp, load, daDi, cmin = INT_MAX, dmin = INT_MAX;
int d[30][30], tp[30], res[30], khach[30];
bool b[30];

void scan(){
    for (int i = 0; i <= n; i++)
        for (int j = 0; j <= n; j++) {
            cin >> d[i][j];
            if (d[i][j] < dmin && i != j)
                dmin = d[i][j];
        }
}

void CP(){
    for (int i = 1; i <= n; i++)
        res[i] = tp[i];
}

void print(){
    for (int i = 0; i <= n; i++)
        cout << res[i] << "->";
    cout << 0 << endl;
}

bool check(){
    return s + dmin * (n - daDi + 1) < cmin;
}

void try1(int cnt){
    if (load == m){
        s += d[cnt][0];
        if (cmin > s){
            cmin = s;
            CP();
        }
        s -= d[cnt][0];
        return;
    }
    for (int v = 1; v <= n; v++){
        if (!b[v]){
            daDi++;
            tp[daDi] = v;
            b[v] = 1;
            s += d[cnt][v];
            //  TH1 len
            if (v <= m && tmp < k){
                tmp++;
                if (check()) try1(v);
                tmp--;
            }
            // TH2 xuong
            if (v > m && b[v - m]){
                tmp--;
                load++;
                if (check()) try1(v);
                tmp++;
                load--;
            }
            // tra lai cau hinh
            daDi--;
            s -= d[cnt][v];
            b[v] = 0;
        }  
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    cin >> m >> k;
    n = m * 2;
    scan();
    try1(0);
    cout << cmin << endl;
    print();
    return 0;
}