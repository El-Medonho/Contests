#include "bits/stdc++.h"

using namespace std;

typedef long long ll;

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
uniform_int_distribution<int> uid(500, 1e8);

string encode(string& s) {
    int n = s.size();

    if(all_of(s.begin(), s.end(), [](char c) {return c == '0';}) ||
       all_of(s.begin(), s.end(), [](char c) {return c == '1';})) {
        return s;
    }

    char s0 = s[0];

    for(int i = 0; i < n && s[i] == s0; i++) {
        s[i] = '2';
    }

    return s;
}

string decode(string& s) {
    int n = s.size();

    if(all_of(s.begin(), s.end(), [](char c) {return c == '0';}) ||
       all_of(s.begin(), s.end(), [](char c) {return c == '1';})) {
        return s;
    }

    int fi = -1;
    int li = -1;

    for(int i = 0; i < n; i++) {
        if(s[i] == '2' && (i != 0 && s[i-1] != '2' || i == 0 && s[n-1] != '2')) {
            fi = i;
        }
        if(s[i] == '2' && (i != n-1 && s[i+1] != '2' || i == n-1 && s[0] != '2')) {
            li = i;
        }
    }

    char s0 = (li != n-1) ? s[li+1] : s[0];
    s0 = (s0 == '0') ? '1' : '0';

    for(int i = 0; i < n; i++) {
        if(s[i] == '2') s[i] = s0;
    }

    string ans(n, '0');

    for(int i = fi, j = 0; j < n; i = (i+1)%n, j++) {
        ans[j] = s[i];
    }

    return ans;
}

signed main(){
    ios_base::sync_with_stdio(false), cin.tie(nullptr);

    string query, s;
    int n;
    cin >> query >> n >> s;

    if(query == "Encode") {
        cout << encode(s) << endl;
    }else {
        cout << decode(s) << endl;
    }

    return 0;
}