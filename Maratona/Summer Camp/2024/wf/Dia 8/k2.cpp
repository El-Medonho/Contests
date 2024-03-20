    #include "bits/stdc++.h"

using namespace std;

#define endl '\n'

typedef long long ll;

signed solve(){

    int n; cin >> n;
    string s = "", t = "";

    for(int i = 0; i < n; i++){
        if(i < n/2){
            s += 'b';
            t += 'b';
        }
        if(i == n/2){
            t += 'b';
            for(int j = 0; j < n; j++){
                s += 'a';
                t += 'a';
            }
        }
        if(i > n/2){
            s += 'b';
            t += 'b';
        }
    }

    s += 'b';

    if(n == 1){
        cout << "ab\nba\n";
        return 0;
    }

    if(n==2){
        cout<<"abab\nbaba\n";
        return 0;
    }

    cout << s << '\n' << t << endl;

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