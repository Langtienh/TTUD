#include<bits/stdc++.h>

#define ll long long
using namespace std;

ll dx[9][9];
int cnt = 0, f = 0;

void print(){
for (int i = 0; i < 9; i++){
        for (int j = 0; j < 9; j++)
                cout << dx[i][j] << " ";
        cout << endl; 
    }
    cout << endl;
}

bool check(int x, int y, int k){
    //check cot, check hang
    for (int i = 0; i < 9; i++)
        if (dx[x][i] == k || dx[i][y] == k)
            return false;
    // check o
    int a = x / 3, b = y / 3;
    a *= 3; b *= 3;
    for (int i = a; i < a + 3; i++)
        for (int j = b; j < b + 3; j++)
            if (dx[i][j] == k)
                return false;
    return true;
}

void backTrack(int x, int y){
    if (f == 81){
        cnt++; return;
    }
    if (dx[x][y] == 0){
        for (int v = 1; v <= 9; v++)
            if(check(x, y, v)){
                dx[x][y] = v;
                f++;
                if (y == 8) backTrack(x + 1, 0);
                else backTrack(x, y + 1);
                dx[x][y] = 0;
                f--;
            }
    }
    else {
        if (y == 8) backTrack(x + 1, 0);
        else backTrack(x, y + 1);
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    for (int i = 0; i < 9; i++)
        for (int j = 0; j < 9; j++){
            cin >>  dx[i][j];
            if (dx[i][j] != 0) f++;
        }
    backTrack(0, 0);
    cout << cnt << endl;
    

        
    return 0;
}