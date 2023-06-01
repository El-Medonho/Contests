#include "bits/stdc++.h"

using namespace std;

#define fastio ios_base::sync_with_stdio(false), cin.tie(nullptr)

int hh;

vector<int> z_function(string s, int pre) {          
    int n = min(hh+1, (int) s.size());
    vector<int> z(n);
    for (int i = 1, l = 0, r = 0; i < n; ++i) {
        if (i <= r)
            z[i] = min (r - i + 1, z[i - l]);
        while (i + z[i] + pre < s.length() && s[z[i] + pre] == s[i + z[i] + pre])
            ++z[i];
        if (i + z[i] - 1 > r)
            l = i, r = i + z[i] - 1;
    }
    return z;
}

int main(){
    fastio;

    string str; cin >> str >> hh;

    int pnt = 0; 
    int ans = 0;

    while(pnt < str.length()){
        ans++;
        vector<int> jj = z_function(str, pnt);

        int best = 0;
        for(int i = 0; i < jj.size(); i++){
            best = max(best, i + jj[i]);
        }
        pnt += best;
    }

    cout << ans << endl;


    return 0;
}