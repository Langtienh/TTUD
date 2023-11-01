#include<bits/stdc++.h>

using namespace std;

int main(){
    string s;
    long long n;
    stack<int> st;
    while(1){
        cin >> s;
        if(s == "#") break;
        if(s == "POP"){
            if (st.empty()) cout << "NULL" << endl;
            else{
            cout << st.top() << endl;
            st.pop();
            }
        }
        else{
            cin >> n;
            st.push(n);
        }
    }
    return 0;   
}
