#include "bits/stdc++.h"

using namespace std;

#define endl '\n'

typedef long long ll;

const int b = 1e2;

signed main(){
    ios_base::sync_with_stdio(false), cin.tie(nullptr);

    string s; cin >> s;

    int mod; cin >> mod;

    ll ans = 0;

    int h = 97;

    vector<int> freql(h, 0), freqr(h, 0);

    vector<ll> arrl(1e5, 0), arrr(1e5, 0);

    int n = s.size();

    for(char c: s){
        int cc = c-32;

        for(int i = 1; i < h; i++){
            arrr[cc + b*i] += freqr[i];
            if(arrr[cc + b*i] >= mod) arrr[cc + b*i] -= mod;
        }   

        freqr[cc]++;
    }


    // for(int i = 1; i < h; i++){
    //     freqr[i] = 0;
    //     for(int j = 1; j < h; j++) freqr[i + b*j] = 0;
    // }   

    freqr[s[0]-32]--;
    for(int i = 1; i < h; i++){
        arrr[(s[0]-32) * b + i] -= freqr[i];
        if(arrr[(s[0]-32) * b + i] < 0) arrr[(s[0]-32) * b + i] += mod;
    }

    cout << arrr[('c'-32) * b + ('m'-32)] << endl;

    for(int i = 0; i < n; i++){
        int cc = s[i]-32;

        if(i < n-1){
            freqr[s[i+1]-32]--;
            for(int j = 1; j < h; j++){
                arrr[(s[i+1]-32) * b + j] -= freqr[j];
                if(arrr[(s[i+1]-32) * b + j] < 0) arrr[(s[i+1]-32) * b + j] += mod;
            }
        }

        if(i){
            for(int j = 1; j < h; j++){
                arrl[cc*b + j] += freql[j];
                if(arrl[j + cc*b] >= mod) arrr[cc*b + j] -= mod;
                ans += arrl[j+cc*b] * arrr[j+cc*b] % mod;
                if(ans >= mod) ans -= mod;
            }   
        }

        freql[cc]++;

        cout << ans << endl;
    }

    cout << ans << endl;




    return 0;
}