#include "bits/stdc++.h"
//ALELUIAAAAAAAAAAAAAAAAAAAA
using namespace std;

string s1, s2, s3, d1, d2, d3;
int n, ds;
vector<string> ans;
vector<int> di;

int diffCount(const string &a, const string &b) {
    int ans = 0;

    for(int i = 0; i < a.size(); i++) {
        if(a[i] != b[i]) ans++;
    }

    return ans;
}

void backtracking(string curr) {
    if(curr.size() < ds) {
        for(char c = 'a'; c <= 'z'; c++) {
            backtracking(curr + c);
        }
    }else {
        if(diffCount(d1,curr) <= 1
        && diffCount(d2,curr) <= 1
        && diffCount(d3,curr) <= 1) {
            ans.push_back(curr);
        }

        if(ans.size() > 1) {
            cout << "Ambiguous\n";
            exit(0);
        }
    }
}

int main() {
    ios::sync_with_stdio(0);
    
    cin >> s1 >> s2 >> s3;
    
    n = s1.size();

    for(int i = 0; i < n; i++) {
        if(s1[i] != s2[i] 
        || s1[i] != s3[i]
        || s2[i] != s3[i]) {
            d1.push_back(s1[i]);
            d2.push_back(s2[i]);
            d3.push_back(s3[i]);
            di.push_back(i);
        }    
    }

    ds = d1.size();

    if(ds > 3) {
        cout << "Impossible\n";
        return 0;
    }

    if(ds < 1) {
        cout << "Ambiguous";
        return 0;
    }

    backtracking("");

    if(ans.empty()) cout << "Impossible\n";
    else {
        for(int i = 0; i < di.size(); i++) {
            s1[di[i]] = ans[0][i]; 
        }
        cout << s1 << '\n';
    }
}
