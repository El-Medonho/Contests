#include "bits/stdc++.h"

using namespace std;

typedef long long ll;

int find_first_diff(const string& s, char c) {
    for(int i = 0; i < s.size(); i++) {
        if(s[i] != c) return i;
    }
    return -1;
}

signed solve(){
    int n, e;
    cin >> n >> e;

    vector<string> s(n);
    for(string& si : s) cin >> si;
    
    vector<int> moves(e);

    
    for(char c = 'a'; c <= 'a'+e; c++) {
        for(string& si : s) {
            int curr = find_first_diff(si, c);
            if(curr == -1) {
                moves[c-'a'] = 1e9;
                break;
            }
            moves[c-'a'] += curr;
        }
    }
    
    if(all_of(moves.begin(), moves.end(), [](int x) {return x == 1e9;} )) {
        cout << "NO\n";
    }else {
        int c = min_element(moves.begin(), moves.end()) - moves.begin();
        cout << string(moves[c]+1,'a'+c) << '\n';
    }

    return 0;
}

signed main(){
    ios_base::sync_with_stdio(false), cin.tie(nullptr);

    int t = 1;

    while(t--){
        solve();
    }


    return 0;
}