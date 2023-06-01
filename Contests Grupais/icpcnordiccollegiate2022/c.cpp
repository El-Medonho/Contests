#include "bits/stdc++.h"

using namespace std;

#define fastio ios_base::sync_with_stdio(false), cin.tie(nullptr)

int main(){
    fastio;

    int n; cin >> n;
    string s; cin >> s;
    int ans = 0;
    int curr = 0;

    for(int i = 0; i < n; i++){
        if(s[i] == '1'){
            curr = 3;
        }
        if(curr){
            curr--;
            ans++;
        }
    }

    cout << ans << '\n';

    return 0;
}