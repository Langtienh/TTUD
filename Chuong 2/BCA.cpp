#include <bits/stdc++.h>

using namespace std;

int m, n, k, h, MaxLoad, cmin = INT_MAX, xd[31][31];
vector<vector<int> > mon(31), gv(10);

// Thêm danh sách những người có thể dạy môn h
void pushMonHoc(){
    for (int i = 0; i < m; i++){
        cin >> k;
        for (int j = 0; j < k; j++){
            cin >> h; 
            mon[h].push_back(i);
        }
    }
}

// các môn trùng lịch (xung đột)
void pushXD(){
    int a, b;
    for (int i = 0; i < k; i++){
        cin >> a >> b;
        xd[a][b] = xd[b][a] = true;
    }
}

// in ra các giáo viên có thể dạy môn i
void printMon(){
    for (int i = 0; i <= n; i++){
        cout << "mon " << i << " : ";
        for (int j = 0; j < mon[i].size(); j++)
            cout << mon[i][j] << " ";
        cout << endl;
    }
}

// in ra các môn học mà giáo viên i được phân công 
void printGV(){
    for (int i = 0; i < m; i++){
        cout << "giao vien thu " << i << " day cac mon: ";
        for (int j = 0; j < gv[i].size(); j++)
            cout << gv[i][j] << " ";
        cout << endl;
    }
}

// Giáo viên dạy nhiều môn nhất
void maxLoad(){
    MaxLoad = 0;
    for (int i = 0; i < m; i++)
        if (MaxLoad < gv[i].size())
            MaxLoad = gv[i].size();
}

bool checkXD(int a, int b){
    for (int i = 0; i < gv[b].size(); i++)
        if(xd[a][gv[b][i]]) return false;
    return true;
}

// Phân bố môn học cnt cho 1 trong các gv
void try1(int cnt){
    //tìm phương án phân bố sao cho maxLoad là nhỏ nhất
    if (cnt == n + 1){
        maxLoad();
        if (MaxLoad < cmin){
            cmin = MaxLoad;
            // printGV();
        }
        return;
    }
    for (int i = 0; i < mon[cnt].size(); i++){
        if (checkXD(cnt, mon[cnt][i])){
            gv[mon[cnt][i]].push_back(cnt);
            try1(cnt + 1);
            gv[mon[cnt][i]].pop_back();
        }
    }

}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    cin >> m >> n;
    pushMonHoc();
    cin >> k;
    pushXD();
    try1(1); 
    cout << cmin << endl;
    return 0;
}
