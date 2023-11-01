#include<bits/stdc++.h>
#define ll long long

using namespace std;

int n, cmin = INT_MAX, s = 0;
int d[20][20]; // quãng đường từ TP i đến TP j
int tp[20], res[20]; // thanh pho da di qua thu i
bool b[20]; // Các thành phố đã đi qua  

// Nhập quãng đường
void enter(){
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            cin >> d[i][j];
}

void print(){
    for (int i = 0; i <= n; i++)
        cout << res[i] << " ";
    cout << endl;
}

void copyMIN(){
    for (int i = 1; i <= n; i++)
        res[i] = tp[i];
}

void TPDaDiThu(int cnt){
    int j = cnt - 1; // hiện tại đang ở tp tp[j]
    // da di duoc j TP và bây giờ trở về tp 0
    if (cnt == n){
        s += d[tp[j]][0];
        if (cmin > s){
            cmin = s;
            copyMIN();
        }
        s -= d[tp[j]][0];
        return;
    }
    // thử đi đến các thành phố chưa đi
    for (int i = 1; i < n; i++){
        if (!b[i] && i != tp[j]){
            s += d[tp[j]][i];
            b[i] = true;
            tp[cnt] = i;
            // nếu quãng đường lớn hơn cmin thì dừng lại
            if (s < cmin) TPDaDiThu(cnt + 1);
            // trả lại cấu hình
            s -= d[tp[j]][i];
            b[i] = false;
        }
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    cin >> n; enter();
    tp[0] = tp[n] = 0;
    TPDaDiThu(1); // bắt đầu từ tp 0 đi đến các TP khác
    cout << cmin << endl;
    print(); // in cac thanh pho da di qua
    return 0;
}