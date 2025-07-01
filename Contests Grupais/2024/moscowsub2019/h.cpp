#include "bits/stdc++.h"

using namespace std;

#define endl '\n'

typedef long long ll;

const int mxn = 1e5+5;

signed solve(){

    int n,q; cin >> n >> q;

    string s; cin >> s;

    int cnt = 1;

    for(int i = 1; i < n; i++){
        if(s[i] != s[i-1]) cnt++;
    }

    // cout << s << ' ' << cnt << endl;

    while(q--){
        int a,b; cin >> a >> b; a--; b--;

        if(a > b) swap(a,b);

        if(s[a] != s[b]) {
            swap(s[a], s[b]);

            if(a == b-1){
                if(a != 0 && b != n-1){
                    if(s[a-1] == s[a] && s[b+1] == s[b]) cnt -= 2;
                    else if(s[a-1] != s[a] && s[b+1] != s[b]) cnt += 2;
                }

                else if(a != 0){
                    if(s[a-1] == s[a]) cnt--;
                    else cnt++;
                }

                else if(b != n-1){
                    if(s[b+1] == s[b]) cnt--;
                    else cnt++;
                }
            }

            else{
                if(a != 0 && a != n-1){
                    if(s[a-1] == s[a+1] && s[a-1] == s[a]) cnt-=2;
                    else if(s[a-1] == s[a+1] && s[a-1] != s[a]) cnt+=2;
                }

                else if(a == 0){
                    if(s[a] == s[a+1]) cnt--;
                    else cnt++;
                }

                else if(a == n-1){
                    if(s[a] == s[a-1]) cnt--;
                    else cnt++;
                }


                if(b != 0 && b != n-1){
                    if(s[b-1] == s[b+1] && s[b-1] == s[b]) cnt-=2;
                    else if(s[b-1] == s[b+1] && s[b-1] != s[b]) cnt+=2;
                }

                else if(b == 0){
                    if(s[b] == s[b+1]) cnt--;
                    else cnt++;
                }

                else if(b == n-1){
                    if(s[b] == s[b-1]) cnt--;
                    else cnt++;
                }
            }

        }


        // cout << s << ' ' << cnt << endl;

        if(cnt >= 8){
            cout << "Yes\n";
        }
        else{
            cout << "No\n";
        }
    }


    return 0;
}

signed main(){
    ios_base::sync_with_stdio(false), cin.tie(nullptr);

    int t = 1;
    // cin >> t;

    while(t--){
        solve();
    }

    return 0;
}