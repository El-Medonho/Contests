#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
typedef long long ll;
const int mxn = 1e5+5;

int main(){
    int n;
    cin >> n;
    getchar();
    vector<pair<string, string> > v;

    for(int i=0; i<n; i++){
        string a;
        getline(cin, a);
        int pos = 0;
        for(int j=0; j<a.size(); j++){
            if(a[j]>='A' && a[j]<='Z'){
                pos = j;
                break;
            }
        }
        string b = a.substr(pos);
        v.push_back({b, a});
    }
    sort(v.begin(), v.end());
    for(auto [a, b]:v) cout << b << endl;
    return 0;
}