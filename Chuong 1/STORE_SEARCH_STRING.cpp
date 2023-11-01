#include<bits/stdc++.h>

using namespace std;

int main(){
    string s, s2;
    set<string> se;
    while(1){
        cin >> s;
        if(s == "*") break;
        se.insert(s);
    }
    while(1){
        cin >> s;
        if(s == "***") break;
        cin >> s2;
        if (s == "find"){
            if (se.find(s2) != se.end()) cout << 1 << endl;
            else cout << 0 << endl;
        }
        else{
            if(se.find(s2) != se.end()) cout << 0 << endl;
            else{ 
                cout << 1 << endl;
                se.insert(s2);
            }
        }
    }
}
