#include<bits/stdc++.h>

using namespace std;

int main(){
    string s;
    long long n;
    queue <long long> qe;
    while(1){
        cin >> s;
        if(s == "#") break;
        if(s == "POP"){
            if (qe.empty()) cout << "NULL" << endl;
            else{
            cout << qe.front() << endl;
            qe.pop();
            }
        }
        else{
            cin >> n;
            qe.push(n);
        }
    }
    return 0;   
}
