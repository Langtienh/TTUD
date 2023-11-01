#include<bits/stdc++.h>

using namespace std;

int m, n, c[20], cnt, res = INT_MAX, cmin = INT_MAX; // cnt = so mon da hoc, res la dap an toi uu
bool b[20], d[20][5]; //b[i], d[i][j] da hoc mon i vao ki ki j
vector<vector<int> > monDK(20);

void scan1(){
    for (int i = 1; i <= n; i++){
        cin >> c[i];
        if (c[i] < cmin) cmin = c[i];
    }
}

void scan2(){
    bool x;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++) {
            cin >> x;
            if (x) monDK[i].push_back(j);
        }
}

void maxLoads(){    
    int s, maxLoad;
    s = maxLoad = 0;
    for (int i = 1; i <= m; i++){
        for (int j = 1; j <= n; j++)
            if (d[j][i]) s += c[j];
        if(s > maxLoad)  maxLoad = s;
        s = 0;
    }
    if (res > maxLoad) res = maxLoad;
}

void print(){
    for (int i = 1; i <= m; i++){
        for (int j = 1; j <= n; j++)
            cout << d[j][i] << " ";
        cout << endl;
    }
}

bool check(int v, int k){
    if (b[v]) return 0;
    for (int i = 0; i < monDK[v].size(); i++) {
        bool temp = 0;
        for (int j = 1; j < k; j++)
            if (d[monDK[v][i]][j]) temp = 1;
        if (!temp) return 0;
    }
    return 1;
}

bool Stop(int k) {
    return 0;
}

// xem xet co hoc mon v vao ki k khong
void try1(int k, int v){ 
    if (cnt == n) {
        // print();
        maxLoads();
        return;
    }
    if (k > m) return;
    // TH1: khong hoc
    if (v == n && !Stop(k)) try1(k + 1, 1);
    else if (!Stop(k)) try1(k, v + 1);
    // TH2: hoc
    if (check(v, k)) {
        cnt++;
        d[v][k] = b[v] = 1;
        if (v == n && !Stop(k)) try1(k + 1, 1);
        else if (!Stop(k)) try1(k, v + 1);
        d[v][k] = b[v] = 0;
        cnt--;
    }
}

int main() {
    // template
    // test1 : 12
    // test2 : 10
    // test3: 11
    // test4: 13
    char c[10] = "testN.txt";
    char x; cin >> x; c[4] = x;
    freopen(c, "r", stdin);
    freopen("output.txt", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    // code
    cin >> n >> m;
    scan1();
    scan2();
    try1(1, 1);
    cout << res << endl;
    return 0;
}
