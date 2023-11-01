#include<bits/stdc++.h>

using namespace std;

int main(){
    string s;
    map<string, int> mp;
    while(cin >> s) mp[s]++;
    for (map<string, int>::iterator it = mp.begin(); it != mp.end(); it++)
        cout << it->first << " " << it->second << endl;
    return 0;
}
